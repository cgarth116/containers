//
// Created by Caeneus Garth on 3/11/21.
//

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

	std::cout << "Test " << i++ << std::endl;
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

	std::cout << "Test " << i++ << std::endl;
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

	std::cout << "Test " << i++ << std::endl;
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

	std::cout << "Test " << i++ << std::endl;
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

	std::cout << "Test " << i++ << std::endl;
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

	std::cout << "\nMistakes=" << mistakes << std::endl;

	return 0;
}