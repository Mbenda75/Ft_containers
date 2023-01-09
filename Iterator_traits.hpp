#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iostream>


/*  https://en.cppreference.com/w/cpp/iterator/iterator_traits
    https://cplusplus.com/reference/iterator/iterator_traits/ */
    
namespace ft
{

	struct bidirectional_iterator_tag ;
    struct random_access_iterator_tag ;
    struct forward_iterator_tag ;

    template< typename Iter >
    class iterator_traits
    {
        public:
            typedef typename Iter::iterator_category iterator_category; // iterator_category is a type that identifies the category of the iterator
            typedef typename Iter::difference_type   difference_type;   // difference_type is a signed integer type that can be used to identify distance between two iterators
            typedef typename Iter::value_type        value_type;	    // value_type is the type of the values that can be obtained by dereferencing the iterator
            typedef typename Iter::pointer           pointer;        // pointer is the type of a pointer to an element that can be obtained by dereferencing the iterator
            typedef typename Iter::reference         reference;     // reference is the type of a reference to an element that can be obtained by dereferencing the iterator
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
            typedef std::ptrdiff_t                  difference_type;        // std::ptrdiff_t is a signed integer type that can be used to identify distance between two pointers
            typedef T                               value_type;     // T is the type of the value pointed to by const T*
            typedef const T*                              pointer;  // const T* is a pointer to a const T
            typedef const T&                              reference;    // const T& is a reference to a const T
            typedef std::random_access_iterator_tag iterator_category;      // std::random_access_iterator_tag is a tag type used to identify random access iterators
    };
}


#endif