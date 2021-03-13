# include <deque.hpp>

namespace ft
{
	template <class T, class Container = ft::deque<T> >
	class queue
	{
		public:

			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

			explicit queue (const container_type& ctnr = container_type()) :ct(ctnr){}

			~queue(){}

			bool empty() const {
				return (ct.empty());
			}

			size_type size() const {
				return (ct.size());
			}

			value_type& front() {
				return (ct.front());
			}

			const value_type& front() const {
				return (ct.front());
			}

			value_type& back() {
				return (ct.back());
			}

			const value_type& back() const {
				return (ct.back());
			}

			void push (const value_type& val) {
				ct.push_back(val);
			}

			void pop () {
				ct.pop_front();
			}

			template <class Tn, class ContainerN>
			friend bool operator== (const ft::queue<Tn, ContainerN>& lhs, const ft::queue<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
			friend bool operator!= (const ft::queue<Tn, ContainerN>& lhs, const ft::queue<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
			friend bool operator< (const ft::queue<Tn, ContainerN>& lhs, const ft::queue<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
			friend bool operator<= (const ft::queue<Tn, ContainerN>& lhs, const ft::queue<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
			friend bool operator> (const ft::queue<Tn, ContainerN>& lhs, const ft::queue<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
			friend bool operator>= (const ft::queue<Tn, ContainerN>& lhs, const ft::queue<Tn, ContainerN>& rhs);

		protected:
			container_type ct;
	};

	template <class T, class Container>
	bool operator== (const ft::queue<T, Container>& lhs, const ft::queue<T, Container>& rhs){
		return (lhs.ct == rhs.ct);
	}

	template <class T, class Container>
	bool operator!= (const ft::queue<T, Container>& lhs, const ft::queue<T, Container>& rhs){
		return (lhs.ct != rhs.ct);
	}

	template <class T, class Container>
	bool operator< (const ft::queue<T, Container>& lhs, const ft::queue<T, Container>& rhs){
		return (lhs.ct < rhs.ct);
	}

	template <class T, class Container>
	bool operator<= (const ft::queue<T, Container>& lhs, const ft::queue<T, Container>& rhs){
		return (lhs.ct <= rhs.ct);
	}

	template <class T, class Container>
	bool operator> (const ft::queue<T, Container>& lhs, const ft::queue<T, Container>& rhs){
		return (lhs.ct > rhs.ct); }

	template <class T, class Container>
	bool operator>= (const ft::queue<T, Container>& lhs, const ft::queue<T, Container>& rhs){
		return (lhs.ct >= rhs.ct);
	}
}
