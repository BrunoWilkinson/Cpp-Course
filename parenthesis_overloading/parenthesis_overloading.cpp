#include <iostream>
#include <string>
#include <cassert>

class Mystring
{
private:
    std::string m_string;
public:
    Mystring(std::string string) : m_string{ string }
    {}
    std::string operator() (int start, int end);
};

std::string Mystring::operator() (int start, int end)
{
    assert(start + end <= static_cast<int>(m_string.length()) && "Mystring::operator(int, int): Substring is out of range");
    std::string temp{ "" };
    for (int counter{ 0 }; counter < end; ++counter)
    {
        temp += m_string[static_cast<std::string::size_type>(start + counter)];
    }
    return temp;
}

int main()
{
    Mystring string{ "Hello, world!" };
    std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}