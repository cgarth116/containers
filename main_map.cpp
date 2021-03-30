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


	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test max_size() map<char,int> ******************" << std::endl;
	int i1;
	std::map<int,int> mymap;

	if (mymapOur.max_size()>1000){
		for (i1=0; i1<1000; i1++) mymapOur[i1]=0;
		std::cout << "The map contains 1000 elements.\n";
	} else {
		std::cout << "The map could not hold 1000 elements.\n";
	}

	if (mymapOriginal.max_size()>1000){
		for (i1=0; i1<1000; i1++) mymapOriginal[i1]=0;
		std::cout << "The map contains 1000 elements.\n";
	} else {
		std::cout << "The map could not hold 1000 elements.\n";
	}
	std::cout << "LOOK with my own eyes"<< std::endl;
	std::cout << "✅ OK" << std::endl;


	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test [] map<char,int> ******************" << std::endl;

	ft::map<char,std::string> mymapftOur;
	std::map<char,std::string> mymapftOriginal;

	mymapftOur['a']="an element";
	mymapftOur['b']="another element";
	mymapftOur['c']=mymapftOur['b'];
	mymapftOriginal['a']="an element";
	mymapftOriginal['b']="another element";
	mymapftOriginal['c']=mymapftOriginal['b'];

	std::cout << "mymapfOur['a'] is " << mymapftOur['a'] << '\n';
	std::cout << "mymapfOur['b'] is " << mymapftOur['b'] << '\n';
	std::cout << "mymapftOur['c'] is " << mymapftOur['c'] << '\n';
	std::cout << "mymapftOur['d'] is " << mymapftOur['d'] << '\n';

	std::cout << "mymapftOriginal['a'] is " << mymapftOriginal['a'] << '\n';
	std::cout << "mymapftOriginal['b'] is " << mymapftOriginal['b'] << '\n';
	std::cout << "mymapftOriginal['c'] is " << mymapftOriginal['c'] << '\n';
	std::cout << "mymapftOriginal['d'] is " << mymapftOriginal['d'] << '\n';

	std::cout << "mymapftOur now contains " << mymapftOur.size() << " elements.\n";
	std::cout << "mymapftOriginal now contains " << mymapftOriginal.size() << " elements.\n";

	if (mymapftOur.size() == mymapftOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(mymapftOriginal);
		std::cout << "received ";
		viewAll(mymapftOur);
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test insert(1) map<char,int> ******************" << std::endl;
	mymapOur.clear();
	mymapOriginal.clear();
	// first insert function version (single parameter):
	mymapOur.insert ( std::pair<char,int>('a',100) );
	mymapOur.insert ( std::pair<char,int>('z',200) );
	mymapOriginal.insert ( std::pair<char,int>('a',100) );
	mymapOriginal.insert ( std::pair<char,int>('z',200) );

	std::pair<ft::map<char,int>::iterator,bool> retOur;
	retOur = mymapOur.insert ( std::pair<char,int>('z',500) );
	if (retOur.second==false) {
		std::cout << "Our element 'z' already existed";
		std::cout << " with a value of " << retOur.first->second << '\n';
	}
	std::pair<std::map<char,int>::iterator,bool> retOriginal;
	retOriginal = mymapOriginal.insert ( std::pair<char,int>('z',500) );
	if (retOriginal.second==false) {
		std::cout << "Original element 'z' already existed";
		std::cout << " with a value of " << retOriginal.first->second << '\n';
	}

	if (mymapOur.begin()->first == mymapOriginal.begin()->first && mymapOur.size() == mymapOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(mymapOriginal);
		std::cout << "received ";
		viewAll(mymapOur);
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test insert(2) map<char,int> ******************" << std::endl;
	// second insert function version (with hint position):
	ft::map<char,int>::iterator itOur = mymapOur.begin();
	mymapOur.insert (itOur, std::pair<char,int>('b',300));  // max efficiency inserting
	mymapOur.insert (itOur, std::pair<char,int>('c',400));  // no max efficiency inserting
	std::map<char,int>::iterator itOriginal = mymapOriginal.begin();
	mymapOriginal.insert (itOriginal, std::pair<char,int>('b',300));  // max efficiency inserting
	mymapOriginal.insert (itOriginal, std::pair<char,int>('c',400));  // no max efficiency inserting

	// showing contents:
	std::cout << "Our mymap contains:\n";
	for (itOur=mymapOur.begin(); itOur!=mymapOur.end(); ++itOur)
		std::cout << itOur->first << " => " << itOur->second << '\n';
	std::cout << "Original mymap contains:\n";
	for (itOriginal=mymapOriginal.begin(); itOriginal!=mymapOriginal.end(); ++itOriginal)
		std::cout << itOriginal->first << " => " << itOriginal->second << '\n';

	if (mymapOur.begin()->first == mymapOriginal.begin()->first && mymapOur.size() == mymapOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(mymapOriginal);
		std::cout << "received ";
		viewAll(mymapOur);
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test insert(3) map<char,int> ******************" << std::endl;
	// third insert function version (range insertion):
	ft::map<char,int> anothermapOur;
	anothermapOur.insert(mymapOur.begin(),mymapOur.find('c'));
	std::map<char,int> anothermapOriginal;
	anothermapOriginal.insert(mymapOriginal.begin(),mymapOriginal.find('c'));

	// showing contents:

	std::cout << "Our anothermap contains:\n";
	for (itOur=anothermapOur.begin(); itOur!=anothermapOur.end(); ++itOur)
		std::cout << itOur->first << " => " << itOur->second << '\n';
	std::cout << "Original anothermap contains:\n";
	for (itOriginal=anothermapOriginal.begin(); itOriginal!=anothermapOriginal.end(); ++itOriginal)
		std::cout << itOriginal->first << " => " << itOriginal->second << '\n';

	if (anothermapOur.begin()->first == anothermapOriginal.begin()->first && anothermapOur.size() == anothermapOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(anothermapOriginal);
		std::cout << "received ";
		viewAll(anothermapOur);
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test erase(by iterator) map<char,int> ******************" << std::endl;
	mymapOur.clear();
	mymapOriginal.clear();

	// insert some values:
	mymapOur['a']=10;
	mymapOur['b']=20;
	mymapOur['c']=30;
	mymapOur['d']=40;
	mymapOur['e']=50;
	mymapOur['f']=60;
	mymapOriginal['a']=10;
	mymapOriginal['b']=20;
	mymapOriginal['c']=30;
	mymapOriginal['d']=40;
	mymapOriginal['e']=50;
	mymapOriginal['f']=60;

	itOur=mymapOur.find('b');
	mymapOur.erase (itOur);                   // erasing by iterator
	itOriginal=mymapOriginal.find('b');
	mymapOriginal.erase (itOriginal);                   // erasing by iterator

	if (mymapOur.begin()->first == mymapOriginal.begin()->first && mymapOur.size() == mymapOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(mymapOriginal);
		std::cout << "received ";
		viewAll(mymapOur);
		mistakes++;
	}


	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test erase(by key) map<char,int> ******************" << std::endl;
	mymapOur.viewTree();
	mymapOur.erase ('c');                  // erasing by key
	mymapOriginal.erase ('c');                  // erasing by key
	if (mymapOur.begin()->first == mymapOriginal.begin()->first && mymapOur.size() == mymapOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(mymapOriginal);
		std::cout << "received ";
		viewAll(mymapOur);
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test erase(by range) map<char,int> ******************" << std::endl;
	itOur=mymapOur.find ('e');
	mymapOur.erase ( itOur, mymapOur.end() );    // erasing by range
	itOriginal=mymapOriginal.find ('e');
	mymapOriginal.erase ( itOriginal, mymapOriginal.end() );    // erasing by range

	// show content:
	for (itOur=mymapOur.begin(); itOur!=mymapOur.end(); ++itOur)
		std::cout << "Our:" << itOur->first << " => " << itOur->second << '\n';
	for (itOriginal=mymapOriginal.begin(); itOriginal!=mymapOriginal.end(); ++itOriginal)
		std::cout << "Original:" << itOriginal->first << " => " << itOriginal->second << '\n';
	if (mymapOur.begin()->first == mymapOriginal.begin()->first && mymapOur.size() == mymapOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(mymapOriginal);
		std::cout << "received ";
		viewAll(mymapOur);
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test swap map<char,int> ******************" << std::endl;
	ft::map<char,int> fooOur,barOur;
	std::map<char,int> fooOriginal,barOriginal;

	fooOur['x']=100;
	fooOur['y']=200;

	barOur['a']=11;
	barOur['b']=22;
	barOur['c']=33;

	fooOriginal['x']=100;
	fooOriginal['y']=200;

	barOriginal['a']=11;
	barOriginal['b']=22;
	barOriginal['c']=33;

	fooOur.swap(barOur);
	fooOriginal.swap(barOriginal);

	std::cout << "Our foo contains:\n";
	for (ft::map<char,int>::iterator itOur=fooOur.begin(); itOur!=fooOur.end(); ++itOur)
		std::cout << itOur->first << " => " << itOur->second << '\n';
	std::cout << "Original foo contains:\n";
	for (std::map<char,int>::iterator itOriginal=fooOriginal.begin(); itOriginal!=fooOriginal.end(); ++itOriginal)
		std::cout << itOriginal->first << " => " << itOriginal->second << '\n';
	std::cout << "Our bar contains:\n";
	for (ft::map<char,int>::iterator itOur=barOur.begin(); itOur!=barOur.end(); ++itOur)
		std::cout << itOur->first << " => " << itOur->second << '\n';
	std::cout << "Original bar contains:\n";
	for (std::map<char,int>::iterator itOriginal=barOriginal.begin(); itOriginal!=barOriginal.end(); ++itOriginal)
		std::cout << itOriginal->first << " => " << itOriginal->second << '\n';
	if (fooOur.begin()->first == fooOriginal.begin()->first && fooOur.size() == fooOriginal.size() &&
			barOur.begin()->first == barOriginal.begin()->first && barOur.size() == barOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(fooOriginal);
		std::cout << "received ";
		viewAll(fooOur);
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test clear map<char,int> ******************" << std::endl;
	mymapOur.clear();
	mymapOriginal.clear();

	mymapOur['x']=100;
	mymapOur['y']=200;
	mymapOur['z']=300;
	mymapOriginal['x']=100;
	mymapOriginal['y']=200;
	mymapOriginal['z']=300;

	std::cout << "mymapOur contains:\n";
	for (ft::map<char,int>::iterator itOur=mymapOur.begin(); itOur!=mymapOur.end(); ++itOur)
		std::cout << itOur->first << " => " << itOur->second << '\n';
	std::cout << "mymapOriginl contains:\n";
	for (std::map<char,int>::iterator itOriginal=mymapOriginal.begin(); itOriginal!=mymapOriginal.end(); ++itOriginal)
		std::cout << itOriginal->first << " => " << itOriginal->second << '\n';

	mymapOur.clear();
	mymapOur['a']=1101;
	mymapOur['b']=2202;
	mymapOriginal.clear();
	mymapOriginal['a']=1101;
	mymapOriginal['b']=2202;

	std::cout << "mymapOur contains:\n";
	for (ft::map<char,int>::iterator itOur=mymapOur.begin(); itOur!=mymapOur.end(); ++itOur)
		std::cout << itOur->first << " => " << itOur->second << '\n';
	std::cout << "mymapOriginal contains:\n";
	for (std::map<char,int>::iterator itOriginal=mymapOriginal.begin(); itOriginal!=mymapOriginal.end(); ++itOriginal)
		std::cout << itOriginal->first << " => " << itOriginal->second << '\n';

	if (mymapOur.begin()->first == mymapOriginal.begin()->first && mymapOur.size() == mymapOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(mymapOriginal);
		std::cout << "received ";
		viewAll(mymapOur);
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test key_comp map<char,int> ******************" << std::endl;
	mymapOur.clear();
	mymapOriginal.clear();
	ft::map<char,int>::key_compare mycompOur = mymapOur.key_comp();
	std::map<char,int>::key_compare mycompOriginal = mymapOriginal.key_comp();
	mymapOur['a']=100;
	mymapOur['b']=200;
	mymapOur['c']=300;
	mymapOriginal['a']=100;
	mymapOriginal['b']=200;
	mymapOriginal['c']=300;

	std::cout << "mymapOur contains:\n";

	char highestOur = mymapOur.rbegin()->first;     // key value of last element

	itOur = mymapOur.begin();
	do {
		std::cout << itOur->first << " => " << itOur->second << '\n';
	} while ( mycompOur((*itOur++).first, highestOur) );

	std::cout << '\n';

	std::cout << "mymapOriginal contains:\n";

	char highestOriginal = mymapOriginal.rbegin()->first;     // key value of last element

	itOriginal = mymapOriginal.begin();
	do {
		std::cout << itOriginal->first << " => " << itOriginal->second << '\n';
	} while ( mycompOriginal((*itOriginal++).first, highestOriginal) );

	std::cout << '\n';

	std::cout << "✅ OK - Look eye's)))" << std::endl;

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test value_comp map<char,int> ******************" << std::endl;
	mymapOur.clear();
	mymapOriginal.clear();
	mymapOur['x']=1001;
	mymapOur['y']=2002;
	mymapOur['z']=3003;
	mymapOriginal['x']=1001;
	mymapOriginal['y']=2002;
	mymapOriginal['z']=3003;

	std::cout << "mymapOur contains:\n";

	std::pair<char,int> highestOur2 = *mymapOur.rbegin();          // last element

	itOur = mymapOur.begin();
	do {
		std::cout << itOur->first << " => " << itOur->second << '\n';
	} while ( mymapOur.value_comp()(*itOur++, highestOur2) );

	std::cout << "mymapOriginal contains:\n";

	std::pair<char,int> highestOriginal2 = *mymapOriginal.rbegin();          // last element

	itOriginal = mymapOriginal.begin();
	do {
		std::cout << itOriginal->first << " => " << itOriginal->second << '\n';
	} while ( mymap.value_comp()(*itOriginal++, highestOriginal2) );

	std::cout << "✅ OK - Look eye's)))" << std::endl;


	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test find map<char,int> ******************" << std::endl;
	mymapOur.clear();
	mymapOriginal.clear();
	mymapOur['a']=50;
	mymapOur['b']=100;
	mymapOur['c']=150;
	mymapOur['d']=200;
	mymapOriginal['a']=50;
	mymapOriginal['b']=100;
	mymapOriginal['c']=150;
	mymapOriginal['d']=200;

	itOur = mymapOur.find('b');
	if (itOur != mymapOur.end())
		mymapOur.erase (itOur);

	itOriginal = mymapOriginal.find('b');
	if (itOriginal != mymapOriginal.end())
		mymapOriginal.erase (itOriginal);

	// print content:
	std::cout << "elements in mymapOur:" << '\n';
	std::cout << "a => " << mymapOur.find('a')->second << '\n';
	std::cout << "c => " << mymapOur.find('c')->second << '\n';
	std::cout << "d => " << mymapOur.find('d')->second << '\n';

	std::cout << "elements in mymapOriginal:" << '\n';
	std::cout << "a => " << mymapOriginal.find('a')->second << '\n';
	std::cout << "c => " << mymapOriginal.find('c')->second << '\n';
	std::cout << "d => " << mymapOriginal.find('d')->second << '\n';

	if (mymapOur.begin()->first == mymapOriginal.begin()->first && mymapOur.size() == mymapOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(mymapOriginal);
		std::cout << "received ";
		viewAll(mymapOur);
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test count map<char,int> ******************" << std::endl;
	mymapOur.clear();
	mymapOriginal.clear();
	char c;
	mymapOur ['a']=101;
	mymapOur ['c']=202;
	mymapOur ['f']=303;
	mymapOriginal ['a']=101;
	mymapOriginal ['c']=202;
	mymapOriginal ['f']=303;
	for (c='a'; c<'h'; c++)
	{
		std::cout << c << ":" << std::endl;
		if (mymapOur.count(c)>0)
			std::cout << " is an element of mymapOur.\n";
		else
			std::cout << " is not an element of mymapOur.\n";
		if (mymapOriginal.count(c)>0)
			std::cout << " is an element of mymapOriginal.\n";
		else
			std::cout << " is not an element of mymapOriginal.\n";
		if (mymapOur.count(c) != mymapOriginal.count(c)){
			std::cout << "❌FALSE❌ : expected " << std::endl;
			mistakes++;
		} else {
			std::cout << "✅ OK - Look eye's)))" << std::endl;
		}
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test lower_bound/upper_bound map<char,int> ******************" << std::endl;
	mymapOur.clear();
	mymapOriginal.clear();
	ft::map<char,int>::iterator itlowOur,itupOur;
	std::map<char,int>::iterator itlowOriginal,itupOriginal;
	mymapOur['a']=20;
	mymapOur['b']=40;
	mymapOur['c']=60;
	mymapOur['d']=80;
	mymapOur['e']=100;

	mymapOriginal['a']=20;
	mymapOriginal['b']=40;
	mymapOriginal['c']=60;
	mymapOriginal['d']=80;
	mymapOriginal['e']=100;

	itlowOur=mymapOur.lower_bound ('b');  // itlow points to b
	itupOur=mymapOur.upper_bound ('d');   // itup points to e (not d!)
	mymapOur.erase(itlowOur,itupOur);        // erases [itlow,itup)

	itlowOriginal=mymapOriginal.lower_bound ('b');  // itlow points to b
	itupOriginal=mymapOriginal.upper_bound ('d');   // itup points to e (not d!)
	mymapOriginal.erase(itlowOriginal,itupOriginal);        // erases [itlow,itup)

	// print content:
	for (ft::map<char,int>::iterator itOur=mymapOur.begin(); itOur!=mymapOur.end(); ++itOur)
		std::cout << itOur->first << " => " << itOur->second << '\n';
	for (std::map<char,int>::iterator itOriginal=mymapOriginal.begin(); itOriginal!=mymapOriginal.end(); ++itOriginal)
			std::cout << itOriginal->first << " => " << itOriginal->second << '\n';

	if (mymapOur.begin()->first == mymapOriginal.begin()->first && mymapOur.size() == mymapOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(mymapOriginal);
		std::cout << "received ";
		viewAll(mymapOur);
		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test equal_range map<char,int> ******************" << std::endl;
	mymapOur.clear();
	mymapOriginal.clear();

	mymapOur['a']=10;
	mymapOur['b']=20;
	mymapOur['c']=30;

	mymapOriginal['a']=10;
	mymapOriginal['b']=20;
	mymapOriginal['c']=30;
	std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> retOur1;
	retOur1 = mymapOur.equal_range('b');
	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> retOriginal1;
	retOriginal1 = mymapOriginal.equal_range('b');

	std::cout << "Our lower bound points to: ";
	std::cout << retOur1.first->first << " => " << retOur1.first->second << '\n';
	std::cout << "Original lower bound points to: ";
	std::cout << retOriginal1.first->first << " => " << retOriginal1.first->second << '\n';

	std::cout << "Our upper bound points to: ";
	std::cout << retOur1.second->first << " => " << retOur1.second->second << '\n';
	std::cout << "Original upper bound points to: ";
	std::cout << retOriginal1.second->first << " => " << retOriginal1.second->second << '\n';

	if (retOur1.first->first == retOriginal1.first->first && retOur1.second->first == retOriginal1.second->first)
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected " << std::endl;
		viewAllOriginal(mymapOriginal);
		std::cout << "received ";
		viewAll(mymapOur);
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