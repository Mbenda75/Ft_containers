#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "Vector.hpp"

namespace ft
{
    template<typename T>
    class vectorIterator
    {

        public:
            typedef T ValueType;

            typedef ValueType PointerType;

            typedef ValueType ReferenceType;

        public:
            vectorIterator(PointerType ptr): _ptr(ptr)
            {

            }

            vectorIterator& operator++()//incre apres assisn
            {
                _ptr++;
                return *this;
            }

            vectorIterator operator++(int)//incre avant assign
            {
                vectorIterator iterator = *this;
                ++(*this);
                return iterator;
            }

            vectorIterator& operator--()//incre apres assign
            {
                _ptr--;
                return *this;
            }

            vectorIterator operator--(int)//incre avant assign
            {
                vectorIterator iterator = *this;
                --(*this);
                return iterator;
            }

            ReferenceType operator[](int index)
            {
                return *(_ptr + index);//_ptr[index]
            }

/*           template< class T, class Alloc >
            bool operator<( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs )
            {

            }
         
            template< class T, class Alloc >
            bool operator<=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs )
            {
                return (!(rhs < lhs));
            }
   
            template< class T, class Alloc >
            bool operator>( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs )
            {
                return (rhs < lhs);
            } 

            template< class T, class Alloc >
            bool operator>=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs )
            {
                return (!(lhs < rhs));
            }

            template< class T, class Alloc >
            bool operator==( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs )
            {
                return (*(lhs == rhs));
            }

            template< class T, class Alloc >
            bool operator!=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs )
            {
                return (!(lhs == rhs));
            }*/

        private:
            PointerType _ptr;
    };
}

#endif