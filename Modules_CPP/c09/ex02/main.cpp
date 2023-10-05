#include "PmergeMe.hpp"

void	get_it(std::string arg)
{
	std::stringstream ss(arg);
	std::string tmp;
	while (std::getline(ss, tmp, ' '))
	{
		if (tmp.length() > 1)
		{
			for (unsigned int i = 0; i < tmp.length(); ++i)
			{
				if (!std::isdigit(tmp[i]))
				{
					std::cout << "Error : only digit is allowed" << std::endl;
					exit(EXIT_FAILURE);
				}
			}
		}
		else
		{
			if (!std::isdigit(tmp[0]))
			{
				std::cout << "Error : only digit is allowed" << std::endl;
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	parse(char	**av, int ac)
{
	if (ac == 1)
	{
		std::string tmp(av[0]);
		if (tmp.empty())
		{
			std::cout << "Error : please insert int" << std::endl;
			exit(EXIT_FAILURE);
		}
		get_it(tmp);
	}
	else
	{
		int i = 0;
		while (av && av[i])
		{
			std::string tmp(av[i]);
			if (tmp.empty())
			{
				std::cout << "Error : please insert int" << std::endl;
				exit (EXIT_FAILURE);
			}
			else
			{
				for (unsigned int j = 0; j < tmp.size(); ++j)
				{
					if (!std::isdigit(tmp[j]))
					{
						std::cout << "Error : only digit is allowed : " << tmp << std::endl;
						exit(EXIT_FAILURE);
					}
				}
			}
			++i;
		}
	}
}

int main(int ac, char **av)
{
	try
	{
		if (ac < 2)
		{
			std::cout << "Error : need more args" << std::endl;
			return (1);
		}
		parse(&av[1], (ac - 1));
		if (ac == 2)
		{
			std::string tmp(av[1]);
			PmergeMe pmerge(tmp);
			pmerge.print_before();
			timeval start;
    		gettimeofday(&start, NULL);
			clock_t start_vec = clock();
			pmerge.sort_one_vec();
			clock_t end_vec = clock();
			double vec = double(end_vec - start_vec) / CLOCKS_PER_SEC;
			pmerge.print_after();
			clock_t start_list = clock();
			pmerge.sort_one_list();
			clock_t end_list = clock();
			double list = double(end_list - start_list) / CLOCKS_PER_SEC;
			std::cout << "Time to process a range of " << std::fixed << pmerge.unsort_vec.size() << " elements with std::vector : " << vec << "us." << std::endl;
			std::cout << "Time to process a range of " << std::fixed << pmerge.unsort_vec.size() << " elements with std::list : " << list << "us." << std::endl;
		}
		else
		{
			PmergeMe pmerge(&av[1]);
			pmerge.print_before();
			clock_t start_vec = clock();
			pmerge.sort_one_vec();
			clock_t end_vec = clock();
			double vec = double(end_vec - start_vec) / CLOCKS_PER_SEC;
			pmerge.print_after();
			clock_t start_list = clock();
			pmerge.sort_one_list();
			clock_t end_list = clock();
			double list = double(end_list - start_list) / CLOCKS_PER_SEC;
			std::cout << "Time to process a range of " << std::fixed << pmerge.unsort_vec.size() << " elements with std::vector : " << vec << "us." << std::endl;
			std::cout << "Time to process a range of " << std::fixed << pmerge.unsort_vec.size() << " elements with std::list : " << list << "us." << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
