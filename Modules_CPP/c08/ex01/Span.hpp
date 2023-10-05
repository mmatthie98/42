#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>

class Span
{
	private:
		unsigned int N;
		std::vector<int> array;
	public:
		Span();
		Span(unsigned int size);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		void addNumber(int nb);
		void print_it();
		unsigned int get_size() const;
		int shortestSpan();
		int longestSpan();
		void fill_it(int nb, int content);
};
#endif