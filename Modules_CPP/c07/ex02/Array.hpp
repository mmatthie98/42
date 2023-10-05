#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>

template <typename T>
class Array
{
	public:
		Array<T>()
		{
			array = new T();
			len = 0;
		}

		Array<T>(unsigned int n)
		{
			array = new T[n];
			for (unsigned int i = 0; i < n; i++)
				array[i] = T();
			len = n;
		}

		Array<T>(const Array &other)
		{
			array = new T[other.len];
			for (unsigned int i = 0;i < other.len; i++)
				array[i] = other.array[i];
			len = other.len;
		}

		Array<T>	&operator=(const Array &other)
		{
			array = new T[other.len];
			for (int i = 0;i < other.len; i++)
				array[i] = other.array[i];
			len = other.len;
		}

		T	&operator[](unsigned int index)
		{
			if (index >= 0 && index <= len)
				return (array[index]);
			else
				throw std::exception();
		}

		unsigned int size() const
		{
			return (len);
		}

		~Array()
		{
			if (array)
				delete [] array;
		}
	
	private:
		T	*array;
		unsigned int len;
};
#endif