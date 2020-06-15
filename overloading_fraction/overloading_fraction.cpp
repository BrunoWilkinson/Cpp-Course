#include <iostream>

class Fraction 
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };
public:
    Fraction(int numerator = 0, int denominator = 1) : 
        m_numerator{ numerator }, m_denominator{ denominator }
    {
        reduce();
    }
    void print() const 
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
    static int gcd(int a, int b) {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }
    void reduce()
    {
        if (m_numerator != 0 && m_denominator != 0)
        {
            int gcd{ Fraction::gcd(m_numerator, m_denominator) };
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }
    friend Fraction operator*(const Fraction& a, const Fraction& b);
    friend Fraction operator*(int a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, int b);
    friend std::ostream& operator<< (std::ostream &out, const Fraction &fraction);
    friend std::istream& operator>> (std::istream& in, Fraction& fraction);
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(int value, const Fraction &f1)
{
    return { f1.m_numerator * value, f1.m_denominator};
}

Fraction operator*(const Fraction &f1, int value)
{
    return { f1.m_numerator * value, f1.m_denominator };
}

std::ostream& operator<< (std::ostream &out, const Fraction &fraction)
{
    out << fraction.m_numerator << '/' << fraction.m_denominator;
    return out;
}

std::istream& operator>> (std::istream& in, Fraction& fraction)
{
    in >> fraction.m_numerator;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    in >> fraction.m_denominator;
    fraction.reduce();
    return in;
}

int main()
{
    Fraction f1{ 2, 5 };
    std::cout << f1 << '\n';

    Fraction f2{ 3, 8 };
    std::cout << f2 << '\n';

    Fraction f3{ f1 * f2 };
    std::cout << f3 << '\n';

    Fraction f4{ f1 * 2 };
    std::cout << f4 << '\n';

    Fraction f5{ 2 * f2 };
    std::cout << f5 << '\n';

    Fraction f6{ Fraction{1, 2} *Fraction{2, 3} *Fraction{3, 4} };
    std::cout << f6 << '\n';

    Fraction f7{ 0, 6 };
    std::cout << f7 << '\n';

    Fraction f8;
    std::cout << "Enter fraction 1: ";
    std::cin >> f8;

    Fraction f9;
    std::cout << "Enter fraction 2: ";
    std::cin >> f9;

    std::cout << f8 << " * " << f9 << " is " << f8 * f9 << '\n'; // note: The result of f1 * f2 is an r-value

    return 0;
}