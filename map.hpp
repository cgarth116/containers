#include <memory>
#include <iostream>
#include <type_traits>
#include <stdexcept>
#include "mapIterator.hpp"

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

			//Constructors
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){

				_allocator = alloc;
				_compare = comp;
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
			map (InputIterator first, InputIterator last,
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
					insertNode(*(first.getTreeNode())->_data,_compare,_allocator);
					++first;
				}
			}
			map (const map& rhs){
				_allocator = rhs._allocator;
				_compare = rhs._compare;

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
			iterator insert (iterator position, const value_type& value){
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


			Node search(Node * x, key_type k) {
				if (x == nullptr || k == x->_data.first) {
					return x;
				}
				if (k < x->_data.first) {
					return search(x->_left, k);
				} else {
					return search(x->_right, k);
				}
			}

			void deleteTree(Node **root) {
				if (*root) {
					deleteTree(&((*root)->left));
					deleteTree(&((*root)->right));
					_allocator.destroy(*root);
				}
		}
//			std::pair<iterator,bool> insert (const value_type& val){
//				if (!_buffer->_parent){
//
//				}
//			}
//
//			iterator insert (iterator position, const value_type& val){
//
//			}
//
//			template <class InputIterator>
//			void insert (InputIterator first, InputIterator last){
//
//			}




// section test
		void viewAllNode(iterator node) {
			if (node.getTreeNode()) {
				viewAllNode(node.getTreeNode()->_left);
				std::cout << (*node).first << " ";
				viewAllNode(node.getTreeNode()->_right);
			}
		}

		Node * minimumNode(iterator node){
			if (!node.getTreeNode()->_left){
				return node.getTreeNode();
			}
			return minimumNode(node.getTreeNode()->_left);
			}
		Node * maximumNode(iterator node){
			if (!node.getTreeNode()->_right) {
				return node.getTreeNode();
			}
			return maximumNode(node.getTreeNode()->_right);
		}


		private:

			std::pair<iterator,bool> tryInsertNode(iterator position, const value_type& value){
			Node * newNode = alloc_rebind(_allocator).allocate(1);
			alloc_rebind(_allocator).construct(newNode);
			newNode->insertNode(value);//создаем полностью ноду с ключом
			if (_endNode->_parent == NULL) {
				_buffer = newNode; // корневая нода
				_buffer->_left = _firstNode;
				_buffer->_right = _endNode;
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

			Node * insertOneNode(Node * x, Node * z) {           // x — корень поддерева, z — вставляемый элемент
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
			return z;
		}


			allocator_type	_allocator;
			key_compare		_compare;
			Node * 			_buffer;
			Node *			_firstNode;
			Node *			_endNode;
			size_t 			_sizeMap;
	};
}