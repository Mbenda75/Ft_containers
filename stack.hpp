#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"


/*	https://www.guru99.com/stack-in-cpp-stl.html 
	https://en.cppreference.com/w/cpp/container/stack
	https://www.geeksforgeeks.org/stack-in-cpp-stl/?ref=gcse
*/

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
			container_type _data;

		public:
			stack (const container_type &ct = container_type()) : _data(ct) {}	

			stack(const stack &rhs): _data(rhs._data){}	
			
			~stack() {}
			
			stack &operator=(const stack &rhs) {
				if (*this == rhs)
					return *this;
				_data = rhs._data;
				return *this;
			}

			bool empty() const{return _data.empty();}

			size_type	size() const{return _data.size();}

			value_type& top() { return _data.back();}

			const value_type& top() const {return _data.back();}

			void push(const value_type &val) {_data.push_back(val);}

			void	pop() {return _data.pop_back();}

			friend bool operator== (const stack<T, container>& lhs,
			const stack<T, container>& rhs) {
			return lhs._data == rhs._data;
			}

			friend bool operator!= (const stack<T, container>& lhs, const stack<T, container>& rhs) {
				return lhs._data != rhs._data;
			}

			friend bool operator<  (const stack<T, container>& lhs, const stack<T, container>& rhs) {
				return lhs._data < rhs._data;
			}

			friend bool operator<= (const stack<T, container>& lhs, const stack<T, container>& rhs) {
				return lhs._data <= rhs._data;
			}

			friend bool operator>  (const stack<T, container>& lhs, const stack<T, container>& rhs) {
				return lhs._data > rhs._data;
			}

			friend bool operator>= (const stack<T, container>& lhs, const stack<T, container>& rhs) {
				return lhs._data >= rhs._data;
			}
	};
}
#endif