#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
#include <array>

int main()
{
    std::vector<std::string> logins {
        "319",
        "680",
        "180",
        "690",
        "129",
        "620",
        "762",
        "689",
        "762",
        "318",
        "368",
        "710",
        "720",
        "710",
        "629",
        "168",
        "160",
        "689",
        "716",
        "731",
        "736",
        "729",
        "316",
        "729",
        "729",
        "710",
        "769",
        "290",
        "719",
        "680",
        "318",
        "389",
        "162",
        "289",
        "162",
        "718",
        "729",
        "319",
        "790",
        "680",
        "890",
        "362",
        "319",
        "760",
        "316",
        "729",
        "380",
        "319",
        "728",
        "716"
    };

    std::sort(logins.begin(), logins.end());

    std::array<uint64_t, 10> global_counts{};

    std::array<
        std::array<uint64_t, 10>,
        3
    > local_counts{};
    for(size_t i = 0; i < 10; ++i)
    {
        for(size_t j = 0; j < 3; ++j)
        {
            local_counts[i][j] = 0;
        }
    }

//    for(const auto& pw : logins)
//    {
//        std::cout << pw << "\n";
//    }

    // Output from sorting:

    /**
    129
    160
    162
    162
    168
    180

    289
    290

    316
    316
    318
    318
    319
    319
    319
    319
    362
    368
    380
    389

    620
    629
    680
    680
    680
    689
    689
    690

    710
    710
    710
    716
    716
    718
    719
    720
    728
    729
    729
    729
    729
    729
    731
    736
    760
    762
    762
    769
    790

    890
     */

    // Dependency Graph manually created from sorted output:

    // 0 =>
    // 1 => 02689
    // 2 => 089
    // 3 => 012689
    // 6 => 0289
    // 7 => 0123689
    // 8 => 09
    // 9 => 0

    // Hand figured out answer based on graph:
    // 73162890

    std::cout << 73162890 << "\n";

    return 0;
}
