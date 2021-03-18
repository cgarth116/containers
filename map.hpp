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
			typedef Alloc										allocator_type;
			typedef std::pair< const Key, T >					value_type;
			typedef ft::Node<value_type, allocator_type>		Node;
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef Compare										key_compare;
			class value_compare;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;
			typedef ft::mapIterator<value_type, allocator_type>	iterator;
			typedef typename allocator_type::template rebind<Node>::other		alloc_rebind;

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
				_buffer = alloc_rebind(alloc).allocate(1);
				alloc_rebind(alloc).construct(_buffer);
				_compare = comp;
			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				 const allocator_type& alloc = allocator_type()){
				_buffer = alloc_rebind(alloc).allocate(1);
			}
			map (const map& x){

			}

			map& operator=(const map& rhs){
				//todo корректно проверить можно на viewAll(firstOur);
				if (*this == rhs){
					return (*this);
				}
				//clear();
				//insert(rhs.begin(), rhs.end());
				return *this;
			}

			mapped_type & operator[](const key_type & key) {
				return insertNode(std::make_pair(key,mapped_type()))->second;
				//return _buffer->insertNode(std::make_pair(key,mapped_type()))->second;
			}


			iterator begin(){
				return iterator(minimumNode(_buffer));

				return iterator(_buffer);
			}

			iterator end(){
				return iterator((maximumNode(_buffer)));
				//return iterator(_buffer);
			}

			value_type * insertNode(value_type value,
						   			const key_compare& comp = key_compare(),
						   			const allocator_type& alloc = allocator_type()){
//				if (!search(_buffer, value.first)){
//					return;
//				}
				Node * newNode = alloc_rebind(alloc).allocate(1);
				alloc_rebind(alloc).construct(newNode);
				newNode->insertNode(value);//создаем полностью ноду с ключом
				insert(_buffer, newNode);//вставляем ноду в дерево
				if (_buffer->_parent == NULL) {
					_buffer = newNode; // корневая нода
				}
				return newNode->_data;
			}

			void insert(Node * x, Node * z) {           // x — корень поддерева, z — вставляемый элемент
				while (x != nullptr) {
					if (z->_data->first > x->_data->first) {
						if (x->_right != nullptr) {
							x = x->_right;
						} else {
							z->_parent = x;
							x->_right = z;
							break;
						}
					} else {
						if (z->_data->first < x->_data->first) {
							if (x->_left != nullptr) {
								x = x->_left;
							} else {
								z->_parent = x;
								x->_left = z;
								break;
							}
						}
					}
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

			allocator_type	_allocator;
			key_compare		_compare;
			Node * 			_buffer;
	};
}