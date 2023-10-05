#include "MutantStack.hpp"

/*int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "stack size before pop : " << mstack.size() << std::endl;
	std::cout << "element on the top : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "element on the top after pop : " << mstack.top() << std::endl;
	std::cout << "stack size after pop : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "it before incrementation : " << *it << std::endl;
	++it;
	std::cout << "it after incrementation : " << *it << std::endl;
	--it;
	std::cout << "it after decrementation : " << *it << std::endl;
	std::cout << "the entire list : " << std::endl;
	while (it != mstack.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return(0);
}*/


int main()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "stack size before pop : " << mstack.size() << std::endl;
	std::cout << "element on the top : " << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << "element on the top after pop : " << mstack.back() << std::endl;
	std::cout << "stack size after pop : " << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::cout << "it before incrementation : " << *it << std::endl;
	++it;
	std::cout << "it after incrementation : " << *it << std::endl;
	--it;
	std::cout << "it after decrementation : " << *it << std::endl;
	std::cout << "the entire list : " << std::endl;
	while (it != mstack.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
	return(0);
}