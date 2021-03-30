//
// Created by Caeneus Garth on 2/5/21.
//

#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP

#include <iostream>

namespace ft
{

	template <class T, class Alloc = std::allocator<T> >
	struct Node{
		Node(): nodeNext(NULL), nodePrevious(NULL) {}
		Node(const T& t){
			node = t;
			nodeNext = NULL;
			nodePrevious = NULL;
		}

		T		node; //сама нода
		Node	*nodeNext; //следующий элемент
		Node	*nodePrevious; //предыдущий элемент
	};

	template <class T>
	class iterator: public std::iterator<std::input_iterator_tag, T>{
		typedef T*  _pointer;
		typedef T&  _reference;
    	public:
        	iterator(): _index(NULL) {};
        	iterator(Node<T> * index): _index(index) {};
        	iterator(const iterator & rhs){
        		*this = rhs;
        	}
        	iterator & operator=(const iterator & rhs){
				if (this != &rhs){
					_index = rhs._index;
				}
				return *this;
        	}
        	bool operator==(iterator const & rhs){
            return _index == rhs._index;
        };
        	bool operator!=(iterator const & rhs){
            return _index != rhs._index;
        };
        	iterator & operator++(){
            _index = _index->nodeNext;
            return *this;
        };
        	iterator operator++(int){
            iterator tmp(_index);
            _index = _index->nodeNext;
            return tmp;
        };
       	 	iterator & operator--(){
            _index= _index->nodePrevious;
            return *this;
        };
        	iterator operator--(int){
            iterator tmp(_index);
            _index= _index->nodePrevious;
            return tmp;
        };
       		_reference operator*(){
            	return _index->node;
        	};
       		_pointer operator->(){
       			return &(operator*());
       		}

    	private:
			Node<T> * _index;
    };

	template <class T>
	class reverse_iterator: public std::iterator<std::input_iterator_tag, T>{
		typedef T*  _pointer;
		typedef T&  _reference;
		public:
			reverse_iterator(): _index(NULL) {};
			reverse_iterator(Node<T> * index): _index(index) {};
			reverse_iterator(const reverse_iterator & rhs){
			*this = rhs;
		}
			reverse_iterator & operator=(const reverse_iterator & rhs){
			if (this != &rhs){
				_index = rhs._index;
			}
			return *this;
		}
			bool operator==(reverse_iterator const & rhs){
        	    return _index == rhs._index;
       		};
			bool operator!=(reverse_iterator const & rhs){
        	    return _index != rhs._index;
        	};
			reverse_iterator & operator++(){
        	    _index= _index->nodePrevious;
        	    return *this;
        	};
			reverse_iterator operator++(int){
        	    reverse_iterator tmp(_index);
        	    _index= _index->nodePrevious;
        	    return tmp;
        	};
			reverse_iterator & operator--(){
        	    _index = _index->nodeNext;
        	    return *this;
        	};
			reverse_iterator operator--(int){
        	    reverse_iterator tmp(_index);
        	    _index = _index->nodeNext;
       	     return tmp;
        	};
			_reference operator*(){
				return _index->node;
			};
			_pointer operator->(){
				return &(operator*());
			}

   			private:
				Node<T> * _index;
    	};

	template <class T>
	class const_iterator: public std::iterator<const std::input_iterator_tag, T>{
		typedef T*  _pointer;
		typedef T&  _reference;
		public:
			const_iterator(): _index(NULL) {};
			const_iterator(Node<T> * index): _index(index) {};
			const_iterator(const const_iterator & rhs){
			*this = rhs;
		}
			const_iterator & operator=(const const_iterator & rhs){
			if (this != &rhs){
				_index = rhs._index;
			}
			return *this;
		}
			bool operator==(const_iterator const & rhs){
			return _index == rhs._index;
		};
			bool operator!=(const_iterator const & rhs){
			return _index != rhs._index;
		};
			const_iterator & operator++(){
			_index = _index->nodeNext;
			return *this;
		};
			const_iterator operator++(int){
			const_iterator tmp(_index);
			_index = _index->nodeNext;
			return tmp;
		};
			const_iterator & operator--(){
			_index= _index->nodePrevious;
			return *this;
		};
			const_iterator operator--(int){
			const_iterator tmp(_index);
			_index= _index->nodePrevious;
			return tmp;
		};
			_reference operator*(){
			return _index->node;
		};
			_pointer operator->(){
			return &(operator*());
		}

		private:
			Node<T> * _index;
	};

	template <class T>
	class const_reverse_iterator : public std::iterator<std::input_iterator_tag, T>{
		typedef T*  _pointer;
		typedef T&  _reference;
		public:
			const_reverse_iterator(): _index(NULL) {};
			const_reverse_iterator(Node<T> * index): _index(index) {};
			const_reverse_iterator(const const_reverse_iterator & rhs){
			*this = rhs;
		}
			const_reverse_iterator & operator=(const const_reverse_iterator & rhs){
			if (this != &rhs){
				_index = rhs._index;
			}
			return *this;
		}
			bool operator==(const_reverse_iterator const & rhs){
			return _index == rhs._index;
		};
			bool operator!=(const_reverse_iterator const & rhs){
			return _index != rhs._index;
		};
			const_reverse_iterator & operator++(){
			_index= _index->nodePrevious;
			return *this;
		};
			const_reverse_iterator operator++(int){
			const_reverse_iterator tmp(_index);
			_index= _index->nodePrevious;
			return tmp;
		}
			const_reverse_iterator & operator--(){
			_index = _index->nodeNext;
			return *this;
		};
			const_reverse_iterator operator--(int){
			const_reverse_iterator tmp(_index);
			_index = _index->nodeNext;
			return tmp;
		}
			_reference operator*(){
			return _index->node;
		};
			_pointer operator->(){
			return &(operator*());
		}

		private:
			Node<T> * _index;
	};
}

#endif //LISTITERATOR_HPP
