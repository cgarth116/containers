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
	ft::map<char, int>::iterator it=tmp.begin();
	ft::map<char, int>::iterator ite=tmp.end();
	while (it != ite){
		std::cout << (*it).first << " | " << (*it).second << std::endl;
		++it;
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
	ft::map<char,int> firstOur2;
	std::map<char,int> firstOriginal;
	ft::map<std::map<int, float>,std::map<int, float> > firstOur1;
	std::map<std::map<int, float>,std::map<int, float> > firstOriginal1;

	std::cout << "our begin:" << firstOur.begin()->first << std::endl;
	std::cout << "our end:" << firstOur.end()->first << std::endl;
	std::cout << "original begin:" << firstOriginal.begin()->first << std::endl;
	std::cout << "original end:" << firstOriginal.end()->first << std::endl;

//	firstOriginal['X'] = 30;
//	firstOriginal['c']=50;
//	firstOriginal['A']=70;
//	firstOriginal['b']=30;
//	firstOriginal['d']=70;

	std::cout << "[]:" << firstOur['X'] << std::endl;
	std::cout << "[]:" << firstOur['X'] << std::endl;

	firstOur['X'] = 30;
	firstOriginal['X'] = 30;
	firstOur['c']=50;
	firstOriginal['c']=50;
	firstOur['A']=70;
	firstOriginal['A']=70;
	std::cout << "our begin:" << firstOur.begin()->first << std::endl;
	std::cout << "our end:" << firstOur.end()->first << std::endl;
	std::cout << "original begin:" << firstOriginal.begin()->first << std::endl;
	std::cout << "original end:" << firstOriginal.end()->first << std::endl;

//	firstOur['c']=50;
//	firstOur['A']=70;
//	firstOur['b']=30;
//
//	firstOur['d']=70;
//	viewAllOriginal(firstOriginal);

	//viewAll(firstOur);

	ft::map<char, int>::iterator it=firstOur.begin();
	ft::map<char, int>::iterator ite=firstOur.end();
	while (it != ite){
		std::cout << (*it).first << " | " << (*it).second << std::endl;
		++it;
	}

	std::cout << "Size :" << firstOur.size() << " | " << firstOriginal.size() << std::endl;

	std::cout << "MaxSize :\n" << firstOur.max_size() <<
						"\n" << firstOriginal.max_size() <<
						"\n" << firstOur1.max_size() <<
						"\n" << firstOriginal1.max_size()<<
						std::endl;


	viewAll(firstOur);

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