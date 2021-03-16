#include <iostream>

namespace ft{

	typedef std::ptrdiff_t					difference_type;

	template < typename value_type, typename allocator_type >
	struct Node{

		Node(): _parent(NULL), _left(NULL), _right(NULL) {
			_data = allocator_type().allocate(1);
		}
		Node(const value_type & value) :  _parent(NULL), _left(NULL), _right(NULL)
		{
			_data = allocator_type().allocate(1);
			allocator_type().construct(_data, value);
		}

		value_type *			_data;
		Node *					_parent;
		Node * 					_left;
		Node *					_right;
	};


	template < typename value_type, typename allocator_type >
	class mapIterator: public std::iterator< std::bidirectional_iterator_tag, value_type >{

		typedef std::iterator< std::bidirectional_iterator_tag, value_type >	_stdIt;
		typedef typename _stdIt::pointer										_pointer;
		typedef typename _stdIt::reference										_reference;
		typedef Node<value_type, allocator_type>								Node;
		public:
			mapIterator() : _index(NULL) {};
			mapIterator(Node * index): _index(index){};
			mapIterator & operator=(const mapIterator & rhs) {
				if (this != &rhs){
					_index = rhs._index;
				}
				return *this;
			}
			value_type & operator*(){
				return *_index;
			}


//
//			mapIterator(const mapIterator & rhs) {
//				*this = rhs;
//			}
//			mapIterator & operator=(const mapIterator & rhs){
//				if (this != &rhs){
//					_node = rhs._node;
//				}
//				return *this;
//			}
//
//			mapIterator(Node * rhs) {
//				_node = rhs;
//			}
//
//			_reference operator*(){
//				return *(_node->_data);
//			}
//
//			_pointer  operator->(){
//				return _node->_data;
//			}
//
//			mapIterator & operator++() {
//				Node * tmp;
//				if (_node->_right){
//					return min(_node->right);
//				}
//				tmp = _node->parent;
//				while (tmp && _node == tmp->right){
//					_node = tmp;
//					tmp = tmp->parent;
//				}
//				return tmp;
//			}
////			mapIterator operator++(int){
////				vectorIterator tmp(_index);
////				++_index;
////				return tmp;
////			}
////			mapIterator operator-(difference_type n) {
////				vectorIterator it(*this);
////				it -= n;
////				return it;
////			}
//			mapIterator & operator--() {
//				Node * tmp;
//				if (_node->left){
//					return max(_node->left);
//				}
//				tmp = _node->parent;
//				while (tmp && _node == tmp->left){
//					_node = tmp;
//					tmp = tmp->parent;
//				}
//			return tmp;
//			}
////			mapIterator operator--(int)
////			{
////				vectorIterator tmp(_index);
////				--_index;
////				return tmp;
////			}

		private:

			//обход всего дерева
			void preOrderTravers(Node* root, void (*visit)(Node*, void*), void *params) {
				if (root) {
					visit(root, params);
					preOrderTravers(root->left, visit, params);
					preOrderTravers(root->right, visit, params);
				}
			}

		void preOrderTraversRight(Node* root, void (*visit)(Node*, void*), void *params) {
			if (root){
				preOrderTravers(root->_right, visit, params);
			}
		}

			value_type & getNode(Node *current, void *args) {
				return current->_data;
			}

			void deleteTree(Node **root) {
				if (*root) {
					deleteTree(&((*root)->left));
					deleteTree(&((*root)->right));
					free(*root);
				}
			}


		_pointer _index;
	};
}