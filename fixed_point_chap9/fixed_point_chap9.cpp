#include <iostream>
#include <cmath>

class FixedPoint2
{
private:
	std::int_least16_t m_number{};
	std::int_least8_t m_fraction{};

public:
	FixedPoint2(std::int_least16_t number = 0, std::int_least8_t fraction = 0) :
		m_number{ number }, m_fraction{ fraction }
	{
		if (m_number < 0 || m_fraction < 0)
		{
			if (m_number > 0)
				m_number = -m_number;
			if (m_fraction > 0)
				m_fraction = -m_fraction;
		}
	}

	FixedPoint2(double value) :
		m_number{ static_cast<std::int_least16_t>(value) },
		m_fraction{ static_cast<std::int_least8_t>(round((value - m_number) * 100)) }
	{
	}

	operator double() const
	{
		return m_number + static_cast<double>(m_fraction) / 100.0;
	}

	FixedPoint2 operator- () const;
	friend FixedPoint2 operator+(const FixedPoint2& point1, const FixedPoint2& point2);
	friend bool operator== (const FixedPoint2& point1, const FixedPoint2& point2);
	friend std::ostream& operator<< (std::ostream& out, const FixedPoint2& point);
	friend std::istream& operator>> (std::istream& in, FixedPoint2& point);
};

bool operator== (const FixedPoint2& point1, const FixedPoint2& point2)
{
	return (point1.m_number == point2.m_number && point1.m_fraction == point2.m_fraction);
}

FixedPoint2 FixedPoint2::operator- () const
{
	return FixedPoint2(-m_number, -m_fraction);
}

FixedPoint2 operator+(const FixedPoint2& point1, const FixedPoint2& point2)
{
	return FixedPoint2(static_cast<double>(point1) + static_cast<double>(point2));
}

std::ostream& operator<< (std::ostream& out, const FixedPoint2& point)
{
	out << static_cast<double>(point);
	return out;
}

std::istream& operator>> (std::istream& in, FixedPoint2& point)
{
	double d{};
	in >> d;
	point = FixedPoint2(d);
	return in;
}

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } +FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } +FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } +FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } +FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } +FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } +FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } +FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } +FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}

int main()
{
	testAddition();

	FixedPoint2 a{ -0.48 };
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}