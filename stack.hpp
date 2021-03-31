# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:

		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		explicit stack (const container_type& ct = container_type()) :_ct(ct){}

		~stack(){}

		bool empty() const {
			return (_ct.empty());
		}

		size_type size() const {
			return (_ct.size());
		}

		value_type& top() {
			return (_ct.back());
		}

		const value_type& top() const {
			return (_ct.back());
		}

		void push (const value_type& val) {
			_ct.push_back(val);
		}

		void pop() {
			_ct.pop_back();
		}

	protected:
		container_type _ct;
	};

	template <class T, class Container>
	bool operator== (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs){
		return (lhs.ct == rhs.ct);
	}

	template <class T, class Container>
	bool operator!= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs){
		return (lhs.ct != rhs.ct);
	}

	template <class T, class Container>
	bool operator< (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs){
		return (lhs.ct < rhs.ct);
	}

	template <class T, class Container>
	bool operator<= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs){
		return (lhs.ct <= rhs.ct);
	}

	template <class T, class Container>
	bool operator> (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs){
		return (lhs.ct > rhs.ct);
	}

	template <class T, class Container>
	bool operator>= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs){
		return (lhs.ct >= rhs.ct);
	}
}