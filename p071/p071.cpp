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
 * Ordered fractions
 * Problem 71
 *
 * Consider the fraction, n/d, where n and d are positive integers.
 * If n < d and HCF(n, d) = 1, it is called a reduced proper fraction.
 *
 * If we list the set of reduced proper fractions for d <= 8 in ascending order of size, we get:
 *  1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
 *
 * It can be seen that 2/5 is the fraction immediately to the left of 3/7.
 *
 * By listing the set of reduced proper fractions for d <= 1,000,000 in ascending order of size,
 * find the numerator of the fraction immediately to the left of 3/7.
 */
int main()
{
    Fraction three_sevenths{3, 7};
    Fraction global_to_the_left{2, 5};
    std::atomic<size_t> worker_position{0};
    std::mutex rpf_lock;

    std::vector<std::thread> workers;

    constexpr size_t WORKER_COUNT = 8;
    constexpr size_t STOP = 1'000'000;
    constexpr size_t WORK_AMOUNT = 1000;

    for(size_t w = 0; w < WORKER_COUNT; ++w)
    {
        workers.emplace_back(
            [&three_sevenths, &global_to_the_left, &worker_position, &rpf_lock]()
            {
                Fraction local_to_the_left{1, 1};
                {
                    std::lock_guard<std::mutex> guard{rpf_lock};
                    local_to_the_left = global_to_the_left;
                }

                while(worker_position < STOP)
                {
                    size_t start_idx = worker_position.fetch_add(WORK_AMOUNT);
                    size_t stop_idx = start_idx + WORK_AMOUNT;

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
                            if(value <= local_to_the_left.value)
                            {
                                continue;
                            }
                            // stop entirely if the fraction is now 3/7 or greater.
                            else if(value >= three_sevenths.value)
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
                                local_to_the_left.numerator = n;
                                local_to_the_left.denominator = d;
                                local_to_the_left.value = value;
                            }
                        }
                    }

                    // Now update local/global copy to the new best value.
                    {
                        std::lock_guard<std::mutex> guard{rpf_lock};
                        if(local_to_the_left.value > global_to_the_left.value)
                        {
                            global_to_the_left = local_to_the_left;
                        }
                        else
                        {
                            local_to_the_left = global_to_the_left;
                        }
                    }
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

    std::cout << global_to_the_left.numerator << "/" << global_to_the_left.denominator;

    return 0;
}
