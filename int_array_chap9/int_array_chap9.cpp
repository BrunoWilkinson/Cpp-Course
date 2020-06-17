#include <iostream>
#include <cassert>

/*
Write your own integer array class named IntArray from scratch (do not use std::array or std::vector). 
Users should pass in the size of the array when it is created, and the array should be dynamically allocated. 
Use assert statements to guard against bad data. Create any constructors or overloaded operators needed to make the following program operate correctly:
*/

class IntArray
{
private:
	int m_size{ 0 };
	int* m_data{ nullptr };

public:
	IntArray(int size) : m_size{ size }
	{
		assert(size > 0 && "IntArray length should be a positive integer");
		m_data = new int[m_size] {};
	}

	IntArray(const IntArray& source) :
		m_size{ source.m_size }
	{
		m_data = new int[m_size];
		for (int i{ 0 }; i < source.m_size; i++)
			m_data[i] = source.m_data[i];
	}

	~IntArray()
	{
		delete[] m_data;
	}

	IntArray& operator= (const IntArray& source);
	friend std::ostream& operator<< (std::ostream& out, const IntArray& array);
	int& operator[] (int index);
};

IntArray& IntArray::operator= (const IntArray& source)
{
	if (this == &source)
		return *this;

	delete[] m_data;

	m_size = source.m_size;

	m_data = new int[m_size];

	for (int i{ 0 }; i < source.m_size; i++)
		m_data[i] = source.m_data[i];

	return *this;
}

std::ostream& operator<< (std::ostream& out, const IntArray& array)
{
	for (int i{ 0 }; i < array.m_size; ++i)
	{
		out << array.m_data[i] << ' ';
	}
	return out;
}

int& IntArray::operator[] (int index)
{
	assert(index >= 0);
	assert(index < m_size);
	return m_data[index];
}

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };
	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	std::cout << b << '\n';

	return 0;
}