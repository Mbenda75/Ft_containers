#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
#include "Vector.hpp"

namespace ft
{
    template< class Iter >
    struct iterator_traits
    {
        typedef Iter::difference_type   difference_type;
        typedef Iter::value_type        value_type;	   
        typedef Iter::pointer           pointer;
        typedef Iter::reference         reference;
        typedef Iter::iterator_category iterator_category;
    };


    /*Specializations This type trait may be specialized for user-provided types that may be used as iterators.
    The standard library provides partial specializations for pointer types T*, 
    which makes it possible to use all iterator-based algorithms with raw pointers.*/

    template< class T >
    struct iterator_traits<T*>
    {
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template< class T >
    struct iterator_traits<const T*>
    {
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <class Iter>
    class reverse__iterator 
    {
        public:
            typedef Iter iterator_type;
            typedef typename iterator_traits<Iter>::iterator_category iterator_category;
            typedef typename iterator_traits<Iter>::value_type value_type;
            typedef typename iterator_traits<Iter>::difference_type difference_type;
            typedef typename iterator_traits<Iter>::pointer pointer;
            typedef typename iterator_traits<Iter>::reference reference;
    }       
}

#endif