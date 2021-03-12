//
// Created by Caeneus Garth on 3/11/21.
//

#include <iostream>
#include <vector>
#include "vector.hpp"

template <typename T>
void viewAll(ft::vector<T> tmp)
{
	size_t k = 0;
	std::cout << " ft::list<T>: ";
	for (typename ft::vector<T>::iterator it=tmp.begin(); it != tmp.end(); ++it)
	{
		std::cout << " | " << *it;
		k++;
	}
	std::cout << " |" << std::endl;
}

template <typename T>
void viewAllOriginal(std::vector<T> tmp)
{
	size_t k = 0;
	std::cout << "std::list<T>: ";
	for (typename std::vector<T>::iterator it=tmp.begin(); it != tmp.end(); ++it)
	{
		std::cout << " | " << *it;
		k++;
	}
	std::cout << " |" << std::endl;
}

int main(){
	size_t i = 1;
	size_t mistakes = 0;

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test begin/end vector<int> ******************" << std::endl;
	ft::vector<int> vectorOur;
	for (int i=1; i<=5; i++) vectorOur.push_back(i);
	std::vector<int> vectorOriginal;
	for (int i=1; i<=5; i++) vectorOriginal.push_back(i);

	viewAll(vectorOur);
	viewAllOriginal(vectorOriginal);
	std::cout << '\n';
	if (*vectorOur.begin() == *vectorOriginal.begin() && vectorOur.size() == vectorOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(vectorOriginal);
		std::cout << "received ";
		viewAll(vectorOur);

		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test resize vector<int> ******************" << std::endl;
	viewAll(vectorOur);
	viewAllOriginal(vectorOriginal);
	std::cout << "*Resize*" << std::endl;
	vectorOur.clear();
	vectorOur.resize(15,42);  // 5 default-constructed ints
	vectorOriginal.clear();
	vectorOriginal.resize(15,42);  // 5 default-constructed ints


	viewAll(vectorOur);
	viewAllOriginal(vectorOriginal);
	if (*vectorOur.begin() == *vectorOriginal.begin() && vectorOur.size() == vectorOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(vectorOriginal);
		std::cout << "received ";
		viewAll(vectorOur);

		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test rbegin/rend vector<int> ******************" << std::endl;
	vectorOur.clear();
	vectorOur.resize(5,0);  // 5 default-constructed ints
	vectorOriginal.clear();
	vectorOriginal.resize(5,0);  // 5 default-constructed ints

	i=0;

	ft::vector<int>::reverse_iterator rit = vectorOur.rbegin();
	for (; rit != vectorOur.rend(); ++rit)
		*rit = ++i;
	i = 0;
	std::vector<int>::reverse_iterator ritOriginal = vectorOriginal.rbegin();
	for (; ritOriginal!= vectorOriginal.rend(); ++ritOriginal)
		*ritOriginal = ++i;
	viewAll(vectorOur);
	viewAllOriginal(vectorOriginal);
	if (*vectorOur.begin() == *vectorOriginal.begin() && vectorOur.size() == vectorOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(vectorOriginal);
		std::cout << "received ";
		viewAll(vectorOur);

		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test size vector<int> ******************" << std::endl;
	vectorOur.clear();
	vectorOriginal.clear();
	std::cout << "0. size: " << vectorOur.size() << '\n';
	std::cout << "0. size: " << vectorOriginal.size() << '\n';
	if (vectorOur.size() == vectorOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(vectorOriginal);
		std::cout << "received ";
		viewAll(vectorOur);

		mistakes++;
	}

	for (int i=0; i<10; i++) vectorOur.push_back(i);
	std::cout << "1. size: " << vectorOur.size() << '\n';
	for (int i=0; i<10; i++) vectorOriginal.push_back(i);
	std::cout << "1. size: " << vectorOriginal.size() << '\n';
	if (vectorOur.size() == vectorOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(vectorOriginal);
		std::cout << "received ";
		viewAll(vectorOur);

		mistakes++;
	}

	vectorOur.insert (vectorOur.end(),10,100);
	std::cout << "2. size: " << vectorOur.size() << '\n';
	vectorOriginal.insert (vectorOriginal.end(),10,100);
	std::cout << "2. size: " << vectorOriginal.size() << '\n';
	if (vectorOur.size() == vectorOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(vectorOriginal);
		std::cout << "received ";
		viewAll(vectorOur);

		mistakes++;
	}
	vectorOur.pop_back();
	std::cout << "3. size: " << vectorOur.size() << '\n';
	vectorOriginal.pop_back();
	std::cout << "3. size: " << vectorOriginal.size() << '\n';
	if (vectorOur.size() == vectorOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(vectorOriginal);
		std::cout << "received ";
		viewAll(vectorOur);

		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test max_size/capacity vector<int> ******************" << std::endl;
	ft::vector<int> vectorCOur;
	std::vector<int> vectorCOriginal;

	// set some content in the vector:
	for (int i=0; i<100; i++) vectorCOur.push_back(i);
	std::cout << "vectorCOur size: " << vectorCOur.size() << "\n";
	std::cout << "vectorCOur capacity: " << vectorCOur.capacity() << "\n";
	std::cout << "vectorCOur max_size: " << vectorCOur.max_size() << "\n";

	for (int i=0; i<100; i++) vectorCOriginal.push_back(i);

	std::cout << "vectorCOriginal size: " << vectorCOriginal.size() << "\n";
	std::cout << "vectorCOriginal capacity: " << vectorCOriginal.capacity() << "\n";
	std::cout << "vectorCOriginal max_size: " << vectorCOriginal.max_size() << "\n";

	if (vectorCOur.size() == vectorCOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(vectorCOriginal);
		std::cout << "received ";
		viewAll(vectorCOur);

		mistakes++;
	}


	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test empty vector<int> ******************" << std::endl;
	vectorOur.clear();
	vectorOriginal.clear();
	int sum (0);
	int sumOriginal (0);

	for (int i=1;i<=10;i++) vectorOur.push_back(i);
	while (!vectorOur.empty())
	{
		sum += vectorOur.back();
		vectorOur.pop_back();
	}

	for (int i=1;i<=10;i++) vectorOriginal.push_back(i);
	while (!vectorOriginal.empty())
	{
		sumOriginal += vectorOriginal.back();
		vectorOriginal.pop_back();
	}
	std::cout << "total: " << sum << '\n';
	std::cout << "total: " << sumOriginal << '\n';

	if (sum == sumOriginal)
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(vectorOriginal);
		std::cout << "received ";
		viewAll(vectorOur);

		mistakes++;
	}


	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test reserve vector<int> ******************" << std::endl;

	size_t sz;
	std::vector<int>::size_type szOriginal;

	ft::vector<int> foo;
	std::vector<int> fooOriginal;
	szOriginal = fooOriginal.capacity();

	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		fooOriginal.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
		if (szOriginal!=fooOriginal.capacity()) {
			szOriginal = fooOriginal.capacity();
			std::cout << "capacity changed: " << szOriginal << '\n';

			if (sz == szOriginal)
				std::cout << "✅ OK" << std::endl;
			else
			{
				std::cout << "❌FALSE❌ : expected ";
				viewAllOriginal(fooOriginal);
				std::cout << "received ";
				viewAll(foo);

				mistakes++;
			}
		}
	}

	ft::vector<int> bar;
	std::vector<int> barOriginal;
	sz = bar.capacity();
	szOriginal = barOriginal.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	barOriginal.reserve(100);
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
		barOriginal.push_back(i);
		if (szOriginal!=barOriginal.capacity()) {
			szOriginal = barOriginal.capacity();
			std::cout << "capacity changed: " << szOriginal << '\n';
			if (sz == szOriginal)
				std::cout << "✅ OK" << std::endl;
			else
			{
				std::cout << "❌FALSE❌ : expected ";
				viewAllOriginal(barOriginal);
				std::cout << "received ";
				viewAll(bar);

				mistakes++;
			}
		}
	}


	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test [] vector<int> ******************" << std::endl;

	ft::vector<int> myvector (10);   // 10 zero-initialized elements
	std::vector<int> myvectorOriginal (10);   // 10 zero-initialized elements

	sz = myvector.size();
	szOriginal = myvectorOriginal.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;
	for (unsigned i=0; i<szOriginal; i++) myvectorOriginal[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i] = myvector[i];
		myvector[i] = temp;
	}

	for (unsigned i=0; i<szOriginal/2; i++)
	{
		int temp;
		temp = myvectorOriginal[szOriginal-1-i];
		myvectorOriginal[szOriginal-1-i]=myvectorOriginal[i];
		myvectorOriginal[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << " i:" << myvector[i];
	std::cout << '\n';
	std::cout << "Original contains:";
	for (unsigned i=0; i<szOriginal; i++)
		std::cout << " i:" << myvectorOriginal[i];
	std::cout << '\n';

	if (myvector[myvector.size() - 1] == myvectorOriginal[myvectorOriginal.size() - 1] && myvector[0] == myvectorOriginal[0])
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(myvectorOriginal);
		std::cout << "received ";
		viewAll(myvector);

		mistakes++;
	}

	std::cout << "\nMistakes=" << mistakes << std::endl;

	return 0;
}