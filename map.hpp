# ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>
#include "pair.hpp"


# include "Vector_iterator.hpp"
# include "Iterator_traits.hpp"
# include "reverse_iterator.hpp"


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
		typedef ft::vectorIterator<const value_type> const_iterator;

        typedef	ft::reverse_iterator<iterator>			reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	/*---------------------------MEMBER FUNCTIONS MAP -----------------------------------------------------*/

		map();
	
		explicit map( const Compare& comp,onst Allocator& alloc = Allocator() );

		map( const map& other );

		map& operator=( const map& other );


	/*-----------------------------------ELEMENT ACCESS-------------------------------------------------*/

		T& at( const Key& key );

		const T& at( const Key& key ) const;

		T& operator[]( const Key& key );

	/*----------------------------------ITERATOR FUNCTION-----------------------------------------------*/

		iterator begin();

		const_iterator begin() const;


		iterator end();


		const_iterator end() const;
		
		reverse_iterator rbegin();

		const_reverse_iterator rbegin()const;

		reverse_iterator rend();

		const_reverse_iterator rend()const;

	/*-----------------------------CAPACITY FUNCTIONS------------------------------------------------ */

		bool empty() const;

		size_type size() const;

		size_type max_size() const;
	
	/*---------------------------MODIFIERS FUNCTIONS------------------------------------------*/

		void clear();

		std::pair<iterator, bool> insert( const value_type& value );

		iterator insert( iterator pos, const value_type& value );

		template< class InputIt >
		void insert( InputIt first, InputIt last );

		iterator erase( iterator pos );

		iterator erase( iterator first, iterator last );

		size_type erase( const Key& key );

		void swap( map& other );
	/*---------------------------LOOK UP----------------------------------------------*/

		size_type count( const Key& key ) const;

		iterator find( const Key& key );

		const_iterator find( const Key& key ) const;

		std::pair<iterator,iterator> equal_range( const Key& key );

		std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

		iterator lower_bound( const Key& key );

		const_iterator lower_bound( const Key& key ) const;

		iterator upper_bound( const Key& key );

		const_iterator upper_bound( const Key& key ) const;

	/*---------------------------OBSERVERS----------------------------------------------*/

		key_compare key_comp() const;

		ft::map::value_compare value_comp() const;

    	};

	/*---------------------------NON MEMBER CLASS--------------------------------------------*/

		template< class Key, class T, class Compare, class Alloc >
		bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
		                 const ft::map<Key,T,Compare,Alloc>& rhs );

		template< class Key, class T, class Compare, class Alloc >
		bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
		                 const ft::map<Key,T,Compare,Alloc>& rhs );

		template< class Key, class T, class Compare, class Alloc >
		bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
		                const ft::map<Key,T,Compare,Alloc>& rhs );

		template< class Key, class T, class Compare, class Alloc >
		bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
		                 const ft::map<Key,T,Compare,Alloc>& rhs );

		template< class Key, class T, class Compare, class Alloc >
		bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
		                const ft::map<Key,T,Compare,Alloc>& rhs );

		template< class Key, class T, class Compare, class Alloc >
		bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
		                 const ft::map<Key,T,Compare,Alloc>& rhs )
}