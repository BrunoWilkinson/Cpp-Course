#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Car
{
private:
    std::string m_make;
    std::string m_model;
public:
    Car(std::string make, std::string model) : 
        m_make{ make }, m_model { model }
    {}
    friend bool operator==(const Car& c1, const Car& c2);
    friend bool operator!=(const Car& c1, const Car& c2);
    friend std::ostream& operator<< (std::ostream& out, const Car& car);
    friend bool operator<(const Car& c1, const Car& c2)
    {
        if (c1.m_make == c2.m_make)
            return c1.m_model < c2.m_model;
        return c1.m_make < c2.m_make;
    }
};
bool operator==(const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make && c1.m_model == c2.m_model);
}

bool operator!=(const Car& c1, const Car& c2)
{
    return !(c1 == c2);
}

std::ostream& operator<< (std::ostream &out, const Car &car)
{
    out << '(' << car.m_make << ", " << car.m_model << ')';
    return out;
}

int main()
{
    std::vector<Car> cars{
      { "Toyota", "Corolla" },
      { "Honda", "Accord" },
      { "Toyota", "Camry" },
      { "Honda", "Civic" }
    };

    std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

    for (const auto& car : cars)
        std::cout << car << '\n'; // requires an overloaded operator<<

    return 0;
}
