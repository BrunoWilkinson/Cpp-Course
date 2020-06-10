#include <iostream>
#include <array>
#include <string>
#include <algorithm>

struct Student
{
    std::string name{};
    int score{};
};

struct Season
{
    std::string name{};
    double averageTmp{};
};


int main()
{
    std::array<Student, 8> arr{
    { { "Albert", 3 },
      { "Ben", 5 },
      { "Christine", 2 },
      { "Dan", 8 },
      { "Enchilada", 4 },
      { "Francis", 1 },
      { "Greg", 3 },
      { "Hagrid", 5 } }
    };
    auto best{
        std::max_element(arr.begin(), arr.end(), [](const auto& a, const auto& b) -> bool {
            return (a.score < b.score);
        })
    };
    std::cout << best->name << " is the best student\n";

    std::array<Season, 4> seasons{
    { { "Spring", 285.0 },
      { "Summer", 296.0 },
      { "Fall", 288.0 }, 
      { "Winter", 263.0 } }
    };
    std::sort(seasons.begin(), seasons.end(), [](const auto& a, const auto& b) {
        return (a.averageTmp < b.averageTmp);
        });
    for (const auto& season : seasons)
    {
        std::cout << season.name << '\n';
    }

    return 0;
}