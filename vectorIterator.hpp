//
// Created by Caeneus Garth on 2/5/21.
//

#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include <iostream>

namespace ft{

	template <class T>
	class iterator: public std::iterator<std::input_iterator_tag, T>{
	public:
		iterator(): _index(NULL) {};
		iterator(T * index): _index(index) {};
		bool operator==(iterator const & rhs){
			return _index == rhs._index;
		};
		bool operator!=(const iterator & rhs){
			return _index != rhs._index;
		};

		bool operator <(const iterator & rhs){
			return _index < rhs._index;
		}
		bool operator >(const iterator & rhs){
			return _index > rhs._index;
		}
		bool operator <=(const iterator & rhs){
			return _index <= rhs._index;
		}
		bool operator >=(const iterator & rhs){
			return _index >= rhs._index;
		}

		T *	operator->() const {
			return _index;
		};
		iterator & operator+=(size_t n) {
			_index += n;
			return *this;
		};
		iterator & operator-=(size_t n) {
			_index -= n;
			return *this;
		};
		iterator operator+(size_t n) {
			iterator it(*this);
			it += n;
			return it;
		};
		iterator & operator++() {
			++_index;
			return *this;
		};
		iterator operator++(int)
		{
			iterator tmp(_index);
			++_index;
			return tmp;
		};
		iterator operator-(size_t n) {
			iterator it(*this);
			it -= n;
			return it;
		};
		iterator & operator--() {
			--_index;
			return *this;
		};
		iterator operator--(int)
		{
			iterator tmp(_index);
			--_index;
			return tmp;
		};
		T & operator*(){
			return *_index;
		};

	private:
		T * _index;
	};

	template <class T>
	class reverse_iterator: public std::iterator<std::input_iterator_tag, T>{
	public:
		reverse_iterator(): _index(NULL) {};
		reverse_iterator(T * index): _index(index) {};
		bool operator==(reverse_iterator const & rhs){
			return _index == rhs._index;
		};
		bool operator!=(reverse_iterator const & rhs){
			return _index != rhs._index;
		};
		bool operator <(const reverse_iterator & rhs){
			return _index < rhs._index;
		}
		bool operator >(const reverse_iterator & rhs){
			return _index > rhs._index;
		}
		bool operator <=(const reverse_iterator & rhs){
			return _index <= rhs._index;
		}
		bool operator >=(const reverse_iterator & rhs){
			return _index >= rhs._index;
		}
		T *	operator->() const {
			return _index;
		}
		reverse_iterator & operator+=(size_t n) {
			_index -= n;
			return *this;
		};
		reverse_iterator & operator-=(size_t n) {
			_index += n;
			return *this;
		};
		reverse_iterator operator+(size_t n) {
			reverse_iterator it(*this);
			it -= n;
			return it;
		};
		reverse_iterator & operator++() {
			--_index;
			return *this;
		};
		reverse_iterator operator++(int)
		{
			reverse_iterator tmp(_index);
			--_index;
			return tmp;
		}
		reverse_iterator operator-(size_t n) {
			reverse_iterator it(*this);
			it += n;
			return it;
		};
		reverse_iterator & operator--() {
			++_index;
			return *this;
		};
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp(_index);
			++_index;
			return tmp;
		}
		T & operator*(){
			return *_index;
		};

	private:
		T * _index;
	};

	template <class T>
	class const_iterator: public std::iterator<const std::input_iterator_tag, T>{
	public:
		const_iterator(): _index(NULL) {};
		const_iterator(T * index): _index(index) {};
		bool operator==(const_iterator const & rhs){
			return _index == rhs._index;
		};
		bool operator!=(const const_iterator & rhs){
			return _index != rhs._index;
		};
		bool operator <(const const_iterator & rhs){
			return _index < rhs._index;
		}
		bool operator >(const const_iterator & rhs){
			return _index > rhs._index;
		}
		bool operator <=(const const_iterator & rhs){
			return _index <= rhs._index;
		}
		bool operator >=(const const_iterator & rhs){
			return _index >= rhs._index;
		}
		T *	operator->() const {
			return _index;
		}
		const_iterator & operator+=(size_t n) {
			_index += n;
			return *this;
		};
		const_iterator & operator-=(size_t n) {
			_index -= n;
			return *this;
		};
		const_iterator & operator++() {
			++_index;
			return *this;
		};
		const_iterator operator++(int)
		{
			const_iterator tmp(_index);
			++_index;
			return tmp;
		}
		const_iterator & operator--() {
			--_index;
			return *this;
		};
		const_iterator operator-(size_t n) {
			const_iterator it(*this);
			it -= n;
			return it;
		};
		const_iterator operator--(int)
		{
			const_iterator tmp(_index);
			--_index;
			return tmp;
		}
		T & operator*(){
			return *_index;
		};

	private:
		T * _index;
	};

	template <class T>
	class const_reverse_iterator : public std::iterator<std::input_iterator_tag, T>{
	public:
		const_reverse_iterator(): _index(NULL) {};
		const_reverse_iterator(T * index): _index(index) {};
		bool operator==(const_reverse_iterator const & rhs){
			return _index == rhs._index;
		};
		bool operator!=(const_reverse_iterator const & rhs){
			return _index != rhs._index;
		};
		bool operator <(const const_reverse_iterator & rhs){
			return _index < rhs._index;
		}
		bool operator >(const const_reverse_iterator & rhs){
			return _index > rhs._index;
		}
		bool operator <=(const const_reverse_iterator & rhs){
			return _index <= rhs._index;
		}
		bool operator >=(const const_reverse_iterator & rhs){
			return _index >= rhs._index;
		}
		T *	operator->() const {
			return _index;
		}
		const_reverse_iterator & operator+=(size_t n) {
			_index -= n;
			return *this;
		};
		const_reverse_iterator & operator-=(size_t n) {
			_index += n;
			return *this;
		};
		const_reverse_iterator operator+(size_t n) {
			const_reverse_iterator it(*this);
			it -= n;
			return it;
		};
		const_reverse_iterator & operator++() {
			--_index;
			return *this;
		};
		const_reverse_iterator operator++(int)
		{
			const_reverse_iterator tmp(_index);
			--_index;
			return tmp;
		}
		const_reverse_iterator operator-(size_t n) {
			const_reverse_iterator it(*this);
			it += n;
			return it;
		};
		const_reverse_iterator & operator--() {
			++_index;
			return *this;
		};
		const_reverse_iterator operator--(int)
		{
			const_reverse_iterator tmp(_index);
			++_index;
			return tmp;
		}
		T & operator*(){
			return *_index;
		};

	private:
		T * _index;
	};

}

#endif