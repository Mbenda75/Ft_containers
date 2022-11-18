#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iostream>


/*  https://en.cppreference.com/w/cpp/iterator/iterator_traits
    https://cplusplus.com/reference/iterator/iterator_traits/ */
    
namespace ft
{
    template< typename Iter >
    class iterator_traits
    {
        public:
            typedef typename Iter::iterator_category iterator_category;
            typedef typename Iter::difference_type   difference_type;
            typedef typename Iter::value_type        value_type;	   
            typedef typename Iter::pointer           pointer;
            typedef typename Iter::reference         reference;
    };

    /*Specializations This type trait may be specialized for user-provided types that may be used as iterators.
    The standard library provides partial specializations for pointer types T*, 
    which makes it possible to use all iterator-based algorithms with raw pointers.*/

    template< typename T >
    class iterator_traits<T*>
    {
        public:
            typedef std::ptrdiff_t                  difference_type;
            typedef T                               value_type;
            typedef T*                              pointer;
            typedef T&                              reference;
            typedef std::random_access_iterator_tag iterator_category;
    };

    template< typename T >
    class iterator_traits<const T*>
    {
        public:
            typedef std::ptrdiff_t                  difference_type;
            typedef T                               value_type;
            typedef const T*                              pointer;
            typedef const T&                              reference;
            typedef std::random_access_iterator_tag iterator_category;
    };
}


#endif