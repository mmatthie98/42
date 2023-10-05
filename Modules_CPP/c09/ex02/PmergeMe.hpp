#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <ctime>
#include <sys/time.h>


class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(char **av);
		PmergeMe(std::string arg);
		~PmergeMe();
		PmergeMe(const PmergeMe	&other);
		PmergeMe	&operator=(const PmergeMe &other);
		void sort_one_vec();
		void sort_one_list();
		void sort_multiple();
		int issort_vec();
		int issort_list();
		void insertion_vec();
		void insertion_list();
		void print_before();
		void print_after();
		void mergeInsertionSortVec(std::vector<int> &arr, int right, int left);
		void mergeInsertionSortList(std::list<int>& arr, int left, int right);
		void insertionSortList(std::list<int>& arr, int left, int right);
		void merge_vec(std::vector<int>& arr, int left, int mid, int right);
		void mergeList(std::list<int>& arr, int left, int mid, int right);
		std::vector<int> unsort_vec;
		std::list<int>	unsort_list;
		std::vector<int> sort_vec;
		std::list<int> sort_ved;
};