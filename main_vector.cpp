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

size_t test(){
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
	std::cout << "****************** Test resize vector<int> ******************" << std::endl;
	viewAll(vectorOur);
	viewAllOriginal(vectorOriginal);
	std::cout << "*Resize*" << std::endl;
	vectorOur.clear();
	vectorOur.resize(3,-42);  // 5 default-constructed ints
	vectorOriginal.clear();
	vectorOriginal.resize(3,-42);  // 5 default-constructed ints


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
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	std::cout << "Original contains:";
	for (unsigned i=0; i<szOriginal; i++)
		std::cout << ' ' << myvectorOriginal[i];
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

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test at vector<int> ******************" << std::endl;
	myvector.clear();
	myvector.resize(10);
	myvectorOriginal.clear();
	myvectorOriginal.resize(10);
	// assign some values:
	for (unsigned i=0; i< myvector.size(); i++) {
		myvector.at(i) = i;
		myvectorOriginal.at(i) = i;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i< myvector.size(); i++) {
		std::cout << ' ' << myvector.at(i);
	}
	std::cout << "\nOriginal contains:";
	for (unsigned i=0; i< myvector.size(); i++) {
		std::cout << ' ' << myvectorOriginal.at(i);
	}
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

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test front vector<int> ******************" << std::endl;
	myvector.clear();
	myvectorOriginal.clear();

	myvector.push_back(78);
	myvector.push_back(16);
	myvectorOriginal.push_back(78);
	myvectorOriginal.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();
	myvectorOriginal.front() -= myvectorOriginal.back();
	std::cout << "myvector.front() is now " << myvector.front() << '\n';
	std::cout << "Original.front() is now " << myvectorOriginal.front() << '\n';
	if (myvector.front() == myvectorOriginal.front())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(myvectorOriginal);
		std::cout << "received ";
		viewAll(myvector);

		mistakes++;
	}
	std::cout << '\n';

	std::cout << "Test " << i++ << std::endl;
	std::cout << "****************** Test back vector<int> ******************" << std::endl;
	myvector.clear();
	myvectorOriginal.clear();

	myvector.push_back(10);
	myvectorOriginal.push_back(10);
	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}
	while (myvectorOriginal.back() != 0)
	{
		myvectorOriginal.push_back ( myvectorOriginal.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << "Original contains:";
	for (unsigned i=0; i<myvectorOriginal.size() ; i++)
		std::cout << ' ' << myvectorOriginal[i];
	std::cout << '\n';

	if (myvector.front() == myvectorOriginal.front() && myvector.back() == myvectorOriginal.back())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(myvectorOriginal);
		std::cout << "received ";
		viewAll(myvector);

		mistakes++;
	}
	std::cout << '\n';



	std::cout << "Test " << i++ << std::endl;
	std::cout << "****************** Test assign vector<int> ******************" << std::endl;
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;
	std::vector<int> firstOriginal;
	std::vector<int> secondOriginal;
	std::vector<int> thirdOriginal;

	first.assign (7,100);             // 7 ints with a value of 100
	firstOriginal.assign (7,100);             // 7 ints with a value of 100

	ft::vector<int>::iterator it;
	it=first.begin()+1;
	std::vector<int>::iterator itOriginal;
	itOriginal=firstOriginal.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first
	secondOriginal.assign (itOriginal,firstOriginal.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.
	int myintsOriginal[] = {1776,7,4};
	thirdOriginal.assign (myintsOriginal,myintsOriginal+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
	std::cout << "Size of firstOriginal: " << int (firstOriginal.size()) << '\n';
	std::cout << "Size of secondOriginal: " << int (secondOriginal.size()) << '\n';
	std::cout << "Size of thirdOriginal: " << int (thirdOriginal.size()) << '\n';

	if (int (first.size()) == int (firstOriginal.size()) &&
		int (second.size()) == int (secondOriginal.size()) &&
		int (third.size()) == int (thirdOriginal.size()))
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		mistakes++;
	}
	std::cout << '\n';

	std::cout << "Test " << i++ << std::endl;
	std::cout << "****************** Test pop_back vector<int> ******************" << std::endl;

	myvector.clear();
	myvectorOriginal.clear();
	sum =0;
	sumOriginal = 0;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	myvectorOriginal.push_back (100);
	myvectorOriginal.push_back (200);
	myvectorOriginal.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}
	while (!myvectorOriginal.empty())
	{
		sumOriginal+=myvectorOriginal.back();
		myvectorOriginal.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';
	std::cout << "The elements of Original add up to " << sumOriginal << '\n';

	if (sum == sumOriginal)
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		mistakes++;
	}
	std::cout << '\n';


	std::cout << "Test " << i++ << std::endl;
	std::cout << "****************** Test insert vector<int> ******************" << std::endl;
	myvector.clear();
	myvector.resize(3, 100);
	myvectorOriginal.clear();
	myvectorOriginal.resize(3, 100);

	it = myvector.begin();
	it = myvector.insert ( it , 200 );
	itOriginal = myvectorOriginal.begin();
	itOriginal = myvectorOriginal.insert ( itOriginal , 200 );

	myvector.insert (it,2,300);
	myvectorOriginal.insert (itOriginal,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();
	itOriginal = myvectorOriginal.begin();
	std::vector<int> anothervector (2,400);
	std::vector<int> anothervectorOriginal (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());
	myvectorOriginal.insert (itOriginal+2,anothervectorOriginal.begin(),anothervectorOriginal.end());
	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);
	int myarrayOriginal [] = { 501,502,503 };
	myvectorOriginal.insert (myvectorOriginal.begin(), myarrayOriginal, myarrayOriginal+3);


	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "Original contains:";
	for (itOriginal=myvectorOriginal.begin(); itOriginal<myvectorOriginal.end(); itOriginal++)
		std::cout << ' ' << *itOriginal;
	std::cout << '\n';
	if (myvector.front() == myvectorOriginal.front() && myvector.back() == myvectorOriginal.back())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(myvectorOriginal);
		std::cout << "received ";
		viewAll(myvector);

		mistakes++;
	}
	std::cout << '\n';

	std::cout << "Test " << i++ << std::endl;
	std::cout << "****************** Test erase vector<int> ******************" << std::endl;
	myvector.clear();
	myvectorOriginal.clear();

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);
	for (int i=1; i<=10; i++) myvectorOriginal.push_back(i);

	// erase the 6th element
	myvector.erase (myvector.begin()+5);
	myvectorOriginal.erase (myvectorOriginal.begin()+5);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);
	myvectorOriginal.erase (myvectorOriginal.begin(),myvectorOriginal.begin()+3);
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	std::cout << "Original contains:";
	for (unsigned i=0; i<myvectorOriginal.size(); ++i)
		std::cout << ' ' << myvectorOriginal[i];

	std::cout << '\n';
	if (myvector.front() == myvectorOriginal.front() && myvector.back() == myvectorOriginal.back())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(myvectorOriginal);
		std::cout << "received ";
		viewAll(myvector);

		mistakes++;
	}
	std::cout << '\n';

	std::cout << "Test " << i++ << std::endl;
	std::cout << "****************** Test swap vector<int> ******************" << std::endl;
	foo.clear();
	foo.resize(3, 100);
	fooOriginal.clear();
	fooOriginal.resize(3, 100);
	bar.clear();
	bar.resize(5, 200);
	barOriginal.clear();
	barOriginal.resize(5, 200);
	viewAll(foo);
	viewAllOriginal(fooOriginal);
	viewAll(bar);
	viewAllOriginal(barOriginal);
	std::cout << "SWAP\n";
	foo.swap(bar);
	fooOriginal.swap(barOriginal);

	viewAll(foo);
	viewAllOriginal(fooOriginal);
	viewAll(bar);
	viewAllOriginal(barOriginal);

	if (bar.front() == barOriginal.front() && foo.front() == fooOriginal.front())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(fooOriginal);
		viewAllOriginal(barOriginal);
		std::cout << "received ";
		viewAll(foo);
		viewAll(bar);

		mistakes++;
	}
	std::cout << '\n';


	std::cout << "Test " << i++ << std::endl;
	std::cout << "****************** Test swap vector<int> ******************" << std::endl;
	myvector.clear();
	myvectorOriginal.clear();
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	myvectorOriginal.push_back (100);
	myvectorOriginal.push_back (200);
	myvectorOriginal.push_back (300);
	viewAll(myvector);
	viewAllOriginal(myvectorOriginal);
	std::cout << "Clear\n";
	myvector.clear();
	myvectorOriginal.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);
	myvectorOriginal.push_back (1101);
	myvectorOriginal.push_back (2202);

	viewAll(myvector);
	viewAllOriginal(myvectorOriginal);
	if (myvector.front() == myvectorOriginal.front() && myvector.front() == myvectorOriginal.front())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(myvectorOriginal);
		std::cout << "received ";
		viewAll(myvector);

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