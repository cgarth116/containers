#include <iostream>

namespace ft{

	typedef std::ptrdiff_t					difference_type;

	template < typename value_type >
	struct Node{
		Node(): _parent(NULL), _left(NULL), _right(NULL) {}
		Node(const value_type & value) :  _parent(NULL), _left(NULL), _right(NULL)
		{
			_data.first = value.first;
			_data.second = value.second;
		}

		value_type *				_data;
		Node *						_parent;
		Node * 						_left;
		Node * 						_right;
	};

	template < typename value_type >
	class mapIterator: public std::iterator< std::bidirectional_iterator_tag, value_type >{

		typedef std::iterator< std::bidirectional_iterator_tag, value_type >	_stdIt;
		typedef typename _stdIt::pointer										_pointer;
		typedef typename _stdIt::reference										_reference;
		public:
			mapIterator() : _node(NULL) {};
			mapIterator(const mapIterator & rhs) {
				*this = rhs;
			}
			mapIterator & operator=(const mapIterator & rhs){
				if (this != &rhs){
					_node = rhs._node;
				}
				return _node;
			}

			mapIterator(Node<value_type> * rhs) {
				_node = rhs;
			}

			_reference operator *(){
				return *(_node._data);
			}

			_pointer  operator *(){
				return _node._data;
			}
		private:
			Node<value_type> * _node;
	};
}