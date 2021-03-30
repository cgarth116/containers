#include <iostream>
#include <queue>
#include <deque>
#include <list>
#include "queue.hpp"

size_t test(){
	size_t mistakes = 0;
	size_t i = 1;

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test constructor queue<char,int> ******************" << std::endl;
	ft::list<int> mylistOur (2,200);         // list with 2 elements
	std::list<int> mylist (2,200);         // list with 2 elements

	ft::queue<int> firstOur;                 // empty queue
	std::queue<int> first;                 // empty queue

	ft::queue<int,ft::list<int> > thirdOur; // empty queue with list as underlying container
	ft::queue<int,ft::list<int> > fourthOur (mylistOur);
	std::queue<int,std::list<int> > third; // empty queue with list as underlying container
	std::queue<int,std::list<int> > fourth (mylist);

	std::cout << "size of firstOur: " << firstOur.size() << '\n';
	std::cout << "size of thirdOur: " << thirdOur.size() << '\n';
	std::cout << "size of fourthOur: " << fourthOur.size() << '\n';
	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';

	if (firstOur.size() == first.size() && thirdOur.size() == third.size() && fourthOur.size() == fourth.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test empty queue<char,int> ******************" << std::endl;
	ft::queue<int> myqueueOur;
	std::queue<int> myqueue;
	int sumOur = 0;
	for (int i=1;i<=10;i++) myqueueOur.push(i);
	for (int i=1;i<=10;i++) myqueue.push(i);

	while (!myqueueOur.empty())
	{
		sumOur += myqueueOur.front();
		myqueueOur.pop();
	}
	std::cout << "total: " << sumOur << '\n';
	int sum = 0;
	while (!myqueue.empty())
	{
		sum += myqueue.front();
		myqueue.pop();
	}

	std::cout << "total: " << sum << '\n';
	if (sumOur == sum)
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test size queue<char,int> ******************" << std::endl;
	std::queue<int> myintsOur;
	std::queue<int> myints;
	std::cout << "0. sizeOur: " << myintsOur.size() << '\n';
	std::cout << "0. size: " << myints.size() << '\n';
	if (myintsOur.size() == myints.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		mistakes++;
	}

	for (int i=0; i<5; i++){
		myintsOur.push(i);
		myints.push(i);
	}
	std::cout << "1. sizeOur: " << myintsOur.size() << '\n';
	std::cout << "1. size: " << myints.size() << '\n';
	if (myintsOur.size() == myints.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		mistakes++;
	}

	myintsOur.pop();
	std::cout << "2. sizeOur: " << myintsOur.size() << '\n';
	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';

	if (myintsOur.size() == myints.size())
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
	//std::cout << "\nCheck leaks in another terminal" << std::endl;
	//getchar();

	return 0;
}