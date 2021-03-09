#include <list>
#include <vector>
#include "list.hpp"
#include <cmath>

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

// a predicate implemented as a function:
bool shot_string (const std::string& value) { return (value.size() <= 3); }

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

bool mycomparison (double first, double second){
	return ( int(first)<int(second) );
}

bool compare_int(const int& x, const int& y) {return x < y;}

// a binary predicate implemented as a function:
bool same_integral_part (int first, int second)
{ return ( first==second + 1 ); }

// a binary predicate implemented as a function:
bool stringPlus (std::string first, std::string second)
{ return ( first.size() == second.size() + 1 ); }

// a binary predicate implemented as a function:
bool same_integral_part2 (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second) < 5.0); }
};


template <typename T>
void viewAll(ft::list<T> tmp)
{
    size_t k = 0;
    std::cout << " ft::list<T>: ";
    for (typename ft::list<T>::iterator it=tmp.begin(); it != tmp.end(); ++it)
    {
        std::cout << " | " << *it;
        k++;
    }
    std::cout << " |" << std::endl;
}

template <typename T>
void viewAllOriginal(std::list<T> tmp)
{
    size_t k = 0;
    std::cout << "std::list<T>: ";
    for (typename std::list<T>::iterator it=tmp.begin(); it != tmp.end(); ++it)
    {
        std::cout << " | " << *it;
        k++;
    }
    std::cout << " |" << std::endl;
}

int main()
{
    size_t i = 1;
    size_t k = 0;
    size_t mistakes = 0;
    int value = 0;
    std::string valueStr = "";

    ft::list<int> A;
    std::list<int> AOrigin;
    ft::list<std::string> B;
    std::list<std::string> BOrigin;
    
    std::cout << "Test " << i++ << std::endl;
    std::cout << "****************** Test list(itb,ite) list<int> ******************" << std::endl;
    ft::list<int> first;                                // empty list of ints
    ft::list<int> second (4,100);                       // four ints with value 100
    ft::list<int> third (second.begin(),second.end());

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    ft::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    std::cout << "The contents of fifth are: ";
    for (ft::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
      std::cout << *it << ' ';

    std::cout << '\n';
    if (fifth.size() == 4)
        std::cout << "✅ OK\n" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected 4" << ", received ft::list.size()=" << fifth.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test size Zero list<int> ******************" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.size() == AOrigin.size())
        std::cout << "✅ OK\n ft::size()=" << A.size() << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << AOrigin.size() << ", received ft::list.size()=" << A.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test size Zero list<std::string> ******************" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.size() == BOrigin.size())
        std::cout << "✅ OK\n ft::size()=" << B.size() << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << BOrigin.size() << ", received ft::list.size()=" << B.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test list(list) Zero list<int> ******************" << std::endl;
    ft::list<int> A17(A);
    std::list<int> A17Origin(AOrigin);
    viewAll(A17);
    viewAllOriginal(A17Origin);

    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A17.size() == AOrigin.size())
        std::cout << "✅ OK\n" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << AOrigin.size() << ", received ft::list.size()=" << A17.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test list(list) Zero list<std::string> ******************" << std::endl;
    ft::list<std::string> B17(B);
    std::list<std::string> B17Origin(BOrigin);
    viewAll(B17);
    viewAllOriginal(B17Origin);

    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B17.size() == BOrigin.size())
        std::cout << "✅ OK\n" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << BOrigin.size() << ", received ft::list.size()=" << B17.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test list(n,val) Zero list<int> ******************" << std::endl;
    ft::list<int> A1(10, 42);
    std::list<int> A1Origin(10,42);
    viewAll(A1);
    viewAllOriginal(A1Origin);

    if (A1.size() == A1Origin.size())
        std::cout << "✅ OK\n" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << A1Origin.size() << ", received ft::list.size()=" << A1.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test list(n,val) Zero list<std::list> ******************" << std::endl;
    ft::list<std::string> B1(10, "42lol");
    std::list<std::string> B1Origin(10,"42lol");
    viewAll(B1);
    viewAllOriginal(B1Origin);

    if (B1.size() == B1Origin.size())
        std::cout << "✅ OK\n" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << B1Origin.size() << ", received ft::list.size()=" << B1.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test list(list) non zero list<int> ******************" << std::endl;
    ft::list<int> A177(A1);
    std::list<int> A177Origin(A1Origin);
    viewAll(A177);
    viewAllOriginal(A177Origin);

    viewAll(A1);
    viewAllOriginal(A1Origin);
    if (A177.size() == A1Origin.size())
        std::cout << "✅ OK\n" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << A1Origin.size() << ", received ft::list.size()=" << A177.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test list(list) non zero list<std::string> ******************" << std::endl;
    ft::list<std::string> B177(B1);
    std::list<std::string> B177Origin(B1Origin);
    viewAll(B177);
    viewAllOriginal(B177Origin);

    viewAll(B1);
    viewAllOriginal(B1Origin);
    if (B177.size() == B1Origin.size())
        std::cout << "✅ OK\n" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << B1Origin.size() << ", received ft::list.size()=" << B177.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    value = 99;
    std::cout << "****************** Test push_back " << value << " / 1 element list<int> ******************" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    A.push_back(value);
    AOrigin.push_back(value);
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.size() == AOrigin.size())
        std::cout << "✅ OK\n ft::size()=" << A.size() << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << AOrigin.size() << ", received ft::list.size()=" << A.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    value = 42;
    std::cout << "****************** Test push_front " << value << " / 1 element list<int> ******************" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    A.push_front(value);
    AOrigin.push_front(value);
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.size() == AOrigin.size())
        std::cout << "✅ OK\n ft::size()=" << A.size() << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << AOrigin.size() << ", received ft::list.size()=" << A.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    value = 20;
    std::cout << "****************** Test push_front " << value << " / 2 element list<int> ******************" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    A.push_front(value);
    AOrigin.push_front(value);
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.size() == AOrigin.size())
        std::cout << "✅ OK\n ft::size()=" << A.size() << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << AOrigin.size() << ", received ft::list.size()=" << A.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    value = 30;
    std::cout << "****************** Test push_front " << value << " / 3 element list<int> ******************" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    A.push_front(value);
    AOrigin.push_front(value);
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.size() == AOrigin.size())
        std::cout << "✅ OK\n ft::size()=" << A.size() << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << AOrigin.size() << ", received ft::list.size()=" << A.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    value = 77;
    std::cout << "****************** Test push_back " << value << " / 4 element list<int> ******************" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    A.push_back(value);
    AOrigin.push_back(value);
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.size() == AOrigin.size())
        std::cout << "✅ OK\n ft::size()=" << A.size() << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << AOrigin.size() << ", received ft::list.size()=" << A.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    valueStr = "Hello word";
    std::cout << "****************** Test push_front " << valueStr << " / 1 element list<std::string> ******************" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    B.push_front(valueStr);
    BOrigin.push_front(valueStr);
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.size() == BOrigin.size())
        std::cout << "✅ OK\n ft::list.size()=" << B.size() << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << BOrigin.size() << ", received ft::list.size()=" << B.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    valueStr = "Friend";
    std::cout << "****************** Test push_back " << valueStr << " / 2 element list<std::string> ******************" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    B.push_back(valueStr);
    BOrigin.push_back(valueStr);
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.size() == BOrigin.size())
        std::cout << "✅ OK\n ft::list.size()=" << B.size() << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << BOrigin.size() << ", received ft::list.size()=" << B.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    valueStr = "Another 321 Another";
    std::cout << "****************** Test push_back " << valueStr << " / 3 element list<std::string> ******************" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    B.push_back(valueStr);
    BOrigin.push_back(valueStr);
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.size() == BOrigin.size())
        std::cout << "✅ OK\n ft::list.size()=" << B.size() << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected std::list.size()=" << BOrigin.size() << ", received ft::list.size()=" << B.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test iterator list<int> ******************" << std::endl;
    std::cout << " ft::list<int>: ";
    for (ft::list<int>::iterator it=A.begin(); it != A.end(); ++it)
    {
        std::cout << ' ' << *it;
        k++;
    }
    std::cout << "\nstd::list<int>: ";
    for (std::list<int>::iterator itOriginal=AOrigin.begin(); itOriginal != AOrigin.end(); ++itOriginal)
      std::cout << ' ' << *itOriginal;
    std::cout << std::endl;
    if (k == A.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << A.size() << ", received " << k << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test iterator < begin list<int> ******************" << std::endl;
    ft::list<int>::iterator it1=A.begin();
    std::list<int>::iterator it3=AOrigin.begin();
    std::cout << " ft::list<int>: ";
    ++it1;
      std::cout << *it1;
    --it1;
      std::cout << ' ' << *it1;
    --it1;
      std::cout << ' ' << *it1;
    ++it1;
      std::cout << ' ' << *it1 << std::endl;
    std::cout << "std::list<int>: ";
    ++it3;
    std::cout << *it3;
    --it3;
    std::cout << ' ' << *it3;
    --it3;
    std::cout << ' ' << *it3 ;
    ++it3;
    std::cout << ' ' << *it3 << std::endl;
    if (it1 == A.begin())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << *A.begin() << ", received " << *it1 << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test iterator > end list<int> ******************" << std::endl;
    ft::list<int>::iterator it2=A.end();
    std::list<int>::iterator it4=AOrigin.end();
    std::cout << " ft::list<int>: ";
    --it2;
      std::cout << *it2;
    ++it2;
      std::cout << ' ' << *it2;
    ++it2;
      std::cout << ' ' << *it2;
    --it2;
        std::cout << ' ' << *it2 << std::endl;
    std::cout << "std::list<int>: ";
    --it4;
    std::cout << *it4;
    ++it4;
    std::cout << ' ' << *it4;
    ++it4;
    std::cout << ' ' << *it4 ;
    --it4;
    std::cout << ' ' << *it4 << std::endl;
    if (it2 == A.end())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << *A.end() << ", received " << *it2 << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test reverse_iterator list<int> ******************" << std::endl;
    std::cout << " ft::list<int>: ";
    k = 0;
    for (ft::list<int>::reverse_iterator it=A.rbegin(); it != A.rend(); ++it)
    {
        std::cout << ' ' << *it;
        k++;
    }
    std::cout << "\nstd::list<int>: ";
    for (std::list<int>::reverse_iterator itOriginal=AOrigin.rbegin(); itOriginal != AOrigin.rend(); ++itOriginal)
      std::cout << ' ' << *itOriginal;
    std::cout << std::endl;
    if (k == A.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << A.size() << ", received " << k << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test reverse_iterator < begin list<int> ******************" << std::endl;
    ft::list<int>::reverse_iterator it5=A.rbegin();
    std::list<int>::reverse_iterator it6 = AOrigin.rbegin();
    std::cout << " ft::list<int>: ";
    ++it5;
    std::cout << *it5;
    --it5;
    std::cout << ' ' << *it5;
    --it5;
    std::cout << ' ' << *it5;
    ++it5;
    std::cout << ' ' << *it5 << std::endl;
    std::cout << "std::list<int>: ";
    ++it6;
    std::cout << *it6;
    --it6;
    std::cout << ' ' << *it6;
    --it6;
    std::cout << ' ' << *it6 ;
    ++it6;
    std::cout << ' ' << *it6 << std::endl;
    if (it5 == A.rbegin())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << *(A.rbegin()) << ", received " << *it5 << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test reverse_iterator > end list<int> ******************" << std::endl;
    ft::list<int>::reverse_iterator it7=A.rend();
    std::list<int>::reverse_iterator it9 = AOrigin.rend();
    std::cout << " ft::list<int>: ";
    --it7;
    std::cout << *it7;
    ++it7;
    std::cout << ' ' << *it7;
    ++it7;
    std::cout << ' ' << *it7;
    --it7;
    std::cout << ' ' << *it7 << std::endl;
    std::cout << "std::list<int>: ";
    --it9;
    std::cout << *it9;
    ++it9;
    std::cout << ' ' << *it9;
    ++it9;
    std::cout << ' ' << *it9;
    --it9;
    std::cout << ' ' << *it9 << std::endl;
    if (it7 == A.rend())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << *(A.rend()) << ", received " << *it7 << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test empty list<int> ******************" << std::endl;
    ft::list<int> AEmpty;
    std::list<int> AEmptyOrigin;
    std::cout << " ft::list<int>: " << AEmpty.empty() << std::endl;
    std::cout << "std::list<int>: " << AEmptyOrigin.empty() << std::endl;
    if (AEmpty.empty() == AEmptyOrigin.empty())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << AEmptyOrigin.empty() << ", received " << AEmpty.empty() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test not empty list<int> ******************" << std::endl;
    std::cout << " ft::list<int>: " << A.empty() << std::endl;
    std::cout << "std::list<int>: " << AOrigin.empty() << std::endl;
    if (A.empty() == AOrigin.empty())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << AOrigin.empty() << ", received " << A.empty() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test empty list<std::string> ******************" << std::endl;
    ft::list<std::string> BEmpty;
    std::list<std::string> BEmptyOrigin;
    std::cout << " ft::list<std::string>: " << BEmpty.empty() << std::endl;
    std::cout << "std::list<std::string>: " << BEmptyOrigin.empty() << std::endl;
    if (BEmpty.empty() == BEmptyOrigin.empty())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << BEmptyOrigin.empty() << ", received " << BEmpty.empty() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test not empty list<std::string> ******************" << std::endl;
    std::cout << " ft::list<std::string>: " << B.empty() << std::endl;
    std::cout << "std::list<std::string>: " << BOrigin.empty() << std::endl;
    if (B.empty() == BOrigin.empty())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << BOrigin.empty() << ", received " << B.empty() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test max_size list<int> ******************" << std::endl;

    std::cout << " ft::list<int>: " << A.max_size() << std::endl;
    std::cout << "std::list<int>: " << AOrigin.max_size() << std::endl;
    if (A.max_size() == AOrigin.max_size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << AOrigin.max_size() << ", received " << A.max_size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test max_size list<std::string> ******************" << std::endl;

    std::cout << " ft::list<std::string>: " << B.max_size() << std::endl;
    std::cout << "std::list<std::string>: " << BOrigin.max_size() << std::endl;
    if (B.max_size() == BOrigin.max_size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << BOrigin.max_size() << ", received " << B.max_size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test front empty list<int> ******************" << std::endl;

    std::cout << " ft::list<int>: " << AEmpty.front() << std::endl;
    std::cout << "std::list<int>: " << AEmptyOrigin.front() << std::endl;
    if (AEmpty.front() == AEmptyOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << AEmptyOrigin.front() << ", received " << AEmpty.front() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test front not empty list<int> ******************" << std::endl;

    std::cout << " ft::list<int>: " << A.front() << std::endl;
    std::cout << "std::list<int>: " << AOrigin.front() << std::endl;
    if (A.front() == AOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << AOrigin.front() << ", received " << A.front() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test back not empty list<int> ******************" << std::endl;

    std::cout << " ft::list<int>: " << A.back() << std::endl;
    std::cout << "std::list<int>: " << AOrigin.back() << std::endl;
    if (A.back() == AOrigin.back())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << AOrigin.back() << ", received " << A.back() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test front empty list<std::string> ******************" << std::endl;

    std::cout << " ft::list<std::string>: " << BEmpty.front() << std::endl;
    std::cout << "std::list<std::string>: " << BEmptyOrigin.front() << std::endl;
    if (BEmpty.front() == BEmptyOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << BEmptyOrigin.front() << ", received " << BEmpty.front() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test front not empty list<std::string> ******************" << std::endl;

    std::cout << " ft::list<std::string>: " << B.front() << std::endl;
    std::cout << "std::list<std::string>: " << BOrigin.front() << std::endl;
    if (B.front() == BOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << BOrigin.front() << ", received " << B.front() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test back not empty list<std::string> ******************" << std::endl;

    std::cout << " ft::list<std::string>: " << B.back() << std::endl;
    std::cout << "std::list<std::string>: " << BOrigin.back() << std::endl;
    if (B.back() == BOrigin.back())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << BOrigin.back() << ", received " << B.back() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test pop_front not empty list<int> ******************" << std::endl;
    A.pop_front();
    AOrigin.pop_front();
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.size() == AOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << AOrigin.size() << ", received " << A.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test pop_front not empty list<std::string> ******************" << std::endl;
    ft::list<std::string>::iterator it999 = B.begin();
    std::list<std::string>::iterator it99 = BOrigin.begin();
    std::cout << *it999 << std::endl;
    std::cout << *it99 << std::endl;
    B.pop_front();
    BOrigin.pop_front();
    std::cout << *(++it999) << std::endl;
    std::cout << *(++it99) << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.size() == BOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << BOrigin.size() << ", received " << B.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test pop_front empty list<int> ******************" << std::endl;
    AEmpty.pop_front();
    //AEmptyOrigin.pop_front(); //Original get segfault
    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    if (AEmpty.size() == AEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << AEmptyOrigin.size() << ", received " << AEmpty.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test pop_front empty list<std::string> ******************" << std::endl;
    BEmpty.pop_front();
    //BEmptyOrigin.pop_front(); //Original get segfault
    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    if (BEmpty.size() == BEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << BEmptyOrigin.size() << ", received " << BEmpty.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test pop_back not empty list<int> ******************" << std::endl;
    A.pop_back();
    AOrigin.pop_back();
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.size() == AOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << AOrigin.size() << ", received " << A.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test pop_back not empty list<std::string> ******************" << std::endl;
    it999 = B.end();
    it99 = BOrigin.end();
    std::cout << *(--it999) << std::endl;
    std::cout << *(--it99) << std::endl;
    B.pop_back();
    BOrigin.pop_back();
    std::cout << *(--it999) << std::endl;
    std::cout << *(--it99) << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.size() == BOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << BOrigin.size() << ", received " << B.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test pop_back empty list<int> ******************" << std::endl;
    AEmpty.pop_back();
    //AEmptyOrigin.pop_back(); //Original get segfault
    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    if (AEmpty.size() == AEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << AEmptyOrigin.size() << ", received " << AEmpty.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test erace(it) not empty list<std::string> ******************" << std::endl;
    B.push_front("New life");
    BOrigin.push_front("New life");
    it999 = B.begin();
    it99 = BOrigin.begin();
    std::cout << *(B.erase(it999)) << std::endl;
    std::cout << *(BOrigin.erase(it99)) << std::endl; //segfault if it99=end
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.size() == BOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << BOrigin.size() << ", received " << B.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test erace(it) empty list<std::string> ******************" << std::endl;
    it999 = BEmpty.begin();
    it99 = BEmptyOrigin.begin();
    std::cout << *(BEmpty.erase(it999)) << std::endl;
    //std::cout << *(BEmptyOrigin.erase(it99)) << std::endl; //Original get segfault
    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    if (BEmpty.size() == BEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << BEmptyOrigin.size() << ", received " << BEmpty.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test erace(it) not empty list<int> ******************" << std::endl;
    ft::list<int>::iterator it999A = A.begin();
    std::list<int>::iterator it99A = AOrigin.begin();
    A.push_front(123);
    AOrigin.push_front(123);
    it999A = A.begin();
    it99A = AOrigin.begin();
    std::cout << *(A.erase(it999A)) << std::endl;
    std::cout << *(AOrigin.erase(it99A)) << std::endl; //segfault if it99=end
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.size() == AOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << AOrigin.size() << ", received " << A.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test erace(it) empty list<int> ******************" << std::endl;
    it999A = AEmpty.begin();
    it99A = AEmptyOrigin.begin();
    std::cout << *(AEmpty.erase(it999A)) << std::endl;
    //std::cout << *(BEmptyOrigin.erase(it99)) << std::endl; //Original get segfault
    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    if (AEmpty.size() == AEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << AEmptyOrigin.size() << ", received " << AEmpty.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test erace(it1,it2) not empty it1/it2 good list<int> ******************" << std::endl;
    A.push_front(123);
    AOrigin.push_front(123);
    viewAll(A);
    viewAllOriginal(AOrigin);
    it999A = A.begin();
    it99A = AOrigin.begin();
    std::cout << *(A.erase(it999A,++++it999A)) << std::endl;
    std::cout << *(AOrigin.erase(it99A,++++it99A)) << std::endl; //segfault if it99=end
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.size() == AOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << AOrigin.size() << ", received " << A.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test erace(it1,it2) not empty it1 good/ it2 bad list<int> ******************" << std::endl;
    int sizeTest;
    ft::list<int> AWrong;
    std::list<int> AOriginalWrong;
    viewAll(A);
    it999A = A.begin();
    sizeTest = A.size();
    ft::list<int>::iterator it999AE = A.end();
    ++it999A;
    std::cout << *(A.erase(it999A,AWrong.end())) << std::endl;
    //std::cout << *(AOrigin.erase(it99A,AOriginalWrong.end())) << std::endl; //Original get segfault
    viewAll(A);
    if (A.size() == sizeTest - 1)
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << sizeTest - 1 << ", received " << A.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test erace(it1,it2) not empty it1 bad/ it2 good list<int> ******************" << std::endl;
    viewAll(A);
    sizeTest = A.size();
    it999AE = A.end();
    std::cout << *(A.erase(AWrong.end(),it999AE)) << std::endl;
    //std::cout << *(AOrigin.erase(it99A,AOriginalWrong.end())) << std::endl; //Original get segfault
    viewAll(A);
    if (A.size() == sizeTest)
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << sizeTest - 1 << ", received " << A.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test erace(it1,it2) not empty it1/it2 good list<std::string> ******************" << std::endl;
    B.push_front("new test");
    BOrigin.push_front("new test");
    viewAll(B);
    viewAllOriginal(BOrigin);
    it999 = B.begin();
    it99 = BOrigin.begin();
    std::cout << *(B.erase(it999,++++it999)) << std::endl;
    std::cout << *(BOrigin.erase(it99,++++it99)) << std::endl; //segfault if it99=end
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.size() == BOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << BOrigin.size() << ", received " << B.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test erace(it1,it2) not empty it1 good/ it2 bad list<std::string> ******************" << std::endl;
    B.push_front("new test");
    BOrigin.push_front("new test");
    ft::list<std::string> BWrong;
    std::list<std::string> BOriginalWrong;
    viewAll(B);
    it999 = B.begin();
    it99 = BOrigin.begin();
    sizeTest = B.size();
    ft::list<std::string>::iterator it999BE = B.end();
    ++it999;
    std::cout << *(B.erase(it999,BWrong.end())) << std::endl;
    //std::cout << *(BOrigin.erase(it99,BOriginalWrong.end())) << std::endl; //Original get segfault
    viewAll(B);
    if (B.size() == sizeTest)
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << sizeTest - 1 << ", received " << B.size() << std::endl;
        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test erace(it1,it2) not empty it1 bad/ it2 good list<std::string> ******************" << std::endl;
    viewAll(B);
    //viewAllOriginal(BOrigin);
    sizeTest = B.size();
    it999BE = B.end();
    std::cout << *(B.erase(BWrong.end(),it999BE)) << std::endl;
    //std::cout << *(BOrigin.begin(),BOrigin.begin()) << std::endl; //Original get segfault
    viewAll(B);
    //viewAllOriginal(BOrigin);
    if (B.size() == sizeTest)
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << sizeTest - 1 << ", received " << B.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test clear not empty list<std::string> ******************" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    
    B.clear();
    BOrigin.clear();
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.size() == 0)
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected 0, received " << B.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test clear empty list<std::string> ******************" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    
    B.clear();
    BOrigin.clear();
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.size() == 0)
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected 0, received " << B.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test erace(it1,it2) not empty it==it2 good list<std::string> ******************" << std::endl;
    B.push_front("new test");
    B.push_front("qwerty");
    B.push_front("йцукен");
    BOrigin.push_front("new test");
    BOrigin.push_front("qwerty");
    BOrigin.push_front("йцукен");
    viewAll(B);
    viewAllOriginal(BOrigin);
    sizeTest = B.size();
    std::cout << *(B.erase(B.begin(),B.begin())) << std::endl;
    std::cout << *(BOrigin.erase(BOrigin.begin(),BOrigin.begin())) << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.size() == sizeTest)
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected " << sizeTest - 1 << ", received " << B.size() << std::endl;
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test swap not empty list<std::string> ******************" << std::endl;
    ft::list<std::string> B2;
    std::list<std::string> BOrigin2;
    B.push_front("это просто");
    B.push_front("ооооо");
    B.push_front("ой");
    B2.push_front("это сложно");
    B2.push_front("яяяяя");
    B2.push_front("ай");
    B2.push_front("ай1");
    B2.push_front("ай2");
    BOrigin.push_front("это просто");
    BOrigin.push_front("ооооо");
    BOrigin.push_front("ой");
    BOrigin2.push_front("это сложно");
    BOrigin2.push_front("яяяяя");
    BOrigin2.push_front("ай");
    BOrigin2.push_front("ай1");
    BOrigin2.push_front("ай2");
    viewAll(B);
    viewAll(B2);
    viewAllOriginal(BOrigin);
    viewAllOriginal(BOrigin2);
    
    B.swap(B2);
    BOrigin.swap(BOrigin2);
    std::cout << "*Swap*" << std::endl;
    viewAll(B);
    viewAll(B2);
    viewAllOriginal(BOrigin);
    viewAllOriginal(BOrigin2);
    if (B.front() == BOrigin.front() && B2.front() == BOrigin2.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test swap empty list<std::string> ******************" << std::endl;
    B.pop_front();
    B.pop_front();
    B.pop_front();
    B.pop_front();
    B.pop_front();
    B.pop_front();
    B.pop_front();
    B2.pop_front();
    B2.pop_front();
    B2.pop_front();
    B2.pop_front();
    B2.pop_front();
    B2.pop_front();
    B2.pop_front();
    BOrigin.pop_front();
    BOrigin.pop_front();
    BOrigin.pop_front();
    BOrigin.pop_front();
    BOrigin.pop_front();
    BOrigin2.pop_front();
    BOrigin2.pop_front();
    BOrigin2.pop_front();
    BOrigin2.pop_front();
    BOrigin2.pop_front();
    BOrigin2.pop_front();
    viewAll(B);
    viewAll(B2);
    viewAllOriginal(BOrigin);
    viewAllOriginal(BOrigin2);
    
    B.swap(B2);
    BOrigin.swap(BOrigin2);
    std::cout << "*Swap*" << std::endl;
    viewAll(B);
    viewAll(B2);
    viewAllOriginal(BOrigin);
    viewAllOriginal(BOrigin2);
    if (B.back() == B2.back())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test swap empty list<int> ******************" << std::endl;
    ft::list<int> A2;
    std::list<int> AOrigin2;
    A.pop_front();
    viewAll(A);
    viewAll(A2);
    AOrigin.pop_front();
    AOrigin.pop_front();
    viewAllOriginal(AOrigin);
    viewAllOriginal(AOrigin2);
    
    A.swap(A2);
    AOrigin.swap(AOrigin2);
    std::cout << "*Swap*" << std::endl;
    viewAll(A);
    viewAll(A2);
    viewAllOriginal(AOrigin);
    viewAllOriginal(AOrigin2);
    if (A.back() == A2.back())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAll(A2);
        std::cout << "received ";
        viewAll(A);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test swap empty and not list<int> ******************" << std::endl;
    A.pop_front();
    viewAll(A);
    A2.push_front(44);
    viewAll(A2);
    viewAllOriginal(AOrigin);
    AOrigin2.push_front(44);
    viewAllOriginal(AOrigin2);
    
    A.swap(A2);
    AOrigin.swap(AOrigin2);
    std::cout << "*Swap*" << std::endl;
    viewAll(A);
    viewAll(A2);
    viewAllOriginal(AOrigin);
    viewAllOriginal(AOrigin2);
    if (A.back() == AOrigin.back())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test swap not empty list<int> ******************" << std::endl;
    A.push_front(23);
    A.push_front(34);
    A.push_front(45);
    A2.push_front(67);
    A2.push_front(98);
    A2.push_front(87);
    A2.push_front(76);
    A2.push_front(21);
    AOrigin.push_front(23);
    AOrigin.push_front(34);
    AOrigin.push_front(45);
    AOrigin2.push_front(67);
    AOrigin2.push_front(98);
    AOrigin2.push_front(87);
    AOrigin2.push_front(76);
    AOrigin2.push_front(21);
    viewAll(A);
    viewAll(A2);
    viewAllOriginal(AOrigin);
    viewAllOriginal(AOrigin2);
    
    A.swap(A2);
    AOrigin.swap(AOrigin2);
    std::cout << "*Swap*" << std::endl;
    viewAll(A);
    viewAll(A2);
    viewAllOriginal(AOrigin);
    viewAllOriginal(AOrigin2);
    if (A.front() == AOrigin.front() && A2.front() == AOrigin2.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test resize not empty n > size value=666 list<int> ******************" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    
    A.resize(10, 666);
    AOrigin.resize(10,666);
    std::cout << "*Resize*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.back() == AOrigin.back() && A.size() == AOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test resize not empty n = size value=666 list<int> ******************" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    
    A.resize(10, 666);
    AOrigin.resize(10,666);
    std::cout << "*Resize*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.back() == AOrigin.back() && A.size() == AOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test resize not empty n < size value=666 list<int> ******************" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    
    A.resize(4, 666);
    AOrigin.resize(4,666);
    std::cout << "*Resize*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.back() == AOrigin.back() && A.size() == AOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test resize not empty n > size value "" list<int> ******************" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    
    A.resize(10);
    AOrigin.resize(10);
    std::cout << "*Resize*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.back() == AOrigin.back() && A.size() == AOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test resize empty n > size value=42 list<int> ******************" << std::endl;
    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    
    AEmpty.resize(10,42);
    AEmptyOrigin.resize(10,42);
    std::cout << "*Resize*" << std::endl;
    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    if (AEmpty.back() == AEmptyOrigin.back() && AEmpty.size() == AEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AEmptyOrigin);
        std::cout << "received ";
        viewAll(AEmpty);
        
        mistakes++;
    }
    AEmpty.clear();
    AEmptyOrigin.clear();
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test resize not empty n > size value=\"ooouuuu foooo\" list<std::string> ******************" << std::endl;
    B.push_front("new test");
    BOrigin.push_front("new test");
    viewAll(B);
    viewAllOriginal(BOrigin);
    
    B.resize(10, "ooouuuu foooo");
    BOrigin.resize(10,"ooouuuu foooo");
    std::cout << "*Resize*" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.back() == BOrigin.back() && B.size() == BOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test resize not empty n = size value=\"ooouuuu foooo\" list<std::string> ******************" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    
    B.resize(10, "ooouuuu foooo");
    BOrigin.resize(10,"ooouuuu foooo");
    std::cout << "*Resize*" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.back() == BOrigin.back() && B.size() == BOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test resize not empty n < size value=\"ooouuuu foooo\" list<std::string> ******************" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    
    B.resize(4, "ooouuuu foooo");
    BOrigin.resize(4,"ooouuuu foooo");
    std::cout << "*Resize*" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.back() == BOrigin.back() && B.size() == BOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test resize not empty n > size value= list<std::string> ******************" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    
    B.resize(10);
    BOrigin.resize(10);
    std::cout << "*Resize*" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.back() == BOrigin.back() && B.size() == BOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test resize empty n > size value=\"42old\" list<std::string> ******************" << std::endl;
    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    
    BEmpty.resize(10,"42old");
    BEmptyOrigin.resize(10,"42old");
    std::cout << "*Resize*" << std::endl;
    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    if (BEmpty.back() == BEmptyOrigin.back() && BEmpty.size() == BEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BEmptyOrigin);
        std::cout << "received ";
        viewAll(BEmpty);
        
        mistakes++;
    }
    AEmpty.clear();
    AEmptyOrigin.clear();
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test remove 34 not empty list have 34 list<int> ******************" << std::endl;
    A.push_front(23);
    A.push_front(34);
    A.push_front(45);
    A.push_front(23);
    A.push_front(34);
    A.push_front(45);
    A.push_front(23);
    A.push_front(34);
    A.push_front(45);
    AOrigin.push_front(23);
    AOrigin.push_front(34);
    AOrigin.push_front(45);
    AOrigin.push_front(23);
    AOrigin.push_front(34);
    AOrigin.push_front(45);
    AOrigin.push_front(23);
    AOrigin.push_front(34);
    AOrigin.push_front(45);

    viewAll(A);
    viewAllOriginal(AOrigin);
    
    A.remove(34);
    AOrigin.remove(34);
    std::cout << "*Remove*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.front() == AOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test remove 34 not empty list not have 34 list<int> ******************" << std::endl;

    viewAll(A);
    viewAllOriginal(AOrigin);
    
    A.remove(34);
    AOrigin.remove(34);
    std::cout << "*Remove*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.front() == AOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test remove 34 empty list<int> ******************" << std::endl;

    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    
    AEmpty.remove(34);
    AEmptyOrigin.remove(34);
    std::cout << "*Remove*" << std::endl;
    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    if (AEmpty.front() == AEmptyOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AEmptyOrigin);
        std::cout << "received ";
        viewAll(AEmpty);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test remove 34 not empty list have 34 list<std::string> ******************" << std::endl;
    B.push_front("23");
    B.push_front("34");
    B.push_front("45");
    B.push_front("23");
    B.push_front("34");
    B.push_front("45");
    B.push_front("23");
    B.push_front("34");
    B.push_front("45");
    BOrigin.push_front("23");
    BOrigin.push_front("34");
    BOrigin.push_front("45");
    BOrigin.push_front("23");
    BOrigin.push_front("34");
    BOrigin.push_front("45");
    BOrigin.push_front("23");
    BOrigin.push_front("34");
    BOrigin.push_front("45");

    viewAll(B);
    viewAllOriginal(BOrigin);
    
    B.remove("34");
    BOrigin.remove("34");
    std::cout << "*Remove*" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.front() == BOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test remove 34 not empty list not have 34 list<std::string> ******************" << std::endl;

    viewAll(B);
    viewAllOriginal(BOrigin);
    
    B.remove("34");
    BOrigin.remove("34");
    std::cout << "*Remove*" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.front() == BOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test remove 34 empty list<std::string> ******************" << std::endl;
    BEmpty.clear();
    BEmptyOrigin.clear();
    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    
    BEmpty.remove("34");
    BEmptyOrigin.remove("34");
    std::cout << "*Remove*" << std::endl;
    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    if (BEmpty.size() == BEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BEmptyOrigin);
        std::cout << "received ";
        viewAll(BEmpty);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test remove_if single_digit not empty list<int> ******************" << std::endl;
    A.push_front(2);
    A.push_front(3400);
    A.push_front(400);
    A.push_front(230);
    A.push_front(3);
    A.push_front(450);
    A.push_front(23);
    A.push_front(34);
    A.push_front(4);
    AOrigin.push_front(2);
    AOrigin.push_front(3400);
    AOrigin.push_front(400);
    AOrigin.push_front(230);
    AOrigin.push_front(3);
    AOrigin.push_front(450);
    AOrigin.push_front(23);
    AOrigin.push_front(34);
    AOrigin.push_front(4);

    viewAll(A);
    viewAllOriginal(AOrigin);
    
    A.remove_if(single_digit);
    AOrigin.remove_if(single_digit);
    std::cout << "*Remove*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.front() == AOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test remove _if single_digit && is_odd() not empty list not have single_digit list<int> ******************" << std::endl;

    viewAll(A);
    viewAllOriginal(AOrigin);
    
    A.remove_if(single_digit);
    A.remove_if(is_odd());
    AOrigin.remove_if(single_digit);
    AOrigin.remove_if(is_odd());
    std::cout << "*Remove*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.front() == AOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test remove single_digit empty list<int> ******************" << std::endl;

    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    
    AEmpty.remove_if(single_digit);
    AEmptyOrigin.remove_if(single_digit);
    std::cout << "*Remove*" << std::endl;
    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    if (AEmpty.front() == AEmptyOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AEmptyOrigin);
        std::cout << "received ";
        viewAll(AEmpty);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test remove shot_string(<=3) not empty list have 34 list<std::string> ******************" << std::endl;
    B.push_front("23");
    B.push_front("347777");
    B.push_front("454");
    B.push_front("23");
    B.push_front("3477");
    B.push_front("45");
    B.push_front("236");
    B.push_front("347777777");
    B.push_front("45");
    BOrigin.push_front("23");
    BOrigin.push_front("347777");
    BOrigin.push_front("454");
    BOrigin.push_front("23");
    BOrigin.push_front("3477");
    BOrigin.push_front("45");
    BOrigin.push_front("236");
    BOrigin.push_front("347777777");
    BOrigin.push_front("45");

    viewAll(B);
    viewAllOriginal(BOrigin);
    
    B.remove_if(shot_string);
    BOrigin.remove_if(shot_string);
    std::cout << "*Remove*" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.front() == BOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test remove shot_string(<=3) not empty list not have shot_string list<std::string> ******************" << std::endl;

    viewAll(B);
    viewAllOriginal(BOrigin);
    
    B.remove_if(shot_string);
    BOrigin.remove_if(shot_string);
    std::cout << "*Remove*" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.front() == BOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test remove shot_string(<=3) empty list<std::string> ******************" << std::endl;
    BEmpty.clear();
    BEmptyOrigin.clear();
    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    
    BEmpty.remove_if(shot_string);
    BEmptyOrigin.remove_if(shot_string);
    std::cout << "*Remove*" << std::endl;
    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    if (BEmpty.size() == BEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BEmptyOrigin);
        std::cout << "received ";
        viewAll(BEmpty);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test sort not empty list<int> ******************" << std::endl;

    viewAll(A);
    viewAllOriginal(AOrigin);

    A.sort();
    AOrigin.sort();
    std::cout << "*Sort*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.front() == AOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);

        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test sort empty list<int> ******************" << std::endl;

    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);

    AEmpty.sort();
    AEmptyOrigin.sort();
    std::cout << "*Sort*" << std::endl;
    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    if (AEmpty.front() == AEmptyOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AEmptyOrigin);
        std::cout << "received ";
        viewAll(AEmpty);

        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test sort not empty list<std::string> ******************" << std::endl;

    viewAll(B);
    viewAllOriginal(BOrigin);

    B.sort();
    BOrigin.sort();
    std::cout << "*Sort*" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.front() == BOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);

        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test sort empty list<std::string> ******************" << std::endl;

    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);

    BEmpty.sort();
    BEmptyOrigin.sort();
    std::cout << "*Sort*" << std::endl;
    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    if (BEmpty.size() == BEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BEmptyOrigin);
        std::cout << "received ";
        viewAll(BEmpty);

        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test sort2 not empty list<int> ******************" << std::endl;

    A.push_front(2);
    A.push_front(3400);
    A.push_front(400);
    A.push_front(230);
    A.push_front(3);
    A.push_front(450);
    A.push_front(23);
    A.push_front(34);
    A.push_front(4);
    AOrigin.push_front(2);
    AOrigin.push_front(3400);
    AOrigin.push_front(400);
    AOrigin.push_front(230);
    AOrigin.push_front(3);
    AOrigin.push_front(450);
    AOrigin.push_front(23);
    AOrigin.push_front(34);
    AOrigin.push_front(4);
    viewAll(A);
    viewAllOriginal(AOrigin);

    A.sort(compare_int);
    AOrigin.sort(compare_int);
    std::cout << "*Sort*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.front() == AOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);

        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test sort2 empty list<int> ******************" << std::endl;

    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);

    AEmpty.sort(compare_int);
    AEmptyOrigin.sort(compare_int);
    std::cout << "*Sort*" << std::endl;
    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    if (AEmpty.front() == AEmptyOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AEmptyOrigin);
        std::cout << "received ";
        viewAll(AEmpty);

        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test sort2 not empty list<std::string> ******************" << std::endl;

    B.push_front("Hello");
    B.push_front("hello");
    B.push_front("qwerty");
    B.push_front("ZxZcZ");
    B.push_front("lkjhg");
    BOrigin.push_front("Hello");
    BOrigin.push_front("hello");
    BOrigin.push_front("qwerty");
    BOrigin.push_front("ZxZcZ");
    BOrigin.push_front("lkjhg");

    viewAll(B);
    viewAllOriginal(BOrigin);

    B.sort(compare_nocase);
    BOrigin.sort(compare_nocase);
    std::cout << "*Sort*" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.front() == BOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);

        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test sort2 empty list<std::string> ******************" << std::endl;

    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);

    BEmpty.sort(compare_nocase);
    BEmptyOrigin.sort(compare_nocase);
    std::cout << "*Sort*" << std::endl;
    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    if (BEmpty.size() == BEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BEmptyOrigin);
        std::cout << "received ";
        viewAll(BEmpty);

        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test reverse not empty list<int> ******************" << std::endl;

    A.push_back(42);
    AOrigin.push_back(42);
    viewAll(A);
    viewAllOriginal(AOrigin);

    ft::list<int>::iterator itRev;
    std::list<int>::iterator itRevOrigin;
    itRev = A.begin();
    itRevOrigin = AOrigin.begin();
    ++itRev;
    ++itRevOrigin;

    A.reverse();
    AOrigin.reverse();
    ++itRev;
    ++itRevOrigin;
    std::cout << "*reverse*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);

    if (A.front() == AOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        std::cout << AOrigin.front() << std::endl;
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        std::cout << A.front() << std::endl;
        viewAll(A);

        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test reverse empty list<int> ******************" << std::endl;

    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);

    AEmpty.reverse();
    AEmptyOrigin.reverse();
    std::cout << "*reverse*" << std::endl;
    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    if (AEmpty.front() == AEmptyOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AEmptyOrigin);
        std::cout << "received ";
        viewAll(AEmpty);

        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test reverse not empty list<std::string> ******************" << std::endl;

    B.push_front("Hello");
    B.push_front("hello");
    B.push_front("qwerty");
    B.push_front("ZxZcZ");
    B.push_front("lkjhg");
    BOrigin.push_front("Hello");
    BOrigin.push_front("hello");
    BOrigin.push_front("qwerty");
    BOrigin.push_front("ZxZcZ");
    BOrigin.push_front("lkjhg");

    viewAll(B);
    viewAllOriginal(BOrigin);

    B.reverse();
    BOrigin.reverse();
    std::cout << "*reverse*" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.front() == BOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);

        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test reverse empty list<std::string> ******************" << std::endl;

    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);

    BEmpty.reverse();
    BEmptyOrigin.reverse();
    std::cout << "*reverse*" << std::endl;
    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    if (BEmpty.size() == BEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BEmptyOrigin);
        std::cout << "received ";
        viewAll(BEmpty);

        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test unique not empty list<int> ******************" << std::endl;

    viewAll(A);
    viewAllOriginal(AOrigin);
    
    A.unique();
    AOrigin.unique();
    std::cout << "*unique*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.front() == AOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test unique empty list<int> ******************" << std::endl;

    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    
    AEmpty.unique();
    AEmptyOrigin.unique();
    std::cout << "*unique*" << std::endl;
    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    if (AEmpty.front() == AEmptyOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AEmptyOrigin);
        std::cout << "received ";
        viewAll(AEmpty);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test unique not empty list<std::string> ******************" << std::endl;

    B.push_front("Hello");
    B.push_front("hello");
    B.push_front("Hello");
    B.push_front("Hello");
    B.push_front("lkjhg");
    BOrigin.push_front("Hello");
    BOrigin.push_front("hello");
    BOrigin.push_front("Hello");
    BOrigin.push_front("Hello");
    BOrigin.push_front("lkjhg");
    
    viewAll(B);
    viewAllOriginal(BOrigin);
    
    B.unique();
    BOrigin.unique();
    std::cout << "*unique*" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.front() == BOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test unique empty list<std::string> ******************" << std::endl;

    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    
    BEmpty.unique();
    BEmptyOrigin.unique();
    std::cout << "*unique*" << std::endl;
    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    if (BEmpty.size() == BEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BEmptyOrigin);
        std::cout << "received ";
        viewAll(BEmpty);
        
        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test uniq list<std::int> ******************" << std::endl;
    double mydoubles[] = { 2.72,  3.14, 12.15, 12.77, 12.77, 15.3,  72.25, 72.25, 73.0,  73.35 };
    std::list<double> std_list (mydoubles,mydoubles + 10);
    ft::list<double> ft_list (mydoubles, mydoubles + 10);

    viewAll(ft_list);
    viewAllOriginal(std_list);

    std::cout << "uniq:\n";

    std_list.unique (is_near());
    ft_list.unique (is_near());

    viewAll(ft_list);
    viewAllOriginal(std_list);

    if (ft_list.back() == std_list.back())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(std_list);
        std::cout << "received ";
        viewAll(ft_list);

        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test unique BinaryPredicate not empty list<int> ******************" << std::endl;

    viewAll(A);
    viewAllOriginal(AOrigin);
    
    A.unique(same_integral_part);
    AOrigin.unique(same_integral_part);
    std::cout << "*unique BinaryPredicate*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.back() == AOrigin.back() && A.size() == AOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test unique BinaryPredicate empty list<int> ******************" << std::endl;

    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    
    AEmpty.unique(same_integral_part);
    AEmptyOrigin.unique(same_integral_part);
    std::cout << "*unique BinaryPredicate*" << std::endl;
    viewAll(AEmpty);
    viewAllOriginal(AEmptyOrigin);
    if (AEmpty.front() == AEmptyOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AEmptyOrigin);
        std::cout << "received ";
        viewAll(AEmpty);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test unique BinaryPredicate not empty list<std::string> ******************" << std::endl;

    B.push_front("Hello");
    B.push_front("hello");
    B.push_front("Hello1");
    B.push_front("Hello2");
    B.push_front("lkjhg3");
    BOrigin.push_front("Hello");
    BOrigin.push_front("hello");
    BOrigin.push_front("Hello1");
    BOrigin.push_front("Hello2");
    BOrigin.push_front("lkjhg3");
    
    viewAll(B);
    viewAllOriginal(BOrigin);
    
    B.unique(stringPlus);
    BOrigin.unique(stringPlus);
    std::cout << "*unique BinaryPredicate*" << std::endl;
    viewAll(B);
    viewAllOriginal(BOrigin);
    if (B.front() == BOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BOrigin);
        std::cout << "received ";
        viewAll(B);
        
        mistakes++;
    }
    
    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test unique BinaryPredicate empty list<std::string> ******************" << std::endl;

    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    
    BEmpty.unique(stringPlus);
    BEmptyOrigin.unique(stringPlus);
    std::cout << "*unique BinaryPredicate*" << std::endl;
    viewAll(BEmpty);
    viewAllOriginal(BEmptyOrigin);
    if (BEmpty.size() == BEmptyOrigin.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(BEmptyOrigin);
        std::cout << "received ";
        viewAll(BEmpty);
        
        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test assign list<std::int> ******************" << std::endl;

    ft::list<int> firstAs;
    ft::list<int> secondAs;
    std::list<int> firstAsOriginal;
    std::list<int> secondAsOriginal;

    firstAs.assign (7,100);                      // 7 ints with value 100
    firstAsOriginal.assign (7,100);
    secondAs.assign (firstAs.begin(),firstAs.end()); // a copy of first
    secondAsOriginal.assign (firstAs.begin(),firstAs.end());
    int myintsAs[]={1776,7,4};
    firstAs.assign (myintsAs,myintsAs+3);            // assigning from array
    firstAsOriginal.assign (myintsAs,myintsAs+3);
    viewAll(firstAs);
    viewAllOriginal(firstAsOriginal);

    if (firstAs.size() == firstAsOriginal.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(firstAsOriginal);
        std::cout << "received ";
        viewAll(BEmpty);

        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test insert list<std::int> ******************" << std::endl;
    ft::list<int> mylistIns;
    ft::list<int>::iterator itIns;

    // set some initial values:
    for (int i=1; i<=5; ++i) mylistIns.push_back(i); // 1 2 3 4 5

    itIns = mylistIns.begin();
    ++itIns;       // it points now to number 2           ^

    mylistIns.insert (itIns,10);                        // 1 10 2 3 4 5

    std::list<int> mylistInsOriginal;
    std::list<int>::iterator itInsOriginal;

    viewAll(mylistIns);

    // set some initial values:
    for (int i=1; i<=5; ++i) mylistInsOriginal.push_back(i); // 1 2 3 4 5

    itInsOriginal = mylistInsOriginal.begin();
    ++itInsOriginal;       // it points now to number 2           ^
    mylistInsOriginal.insert(itInsOriginal,10);
    viewAllOriginal(mylistInsOriginal);
    // "it" still points to number 2                      ^
    mylistIns.insert(itIns,2,20);
    mylistInsOriginal.insert (itInsOriginal,2,20);                      // 1 10 20 20 2 3 4 5
    viewAll(mylistIns);
    viewAllOriginal(mylistInsOriginal);
    --itIns;
    --itInsOriginal;       // it points now to the second 20            ^

    std::vector<int> myvector (2,30);
    mylistIns.insert (itIns,myvector.begin(),myvector.end());
    mylistInsOriginal.insert (itInsOriginal,myvector.begin(),myvector.end());   // 1 10 20 30 30 20 2 3 4 5

    viewAll(mylistIns);
    viewAllOriginal(mylistInsOriginal);

    if (mylistIns.size() == mylistInsOriginal.size())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(mylistInsOriginal);
        std::cout << "received ";
        viewAll(mylistIns);

        mistakes++;
    }

    std::cout << "\nTest " << i++ << std::endl;
    std::cout << "****************** Test sort2not empty list<int> ******************" << std::endl;

    ft::list<int>::iterator itSort = A.begin();
    std::list<int>::iterator itSortOriginal = AOrigin.begin();

    viewAll(A);
    viewAllOriginal(AOrigin);
    ++itSort;
    ++itSortOriginal;

    A.sort();
    AOrigin.sort();
    std::cout << "*Sort*" << std::endl;
    viewAll(A);
    viewAllOriginal(AOrigin);
    if (A.front() == AOrigin.front())
        std::cout << "✅ OK" << std::endl;
    else
    {
        std::cout << "❌FALSE❌ : expected ";
        viewAllOriginal(AOrigin);
        std::cout << "received ";
        viewAll(A);
        mistakes++;
    }


	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test splice1 list<std::int> ******************" << std::endl;

	ft::list<int> firstSs;
	ft::list<int> secondSs;
	std::list<int> firstSsOriginal;
	std::list<int> secondSsOriginal;

	ft::list<int>::iterator itS;
	std::list<int>::iterator it;
	// set some initial values:
	for (int i=1; i<=4; ++i)
		firstSs.push_back(i);      // mylist1: 1 2 3 4
	for (int i=1; i<=3; ++i)
		secondSs.push_back(i*10);   // mylist2: 10 20 30
	itS = firstSs.begin();
	++itS;                         // points to 2
	viewAll(firstSs);
	firstSs.splice (itS, secondSs);

	for (int i=1; i<=4; ++i)
		firstSsOriginal.push_back(i);      // mylist1: 1 2 3 4
	for (int i=1; i<=3; ++i)
		secondSsOriginal.push_back(i*10);   // mylist2: 10 20 30
	it = firstSsOriginal.begin();
	++it;                         // points to 2
	viewAllOriginal(firstSsOriginal);
	firstSsOriginal.splice (it, secondSsOriginal);
	std::cout << "*Splice*" << std::endl;
	viewAll(firstSs);
	viewAll(secondSs);
	viewAllOriginal(firstSsOriginal);
	viewAllOriginal(secondSsOriginal);

	if (firstAs.size() == firstAsOriginal.size())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(firstAsOriginal);
		std::cout << "received ";
		viewAll(firstSs);

		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test splice2 list<std::int> ******************" << std::endl;
	viewAll(firstSs);
	viewAll(secondSs);
	viewAllOriginal(firstSsOriginal);
	viewAllOriginal(secondSsOriginal);
	secondSs.splice (secondSs.begin(),firstSs, itS);
	secondSsOriginal.splice (secondSsOriginal.begin(),firstSsOriginal, it);
	std::cout << "*Splice*" << std::endl;
	viewAll(firstSs);
	viewAll(secondSs);
	viewAllOriginal(firstSsOriginal);
	viewAllOriginal(secondSsOriginal);
	if (*secondSs.begin() == *secondSsOriginal.begin())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(firstAsOriginal);
		std::cout << "received ";
		viewAll(firstSs);

		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test splice3 list<std::int> ******************" << std::endl;
	viewAll(firstSs);
	viewAllOriginal(firstSsOriginal);

	itS = firstSs.begin();
	std::advance(itS,3);           // "it" points now to 30

	firstSs.splice(firstSs.begin(), firstSs, itS, firstSs.end());
	// mylist1: 30 3 4 1 10 20

	it = firstSsOriginal.begin();
	std::advance(it,3);           // "it" points now to 30

	firstSsOriginal.splice ( firstSsOriginal.begin(), firstSsOriginal, it, firstSsOriginal.end());
	// mylist1: 30 3 4 1 10 20
	std::cout << "*Splice*" << std::endl;
	viewAll(firstSs);
	viewAllOriginal(firstSsOriginal);
	if (*firstSs.begin() == *firstSsOriginal.begin())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(firstAsOriginal);
		std::cout << "received ";
		viewAll(firstSs);

		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test merge1 list<std::int> ******************" << std::endl;
	std::list<double> firstMOriginal, secondMOriginal;
	ft::list<double> firstM, secondM;

	firstM.push_back (3.1);
	firstM.push_back (2.2);
	firstM.push_back (2.9);
	secondM.push_back (3.7);
	secondM.push_back (7.1);
	secondM.push_back (1.4);
	viewAll(firstM);
	viewAll(secondM);

	firstM.sort();
	secondM.sort();
	firstM.merge(secondM);

	firstMOriginal.push_back (3.1);
	firstMOriginal.push_back (2.2);
	firstMOriginal.push_back (2.9);
	secondMOriginal.push_back (3.7);
	secondMOriginal.push_back (7.1);
	secondMOriginal.push_back (1.4);
	viewAllOriginal(firstMOriginal);
	viewAllOriginal(secondMOriginal);
	firstMOriginal.sort();
	secondMOriginal.sort();
	firstMOriginal.merge(secondMOriginal);

	std::cout << "*Merge*" << std::endl;
	viewAll(firstM);
	viewAll(secondM);
	viewAllOriginal(firstMOriginal);
	viewAllOriginal(secondMOriginal);
	if (*firstM.begin() == *firstMOriginal.begin())
		std::cout << "✅ OK" << std::endl;
	else
	{
		std::cout << "❌FALSE❌ : expected ";
		viewAllOriginal(firstMOriginal);
		std::cout << "received ";
		viewAll(firstM);

		mistakes++;
	}

	std::cout << "\nTest " << i++ << std::endl;
	std::cout << "****************** Test merge2 list<std::int> ******************" << std::endl;
	// compare only integral part:
	secondM.push_back (2.1);
	secondM.push_back (2.3);
	secondMOriginal.push_back (2.1);
	secondMOriginal.push_back (2.3);

	viewAll(firstM);
	viewAll(secondM);
	viewAllOriginal(firstMOriginal);
	viewAllOriginal(secondMOriginal);

	firstM.merge(secondM, mycomparison);
	firstMOriginal.merge(secondMOriginal, mycomparison);

	std::cout << "*Merge*" << std::endl;
	viewAll(firstM);
	viewAll(secondM);
	viewAllOriginal(firstMOriginal);
	viewAllOriginal(secondMOriginal);

    std::cout << "\nMistakes=" << mistakes << std::endl;
    
    return 0;
}
