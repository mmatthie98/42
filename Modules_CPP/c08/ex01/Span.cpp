#include "Span.hpp"

Span::Span() : N(0){}

Span::Span(unsigned int nb) : N(nb){}

Span::Span(const Span &other) : N(other.N)
{
	if (other.get_size())
	{
		unsigned int tmp = other.get_size();
		for (unsigned int i = 0;i < tmp; i++)
			array.push_back(other.array[i]);
	}
}

Span	&Span::operator=(const Span	&other)
{
	if (this != &other)
	{
		N = other.N;
		array = other.array;
	}
	return (*this);
}

Span::~Span() {}

void Span::fill_it(int nb, int content)
{
	if (this->get_size() < static_cast<unsigned int>(nb))	
		throw std::string("Span::TooMuchNumbers");
	else if (!nb)
		throw std::string("Span::NeedNumbersToParam");
	else
		this->array.insert(this->array.begin(), nb, content);
}

void Span::addNumber(int nb)
{
	if (array.size() + 1 > this->N)
		throw std::string("Span::TooMuchNumbers");
	this->array.push_back(nb);
}

int Span::shortestSpan()
{
    if (array.size() <= 1)
        throw std::string("Span::NeedMoreNumbers");

    std::sort(array.begin(), array.end());
    int shortest = std::numeric_limits<int>::max();

    for (unsigned int i = 1; i < array.size(); i++)
    {
        int span = array[i] - array[i - 1];
        if (span < shortest)
            shortest = span;
    }

    return shortest;
}

int Span::longestSpan()
{
    if (array.size() <= 1)
        throw std::string("Span::NeedMoreNumbers");

    std::sort(array.begin(), array.end());
    return array.back() - array.front();
}

void Span::print_it()
{
	for (std::vector<int>::iterator it = this->array.begin(); it != this->array.end(); it++)
		std::cout << static_cast<int>(*it) << std::endl;
}

unsigned int Span::get_size() const
{
	return (this->N);
}