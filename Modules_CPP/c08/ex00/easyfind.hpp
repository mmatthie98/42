#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <exception>

template <typename T>
int		easyfind(T container, int n)
{
	if (find(container.begin(), container.end(), n) == container.end())
		throw std::runtime_error("element : " + std::to_string(n) + " is not found");
	else
		return (n);
}
#endif