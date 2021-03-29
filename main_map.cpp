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
	std::cout << "ft::map<Key,T>: \n";
	typename ft::map<Key, T>::iterator it=tmp.begin();
	typename ft::map<Key, T>::iterator ite=tmp.end();
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
	std::cout << "****************** Test constructor_1 map<char,int> ******************" << std::endl;

	ft::map<char,int> firstOur;
	std::map<char,int> firstOriginal;

	firstOur['a']=10;
	firstOur['b']=30;
	firstOur['c']=50;
	firstOur['d']=70;
	firstOriginal['a']=10;
	firstOriginal['b']=30;
	firstOriginal['c']=50;
	firstOriginal['d']=70;

	viewAll(firstOur);
	viewAllOriginal(firstOriginal);

	if (firstOur.begin()->first == firstOriginal.begin()->first && firstOur.size() == firstOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(firstOriginal);
		std::cout << "received ";
		viewAll(firstOur);

		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test constructor_2 map<char,int> ******************" << std::endl;
	ft::map<char,int> secondOur (firstOur.begin(),firstOur.end());
	std::map<char,int> secondOriginal (firstOriginal.begin(),firstOriginal.end());

	viewAll(secondOur);
	viewAllOriginal(secondOriginal);

	if (secondOur.begin()->first == secondOriginal.begin()->first && secondOur.size() == secondOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(secondOriginal);
		std::cout << "received ";
		viewAll(secondOur);

		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test constructor_3 map<char,int> ******************" << std::endl;
	ft::map<char,int> thirdOur (secondOur);
	std::map<char,int> thirdOriginal (secondOriginal);

	viewAll(thirdOur);
	viewAllOriginal(thirdOriginal);

	if (thirdOur.begin()->first == thirdOriginal.begin()->first && thirdOur.size() == thirdOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(thirdOriginal);
		std::cout << "received ";
		viewAll(thirdOur);

		mistakes++;
	}


	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test constructor_4 map<char,int> ******************" << std::endl;
	ft::map<char,int,classcomp> fourthOur;
	std::map<char,int,classcomp> fourthOriginal;                 // class as Compare

	fourthOur['A']=10;
	fourthOur['B']=30;
	fourthOur['C']=50;
	fourthOur['D']=70;
	fourthOur['a']=10;
	fourthOur['b']=30;
	fourthOur['c']=50;
	fourthOur['d']=70;
	fourthOriginal['A']=10;
	fourthOriginal['B']=30;
	fourthOriginal['C']=50;
	fourthOriginal['D']=70;
	fourthOriginal['a']=10;
	fourthOriginal['b']=30;
	fourthOriginal['c']=50;
	fourthOriginal['d']=70;

	fourthOur.viewTree();

	if (fourthOur.begin()->first == fourthOriginal.begin()->first && fourthOur.size() == fourthOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		//viewAllOriginal(thirdOriginal);
		std::cout << "received ";
		//viewAll(thirdOur);

		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test constructor_5 map<char,int> ******************" << std::endl;
	bool(*fn_pt)(char,char) = fncomp;
	ft::map<char,int,bool(*)(char,char)> fifthOur (fn_pt);
	std::map<char,int,bool(*)(char,char)> fifthOriginal (fn_pt);

	fifthOur['A']=10;
	fifthOur['B']=30;
	fifthOur['C']=50;
	fifthOur['D']=70;
	fifthOur['a']=10;
	fifthOur['b']=30;
	fifthOur['c']=50;
	fifthOur['d']=70;
	fifthOriginal['A']=10;
	fifthOriginal['B']=30;
	fifthOriginal['C']=50;
	fifthOriginal['D']=70;
	fifthOriginal['a']=10;
	fifthOriginal['b']=30;
	fifthOriginal['c']=50;
	fifthOriginal['d']=70;

	fifthOur.viewTree();

	if (fifthOur.begin()->first == fifthOriginal.begin()->first && fifthOur.size() == fifthOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		//viewAllOriginal(thirdOriginal);
		std::cout << "received ";
		//viewAll(thirdOur);

		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test operator = map<char,int> ******************" << std::endl;

	firstOur.clear();
	secondOur.clear();
	firstOriginal.clear();
	secondOriginal.clear();
	std::cout << "Size of first out: " << firstOur.size() << '\n';
	std::cout << "Size of second out: " << secondOur.size() << '\n';
	std::cout << "Size of first original: " << firstOriginal.size() << '\n';
	std::cout << "Size of second original: " << secondOriginal.size() << '\n';

	firstOur['x']=8;
	firstOur['y']=16;
	firstOur['z']=32;
	firstOriginal['x']=8;
	firstOriginal['y']=16;
	firstOriginal['z']=32;
	std::cout << "Do operator = " << std::endl;

	secondOur=firstOur;
	secondOriginal=firstOriginal;                // second now contains 3 ints
	firstOur=ft::map<char,int>();
	firstOriginal=std::map<char,int>();  // and first is now empty

	std::cout << "Size of first our: " << firstOur.size() << '\n';
	std::cout << "Size of second our: " << secondOur.size() << '\n';
	std::cout << "Size of first original: " << firstOriginal.size() << '\n';
	std::cout << "Size of second original: " << secondOriginal.size() << '\n';

	if (firstOur.size() == firstOriginal.size() && secondOur.size() == secondOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		//viewAllOriginal(thirdOriginal);
		std::cout << "received ";
		//viewAll(thirdOur);

		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test begin()/end() map<char,int> ******************" << std::endl;
	ft::map<char,int> mymapOur;
	std::map<char,int> mymapOriginal;

	mymapOur['b'] = 100;
	mymapOur['a'] = 200;
	mymapOur['c'] = 300;
	mymapOriginal['b'] = 100;
	mymapOriginal['a'] = 200;
	mymapOriginal['c'] = 300;

	// show content:
	for (ft::map<char,int>::iterator itOur=mymapOur.begin(); itOur!=mymapOur.end(); ++itOur)
		std::cout << itOur->first << " => " << itOur->second << '\n';
	for (std::map<char,int>::iterator it=mymapOriginal.begin(); it!=mymapOriginal.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	if (mymapOur.begin()->second == mymapOriginal.begin()->second)
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		//viewAllOriginal(thirdOriginal);
		std::cout << "received ";
		//viewAll(thirdOur);
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test rbegin()/rend() map<char,int> ******************" << std::endl;

	ft::map<char,int>::reverse_iterator ritOur;
	for (ritOur=mymapOur.rbegin(); ritOur!=mymapOur.rend(); ++ritOur)
		std::cout << ritOur->first << " => " << ritOur->second << '\n';
	// show content:
	std::map<char,int>::reverse_iterator rit;
	for (rit=mymapOriginal.rbegin(); rit!=mymapOriginal.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';

	if (mymapOur.rbegin()->second == mymapOriginal.rbegin()->second)
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		//viewAllOriginal(thirdOriginal);
		std::cout << "received ";
		//viewAll(thirdOur);
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test empty() map<char,int> ******************" << std::endl;
	mymapOur.clear();
	mymapOriginal.clear();
	mymapOur['a']=10;
	mymapOur['b']=20;
	mymapOur['c']=30;
	mymapOriginal['a']=10;
	mymapOriginal['b']=20;
	mymapOriginal['c']=30;

	while (!mymapOur.empty())
	{
		std::cout << mymapOur.begin()->first << " => " << mymapOur.begin()->second << '\n';
		mymapOur.erase(mymapOur.begin());
	}

	while (!mymapOriginal.empty())
	{
		std::cout << mymapOriginal.begin()->first << " => " << mymapOriginal.begin()->second << '\n';
		mymapOriginal.erase(mymapOriginal.begin());
	}
	if (mymapOur.size() == mymapOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(thirdOriginal);
		std::cout << "received ";
		viewAll(thirdOur);
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test size() map<char,int> ******************" << std::endl;
	mymapOur.clear();
	mymapOriginal.clear();
	mymapOur['a']=101;
	mymapOur['b']=202;
	mymapOur['c']=303;
	mymapOriginal['a']=101;
	mymapOriginal['b']=202;
	mymapOriginal['c']=303;

	std::cout << "mymapOur.size() is " << mymapOur.size() << '\n';
	std::cout << "mymapOriginal.size() is " << mymapOriginal.size() << '\n';
	if (mymapOur.size() == mymapOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(thirdOriginal);
		std::cout << "received ";
		viewAll(thirdOur);
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