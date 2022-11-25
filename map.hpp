# ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>
#include "pair.hpp"
#include "reverse_iterator.hpp"
#include "Vector_iterator.hpp"


#endif


namespace ft{

    template < class Key, class T, 
	class Compare = std::less<Key>, 
	class Alloc = std::allocator<ft::pair<const Key,T> > >
class map {
	/*			***				MEMBER TYPE				***		*/
	public:
		typedef Key								key_type;
		typedef T								mapped_type;
		typedef ft::pair<key_type, mapped_type> value_type;
		typedef	std::size_t						size_type;
		typedef	std::ptrdiff_t					difference_type;
		typedef	Compare							key_compare;
		typedef	Alloc							allocator_type;

		typedef	value_type&						reference;
		typedef	const value_type&				const_reference;

        typedef typename	allocator_type::pointer					pointer;
		typedef	typename	allocator_type::const_pointer			const_pointer;

        typedef ft::vectorIterator<value_type> iterator;
		typedef ft::const_vectorIterator<value_type> const_iterator;

        typedef	typename	ft::reverse_iterator<iterator>			reverse_iterator;
		typedef	typename	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

        };

}