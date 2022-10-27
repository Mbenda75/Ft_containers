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

            /*         
            template <class T, class Alloc>
            bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
              if (lhs.size() == rhs.size())
                return equal(lhs.begin(), lhs.end(), rhs.begin());
              return false;
            }

            template <class T, class Alloc>
            bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
              return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                             rhs.end());
            }

            template <class T, class Alloc>
            bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
              return !(lhs > rhs);
            }

            template <class T, class Alloc>
            bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
              return rhs < lhs;
            }

            template <class T, class Alloc>
            bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
              return !(lhs < rhs);
            }*/

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

   /*           friend bool operator==(const const_vector_iterator &lhs,
                         const const_vector_iterator &rhs) {
              return lhs.elem == rhs.elem;
            }
            
            friend bool operator!=(const const_vector_iterator &lhs,
                                   const const_vector_iterator &rhs) {
              return !(lhs.elem == rhs.elem);
            }
            
            friend bool operator<(const const_vector_iterator &lhs,
                                  const const_vector_iterator &rhs) {
              return lhs.elem < rhs.elem;
            }
            
            friend bool operator>(const const_vector_iterator &lhs,
                                  const const_vector_iterator &rhs) {
              return rhs.elem < lhs.elem;
            }
            
            friend bool operator<=(const const_vector_iterator &lhs,
                                   const const_vector_iterator &rhs) {
              return !(lhs.elem > rhs.elem);
            }
            
            friend bool operator>=(const const_vector_iterator &lhs,
                                   const const_vector_iterator &rhs) {
              return !(lhs.elem < rhs.elem);
            } */
}

#endif