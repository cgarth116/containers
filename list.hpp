#include <memory>
#include <iostream>
#include "listIterator.hpp"

namespace ft {
//template<bool Cond, class T = void> struct enable_if {};
//template<class T> struct enable_if<true, T> { typedef T type; };


	template< typename T >
	inline void	swap(T & x, T & y) {
		T	tmp(x);
		x = y;
		y = tmp;
	};

    template <class T, class Alloc = std::allocator<T> >
    class list
    {

        public:
			typedef T   							value_type;
			typedef Alloc							allocator_type;
			typedef typename Alloc::reference		reference;
			typedef typename Alloc::const_reference	const_reference;
			typedef typename Alloc::pointer			pointer;
			typedef typename Alloc::const_pointer	const_pointer;
			typedef std::ptrdiff_t					difference_type;
			typedef std::size_t 					size_type;
			typedef ft::Node<T, Alloc> 				Node;
			typedef ft::iterator<T>  				iterator;
			typedef ft::const_iterator<T>  			const_iterator;
			typedef ft::reverse_iterator<T>			reverse_iterator;
			typedef ft::const_reverse_iterator<T>	const_reverse_iterator;

			static bool compare(const T & x, const T & y) {
				return x < y;
			}

            explicit list (const Alloc& alloc = Alloc()){
				Node *nodeEnd = new Node();

				nodeEnd->nodePrevious = nodeEnd;
				nodeEnd->nodeNext = nodeEnd;
				_listEnd = nodeEnd;
				_sizelist = 0;
				_sizeNode = sizeof(Node);
				_allocator = alloc;
			};
            explicit list (size_t n, const value_type& val = value_type(),
						   const Alloc& alloc = Alloc()){
            	Node *nodeEnd = new Node();

				nodeEnd->nodePrevious = nodeEnd;
				nodeEnd->nodeNext = nodeEnd;
				_listEnd = nodeEnd;
				_sizelist = 0;
				_sizeNode = sizeof(Node);
				while (n-- > 0)
					push_front(val);
				_allocator = alloc;
			};
            template <class InputIterator>
            list (InputIterator first,
				  InputIterator last,
				  const Alloc& alloc = Alloc(),
				  typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
            	Node *nodeEnd = new Node();

				nodeEnd->nodePrevious = nodeEnd;
				nodeEnd->nodeNext = nodeEnd;
				_listEnd = nodeEnd;
				_sizelist = 0;
				_sizeNode = sizeof(Node);
				while (first != last ){
					push_back(*first);
					++first;
				}
				_allocator = alloc;
			};
            list (const list & rhs){
				Node *nodeEnd = new Node();

				nodeEnd->nodePrevious = nodeEnd;
				nodeEnd->nodeNext = nodeEnd;
				_listEnd = nodeEnd;
				_sizelist = 0;
				_sizeNode = sizeof(Node);
				*this = rhs;
			};
            list & operator=(const list & rhs){
				if (this == &rhs)
					return *this;
				clear();
				if (rhs._sizelist != 0){
					ft::Node<T>* tmp = rhs._listEnd->nodeNext;
					while (tmp != rhs._listEnd){
						push_back(tmp->node);
						tmp = tmp->nodeNext;
					}
				}
				return *this;
			};

            iterator begin(){
              return iterator(_listEnd->nodeNext);
            };
			const_iterator begin() const{
				return const_iterator(_listEnd->nodeNext);
			};
            iterator end(){
              return iterator(_listEnd);
            };
			const_iterator end() const{
				return const_iterator(_listEnd);
			};
            reverse_iterator rbegin(){
                return reverse_iterator(_listEnd->nodePrevious);
            };
			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(_listEnd->nodePrevious);
			};
            reverse_iterator rend(){
                return reverse_iterator(_listEnd);
            };
			const_reverse_iterator rend() const{
				return const_reverse_iterator(_listEnd);
			};

            bool empty() const{
                return _sizelist == 0;
            }
            size_t size() const{
                return _sizelist;
            }
            size_t max_size() const{
                return std::numeric_limits<size_t>::max() / _sizeNode;
            }

            value_type& front(){
                return _listEnd->nodeNext->node;
            }
            const value_type& front() const{
                return _listEnd->nodeNext->node;
            }
            value_type& back(){
                return _listEnd->nodePrevious->node;
            }
            const value_type& back() const{
                return _listEnd->nodePrevious->node;
            }

            template <class InputIterator>
            void assign (InputIterator first, InputIterator last, typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
                if (_sizelist != 0)
                    clear();
                while (first != last){
                    push_back(*first);
                    first++;
                }
            }
            void assign (size_t n, const value_type& val){
                if (_sizelist != 0)
                    clear();
                while (n > 0){
                    push_back(val);
                    n--;
                }
            }
            void push_front(const value_type& t){
            	if (Node *node = new Node(t)){
                    if (_sizelist != 0){
                        node->nodeNext = _listEnd->nodeNext;
                        node->nodeNext->nodePrevious = node;
                    }
                    else{
                        node->nodeNext = _listEnd;
                        _listEnd->nodePrevious = node;
                    }
                    _listEnd->nodeNext = node;
                    node->nodePrevious = _listEnd;
                    _sizelist++;
                    _listEnd->node = _sizelist;
                }
            }
            void pop_front(){
                if (_sizelist != 0){
                    _listEnd->nodeNext = _listEnd->nodeNext->nodeNext;
                    delete _listEnd->nodeNext->nodePrevious;
                    _listEnd->nodeNext->nodePrevious = _listEnd;
                    _sizelist--;
                    _listEnd->node = _sizelist;
                }
            }
            void push_back(const value_type& t){
                if (Node *node = new Node(t)){
                    if (_sizelist != 0){
                        node->nodePrevious = _listEnd->nodePrevious;
                        node->nodePrevious->nodeNext = node;
                    }
                    else{
                        node->nodePrevious = _listEnd;
						_listEnd->nodeNext = node;
                    }
                    node->nodeNext = _listEnd;
                    _listEnd->nodePrevious = node;
                    _sizelist++;
                    _listEnd->node = _sizelist;
                }
            }
            void pop_back(){
                if (_sizelist != 0){
                    _listEnd->nodePrevious = _listEnd->nodePrevious->nodePrevious;
                    delete _listEnd->nodePrevious->nodeNext;
                    _listEnd->nodePrevious->nodeNext = _listEnd;
                    _sizelist--;
                    _listEnd->node = _sizelist;
                }
            }
            iterator insert (iterator position, const value_type& val){
                iterator begin = _listEnd->nodeNext;
                iterator end = _listEnd;
                Node * tmp = _listEnd->nodeNext;

                while (begin != position && begin != end) {
                    tmp = tmp->nodeNext;
                    begin++;
                }
                if (Node *node = new Node(val)){
                    node->nodeNext = tmp;
                    node->nodePrevious = tmp->nodePrevious;
                    tmp->nodePrevious->nodeNext = node;
                    tmp->nodePrevious = node;
                    _sizelist++;
                    _listEnd->node = _sizelist;
                    return node;
                }
                return _listEnd;
            }
            void insert (iterator position, size_t n, const value_type& val){
                while (n > 0){
                    position = insert(position, val);
                 n--;
                }
            }
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
                while (first != last){
                    position = insert(position, *first);
                    first++;
                }
            }
            iterator erase(iterator position){
                return erase(position, ++position);
            }
            iterator erase(iterator first, iterator last){
                iterator it = _listEnd->nodeNext;
                if (_sizelist != 0 && first != _listEnd){
                    Node * tmp;
                    Node * tmpB;
                    tmp = _listEnd->nodeNext;
                    while (it != first && it != _listEnd){
                        tmp = tmp->nodeNext;
                        ++it;
                    }
                    tmpB = tmp->nodePrevious;
                    while (it != last && it != _listEnd){
                        tmpB->nodeNext = tmp->nodeNext;
                        delete tmp;
                        tmp = tmpB->nodeNext;
                        _sizelist--;
                        _listEnd->node = _sizelist;
                        ++it;
                    }
                    tmp->nodePrevious = tmpB;
                    return it;
                }
                it = _listEnd;
                return it;
            }
            void swap (list & x){
				ft::swap(_allocator, x._allocator);
            	ft::swap(_listEnd, x._listEnd);
            	ft::swap(_sizelist, x._sizelist);
            }
            void resize (size_t n, value_type val = value_type ()){
                if (n >= _sizelist){
                    while (_sizelist != n)
                        push_back(val);
                }
                else{
                    while (_sizelist != n)
                        pop_back();
                }
            }
            void clear (){
                erase(_listEnd->nodeNext, _listEnd);
            }

			void splice (iterator position, list & x){
				splice(position, x, x.begin(), x.end());
            }
			void splice (iterator position, list& x, iterator i){
				iterator in = i;
            	splice(position, x, i, ++in);
            }
			void splice (iterator position, list& x, iterator first, iterator last){
				while (first != last){
					insert(position, *first);
					x.erase(first++);
				}
            }
            void remove (const value_type& val){
                iterator it = _listEnd->nodeNext;
                while (it != _listEnd)
                {
                    if (*it == val)
                        erase(it);
                    ++it;
                }
            }
            template <class Predicate>
            void remove_if (Predicate pred){
                iterator it = _listEnd->nodeNext;
                while (it != _listEnd)
                {
                    if (pred(*it))
                        erase(it);
                    ++it;
                }
            }
            void unique(){
                T tmp;
                iterator it = _listEnd->nodeNext;
                while (it != _listEnd){
                    tmp = *it;
                    if (*(++it) == tmp)
                        while (*it == tmp)
                            erase(it++);
                }
            }
            template <class BinaryPredicate>
            void unique (BinaryPredicate binary_pred){
                T tmp;
                iterator it = _listEnd->nodeNext;
                while (it != _listEnd)
                {
                    tmp = *it;
                    if (binary_pred(tmp, *(++it)))
                        while ( binary_pred(tmp, *it))
                            erase(it++);
                }
            }
			void merge (list& x){
            	splice(begin(), x);
            	sort();
            }
			template <class Compare>
			void merge (list & x, Compare comp){
				sort();
            	x.sort();
            	iterator it = begin();
				iterator ite = end();
				iterator itX = x.begin();
				iterator itXe = x.end();
				if (size() == 0){
					while(itX != itXe){
						push_back(*itX);
						x.erase(itX++);
					}
				}
				else{
            		while(itX != itXe) {
						while (it != ite) {
							if (comp(*itX, *it) > 0) {
								insert(it, *itX);
								x.erase(itX);
								break;
							}
							++it;
						}
						++itX;
					}
				}
            }
            void sort(){
				sort(compare);
            }
            template <class Compare>
            void sort(Compare comp){
				Node * tmp;
				Node * tmpN;
                iterator it;
                iterator countIn = _listEnd;
                while (countIn != _listEnd->nodeNext)
                {
                    it = _listEnd->nodeNext;
					tmp = _listEnd->nodeNext;
                    while (it != countIn){
                        if (++it != countIn && comp(tmp->nodeNext->node, tmp->node) > 0){
							tmpN = tmp->nodeNext->nodeNext;
							tmp->nodeNext->nodeNext->nodePrevious = tmp;
							tmp->nodePrevious->nodeNext = tmp->nodeNext;
							tmp->nodeNext->nodePrevious = tmp->nodePrevious;
							tmp->nodeNext->nodeNext = tmp;
							tmp->nodePrevious = tmp->nodeNext;
							tmp->nodeNext = tmpN;
							it = tmp;
						}
						else{
							tmp = tmp->nodeNext;
						}
                    }
                    --countIn;
                }
            }
            void reverse(){
                Node * tmp;
                Node * tmpNode;
                iterator begin = _listEnd->nodeNext;

                tmpNode = _listEnd->nodeNext;
                while (begin != _listEnd)
                {
                    begin++;
                    tmp = tmpNode->nodeNext;
                    tmpNode->nodeNext = tmpNode->nodePrevious;
                    tmpNode->nodePrevious = tmp;
                    tmpNode = tmp;
                }
                tmp= _listEnd->nodeNext;
                _listEnd->nodeNext = _listEnd->nodePrevious;
                _listEnd->nodePrevious = tmp;
            }

            ~list(){
            	while(_sizelist != 0){
            		pop_back();
            	}
				delete _listEnd;
            }

        private:
            Node *			_listEnd;
            size_t			_sizelist;
            size_t			_sizeNode;
			allocator_type	_allocator;

    };

	template < class T, class Alloc >
	bool operator==(const list<T,Alloc>& lhs, const list<T,Alloc> & rhs) {
		typedef typename list<T, Alloc>::const_iterator _iter;

		if (lhs.size() != rhs.size()) {
			return false;
		}
		_iter	lIt		= lhs.begin();
		_iter	lIte	= lhs.end();
		_iter	rIt		= rhs.begin();
		_iter	rIte	= rhs.end();
		while (lIt != lIte && rIt != rIte) {
			if (!(*lIt == *rIt)) {
				return false;
			}
			++rIt;
			++lIt;
		}
		return (lIt == lIte && rIt == rIte);
	};

	template < class T, class Alloc >
	bool operator!=(const list<T,Alloc>& lhs, const list<T,Alloc> & rhs) {
		return !(lhs == rhs);
	};

	template < class T, class Alloc >
	bool operator< (const list<T,Alloc>& lhs, const list<T,Alloc> & rhs) {
		typedef typename list<T, Alloc>::const_iterator _iter;

		_iter	lIt		= lhs.begin();
		_iter	lIte	= lhs.end();
		_iter	rIt		= rhs.begin();
		_iter	rIte	= rhs.end();

		while (lIt != lIte && rIt != rIte) {
			if (*lIt < *rIt) {
				return true;
			}
			if (*rIt < *lIt) {
				return false;
			}
			++lIt;
			++rIt;
		}
		return (lIt == lIte && rIt != rIte);
	};

	template < class T, class Alloc >
	bool operator<=(const list<T,Alloc>& lhs, const list<T,Alloc> & rhs) {
		return !(rhs < lhs);
	};

	template < class T, class Alloc >
	bool operator> (const list<T,Alloc>& lhs, const list<T,Alloc> & rhs) {
		return (rhs < lhs);
	};

	template < class T, class Alloc >
	bool operator>=(const list<T,Alloc>& lhs, const list<T,Alloc> & rhs) {
		return !(lhs < rhs);
	};

	template <class T, class Alloc>
	void swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y){
		x.swap(y);
	};
}

