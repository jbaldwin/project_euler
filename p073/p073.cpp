#include <lib/Numeric.hpp>

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>

struct Fraction
{
    Fraction(uint64_t n, uint64_t d)
        :   numerator(n),
            denominator(d),
            value((double)n / d)
    {

    }

    Fraction(uint64_t n, uint64_t d, double f)
        :   numerator(n),
            denominator(d),
            value(f)
    {

    }

    size_t numerator;
    size_t denominator;
    double value;

    auto operator<(const Fraction& other) const -> bool
    {
        return value < other.value;
    }
};

/**
 * Counting fractions in a range
 * Problem 71
 *
 * Consider the fraction, n/d, where n and d are positive integers.
 * If n < d and HCF(n, d) = 1, it is called a reduced proper fraction.
 *
 * If we list the set of reduced proper fractions for d <= 8 in ascending order of size, we get:
 *  1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
 *
 * It can be seen that there are 3 fractions between 1/3 and 1/2.
 *
 * How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d <= 12,000?
 */
int main()
{
    Fraction lower_bound{1, 3};
    Fraction upper_bound{1, 2};
    std::atomic<size_t> worker_position{0};
    std::atomic<size_t> g_count{0};

    std::vector<std::thread> workers;

    constexpr size_t WORKER_COUNT = 8;
    constexpr size_t STOP = 12'000;
    constexpr size_t WORK_AMOUNT = 1000;

    for(size_t w = 0; w < WORKER_COUNT; ++w)
    {
        workers.emplace_back(
            [&lower_bound, &upper_bound, &worker_position, &g_count]()
            {
                while(worker_position < STOP)
                {
                    size_t start_idx = worker_position.fetch_add(WORK_AMOUNT);
                    size_t stop_idx = start_idx + WORK_AMOUNT;

                    size_t local_count{0};

                    if(__glibc_unlikely(start_idx == 0))
                    {
                        start_idx = 2;
                    }

                    if(__glibc_unlikely(stop_idx >= STOP))
                    {
                        stop_idx = STOP + 1;
                    }

                    for(size_t d = start_idx; d < stop_idx; ++d)
                    {
                        for(size_t n = 1; n < d; ++n)
                        {
                            // skip anything less than current left fraction
                            double value = ((double)n) / d;
                            if(value <= lower_bound.value)
                            {
                                continue;
                            }
                            // stop entirely if the fraction is now 3/7 or greater.
                            else if(value >= upper_bound.value)
                            {
                                break;
                            }

                            // If the gcd equals 1, reduce the fraction
                            // and save to merge into the global to_the_left var
                            // across threads. These are our candidates to be the
                            // next version
                            auto hcf = lib::gcd(n, d);
                            if(hcf == 1)
                            {
                                ++local_count;
                            }
                        }
                    }

                    g_count += local_count;
                }
            }
        );
    }

    while(worker_position < STOP)
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1000ms);
        std::cout << worker_position << "\n";
    }

    for(auto& t : workers)
    {
        t.join();
    }

    std::cout << g_count;

    return 0;
}
