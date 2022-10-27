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

#endif