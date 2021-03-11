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

	std::cout << "\nMistakes=" << mistakes << std::endl;

	return 0;
}