#include <iostream>
#include <stack>
#include <vector>
#include "stack.hpp"

size_t test(){
	size_t mistakes = 0;
	size_t i = 1;

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test constructor stack<int> ******************" << std::endl;
	std::deque<int> mydeque (3,100);
	std::vector<int> myvector (2,200);        // vector with 2 elements

	ft::stack<int> firstOur;                    // empty stack
	std::stack<int> firstOriginal;                    // empty stack

	ft::stack<int,std::deque<int> > secondOur (mydeque);
	std::stack<int> secondOriginal (mydeque);
	ft::stack<int,std::vector<int> > thirdOur;  // empty stack using vector
	ft::stack<int,std::vector<int> > fourthOur (myvector);
	std::stack<int,std::vector<int> > thirdOriginal;  // empty stack using vector
	std::stack<int,std::vector<int> > fourthOriginal (myvector);

	std::cout << "Our size of first: " << firstOur.size() << '\n';
	std::cout << "Our size of second: " << secondOur.size() << '\n';
	std::cout << "Our size of third: " << thirdOur.size() << '\n';
	std::cout << "Our size of fourth: " << fourthOur.size() << '\n';
	std::cout << "Original size of first: " << firstOriginal.size() << '\n';
	std::cout << "Original size of second: " << secondOriginal.size() << '\n';
	std::cout << "Original size of third: " << thirdOriginal.size() << '\n';
	std::cout << "Original size of fourth: " << fourthOriginal.size() << '\n';
	if (firstOur.size() == firstOriginal.size() &&
		secondOur.size() == secondOriginal.size() &&
		thirdOur.size() == thirdOriginal.size() &&
		fourthOur.size() == fourthOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test empty stack<int> ******************" << std::endl;
	ft::stack<int> mystackOur;
	std::stack<int> mystackOriginal;
	int sum (0);
	int sumOriginal (0);
	for (int i=1;i<=10;i++) mystackOur.push(i);
	for (int i=1;i<=10;i++) mystackOriginal.push(i);
	while (!mystackOur.empty())
	{
		sum += mystackOur.top();
		mystackOur.pop();
	}
	while (!mystackOriginal.empty())
	{
		sumOriginal += mystackOriginal.top();
		mystackOriginal.pop();
	}
	std::cout << "Our total: " << sum << '\n';
	std::cout << "Original total: " << sumOriginal << '\n';
	if (sum == sumOriginal)
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test size/pop stack<int> ******************" << std::endl;
	ft::stack<int> myintsOur;
	std::stack<int> myintsOriginal;
	std::cout << "0. size: " << myintsOur.size() << '\n';
	std::cout << "0. size: " << myintsOriginal.size() << '\n';
	for (int i=0; i<5; i++) myintsOur.push(i);
	std::cout << "1. size: " << myintsOur.size() << '\n';
	for (int i=0; i<5; i++) myintsOriginal.push(i);
	std::cout << "1. size: " << myintsOriginal.size() << '\n';
	myintsOur.pop();
	std::cout << "2. size: " << myintsOur.size() << '\n';
	myintsOriginal.pop();
	std::cout << "2. size: " << myintsOriginal.size() << '\n';
	if (myintsOur.size() == myintsOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test top/push stack<int> ******************" << std::endl;
	ft::stack<int> mystackTopOur;
	std::stack<int> mystackTopOriginal;
	mystackTopOur.push(10);
	mystackTopOur.push(20);
	mystackTopOriginal.push(10);
	mystackTopOriginal.push(20);

	mystackTopOur.top() -= 5;
	mystackTopOriginal.top() -= 5;

	std::cout << "Our mystack.top() is now " << mystackTopOur.top() << '\n';
	std::cout << "Original mystack.top() is now " << mystackTopOriginal.top() << '\n';

	if (mystackTopOur.top() == mystackTopOriginal.top())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		mistakes++;
	}

	return mistakes;
}

int main(){

	size_t result = test();

	std::cout << "\nMistakes=" << result << std::endl;
	std::cout << "Check leaks in another terminal" << std::endl;
	getchar();

	return 0;
}