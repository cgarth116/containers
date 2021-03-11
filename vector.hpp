#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stdexcept>
#include "vectorIterator.hpp"

namespace ft
{
	template <class T>
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

			explicit vector (const allocator_type& alloc = allocator_type()){
				_size = 0;
				_capasity = 0;
				_buffer = new T[_size];
			}
			explicit vector (size_t n,
							const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()){
				_size = n;
				_capasity = n;
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
				_capasity = _size;
				_buffer = new T[_size];
				while (first != last){
					_buffer[i++] = *first;
					++first;
				}
			}
			vector (const vector& x){
				size_t i = 0;
				_size = x.size();
				_capasity = x.capacity();
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
					return iterator(_buffer + _size - 1);
				}
				return iterator(_buffer);
			}
			const_reverse_iterator rbegin() const{
				if (_size > 0) {
					return const_iterator(_buffer + _size - 1);
				}
				return const_iterator(_buffer);
			}

			size_t size() const{
				return _size;
			}
			size_t max_size() const{
				return std::numeric_limits<size_t>::max() / sizeof(T);
			}
			void resize (size_t n, value_type val = value_type()){
				if (_size < n) {
					insert(_size, n - _size, val);
				}
				else{
					erase(n, _size);
				}
			}
			size_t capacity() const{
				return std::numeric_limits<size_t>::max() / sizeof(_buffer[0]);
			}
			bool empty() const{
				return _size == 0;
			}
			void reserve (size_t n){
				if (_capasity < n){
					//todo change _capadity
					_capasity = n;
				}
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
				if (_size == _capasity) {
					//todo change _capasity
				}
				insert(end(), val);
			}
			void pop_back(){
				if (_size != 0){
					delete _buffer[_size - 1];
					_size--;
				}
			}
			iterator insert (iterator position,
							const value_type& val){
				if (_size == _capasity) {
					//todo change _capasity
				}
				iterator it = end();
				iterator tmp;
				while (it != position){
					tmp = it;
					*it = *(--tmp);
					--it;
				}
				*it = val;
				_size++;
				return it;
			}
			void insert (iterator position,
						size_t n,
						const value_type& val) {
				if (_size == _capasity) {
					//todo change _capasity
				}
				iterator it = end() - 1;
				while (it != position){
					_buffer[it + n] = _buffer[it];
					_buffer[it] = val;
					_size++;
					--it;
				}
			}

			template <class InputIterator>
			void insert (iterator position,
						InputIterator first,
						InputIterator last){
				if (_size == _capasity) {
					//todo change _capasity
				}
				size_t n = last - first;
				iterator it = end() - 1;
				while (it != position){
					_buffer[it + n] = _buffer[it];
					_buffer[it] = *last;
					_size++;
					--it;
					--last;
				}
			}
			iterator erase (iterator position){
				if (_size != 0) {
					iterator it = end() - 1;
					iterator res = position;
					while (position != it) {
						_buffer[position] = _buffer[position + 1];
						++position;
					}
					--_size;
					delete _buffer[it];
					return res;
				}
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
				delete [] _buffer;
			}


		private:
			size_t	_size;
			size_t	_capasity;
			T *		_buffer;
	};
}

#endif