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
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef std::pair< const Key, T >					value_type;
			typedef Compare										key_compare;
			class value_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;

			explicit map (const key_compare& comp = key_compare(),
					 	 const allocator_type& alloc = allocator_type()){
				_allocator = alloc;
				_compare = comp;
				_node = alloc.allocate(1);
			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
			 	const allocator_type& alloc = allocator_type()){
				_allocator = alloc;
			}
			map (const map& x){

			}


		private:

			allocator_type	_allocator;
			key_compare		_compare;
			Node * 			_node;
	};
}