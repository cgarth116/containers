//
// Created by Caeneus Garth on 2/5/21.
//

#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP

#include <iostream>

namespace ft
{
	template <class T>
	struct Node{
		Node(): nodeNext(NULL), nodePrevious(NULL) {}
		Node(const T& t)
		{
			node = t;
			nodeNext = NULL;
			nodePrevious = NULL;
		}
		T node; //сама нода
		Node *nodeNext; //следующий элемент
		Node *nodePrevious; //предыдущий элемент
	};

	template <class T>
    		class iterator: public std::iterator<std::input_iterator_tag, T>{
    public:
        iterator(): _index(NULL) {};
        iterator(Node<T> * index): _index(index) {};
        bool operator==(iterator const & rhs){
            return _index == rhs._index;
        };
        bool operator!=(iterator const & rhs){
            return _index != rhs._index;
        };
        iterator & operator++() {
            _index = _index->nodeNext;
            return *this;
        };
        iterator operator++(int)
        {
            iterator tmp(_index);
            _index = _index->nodeNext;
            return tmp;
        }
        iterator & operator--() {
            _index= _index->nodePrevious;
            return *this;
        };
        iterator operator--(int)
        {
            iterator tmp(_index);
            _index= _index->nodePrevious;
            return tmp;
        }
        T & operator*(){
            return _index->node;
        };

    private:
		Node<T> * _index;
    };

	template <class T>
			class reverse_iterator: public std::iterator<std::input_iterator_tag, T>{
    		public:
        	reverse_iterator(): _index(NULL) {};
        	reverse_iterator(Node<T> * index): _index(index) {};
        	bool operator==(reverse_iterator const & rhs){
        	    return _index == rhs._index;
       		};
        	bool operator!=(reverse_iterator const & rhs){
        	    return _index != rhs._index;
        	};
        	reverse_iterator & operator++() {
        	    _index= _index->nodePrevious;
        	    return *this;
        	};
        	reverse_iterator operator++(int)
        	{
        	    reverse_iterator tmp(_index);
        	    _index= _index->nodePrevious;
        	    return tmp;
        	}
        	reverse_iterator & operator--() {
        	    _index = _index->nodeNext;
        	    return *this;
        	};
        	reverse_iterator operator--(int)
        	{
        	    reverse_iterator tmp(_index);
        	    _index = _index->nodeNext;
       	     return tmp;
        	}
        	T & operator*(){
        	    return _index->node;
        	};

   		private:
			Node<T> * _index;
    	};

	template <class T>
	class const_iterator: public std::iterator<const std::input_iterator_tag, T>{
	public:
		const_iterator(): _index(NULL) {};
		const_iterator(Node<T> * index): _index(index) {};
		bool operator==(const_iterator const & rhs){
			return _index == rhs._index;
		};
		bool operator!=(const_iterator const & rhs){
			return _index != rhs._index;
		};
		const_iterator & operator++() {
			_index = _index->nodeNext;
			return *this;
		};
		const_iterator operator++(int)
		{
			const_iterator tmp(_index);
			_index = _index->nodeNext;
			return tmp;
		}
		const_iterator & operator--() {
			_index= _index->nodePrevious;
			return *this;
		};
		const_iterator operator--(int)
		{
			const_iterator tmp(_index);
			_index= _index->nodePrevious;
			return tmp;
		}
		T & operator*(){
			return _index->node;
		};

	private:
		Node<T> * _index;
	};

	template <class T>
	class const_reverse_iterator : public std::iterator<std::input_iterator_tag, T>{
	public:
		const_reverse_iterator(): _index(NULL) {};
		const_reverse_iterator(Node<T> * index): _index(index) {};
		bool operator==(const_reverse_iterator const & rhs){
			return _index == rhs._index;
		};
		bool operator!=(const_reverse_iterator const & rhs){
			return _index != rhs._index;
		};
		const_reverse_iterator & operator++() {
			_index= _index->nodePrevious;
			return *this;
		};
		const_reverse_iterator operator++(int)
		{
			const_reverse_iterator tmp(_index);
			_index= _index->nodePrevious;
			return tmp;
		}
		const_reverse_iterator & operator--() {
			_index = _index->nodeNext;
			return *this;
		};
		const_reverse_iterator operator--(int)
		{
			const_reverse_iterator tmp(_index);
			_index = _index->nodeNext;
			return tmp;
		}
		T & operator*(){
			return _index->node;
		};

	private:
		Node<T> * _index;
	};
}

#endif //LISTITERATOR_HPP