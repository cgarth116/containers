//
// Created by Caeneus Garth on 2/5/21.
//

#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include <iostream>

namespace ft{

	template <class T>
	class vectorIterator: public std::iterator<std::random_access_iterator_tag, T>{
		typedef std::iterator< std::random_access_iterator_tag,T > 	_stdIt;
		typedef typename _stdIt::difference_type					_difference_type;
		typedef typename _stdIt::pointer							_pointer;
		typedef typename _stdIt::reference 							_reference;

		public:
			vectorIterator(): _index(NULL) {};
			vectorIterator(T * index): _index(index) {};
			bool operator==(vectorIterator const & rhs){
			return _index == rhs._index;
		};
			bool operator!=(const vectorIterator & rhs){
			return _index != rhs._index;
		};
			bool operator <(const vectorIterator & rhs){
			return _index < rhs._index;
		};
			bool operator >(const vectorIterator & rhs){
			return _index > rhs._index;
		};
			bool operator <=(const vectorIterator & rhs){
			return _index <= rhs._index;
		};
			bool operator >=(const vectorIterator & rhs){
			return _index >= rhs._index;
		};
			_pointer operator->() const {
			return _index;
		};
			_reference operator*(){
			return *_index;
		};
			vectorIterator & operator=(const vectorIterator & rhs){
			if (this != &rhs){
				_index = rhs._index;
			}
			return *this;
		};
			vectorIterator & operator+=(_difference_type n){
			_index += n;
			return *this;
		};
			vectorIterator & operator-=(_difference_type n){
			_index -= n;
			return *this;
		};
			vectorIterator operator+(_difference_type n){
			vectorIterator it(*this);
			it += n;
			return it;
		};
			vectorIterator & operator++(){
			++_index;
			return *this;
		};
			vectorIterator operator++(int){
			vectorIterator tmp(_index);
			++_index;
			return tmp;
		};
			vectorIterator operator-(_difference_type n){
			vectorIterator it(*this);
			it -= n;
			return it;
		};
			vectorIterator & operator--(){
			--_index;
			return *this;
		};
			vectorIterator operator--(int){
			vectorIterator tmp(_index);
			--_index;
			return tmp;
		};

		private:
			_pointer _index;
	};

	template <class T>
	class reverse_vectorIterator: public std::iterator<std::random_access_iterator_tag, T>{
		typedef std::iterator< std::random_access_iterator_tag,T > 	_stdIt;
		typedef typename _stdIt::difference_type					_difference_type;
		typedef typename _stdIt::pointer							_pointer;
		typedef typename _stdIt::reference 							_reference;
		public:
			reverse_vectorIterator(): _index(NULL) {};
			reverse_vectorIterator(T * index): _index(index) {};
			bool operator==(reverse_vectorIterator const & rhs){
			return _index == rhs._index;
		};
			bool operator!=(reverse_vectorIterator const & rhs){
			return _index != rhs._index;
		};
			bool operator <(const reverse_vectorIterator & rhs){
			return _index < rhs._index;
		};
			bool operator >(const reverse_vectorIterator & rhs){
			return _index > rhs._index;
		};
			bool operator <=(const reverse_vectorIterator & rhs){
			return _index <= rhs._index;
		};
			bool operator >=(const reverse_vectorIterator & rhs){
			return _index >= rhs._index;
		};
			_pointer operator->() const {
			return _index;
		};
			_reference operator*(){
			return *_index;
		};
			reverse_vectorIterator & operator=(const reverse_vectorIterator & rhs) {
			if (this != &rhs){
				_index = rhs._index;
			}
			return *this;
		};
			reverse_vectorIterator & operator+=(_difference_type n) {
			_index -= n;
			return *this;
		};
			reverse_vectorIterator & operator-=(_difference_type n) {
			_index += n;
			return *this;
		};
			reverse_vectorIterator operator+(_difference_type n) {
			reverse_vectorIterator it(*this);
			it -= n;
			return it;
		};
			reverse_vectorIterator & operator++() {
			--_index;
			return *this;
		};
			reverse_vectorIterator operator++(int){
			reverse_vectorIterator tmp(_index);
			--_index;
			return tmp;
		};
			reverse_vectorIterator operator-(_difference_type n) {
			reverse_vectorIterator it(*this);
			it += n;
			return it;
		};
			reverse_vectorIterator & operator--() {
			++_index;
			return *this;
		};
			reverse_vectorIterator operator--(int){
			reverse_vectorIterator tmp(_index);
			++_index;
			return tmp;
		};

		private:
			T * _index;
	};

	template <class T>
	class const_vectorIterator: public std::iterator<const std::random_access_iterator_tag, T>{
		typedef std::iterator< std::random_access_iterator_tag,T > 	_stdIt;
		typedef typename _stdIt::difference_type					_difference_type;
		typedef typename _stdIt::pointer							_pointer;
		typedef typename _stdIt::reference 							_reference;
		public:
			const_vectorIterator(): _index(NULL) {};
			const_vectorIterator(T * index): _index(index) {};
			bool operator==(const_vectorIterator const & rhs){
			return _index == rhs._index;
		};
			bool operator!=(const const_vectorIterator & rhs){
			return _index != rhs._index;
		};
			bool operator <(const const_vectorIterator & rhs){
			return _index < rhs._index;
		};
			bool operator >(const const_vectorIterator & rhs){
			return _index > rhs._index;
		};
			bool operator <=(const const_vectorIterator & rhs){
			return _index <= rhs._index;
		};
			bool operator >=(const const_vectorIterator & rhs){
				return _index >= rhs._index;
			};
			_pointer operator->() const {
				return _index;
			};
			_reference operator*(){
			return *_index;
		};
			const_vectorIterator & operator=(const const_vectorIterator & rhs) {
			if (this != &rhs){
				_index = rhs._index;
			}
			return *this;
		};
			const_vectorIterator & operator+=(_difference_type n) {
			_index += n;
			return *this;
		};
			const_vectorIterator & operator-=(_difference_type n) {
			_index -= n;
			return *this;
		};
			const_vectorIterator operator+(_difference_type n){
				const_vectorIterator it(*this);
				it += n;
				return it;
			}
			const_vectorIterator & operator++() {
			++_index;
			return *this;
		};
			const_vectorIterator operator++(int){
			const_vectorIterator tmp(_index);
			++_index;
			return tmp;
		};
			const_vectorIterator & operator--(){
			--_index;
			return *this;
		};
			const_vectorIterator operator-(_difference_type n) {
			const_vectorIterator it(*this);
			it -= n;
			return it;
		};
			const_vectorIterator operator--(int){
			const_vectorIterator tmp(_index);
			--_index;
			return tmp;
		};

		private:
			T * _index;
	};

	template <class T>
	class const_reverse_vectorIterator : public std::iterator<std::random_access_iterator_tag, T>{
		typedef std::iterator< std::random_access_iterator_tag,T > 	_stdIt;
		typedef typename _stdIt::difference_type					_difference_type;
		typedef typename _stdIt::pointer							_pointer;
		typedef typename _stdIt::reference 							_reference;
		public:
			const_reverse_vectorIterator(): _index(NULL) {};
			const_reverse_vectorIterator(T * index): _index(index) {};
			bool operator==(const_reverse_vectorIterator const & rhs){
			return _index == rhs._index;
		};
			bool operator!=(const_reverse_vectorIterator const & rhs){
			return _index != rhs._index;
		};
			bool operator <(const const_reverse_vectorIterator & rhs){
			return _index < rhs._index;
		};
			bool operator >(const const_reverse_vectorIterator & rhs){
			return _index > rhs._index;
		};
			bool operator <=(const const_reverse_vectorIterator & rhs){
			return _index <= rhs._index;
		};
			bool operator >=(const const_reverse_vectorIterator & rhs){
			return _index >= rhs._index;
		};
			_pointer operator->() const {
			return _index;
		};
			_reference operator*(){
			return *_index;
		};
			const_reverse_vectorIterator & operator=(const const_reverse_vectorIterator & rhs) {
			if (this != &rhs){
				_index = rhs._index;
			}
			return *this;
		};
			const_reverse_vectorIterator & operator+=(_difference_type n) {
			_index -= n;
			return *this;
		};
			const_reverse_vectorIterator & operator-=(_difference_type n) {
			_index += n;
			return *this;
		};
			const_reverse_vectorIterator operator+(_difference_type n) {
			const_reverse_vectorIterator it(*this);
			it -= n;
			return it;
		};
			const_reverse_vectorIterator & operator++() {
			--_index;
			return *this;
		};
			const_reverse_vectorIterator operator++(int){
			const_reverse_vectorIterator tmp(_index);
			--_index;
			return tmp;
		};
			const_reverse_vectorIterator operator-(_difference_type n) {
			const_reverse_vectorIterator it(*this);
			it += n;
			return it;
		};
			const_reverse_vectorIterator & operator--() {
			++_index;
			return *this;
		};
			const_reverse_vectorIterator operator--(int){
			const_reverse_vectorIterator tmp(_index);
			++_index;
			return tmp;
		};

		private:
			T * _index;
	};

}

#endif