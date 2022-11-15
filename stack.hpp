#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft{
	template<class T, class container = ft::vector<T> >
	class stack {
		public:
			typedef container   container_type;
			typedef T           value_type;
			typedef typename    container::size_type    size_type;
			typedef typename    container::reference    reference;
			typedef typename    container::const_reference    const_reference;

		protected:
			container_type _container;

		public:
			explicit stack (const container_type &ctnr = container_type()) : _container(ctnr) {}

			stack(const stack &rhs): _container(rhs._container){}
			
			~stack() {}
			
			stack &operator=(const stack &rhs) {
				if (*this == rhs)
					return *this;
				_container = rhs._container;
				return *this;
			}

			bool empty() const{return _container.empty();}

			size_type	size() const{return _container.size();}

			value_type& top() { return _container.back();}

			const value_type& top() const {return _container.back();}

			void push(const value_type &val) {_container.push_back(val);}

			void	pop() {return _container.pop_back();}

			friend bool operator== (const stack<T, container>& lhs,
			const stack<T, container>& rhs) {
			return lhs._container == rhs._container;
			}

			friend bool operator!= (const stack<T, container>& lhs, const stack<T, container>& rhs) {
				return lhs._container != rhs._container;
			}

			friend bool operator<  (const stack<T, container>& lhs, const stack<T, container>& rhs) {
				return lhs._container < rhs._container;
			}

			friend bool operator<= (const stack<T, container>& lhs, const stack<T, container>& rhs) {
				return lhs._container <= rhs._container;
			}

			friend bool operator>  (const stack<T, container>& lhs, const stack<T, container>& rhs) {
				return lhs._container > rhs._container;
			}

			friend bool operator>= (const stack<T, container>& lhs, const stack<T, container>& rhs) {
				return lhs._container >= rhs._container;
			}
	};
}
#endif