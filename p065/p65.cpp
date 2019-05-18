#include <iostream>
#include <gmpxx.h>

int main()
{
    using BigInt = mpz_class;

    BigInt n_k1{1};
    BigInt n{2};

    for(int i = 2; i <= 100; ++i)
    {
        BigInt n_k2 = n_k1;

        BigInt a_k = (i % 3 == 0) ? 2 * (i / 3) : 1;
        n_k1 = n;

        a_k = a_k * n_k1;
        a_k = a_k + n_k2;
        n = a_k;
    }

    std::string s = n.get_str(10);
    int sum = 0;
    for(auto c : s)
    {
        sum += c - 48;
    }

    std::cout << sum;

    return 0;
}
