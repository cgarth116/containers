#include <iostream>
namespace ft{

	typedef std::ptrdiff_t					difference_type;

	template < typename value_type, typename allocator_type >
	struct Node{

		static const bool	_black	= true;
		static const bool	_red	= false;

		Node(): _parent(nullptr), _left(nullptr), _right(nullptr), _color(_red) {
			_data = allocator_type().allocate(1);
			allocator_type().construct(_data);
		}
//		Node(const value_type & value) :  _parent(NULL), _left(NULL), _right(NULL)
//		{
//			_data = allocator_type().allocate(1);
//			allocator_type().construct(_data(value));
//		}

		value_type * insertNode(const value_type & value){

			_data = allocator_type().allocate(1);
			allocator_type().construct(_data, value);
			return _data;
		}

		value_type *			_data;
		Node *					_parent;
		Node * 					_left;
		Node *					_right;
		bool 					_color; //true - black, false - red
	};


	template < typename value_type, typename allocator_type >
	class mapIterator: public std::iterator< std::bidirectional_iterator_tag, value_type >{

		typedef std::iterator< std::bidirectional_iterator_tag, value_type >	_stdIt;
		typedef typename _stdIt::pointer										_pointer;
		typedef typename _stdIt::reference										_reference;
		typedef Node<value_type, allocator_type>								Node;
		public:
			mapIterator() : _index(NULL) {};
			mapIterator(Node * rhs) : _index(rhs){}
			mapIterator(const mapIterator & rhs){
				*this = rhs;
			};

			mapIterator & operator=(const mapIterator & rhs) {
				if (this != &rhs){
					_index = rhs._index;
				}
				return *this;
			}
			bool operator!=(const mapIterator & rhs){
				return _index != rhs._index;
			}
			bool operator==(const mapIterator & rhs){
				return _index == rhs._index;
			}
			_reference operator*(){
				return *(_index->_data);
			}
			_pointer operator->(){
				return _index->_data;
			}
			Node * getTreeNode(){
				return _index;
			}

			virtual ~mapIterator(){}

			mapIterator operator++() {
				Node * tmp;
				if (_index->_right){
					if (_index->_right == _index->_right->_right){
						return _index = _index->_right;
					}
					return _index = minimumNode(_index->_right);
				}
				tmp = _index->_parent;
				while (tmp && _index == tmp->_right){
					_index = tmp;
					tmp = tmp->_parent;
				}
				_index = tmp;
				return _index;
			}

//			mapIterator operator--() {
//				Node * x = _index;
//				Node * tmp;
//				if (!x->_left){
//					return mapIterator(maximumNode(x->_left));
//				}
//				tmp = x->_parent;
//				while (tmp && x == tmp->_left){
//					x = tmp;
//					tmp = tmp->_parent;
//				}
//				return mapIterator(tmp);
//			}

			Node * minimumNode(mapIterator node){
				if (!node.getTreeNode()->_left){
					return node.getTreeNode();
				}
				return minimumNode(node.getTreeNode()->_left);
			}
			Node * maximumNode(mapIterator node){
				if (!node.getTreeNode()->_right) {
					return node.getTreeNode()->_parent;
				}
				return maximumNode(node.getTreeNode()->_right);
			}


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


		Node * _index;
	};

	template < typename value_type, typename allocator_type >
	class const_mapIterator: public std::iterator<const std::bidirectional_iterator_tag, value_type >{

		typedef std::iterator< std::bidirectional_iterator_tag, value_type >	_stdIt;
		typedef typename _stdIt::pointer										_pointer;
		typedef typename _stdIt::reference										_reference;
		typedef Node<value_type, allocator_type>								Node;
	public:
		const_mapIterator() : _index(NULL) {};
		const_mapIterator(Node * rhs) : _index(rhs){}
		const_mapIterator(const const_mapIterator & rhs){
			*this = rhs;
		};

		const_mapIterator & operator=(const const_mapIterator & rhs) {
			if (this != &rhs){
				_index = rhs._index;
			}
			return *this;
		}
		bool operator!=(const const_mapIterator & rhs){
			return _index != rhs._index;
		}
		bool operator==(const const_mapIterator & rhs){
			return _index == rhs._index;
		}
		_reference operator*(){
			return *(_index->_data);
		}
		_pointer operator->(){
			return _index->_data;
		}
		Node * getTreeNode(){
			return _index;
		}

		virtual ~const_mapIterator(){}

		const_mapIterator operator++() {
			Node * tmp;
			if (_index->_right){
				if (_index->_right == _index->_right->_right){
					return _index = _index->_right;
				}
				return _index = minimumNode(_index->_right);
			}
			tmp = _index->_parent;
			while (tmp && _index == tmp->_right){
				_index = tmp;
				tmp = tmp->_parent;
			}
			_index = tmp;
			return _index;
		}

//			mapIterator operator--() {
//				Node * x = _index;
//				Node * tmp;
//				if (!x->_left){
//					return mapIterator(maximumNode(x->_left));
//				}
//				tmp = x->_parent;
//				while (tmp && x == tmp->_left){
//					x = tmp;
//					tmp = tmp->_parent;
//				}
//				return mapIterator(tmp);
//			}

		Node * minimumNode(const_mapIterator node){
			if (!node.getTreeNode()->_left){
				return node.getTreeNode();
			}
			return minimumNode(node.getTreeNode()->_left);
		}
		Node * maximumNode(const_mapIterator node){
			if (!node.getTreeNode()->_right) {
				return node.getTreeNode()->_parent;
			}
			return maximumNode(node.getTreeNode()->_right);
		}

		private:
			Node * _index;
	};

	template < typename value_type, typename allocator_type >
	class reverse_mapIterator: public std::iterator<const std::bidirectional_iterator_tag, value_type >{

		typedef std::iterator< std::bidirectional_iterator_tag, value_type >	_stdIt;
		typedef typename _stdIt::pointer										_pointer;
		typedef typename _stdIt::reference										_reference;
		typedef Node<value_type, allocator_type>								Node;
	public:
		reverse_mapIterator() : _index(NULL) {};
		reverse_mapIterator(Node * rhs) : _index(rhs){}
		reverse_mapIterator(const reverse_mapIterator & rhs){
			*this = rhs;
		};

		reverse_mapIterator & operator=(const reverse_mapIterator & rhs) {
			if (this != &rhs){
				_index = rhs._index;
			}
			return *this;
		}
		bool operator!=(const reverse_mapIterator & rhs){
			return _index != rhs._index;
		}
		bool operator==(const reverse_mapIterator & rhs){
			return _index == rhs._index;
		}
		_reference operator*(){
			return *(_index->_data);
		}
		_pointer operator->(){
			return _index->_data;
		}
		Node * getTreeNode(){
			return _index;
		}

		virtual ~reverse_mapIterator(){}

		reverse_mapIterator operator++() {
			Node * tmp;
			if (_index->_right){
				if (_index->_right == _index->_right->_right){
					return _index = _index->_right;
				}
				return _index = minimumNode(_index->_right);
			}
			tmp = _index->_parent;
			while (tmp && _index == tmp->_right){
				_index = tmp;
				tmp = tmp->_parent;
			}
			_index = tmp;
			return _index;
		}

//			mapIterator operator--() {
//				Node * x = _index;
//				Node * tmp;
//				if (!x->_left){
//					return mapIterator(maximumNode(x->_left));
//				}
//				tmp = x->_parent;
//				while (tmp && x == tmp->_left){
//					x = tmp;
//					tmp = tmp->_parent;
//				}
//				return mapIterator(tmp);
//			}

		Node * minimumNode(reverse_mapIterator node){
			if (!node.getTreeNode()->_left){
				return node.getTreeNode();
			}
			return minimumNode(node.getTreeNode()->_left);
		}
		Node * maximumNode(reverse_mapIterator node){
			if (!node.getTreeNode()->_right) {
				return node.getTreeNode()->_parent;
			}
			return maximumNode(node.getTreeNode()->_right);
		}

	private:
		Node * _index;
	};

	template < typename value_type, typename allocator_type >
	class const_reverse_mapIterator: public std::iterator<const std::bidirectional_iterator_tag, value_type >{

		typedef std::iterator< std::bidirectional_iterator_tag, value_type >	_stdIt;
		typedef typename _stdIt::pointer										_pointer;
		typedef typename _stdIt::reference										_reference;
		typedef Node<value_type, allocator_type>								Node;
	public:
		const_reverse_mapIterator() : _index(NULL) {};
		const_reverse_mapIterator(Node * rhs) : _index(rhs){}
		const_reverse_mapIterator(const const_reverse_mapIterator & rhs){
			*this = rhs;
		};

		const_reverse_mapIterator & operator=(const const_reverse_mapIterator & rhs) {
			if (this != &rhs){
				_index = rhs._index;
			}
			return *this;
		}
		bool operator!=(const const_reverse_mapIterator & rhs){
			return _index != rhs._index;
		}
		bool operator==(const const_reverse_mapIterator & rhs){
			return _index == rhs._index;
		}
		_reference operator*(){
			return *(_index->_data);
		}
		_pointer operator->(){
			return _index->_data;
		}
		Node * getTreeNode(){
			return _index;
		}

		virtual ~const_reverse_mapIterator(){}

		const_reverse_mapIterator operator++() {
			Node * tmp;
			if (_index->_right){
				if (_index->_right == _index->_right->_right){
					return _index = _index->_right;
				}
				return _index = minimumNode(_index->_right);
			}
			tmp = _index->_parent;
			while (tmp && _index == tmp->_right){
				_index = tmp;
				tmp = tmp->_parent;
			}
			_index = tmp;
			return _index;
		}

//			mapIterator operator--() {
//				Node * x = _index;
//				Node * tmp;
//				if (!x->_left){
//					return mapIterator(maximumNode(x->_left));
//				}
//				tmp = x->_parent;
//				while (tmp && x == tmp->_left){
//					x = tmp;
//					tmp = tmp->_parent;
//				}
//				return mapIterator(tmp);
//			}

		Node * minimumNode(const_reverse_mapIterator node){
			if (!node.getTreeNode()->_left){
				return node.getTreeNode();
			}
			return minimumNode(node.getTreeNode()->_left);
		}
		Node * maximumNode(const_reverse_mapIterator node){
			if (!node.getTreeNode()->_right) {
				return node.getTreeNode()->_parent;
			}
			return maximumNode(node.getTreeNode()->_right);
		}

	private:
		Node * _index;
	};
}