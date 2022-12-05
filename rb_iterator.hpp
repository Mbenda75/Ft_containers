#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP


#include "rb_tree.hpp"
#include "Iterator_traits.hpp"


template<typename T>
  class Rb_iterator
  {
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    //typedef bidirectional_iterator_tag iterator_category;
    typedef ptrdiff_t                  difference_type;
    typedef Rb_iterator<T>        _Self;
    typedef ft::Rb_tree_base::_ptr _ptr;
    //typedef ft::Rb_tree<T>*           _Link_type;

    _ptr _node;
  
 };

#endif