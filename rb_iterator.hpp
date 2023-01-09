#ifndef RB_ITERATOR_HPP
# define RB_ITERATOR_HPP

#include <cstddef> // for std::ptrdiff_t

#include "Iterator_traits.hpp" 
#include "rb_tree.hpp"
#include "rb_node.hpp"

namespace ft {
template <class T, class N>
class rb_iterator
{
	public:
		typedef T											value_type;
		typedef T*											pointer;
		typedef T&											reference;
		typedef const T*									const_pointer;
		typedef const T&									const_reference;
		typedef typename std::ptrdiff_t						difference_type;
		typedef std::bidirectional_iterator_tag				iterator_category; 
		typedef N				node_type;
		typedef node_type*		node_ptr;
	private:
		node_ptr	_ptr;
		node_ptr	_end;
		node_ptr	_root;
	public:
		rb_iterator() : _ptr(NULL), _end(NULL), _root(NULL) {}

		rb_iterator(node_ptr root, node_ptr base, node_ptr end)
		: _ptr(base), _end(end), _root(root) {}

		rb_iterator(const rb_iterator& x)
		: _ptr(x._ptr), _end(x._end), _root(x._root) {}

		~rb_iterator() {}
		
		rb_iterator &operator=(const rb_iterator &src)
		{
			if (this != &src)
			{
				_ptr = src._ptr;
				_end = src._end;
				_root = src._root;
			}
			return *this;
		}

		operator rb_iterator<value_type const, node_type const>() const
		{
			return rb_iterator<value_type const, node_type const>(_root, _ptr, _end);
		}
		
		reference operator*() {
			return this->_ptr->data;
		}

		const_reference operator*() const {
			return this->_ptr->data;
		}

		pointer operator->() { return &(operator*()); }
		
		const_pointer	operator->	() const {
			return (&(operator*()));
		}

		bool operator==(const rb_iterator& lhs) const{
			return _ptr == lhs._ptr;
		}
		bool operator!=(const rb_iterator& lhs) const {
			return _ptr != lhs._ptr;
		}

		rb_iterator& operator++()
		{
			if (_ptr != _end)
				_ptr = successor(_ptr);
			return *this;
		}

		rb_iterator operator++(int)
		{
			rb_iterator tmp(*this);
			operator++();
			return (tmp);
		}

		rb_iterator &operator--()
		{
			if (_ptr == _end)
				_ptr = maxi(_root);
			else
				_ptr = predecessor(_ptr);
			return (*this);
		}

		rb_iterator operator--(int)
		{
			rb_iterator tmp(*this);
			operator--();
			return tmp;
		}


		node_ptr mini(node_ptr node)
		{
			while (node->left != _end)
				node = node->left;
			return node;
		}

		// same as in rbTree class
		node_ptr maxi(node_ptr node)
		{
			if (node != _end || node != NULL)
			{
				while (node->right != _end)
					node = node->right;
			}
			return node;
		}

		node_ptr successor(node_ptr x)
		{
			if (x->right != _end)	// if right child is not end node
				return mini(x->right);	// return the minimum of the right subtree 
			node_ptr y = x->parent;	// else return the first gp of x whose left child is also an gp of x
			while (y != NULL && x == y->right)	// if x is the right child of y
			{
				x = y;	// x is the gp of y
				y = y->parent;	// y is the gp of x 
			}
			if (y == NULL)
				return _end;
			return y;
		}

		node_ptr predecessor(node_ptr x)
		{
			if (x->left != _end) // if left child is not end node 
				return maxi(x->left); // return the maximum of the left subtree
			node_ptr y = x->parent;
			while (y != _end && x == y->left) // if x is the left child of y 
			{
				x = y; // x is the gp of y 
				y = y->parent; //	 y is the gp of x
			}
			return y;
		}
};
template<class Iterator, class Iter>
bool operator==(ft::rb_iterator<Iterator, ft::Node<Iterator> > const &lhs, ft::rb_iterator<Iter, ft::Node<Iter> > const &rhs)
{
	return (lhs._ptr == rhs._ptr);
}

template<class Iterator, class Iter>
bool operator!=(ft::rb_iterator<Iterator, ft::Node<Iterator> > const &lhs, ft::rb_iterator<Iter, ft::Node<Iter> > const &rhs)
{
	return (lhs._ptr != rhs._ptr);
}
}

#endif