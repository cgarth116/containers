#include <memory>
#include <iostream>
#include <type_traits>
#include <stdexcept>
#include "mapIterator.hpp"
#include <list>

namespace ft
{

	template <class Key,                                   // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<std::pair<const Key,T> > >   // map::allocator_type
	class map
	{

		public:
			typedef Alloc														allocator_type;
			typedef std::pair< const Key, T >									value_type;
			typedef ft::Node<value_type, allocator_type>						Node;
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef Compare														key_compare;
			class value_compare;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef std::ptrdiff_t												difference_type;
			typedef std::size_t													size_type;
			typedef ft::mapIterator<value_type, allocator_type>					iterator;
			typedef ft::const_mapIterator<value_type, allocator_type>			const_iterator;
			typedef ft::reverse_mapIterator<value_type, allocator_type>			reverse_iterator;
			typedef ft::const_reverse_mapIterator<value_type, allocator_type>	const_reverse_iterator;
			typedef typename allocator_type::template rebind<Node>::other		alloc_rebind;
			static const bool	_black	= true;
			static const bool	_red	= false;
			//Constructors
			explicit map (const key_compare& comp = key_compare(),
				 		const allocator_type& alloc = allocator_type()):
						_allocator(alloc), _keyCompare(comp), _valueCompare(comp){
				_buffer = alloc_rebind(alloc).allocate(1);
				alloc_rebind(alloc).construct(_buffer);

				//создаем first ноду
				_firstNode = alloc_rebind(alloc).allocate(1);
				alloc_rebind(alloc).construct(_firstNode);
				_firstNode->_right = _firstNode;
				_firstNode->_left = _firstNode;
				_firstNode->_parent = _endNode;
				//создаем end ноду
				_endNode = alloc_rebind(alloc).allocate(1);
				alloc_rebind(alloc).construct(_endNode);
				_endNode->_right = _endNode;
				_endNode->_left = _endNode;
				_sizeMap = 0;
			}
			template <class InputIterator>
			map (InputIterator first,
				InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type(),
				typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) :map(){
//				_allocator = alloc;
//				_compare = comp;
//
//				_buffer = alloc_rebind(_allocator).allocate(1);
//				alloc_rebind(_allocator).construct(_buffer);
//				//создаем first ноду
//				_firstNode = alloc_rebind(_allocator).allocate(1);
//				alloc_rebind(_allocator).construct(_firstNode);
//				_firstNode->_right = _firstNode;
//				_firstNode->_left = _firstNode;
//				_firstNode->_parent = _endNode;
//				//создаем end ноду
//				_endNode = alloc_rebind(_allocator).allocate(1);
//				alloc_rebind(_allocator).construct(_endNode);
//				_endNode->_right = _endNode;
//				_endNode->_left = _endNode;
//				_sizeMap = 0;

				while (first != last){
					insertNode(*(first.getTreeNode())->_data,_keyCompare,_allocator);
					++first;
				}
			}
			map (const map& rhs):
					_allocator(rhs._allocator), _keyCompare(rhs._keyCompare), _valueCompare(rhs._valueCompare){
				_buffer = alloc_rebind(_allocator).allocate(1);
				alloc_rebind(_allocator).construct(_buffer);
				//создаем first ноду
				_firstNode = alloc_rebind(_allocator).allocate(1);
				alloc_rebind(_allocator).construct(_firstNode);
				_firstNode->_right = _firstNode;
				_firstNode->_left = _firstNode;
				_firstNode->_parent = _endNode;
				//создаем end ноду
				_endNode = alloc_rebind(_allocator).allocate(1);
				alloc_rebind(_allocator).construct(_endNode);
				_endNode->_right = _endNode;
				_endNode->_left = _endNode;
				_sizeMap = 0;

				*this = rhs;
			}

			map& operator=(const map& rhs){
				if (this == &rhs){
					return *this;
				}
				//todo clear();
				//clear();
				if (rhs.size() != 0){
					const_iterator it = rhs.begin();
					const_iterator ite = rhs.end();
					while (it != ite){
						insert(*(it.getTreeNode()->_data));
						++it;
					}
				}
				return *this;
			}

			mapped_type & operator[](const key_type & key) {
				return ((insert(std::make_pair(key, mapped_type()))).first)->second;
			}

			//Iterators:
			iterator begin(){
				return iterator(_firstNode->_parent);
			}
			const_iterator begin() const{
				return const_iterator(_firstNode->_parent);
			}
			reverse_iterator rbegin (){
				return reverse_iterator(_endNode->_parent);
			}
			const_reverse_iterator rbegin () const{
				return const_reverse_iteator(_endNode->_parent);
			}
			iterator end(){
				return iterator(_endNode);
			}
			const_iterator end() const{
				return const_iterator(_endNode);
			}
			reverse_iterator rend(){
				return reverse_iterator(_firstNode);
			}
			const_reverse_iterator rend() const{
				return const_reverse_iterator(_firstNode);
			}

			//Capacity:
			bool empty() const{
				return _endNode->_parent == NULL;
			}
			size_type size() const{
				return _sizeMap;
			}
			size_type max_size() const{
				return std::numeric_limits<size_t>::max() / (sizeof(Node) + sizeof(*(_buffer->_data)) );
			}

			//Modifiers
			std::pair<iterator,bool> insert (const value_type& value){
				return tryInsertNode(_buffer, value);
			}
			iterator insert (iterator position,
							const value_type& value){
				return tryInsertNode(position, value).first;
			}
			template <class InputIterator>
			void insert (InputIterator first,
						InputIterator last,
						typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
				while(first != last){
					tryInsertNode(_buffer, *first);
					++first;
				}
			}

			void erase (iterator position){
				erase((*position).first);
			}
			size_type erase (const key_type& k){
				//todo
			}
			void erase (iterator first,
			   			iterator last){
				while (first != last) {
					erase((*(first++)).first);
				}
			}
			void clear(){
				erase(begin(), end());
			}

			//Observers
			key_compare key_comp() const{
				return _keyCompare;
			}
			value_compare value_comp() const{
				return _valueCompare;
			}

			//Operations
			iterator find (const key_type& key){
				return iterator(search(_buffer, key));
			}
			const_iterator find (const key_type& key) const{
				return const_iterator(search(_buffer, key));
			}
			size_type count (const key_type & key) const{
				if (search(_buffer, key) != end().getTreeNode())
					return 1;
				return 0;
			}
			iterator lower_bound (const key_type& key){
				iterator it = begin();
				iterator ite = end();
				while (it != ite && _keyCompare(it->first, key)){
					++it;
				}
				return it;
			}
			const_iterator lower_bound (const key_type& key) const{
				const_iterator it = begin();
				const_iterator ite = end();
				while (it != ite && _keyCompare(it->first, key)){
					++it;
				}
				return it;
			}
			iterator upper_bound (const key_type& key){
				iterator it = lower_bound(key);
				iterator ite = end();
				while(it != ite && !_keyCompare(key, it->first)){
					++it;
				}
				return it;
			}
			const_iterator upper_bound (const key_type& key) const{
				const_iterator it = lower_bound(key);
				const_iterator ite = end();
				while(it != ite && !_keyCompare(key, it->first)){
					++it;
				}
				return it;
			}
			std::pair<const_iterator,const_iterator> equal_range (const key_type& key) const{
				return std::make_pair(lower_bound(key), upper_bound(key));
			}
			std::pair<iterator,iterator> equal_range (const key_type& key){
				return std::make_pair(lower_bound(key), upper_bound(key));
			}

// section test
		void viewAllNode(iterator node) {
			if (node.getTreeNode()) {
				viewAllNode(node.getTreeNode()->_left);
				std::cout << (*node).first << " ";
				viewAllNode(node.getTreeNode()->_right);
			}
		}

//		Node * minimumNode(iterator node){
//			if (!node.getTreeNode()->_left){
//				return node.getTreeNode();
//			}
//			return minimumNode(node.getTreeNode()->_left);
//			}
//		Node * maximumNode(iterator node){
//			if (!node.getTreeNode()->_right) {
//				return node.getTreeNode();
//			}
//			return maximumNode(node.getTreeNode()->_right);
//		}

		void viewTree() {
				Node * tmp = _buffer;
				std::list<Node *> q;
				std::list<Node *> qTmp;
			std::cout << tmp->_data->first << "(" << tmp->_color << ")" << std::endl;
			q.push_back(tmp->_left);
			q.push_back(tmp->_right);

			while (q.size() != 0) {
				qTmp.clear();
				while (q.size() != 0) {
					tmp = q.front();
					q.pop_front();
					if (tmp == nullptr ||
						tmp == _firstNode ||
						tmp == _endNode){
						std::cout << "()";
					} else {
						std::cout << tmp->_data->first << "(" << tmp->_color << ")father=" << tmp->_parent->_data->first;
					}
					if (tmp->_left != nullptr &&
						tmp != _firstNode &&
						tmp != _endNode) {
						qTmp.push_back(tmp->_left);
					}
					if (tmp->_right != nullptr && tmp != _firstNode && tmp != _endNode) {
						qTmp.push_back(tmp->_right);
					}
				}
				std::cout << "\n" << std::endl;
				q.assign(qTmp.begin(),qTmp.end());
			}
		}

		private:
			//Basic operations with our Node
			std::pair<iterator,bool> tryInsertNode(iterator position,
										  			const value_type& value){
				Node * newNode = alloc_rebind(_allocator).allocate(1);
				alloc_rebind(_allocator).construct(newNode);
				newNode->insertNode(value);//создаем полностью ноду с ключом
				if (_endNode->_parent == NULL) {
					_buffer = newNode; // корневая нода
					_buffer->_left = _firstNode;
					_buffer->_right = _endNode;
					_buffer->_color = _black;
					_firstNode->_parent = _buffer; //досоздаем first ноду
					_endNode->_parent = _buffer; //досоздаем end ноду
					++_sizeMap;
					return std::make_pair(_buffer ,true);
				} else {
					Node * tmp = insertOneNode(position.getTreeNode(), newNode); //пробуем вставить ноду в дерево
					if (newNode == tmp){
						return std::make_pair(newNode, true);
					}
					_allocator.destroy(newNode->_data);//элемент существует поэтому уничтожаем ноду
					alloc_rebind(_allocator).destroy(newNode);
					return std::make_pair(tmp, false);
				}
			}
			Node * insertOneNode(Node * x,
								Node * z) {           // x — корень поддерева, z — вставляемый элемент
				while (x != nullptr) {
					if (z->_data->first != x->_data->first) {
						if (z->_data->first > x->_data->first) {
							if (x->_right != nullptr && x->_right != _endNode) {
								x = x->_right;
							} else {
								if (x->_right == _endNode) {
									x->_right = z;
									z->_parent = x;
									z->_right = _endNode;
									_endNode->_parent = z;
								} else {
									z->_parent = x;
									x->_right = z;
								}
								break;
							}
						} else {
							if (z->_data->first < x->_data->first) {
								if (x->_left != nullptr && x->_left != _firstNode) {
									x = x->_left;
								} else {
									if (x->_left == _firstNode) {
										x->_left = z;
										z->_parent = x;
										z->_left = _firstNode;
										_firstNode->_parent = z;
									} else {
										z->_parent = x;
										x->_left = z;
									}
									break;
								}
							}
						}
					} else {
						return x;
					}
				}
				++_sizeMap;
				fixColor(z);
				return z;
			}
			void fixColor(Node * node){
				Node * uncle;
				while (node->_parent && node->_parent->_color == _red ) { //"отец" красный нарушается свойство 3
					if (node->_parent->_parent->_left == node->_parent) { //"отец" — левый ребенок
						uncle = node->_parent->_parent->_right;
						if (uncle && uncle != _endNode && uncle->_color == _red) { //есть красный "дядя"
								node->_parent->_color = _black;
								uncle->_color = _black;
								node->_parent->_parent->_color = _red;
								node = node->_parent->_parent;
						} else { // случай, когда нет "дяди" или он черный
							if (node->_parent->_right == node) { // node — правый сын
								node = node->_parent;
								leftRotate(node);
							}
							node->_parent->_color = _black;
							node->_parent->_parent->_color = _red;
							rightRotate(node->_parent->_parent);
						}
					} else { // "отец" — правый ребенок
						uncle = node->_parent->_parent->_left;
						if (uncle && uncle != _endNode && uncle->_color == _red) { //есть красный "дядя"
							node->_parent->_color = _black;
							uncle->_color = _black;
							node->_parent->_parent->_color = _red;
							node = node->_parent->_parent;
						} else { // случай, когда нет "дяди" или он черный
							if (node->_parent->_left == node) { // node — левый сын
								node = node->_parent;
								rightRotate(node);
							}
							node->_parent->_color = _black;
							node->_parent->_parent->_color = _red;
							leftRotate(node->_parent->_parent);
						}
					}
				}
				_buffer->_color = _black;// восстанавливаем свойство корня
			}
			void leftRotate(Node * node){
				Node *tmp = node->_right;

				tmp->_parent = node->_parent; /* при этом, возможно, tmp становится корнем дерева */
				if (tmp->_parent == NULL){
					_buffer = tmp;
				}
				if (node->_parent != NULL) {
					if (node->_parent->_left==node)
						node->_parent->_left = tmp;
					else
						node->_parent->_right = tmp;
				}

				node->_right = tmp->_left;
				if (tmp->_left != NULL)
					tmp->_left->_parent = node;

				node->_parent = tmp;
				tmp->_left = node;
			}
			void rightRotate(Node *node){
				Node *tmp = node->_left;

				tmp->_parent = node->_parent; /* при этом, возможно, tmp становится корнем дерева */
				if (tmp->_parent == NULL){
					_buffer = tmp;
				}
				if (node->_parent != NULL) {
					if (node->_parent->_left==node)
						node->_parent->_left = tmp;
					else
						node->_parent->_right = tmp;
				}

				node->_left = tmp->_right;
				if (tmp->_right != NULL)
					tmp->_right->_parent = node;

				node->_parent = tmp;
				tmp->_right = node;
			}

			Node * search(Node * x,
						  const key_type& key) {
				if (key == x->_data->first) {
					return x;
				}
				if (x == nullptr ||
						x == end().getTreeNode() ||
						x == begin().getTreeNode()){
					return end().getTreeNode();
				}
				if (key < x->_data->first) {
					return search(x->_left, key);
				} else {
					return search(x->_right, key);
				}
			}
			Node * search(Node * x,
					 	 const key_type& key)const {
			if (key == x->_data->first) {
				return x;
			}
			if (x == nullptr ||
				x == end().getTreeNode() ||
				x == begin().getTreeNode()){
				return end().getTreeNode();
			}
			if (key < x->_data->first) {
				return search(x->_left, key);
			} else {
				return search(x->_right, key);
			}
		}

			allocator_type	_allocator;
			key_compare		_keyCompare;
			value_compare	_valueCompare;
			Node * 			_buffer;
			Node *			_firstNode;
			Node *			_endNode;
			size_t 			_sizeMap;
	};

	template <class Key, class T, class Compare, class Alloc>
	class map<Key,T,Compare,Alloc>::value_compare
									: public std::binary_function<value_type,value_type,bool>{
	protected:
		Compare comp;
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		bool operator() (const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	};
}