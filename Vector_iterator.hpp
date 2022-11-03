#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "Vector.hpp"

namespace ft
{
    template<typename T>
    class vectorIterator
    {

        public:
            typedef T               value_type;
            typedef size_t          size_type;
            typedef std::ptrdiff_t difference_type;
            typedef T *             pointer;
            typedef T &             reference;

        private:
            pointer _ptr;

        public:
            vectorIterator()
            {
            }

            vectorIterator(pointer ptr): _ptr(ptr)
            {

            }


            vectorIterator<T>& operator++()//incre apres assisn
            {
                _ptr++;
                return *this;
            }

            vectorIterator<T> operator++(int)//incre avant assign
            {
                vectorIterator iterator = *this;
                ++(*this);
                return iterator;
            }

            vectorIterator<T>& operator--()//incre apres assign
            {
                _ptr--;
                return *this;
            }

            vectorIterator<T> operator--(int)//incre avant assign
            {
                vectorIterator iterator = *this;
                --(*this);
                return iterator;
            }

            reference operator[](int index)
            {
                return *(_ptr + index);//_ptr[index]
            }

            reference operator*() const { return *_ptr; }

  		    pointer operator->() const { return _ptr; }

            vectorIterator operator +(difference_type other) { return otherectorIterator(_ptr + other); }
			vectorIterator operator -(difference_type other) { return otherectorIterator(_ptr - other); }
			difference_type operator +(vectorIterator other) { return _ptr + other._ptr; }
			difference_type operator -(vectorIterator other) { return _ptr - other._ptr; }

            friend bool operator==(const vectorIterator &lhs,
                         const vectorIterator &rhs) {
              return lhs._ptr == rhs._ptr;
            }
            
            friend bool operator!=(const vectorIterator &lhs,
                                   const vectorIterator &rhs) {
              return !(lhs._ptr == rhs._ptr);
            }
            
            friend bool operator<(const vectorIterator &lhs,
                                  const vectorIterator &rhs) {
              return lhs._ptr < rhs._ptr;
            }
            
            friend bool operator>(const vectorIterator &lhs,
                                  const vectorIterator &rhs) {
              return rhs._ptr < lhs._ptr;
            }
            
            friend bool operator<=(const vectorIterator &lhs,
                                   const vectorIterator &rhs) {
              return !(lhs._ptr > rhs._ptr);
            }
            
            friend bool operator>=(const vectorIterator &lhs,
                                   const vectorIterator &rhs) {
              return !(lhs._ptr < rhs._ptr);
            } 

    };


    template<typename T>
    class const_vectorIterator
    {

        public:
            typedef T                     value_type;
            typedef size_t                size_type;
            typedef std::ptrdiff_t        difference_type;
            typedef const T *             pointer;
            typedef const T &             reference;

        private:
            pointer _ptr;

        public:
            const_vectorIterator()
            {
            }

            const_vectorIterator(pointer ptr): _ptr(ptr)
            {

            }

            const_vectorIterator<T>& operator++()//incre apres assisn
            {
                _ptr++;
                return *this;
            }

            const_vectorIterator<T> operator++(int)//incre avant assign
            {
                const_vectorIterator iterator = *this;
                ++(*this);
                return iterator;
            }

            const_vectorIterator<T>& operator--()//incre apres assign
            {
                _ptr--;
                return *this;
            }

            const_vectorIterator<T> operator--(int)//incre avant assign
            {
                const_vectorIterator iterator = *this;
                --(*this);
                return iterator;
            }

            reference operator[](int index)
            {
                return *(_ptr + index);//_ptr[index]
            }

            reference operator*() const { return *_ptr; }

  		    pointer operator->() const { return _ptr; }

            const_vectorIterator operator +(difference_type other) { return const_vectorIterator(_ptr + other); }
			const_vectorIterator operator -(difference_type other) { return const_vectorIterator(_ptr - other); }
			difference_type operator +(const_vectorIterator other) { return _ptr + other._ptr; }
			difference_type operator -(const_vectorIterator other) { return _ptr - other._ptr; }



            friend bool operator==(const const_vectorIterator &lhs,
                         const const_vectorIterator &rhs) {
              return lhs._ptr == rhs._ptr;
            }
            
            friend bool operator!=(const const_vectorIterator &lhs,
                                   const const_vectorIterator &rhs) {
              return !(lhs._ptr == rhs._ptr);
            }
            
            friend bool operator<(const const_vectorIterator &lhs,
                                  const const_vectorIterator &rhs) {
              return lhs._ptr < rhs._ptr;
            }
            
            friend bool operator>(const const_vectorIterator &lhs,
                                  const const_vectorIterator &rhs) {
              return rhs._ptr < lhs._ptr;
            }
            
            friend bool operator<=(const const_vectorIterator &lhs,
                                   const const_vectorIterator &rhs) {
              return !(lhs._ptr > rhs._ptr);
            }
            
            friend bool operator>=(const const_vectorIterator &lhs,
                                   const const_vectorIterator &rhs) {
              return !(lhs._ptr < rhs._ptr);
            } 
        };
}


	template < class iterator >
	class vector_reverseIterator 
    {
		public :
			typedef iterator							iterator_type;
			typedef typename iterator::value_type		value_type;
			typedef typename iterator::reference		reference;
			typedef typename iterator::const_reference	const_reference;
			typedef typename iterator::pointer			pointer;
			typedef typename iterator::const_pointer	const_pointer;
			typedef typename iterator::difference_type	difference_type;

			vector_reverseIterator(void) {}
			vector_reverseIterator(pointer ptr) { _ptr = ptr; }
			//vector_reverseIterator(vectorIterator<value_type> const &src) { _ptr = src.operator->(); }
			vector_reverseIterator(vector_reverseIterator const &src) { *this = src; } ;
			vector_reverseIterator &operator=(vector_reverseIterator const &src) { _ptr = src.operator->(); return (*this); }
			~vector_reverseIterator() {}

			vector_reverseIterator operator ++() {
				_ptr--;
				return (*this);
			}
		
			vector_reverseIterator operator ++(int) {
				_ptr--;
				return (vector_reverseIterator(_ptr + 1));
			}
		
			vector_reverseIterator operator --() {
				_ptr++;
				return (*this);
			}
		
			vector_reverseIterator operator --(int) {
				_ptr++;
				return (vector_reverseIterator(_ptr - 1));
			}

			void operator +=(difference_type v) { _ptr -= v; }
			void operator -=(difference_type v) { _ptr += v; }

			bool operator ==(vector_reverseIterator const& v) const { return _ptr == v._ptr; }
			bool operator !=(vector_reverseIterator const& v) const { return _ptr != v._ptr; }
			bool operator <(vector_reverseIterator const& v) const { return _ptr < v._ptr; }
			bool operator <=(vector_reverseIterator const& v) const { return _ptr <= v._ptr; }
			bool operator >(vector_reverseIterator const& v) const { return _ptr > v._ptr; }
			bool operator >=(vector_reverseIterator const& v) const { return _ptr >= v._ptr; }

			vector_reverseIterator operator +(difference_type v) { return vector_reverseIterator(_ptr - v); }
			vector_reverseIterator operator -(difference_type v) { return vector_reverseIterator(_ptr + v); }
			difference_type operator +(vector_reverseIterator v) { return _ptr - v._ptr; }
			difference_type operator -(vector_reverseIterator v) { return _ptr + v._ptr; }

			reference operator *() { return *_ptr; }
			const_reference operator *() const { return *_ptr; }
			pointer operator ->() { return _ptr; }
			pointer operator ->() const { return _ptr; }
			reference operator [](difference_type n) { return *(_ptr + n); }
			const_reference operator [](difference_type n) const { return *(_ptr + n); }

			pointer get_ptr() { return _ptr; }
		private :
			pointer _ptr;
	}; 

    	template < class iterator >
	class const_vector_reverseIterator {
		public :
			typedef iterator							iterator_type;
			typedef typename iterator::value_type		value_type;
			typedef typename iterator::reference		reference;
			typedef typename iterator::const_reference	const_reference;
			typedef typename iterator::pointer			pointer;
			typedef typename iterator::const_pointer	const_pointer;
			typedef typename iterator::difference_type	difference_type;

			const_vector_reverseIterator(void) {}
			const_vector_reverseIterator(pointer ptr) { _ptr = ptr; }
			//const_vector_reverseIterator(vector_iterator<value_type> const &src) { _ptr = src.operator->(); }
			const_vector_reverseIterator(const_vector_reverseIterator const &src) { *this = src; } ;
			const_vector_reverseIterator &operator=(const_vector_reverseIterator const &src) { _ptr = src.operator->(); return (*this); }
			~const_vector_reverseIterator() {}

			const_vector_reverseIterator operator ++() {
				_ptr--;
				return (*this);
			}

			const_vector_reverseIterator operator ++(int) {
				_ptr--;
				return (const_vector_reverseIterator(_ptr + 1));
			}

			const_vector_reverseIterator operator --() {
				_ptr++;
				return (*this);
			}
		
			const_vector_reverseIterator operator --(int) {
				_ptr++;
				return (const_vector_reverseIterator(_ptr - 1));
			}

			bool operator ==(const_vector_reverseIterator const& v) const { return _ptr == v._ptr; }
			bool operator !=(const_vector_reverseIterator const& v) const { return _ptr != v._ptr; }
			bool operator <(const_vector_reverseIterator const& v) const { return _ptr < v._ptr; }
			bool operator <=(const_vector_reverseIterator const& v) const { return _ptr <= v._ptr; }
			bool operator >(const_vector_reverseIterator const& v) const { return _ptr > v._ptr; }
			bool operator >=(const_vector_reverseIterator const& v) const { return _ptr >= v._ptr; }

			const_vector_reverseIterator operator +(difference_type v) { return const_vector_reverseIterator(_ptr - v); }
			const_vector_reverseIterator operator -(difference_type v) { return const_vector_reverseIterator(_ptr + v); }
			difference_type operator +(const_vector_reverseIterator v) { return _ptr - v._ptr; }
			difference_type operator -(const_vector_reverseIterator v) { return _ptr + v._ptr; }

			const_reference operator *() const { return *_ptr; }
			pointer operator ->() { return _ptr; }
			pointer operator ->() const { return _ptr; }
			const_reference operator [](difference_type n) const { return *(_ptr + n); }

			pointer get_ptr() { return _ptr; }
		private :
			pointer _ptr;
	};

#endif