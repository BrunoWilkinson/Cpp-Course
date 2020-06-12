#include <iostream>
#include <cstdint>

class RGBA {
private:
	using color_type = std::uint_fast8_t;
private:
	color_type m_red;
	color_type m_green;
	color_type m_blue;
	color_type m_alpha;
public:
	RGBA() : m_red{ 0 }, m_green{ 0 }, m_blue{ 0 }, m_alpha{ 255 }
	{}
	RGBA(color_type red, color_type green, color_type blue) :
		m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ 255 }
	{}
	RGBA(color_type red, color_type green, color_type blue, color_type alpha) :
		m_red { red }, m_green { green }, m_blue { blue }, m_alpha { alpha }
	{}
	void print() {
		std::cout << "r=" << static_cast<int>(m_red) << 
			" g=" << static_cast<int>(m_green) << 
			" blue=" << static_cast<int>(m_blue) << 
			" a=" << static_cast<int>(m_alpha) << '\n';
	}
};

int main()
{
	RGBA teal{ 0, 127, 127 };
	teal.print();
	return 0;
}
