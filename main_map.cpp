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
	size_t k = 0;
	std::cout << "ft:map<Key,T>: \n";
	for (typename ft::map<Key, T>::iterator it=tmp.begin(); it != tmp.end(); ++it)
	{
		std::cout << it->first << " | " << it->second << "\n";
		k++;
	}
	std::cout << " |" << std::endl;
}

template <typename Key, typename T>
void viewAllOriginal(std::map<Key, T> tmp)
{
	size_t k = 0;
	std::cout << "std::map<Key,T>: \n";
	for (typename std::map<Key, T>::iterator it=tmp.begin(); it != tmp.end(); ++it)
	{
		std::cout << it->first << " | " << it->second << "\n";
		k++;
	}
	std::cout << " |" << std::endl;
}

//class A {
//public:
//		A() : a(10) {}
//
//	A & operator=(int other) {a = other; return *this;}
//public:
//	int a;
//
//	};
//
//std::ostream& operator<< (std::ostream &out, const A &a)
//{
//	// Поскольку operator<< является другом класса Point, то мы имеем прямой доступ к членам Point
//	out << a.a;
//	return out;
//}


size_t test(){
	size_t mistakes = 0;
	size_t i = 1;

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test constructor map<char,int> ******************" << std::endl;

	ft::map<char,int> firstOur;
	std::map<char,int> firstOriginal;


//	std::cout << firstOur.begin()._data->first << std::endl;


//	std::map<char, A> f;
	firstOur['a'];
//	firstOur['b']=30;
//	firstOur['c']=50;
//	firstOur['d']=70;

//	f['a'];
//	f['b'] = 30;
//	viewAllOriginal(f);

//	firstOriginal['a'];
//	firstOriginal['b']=30;
//	firstOriginal['c']=50;
//	firstOriginal['d']=70;

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