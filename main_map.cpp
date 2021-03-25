#include <iostream>
#include <map>
#include "map.hpp"

bool fncomp (char lhs, char rhs) {
	return lhs<rhs;
}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const{
		return lhs<rhs;
	}
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

	firstOur['X'] = 30;
//	firstOur['c']=50;
	firstOur['A']=70;


//	firstOur['e']=770;
//	firstOur['f']=7560;
//	firstOur['g']=7450;
//	firstOur['y']=74650;
	firstOur['B']=74750;
	firstOur['C']=74750;
	firstOur['D']=74750;
	firstOur['I']=74750;
	firstOur['F']=74750;
//	firstOur['G']=74750;
//	firstOur['H']=74750;
//	firstOur['z']=74750;

	firstOur.viewTree();

	return mistakes;
}

int main(){

	size_t result = test();

	std::cout << "\nMistakes=" << result << std::endl;
	//std::cout << "\nCheck leaks in another terminal" << std::endl;
	//getchar();

	return 0;
}