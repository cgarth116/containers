# include "list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class queue
	{
		public:

			typedef T					value_type;
			typedef Container			container_type;
			typedef size_t				size_type;
			typedef queue<T, Container> _queue;

			explicit queue (const container_type& ct = container_type()) :_ct(ct){}
			queue(const _queue & rhs): _ct(rhs._ct) {}
			_queue &operator=(const _queue & rhs){
				_ct = rhs._ct;
				return *this;
			}

			~queue(){}

			bool empty() const {
				return (_ct.empty());
			}
			size_type size() const {
				return (_ct.size());
			}
			value_type& front() {
				return (_ct.front());
			}
			const value_type& front() const {
				return (_ct.front());
			}
			value_type& back() {
				return (_ct.back());
			}
			const value_type& back() const {
				return (_ct.back());
			}
			void push (const value_type& val) {
				_ct.push_back(val);
			}
			void pop () {
				_ct.pop_front();
			}

		private:
			container_type _ct;
	};

	template <class T, class Container>
	bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container>
	bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container>
	bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container>
	bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container>
	bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container>
	bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
}
