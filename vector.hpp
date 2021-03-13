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
		public:
			typedef T   							value_type;
			typedef ft::vectorIterator<T>  				iterator;
			typedef ft::const_vectorIterator<T>  			const_iterator;
			typedef ft::reverse_vectorIterator<T>			reverse_iterator;
			typedef ft::const_reverse_vectorIterator<T>	const_reverse_iterator;
			typedef Alloc							allocator_type;
			typedef typename Alloc::reference		reference;
			typedef typename Alloc::const_reference	const_reference;
			typedef typename Alloc::pointer			pointer;
			typedef typename Alloc::const_pointer	const_pointer;
			typedef memVector<T,
							allocator_type,
							size_t >				memVector;
			typedef std::ptrdiff_t					difference_type;
			typedef std::size_t 					size_type;

			explicit vector (const allocator_type& alloc = allocator_type()){
				_size = 0;
				_capacity = 1;
				_allocator = alloc;
				_buffer = _allocator.allocate(_capacity);
			}
			explicit vector (size_t n,
							const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()){
				_size = n;
				_capacity = 1;
				if (n != 0) {
					_capacity = n;
				}
				_allocator = alloc;
				_buffer = _allocator.allocate(_capacity);
				while (n != 0){
					_allocator.construct(_buffer + n--, val);
				}
			}
			template <class InputIterator>
			vector (InputIterator first,
		   			InputIterator last,
		   			const allocator_type& alloc = allocator_type(),
					typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
				size_t n = 0;
				_size = 0;
				_capacity = 1;
				_allocator = alloc;

				_buffer = _allocator.allocate(_capacity);
				while (first != last){
					_allocator.construct(_buffer + n++, *first++);
				}
			}
			vector (const vector& x){
				_buffer = nullptr;
				*this = x;
			}

			vector & operator=(const vector & x) {
				if (this != &x) {
					if (_buffer) {
						memVector::deleteAll(_buffer, _size, _capacity, _allocator);
					}
					_allocator = x._allocator;
					_capacity = x.capacity();
					_size = x.size();
					_buffer = _allocator.allocate(_capacity);
					for (size_t i = 0; i < _size; ++i) {
						_allocator.construct(_buffer + i, *(x._buffer + i));
					}
				}
				return *this;
			}

			reference operator[](size_t n)
			{
				return *(_buffer + n);
			}
			const_reference operator[](size_t n) const {
				return *(_buffer + n);
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
			void resize (size_t n,
						value_type val = value_type()){
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
					_buffer = memVector::realloc(_buffer, _size, _capacity, n, _allocator);
				}
				_capacity = n;
			}

			reference at (size_t n) throw(std::out_of_range){
				if (n >= _size){
					throw std::out_of_range("Out of range!");
				}
				return operator[](n);
			}
			const_reference at (size_t n) const throw(std::out_of_range){
				if (n >= _size){
					throw std::out_of_range("Out of range!");
				}
				return operator[](n);
			}

			reference front(){
					return *_buffer;
			}
			const_reference front() const{
					return *_buffer;
			}
			reference back(){
				if (_size != 0) {
					return *(_buffer + _size - 1);
				}
				return *_buffer;
			}
			const_reference back() const{
				if (_size != 0) {
					return *(_buffer + _size - 1);
				}
				return *_buffer;
			}

			template <class InputIterator>
			void assign (InputIterator first,
						InputIterator last,
						typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
				clear();
				while (first != last){
					push_back(*first);
					first++;
				}
			}
			void assign (size_t n,
						const value_type& val){
				clear();
				reserve(n);
				while (n > 0){
					push_back(val);
					n--;
				}
			}
			void push_back (const value_type& val){
				if (_size == _capacity) {
					reserve(_capacity * 2);
				}
				_allocator.construct(_buffer + _size, val);
				++_size;
			}
			void pop_back(){
				if (_size != 0){
					_allocator.destroy(_buffer + _size - 1);
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
				_allocator.construct(_buffer + delta, val);
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
					_allocator.construct(_buffer + delta + i, val);
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
				value_type * const		positionE = position.operator->();
				const difference_type	delta = positionE - _buffer;

				_allocator.destroy(positionE);
				std::memmove(_buffer + delta,
							_buffer + delta + 1,
							(_size - delta) * sizeof(value_type)
				);
				--_size;
				return iterator(_buffer + delta);
			}
			iterator erase (iterator first, iterator last){
				value_type * const		firstE = first.operator->();
				value_type * const		lastE	= last.operator->();
				const difference_type	delta = firstE - _buffer;
				const difference_type	size = lastE - firstE;

				memVector::destruct(firstE, lastE, _allocator);
				std::memmove(_buffer + delta,
							_buffer + delta + size,
							(_size - delta - size) * sizeof(value_type)
				);
				_size -= size;
				return iterator(_buffer + delta);
			}
			void clear(){
				while (_size != 0){
					pop_back();
				}
			}
			void swap (vector& x){
				if (x == *this)
					return;

				size_type tmp_size = x._size;
				size_type tmp_capacity = x._capacity;
				allocator_type tmp_allocator = x._allocator;
				value_type * tmp_buffer = x._buffer;

				x._size = this->_size;
				x._capacity = this->_capacity;
				x._buffer = this->_buffer;
				x._allocator = this->_allocator;

				this->_size = tmp_size;
				this->_capacity = tmp_capacity;
				this->_buffer = tmp_buffer;
				this->_allocator = tmp_allocator;
			}

			allocator_type get_allocator() const{
				return _allocator;
			}

			~vector(){
				memVector::deleteAll(_buffer, _size, _capacity, _allocator);
			}

		private:
			size_t			_size;
			size_t			_capacity;
			value_type *	_buffer;
			allocator_type	_allocator;
	};

	template < class T, class Alloc >
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc> & rhs) {
		typedef typename vector<T, Alloc>::const_iterator _iter;

		if (lhs.size() != rhs.size()) {
			return false;
		}
		_iter	lIt		= lhs.begin();
		_iter	lIte	= lhs.end();
		_iter	rIt		= rhs.begin();
		_iter	rIte	= rhs.end();
		while (lIt != lIte && rIt != rIte) {
			if (!(*lIt == *rIt)) {
				return false;
			}
			++rIt;
			++lIt;
		}
		return (lIt == lIte && rIt == rIte);
	}

	template < class T, class Alloc >
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc> & rhs) {
		return !operator==(lhs, rhs);
	}

	template < class T, class Alloc >
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc> & rhs) {
		typedef typename vector<T, Alloc>::const_iterator _iter;

		_iter	lIt		= lhs.begin();
		_iter	lIte	= lhs.end();
		_iter	rIt		= rhs.begin();
		_iter	rIte	= rhs.end();

		while (lIt != lIte && rIt != rIte) {
			if (*lIt < *rIt) {
				return true;
			}
			if (*rIt < *lIt) {
				return false;
			}
			++lIt;
			++rIt;
		}
		return (lIt == lIte && rIt != rIte);
	}

	template < class T, class Alloc >
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc> & rhs) {
		return (!operator<(rhs, lhs));
	}

	template < class T, class Alloc >
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc> & rhs) {
		return operator<(rhs, lhs);
	}

	template < class T, class Alloc >
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc> & rhs) {
		return (!operator<(lhs, rhs));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
		x.swap(y);
	}
}
