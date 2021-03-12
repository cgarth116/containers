#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <stdexcept>
#include "vectorIterator.hpp"
#include "memVector.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		typedef T   value_type;

		public:

			typedef ft::iterator<T>  				iterator;
			typedef ft::const_iterator<T>  			const_iterator;
			typedef ft::reverse_iterator<T>			reverse_iterator;
			typedef ft::const_reverse_iterator<T>	const_reverse_iterator;
			typedef std::allocator<value_type>		allocator_type;
			typedef value_type						reference;
			typedef const value_type				const_reference;
			typedef memVector<T,
							allocator_type,
							size_t >				memVector;
			typedef std::ptrdiff_t					difference_type;

			explicit vector (const allocator_type& alloc = allocator_type()){
				_size = 0;
				_capacity = 1;
				_buffer = new T[_size];
			}
			explicit vector (size_t n,
							const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()){
				_size = n;
				_capacity = 1;
				if (n != 0) {
					_capacity = n;
				}
				_buffer = new T[_size];
				while (n != 0){
					_buffer[--n] = val;
				}
			}
			template <class InputIterator>
			vector (InputIterator first,
		   			InputIterator last,
		   			const allocator_type& alloc = allocator_type()){
				size_t i = 0;
				_size = last - first;
				_capacity = _size;
				_buffer = new T[_size];
				while (first != last){
					_buffer[i++] = *first;
					++first;
				}
			}
			vector (const vector& x){
				size_t i = 0;
				_size = x.size();
				_capacity = x.capacity();
				_buffer = new T[_size];
				while (i != _size){
					_buffer[i] = x[i];
					++i;
				}
			}

			iterator begin(){
				return iterator(_buffer);
			}
			const_iterator begin() const{
				return const_iterator(_buffer);
			}
			iterator end(){
				return iterator(_buffer + _size);
			}
			const_iterator end() const{
				return const_iterator(_buffer + _size);
			}
			reverse_iterator rbegin(){
				if (_size > 0){
					return reverse_iterator(_buffer + _size - 1);
				}
				return reverse_iterator(_buffer);
			}
			const_reverse_iterator rbegin() const{
				if (_size > 0) {
					return const_reverse_iterator(_buffer + _size - 1);
				}
				return const_reverse_iterator(_buffer);
			}
			reverse_iterator rend(){
				return reverse_iterator(_buffer - 1);
			}
			const_reverse_iterator rend() const{
				return const_reverse_iterator(_buffer - 1);
			}

			size_t size() const{
				return _size;
			}
			size_t max_size() const{
				return allocator_type().max_size();
			}
			void resize (size_t n, value_type val = value_type()){
				if (_size == n){
					return;
				}
				if (n > _capacity){
					reserve(n);
				}
				if (_size < n) {
					insert(_buffer + _size, n - _size, val);
				}
				else{
					erase(_buffer + n);
				}
			}
			size_t capacity() const{
				return _capacity;
			}
			bool empty() const{
				return _size == 0;
			}
			void reserve (size_t n){
				if (_capacity < n){
					_buffer = memVector::realloc(_buffer, _size, _capacity, n, allocator);
				}
				_capacity = n;
			}

			reference operator[] (size_t n){
				return _buffer[n];
			}
			const_reference operator[] (size_t n) const{
				return _buffer[n];
			}
			reference at (size_t n){
				if (n > _size){
					throw std::out_of_range("");
				}
				return reference(_buffer[n]);
			}
			const_reference at (size_t n) const{
				if (n > _size){
					throw std::out_of_range("");
				}
				return const_reference(_buffer[n]);
			}

			reference front(){
				if (_size != 0) {
					return reference(_buffer[0]);
				}
				return 0;
			}
			const_reference front() const{
				if (_size != 0) {
					return const_reference(_buffer[0]);
				}
				return 0;
			}
			reference back(){
				if (_size != 0) {
					return reference(_buffer[_size - 1]);
				}
				return 0;
			}
			const_reference back() const{
				if (_size != 0) {
					return const_reference(_buffer[_size - 1]);
				}
				return 0;
			}

			template <class InputIterator>
			void assign (InputIterator first,
						InputIterator last,
						 typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
				if (_size != 0)
					clear();
				while (first != last){
					push_back(*first);
					first++;
				}
			}
			void assign (size_t n,
						const value_type& val){
				if (_size != 0){
					clear();
				}
				while (n > 0){
					push_back(val);
					n--;
				}
			}
			void push_back (const value_type& val){
				if (_size == _capacity) {
					reserve(_capacity * 2);
				}
				allocator.construct(_buffer + _size, val);
				++_size;
				//insert(end(), val);
			}
			void pop_back(){
				if (_size != 0){
					allocator.destroy(_buffer + _size - 1);
					_size--;
				}
			}
			iterator insert (iterator position,
							const value_type& val){
				value_type * const		pos		= position.operator->();
				const difference_type	delta	= pos - _buffer;

				if (_size == _capacity) {
					reserve(_capacity * 2);
				}
				std::memmove(_buffer + delta + 1,
							_buffer + delta,
							(_size - delta) * sizeof(value_type));
				allocator.construct(_buffer + delta, val);
				_size++;
				return iterator(_buffer + delta);
			}
			void insert (iterator position,
						size_t n,
						const value_type& val) {
				value_type * const		pos		= position.operator->();
				const difference_type	delta	= pos - _buffer;

				if (_size + n > _capacity) {
					reserve(_size + n);
				}
				std::memmove(_buffer + delta + n,
						_buffer + delta,
						(_size - delta) * sizeof(value_type)
				);
				for (size_t i = 0; i < n; ++i) {
					allocator.construct(_buffer + delta + i, val);
				}
				_size += n;
			}

			template <class InputIterator>
			void insert (iterator position,
						InputIterator first,
						InputIterator last,
						 typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
				while (first != last){
					position = insert(position, *(first++)) + 1;
				}
			}
			iterator erase (iterator position){
				if (_size != 0) {
					iterator it = end() - 1;
					iterator res = position;
					while (position != it) {
						*position = *(position + 1);
						++position;
					}
					--_size;
					//todo delete position
					//delete it;
					return res;
				}
				return _buffer;
			}
			iterator erase (iterator first, iterator last){
				if (_size != 0) {
					iterator res = last - first;
					while (first != last) {
						_buffer[first] = _buffer[first + res];
						delete _buffer[first + res];
						++first;
						--_size;
					}
					return last - res;
				}
			}
			void clear(){
				iterator it = begin();
				iterator ite = end();
				while (it != ite){
					*(it++) = 0;
				}
				_size = 0;
			}

			~vector(){
				delete [] _buffer;
			}

		private:
			size_t			_size;
			size_t			_capacity;
			T *				_buffer;
			allocator_type	allocator;
	};
}

#endif