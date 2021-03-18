#include <iostream>
#include <map>
#include "map.hpp"

bool fncomp (char lhs, char rhs) {
	return lhs<rhs;
}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

template <typename Key, typename T>
void viewAll(ft::map<Key, T> tmp)
{
	for (typename ft::map<Key, T>::iterator it=tmp.begin(); it != tmp.end(); ++it)
	{
		std::cout << (*it).first << " | " << (*it).second << std::endl;
	}
}

template <typename Key, typename T>
void viewAllOriginal(std::map<Key, T> tmp)
{
	std::cout << "std::map<Key,T>: \n";
	for (typename std::map<Key, T>::iterator it=tmp.begin(); it != tmp.end(); ++it){
		std::cout << (*it).first << " | " << (*it).second << "\n";
	}
}


size_t test(){
	size_t mistakes = 0;
	size_t i = 1;

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test constructor map<char,int> ******************" << std::endl;

	ft::map<char,int> firstOur;
//	std::map<char,int> firstOriginal;

//	firstOriginal['X'] = 30;
//	firstOriginal['c']=50;
//	firstOriginal['A']=70;
//	firstOriginal['b']=30;
//	firstOriginal['d']=70;


	firstOur['X'] = 30;

	firstOur['c']=50;

	firstOur['A']=70;
	firstOur['b']=30;

	firstOur['d']=70;
//	viewAllOriginal(firstOriginal);

	//viewAll(firstOur);

	ft::map<char, int>::iterator it=firstOur.begin();
	ft::map<char, int>::iterator ite=firstOur.end();
	while (it != ite){
		std::cout << (*it).first << " | " << (*it).second << std::endl;
		++it;
	}


//	for (typename ft::map<char, int>::iterator it=firstOur.begin(); it != firstOur.end(); ++it)
//	{
//		std::cout << it.getTreeNode() << std::endl;
//		std::cout << (*it).first << " | " << (*it).second << std::endl;
//	}

	//	viewAll(firstOur);
//	viewAllOriginal(firstOriginal);

//	std::map<char,int> secondOriginal (firstOriginal.begin(),firstOriginal.end());
//
//	std::map<char,int> thirdOriginal (secondOriginal);
//
//	std::map<char,int,classcomp> fourthOriginal;                 // class as Compare
//
//	bool(*fn_pt)(char,char) = fncomp;
//	std::map<char,int,bool(*)(char,char)> fifthOriginal (fn_pt);



	mistakes++;

	return mistakes;
}

int main(){

	size_t result = test();

	std::cout << "\nMistakes=" << result << std::endl;
	//std::cout << "\nCheck leaks in another terminal" << std::endl;
	//getchar();

	return 0;
}