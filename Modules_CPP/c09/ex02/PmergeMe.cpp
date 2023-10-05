#include "PmergeMe.hpp"

void PmergeMe::mergeInsertionSortVec(std::vector<int>& arr, int left, int right)
{
    if (right - left + 1 <= 10)
	{
        insertion_vec();
        return;
    }
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeInsertionSortVec(arr, left, mid);
    mergeInsertionSortVec(arr, mid + 1, right);
    merge_vec(arr, left, mid, right);
}

void PmergeMe::insertionSortList(std::list<int>& arr, int left, int right) {
    std::list<int>::iterator it, j;
    for (it = std::next(arr.begin(), left + 1); it != std::next(arr.begin(), right + 1); ++it) {
        int value = *it;
        j = it;
        while (j != arr.begin() && *std::prev(j) > value) {
            *j = *std::prev(j);
            --j;
        }
        *j = value;
    }
}

void PmergeMe::mergeInsertionSortList(std::list<int>& arr, int left, int right) {
    if (right - left <= 5) {
        insertionSortList(arr, left, right);
    } else {
		int mid = left + (right - left) / 2;
        mergeInsertionSortList(arr, left, mid);
        mergeInsertionSortList(arr, mid + 1, right);
        mergeList(arr, left, mid, right);
    }
}

void	PmergeMe::print_before()
{
	std::cout << "Before : ";
	for (size_t i = 0; i < unsort_vec.size(); i++)
        std::cout << unsort_vec[i] << " ";
    std::cout << std::endl;
}

void	PmergeMe::print_after()
{
	std::cout << "After : ";
	for (size_t i = 0; i < unsort_vec.size(); i++)
        std::cout << unsort_vec[i] << " ";
    std::cout << std::endl;
}

void	PmergeMe::insertion_vec()
{
	for (size_t i = 1; i < unsort_vec.size(); ++i)
	{
		int key = unsort_vec[i];
		int j = i - 1;
		while (j >= 0 && unsort_vec[j] > key)
		{
			unsort_vec[j + 1] = unsort_vec[j];
			j--;
		}
		unsort_vec[j + 1] = key;
	}
}

void	PmergeMe::insertion_list()
{
	std::list<int>::iterator it = unsort_list.begin();
	std::list<int>::iterator ite = it;
	ite++;
	while (ite != unsort_list.end())
	{
		if (*it > *ite)
		{
			std::iter_swap(it, ite);
			it = unsort_list.begin();
			ite = it;
			++ite;
		}
		else
		{
			++it;
			++ite;
		}
	}
}

void	PmergeMe::sort_one_vec()
{
	if (unsort_vec.size() < 2)
	{
		std::cout << "Error : need at least 2 number to sort" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		if (unsort_vec.size() < 10)
			insertion_vec();
		else
			mergeInsertionSortVec(unsort_vec, 0, unsort_vec.size() - 1);
	}
}

void	PmergeMe::sort_one_list()
{
	if (unsort_list.size() < 2)
	{
		std::cout << "Error : need at lease 2 number to sort" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		if (unsort_list.size() < 10)
			insertion_list();
		else
			mergeInsertionSortList(unsort_list, 0, unsort_list.size() - 1);
	}
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char	**av)
{
	int i = 0;
	while(av && av[i])
	{
		std::string tmp(av[i]);
		int value = std::stoi(tmp);
		unsort_vec.push_back(value);
		unsort_list.push_back(value);
		i++;
	}
}

PmergeMe::PmergeMe(std::string arg)
{
	std::stringstream ss(arg);
	std::string tmp;
	while (std::getline(ss, tmp, ' '))
	{
		int value = std::stoi(tmp);
		unsort_vec.push_back(value);
		unsort_list.push_back(value);
	}
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) 
{
    unsort_vec = other.unsort_vec;
    unsort_list = other.unsort_list;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) 
{
    if (this != &other) {
        unsort_vec = other.unsort_vec;
        unsort_list = other.unsort_list;
    }
    return *this;
}

void PmergeMe::merge_vec(std::vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
	std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void PmergeMe::mergeList(std::list<int>& arr, int left, int mid, int right) {
    std::list<int> temp;
    std::list<int>::iterator begin = std::next(arr.begin(), left);
    std::list<int>::iterator end = std::next(arr.begin(), right + 1);

    temp.insert(temp.begin(), begin, end);

    std::list<int>::iterator itLeft = temp.begin();
    std::list<int>::iterator itRight = std::next(temp.begin(), mid - left + 1);
    std::list<int>::iterator itOrig = std::next(arr.begin(), left);

    while (itLeft != std::next(temp.begin(), mid - left + 1) && itRight != temp.end()) {
        if (*itLeft < *itRight) {
            *itOrig = *itLeft;
            ++itLeft;
        } else {
            *itOrig = *itRight;
            ++itRight;
        }
        ++itOrig;
    }

    while (itLeft != std::next(temp.begin(), mid - left + 1)) {
        *itOrig = *itLeft;
        ++itLeft;
        ++itOrig;
    }
}