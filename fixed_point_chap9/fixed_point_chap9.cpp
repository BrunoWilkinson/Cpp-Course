#include <iostream>

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

	operator double() const
	{
		return m_number + static_cast<double>(m_fraction) / 100.0;
	}

	friend std::ostream& operator<< (std::ostream& out, const FixedPoint2& point);
};

std::ostream& operator<< (std::ostream& out, const FixedPoint2& point)
{
	out << static_cast<double>(point);
	return out;
}

int main()
{
	FixedPoint2 a{ 34, 56 };
	std::cout << a << '\n';

	FixedPoint2 b{ -2, 8 };
	std::cout << b << '\n';

	FixedPoint2 c{ 2, -8 };
	std::cout << c << '\n';

	FixedPoint2 d{ -2, -8 };
	std::cout << d << '\n';

	FixedPoint2 e{ 0, -5 };
	std::cout << e << '\n';

	std::cout << static_cast<double>(e) << '\n';

	return 0;
}