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
				std::cout << _buffer->_data->first << std::endl;
				std::cout << _buffer->_data->second << std::endl;
			};
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				 const allocator_type& alloc = allocator_type()){
				_buffer = alloc_rebind(alloc).allocate(1);
			};
			map (const map& x){

			};

			map& operator= (const map& rhs){
				if (*this == rhs){
					return (*this);
				}
				//clear();
				insert(rhs.begin(), rhs.end());
				return *this;
			}

			mapped_type & operator[](const key_type & key) {
				return (*((this->insert(
						std::make_pair(key,mapped_type()) )).first)).second;
			}


			Node begin(){
				//if (!_node->_left) {
					return _buffer;
				//}
			//
			};

			iterator end(){
				//if (!_node->_right) {
					return _buffer;
				//}
				//return maximum(_node->_right);
			};

		//вставка ноды
		template < typename value_type , typename allocator_type>
		Node insert(Node & node, value_type & value){      // node — корень поддерева, value — вставляемый ключ
			if (!node){
				return Node(value);                        // подвесим Node с value
			} else {
				if (value < node.key) {
					node.left = insert(node.left, value);
				} else {
					if (value > node.key) {
						node.right = insert(node.right, value);
					}
				}
			}
			return node;
		};

		private:

			allocator_type	_allocator;
			key_compare		_compare;
			Node * 			_buffer;
	};
}