#ifndef MAP_HPP
# define MAP_HPP

#include <functional>	// std::less
#include <memory>	// std::allocator
#include "rb_tree.hpp"
#include "type.hpp"
#include "pair.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

#include "reverse_iterator.hpp"
#include "rb_iterator.hpp"


/*
	All protype from -> https://en.cppreference.com/w/cpp/container/map
*/

namespace ft {
	template <class T, class Key>
	struct get_key // get key from value type (pair) 	
	{
		const Key &operator()(const T &x) const	 
		{
			return (x.first); // return key from pair (key, value) 
		}
	};
template < class Key, class T, 
	class Compare = std::less<Key>, 
	class Alloc = std::allocator<ft::pair<const Key,T> > >
class map {
	/*			***				MEMBER TYPE				***		*/
	public:
		typedef Key								key_type; // first 
		typedef T								mapped_type; // value_type 
		typedef ft::pair<key_type, mapped_type> value_type; // pair (key, value)
		typedef	std::size_t						size_type; // size_t
		typedef	std::ptrdiff_t					difference_type; // ptrdiff_t 
		typedef	Compare							key_compare; // compare key 
		typedef	Alloc							allocator_type;

		typedef	value_type&						reference;
		typedef	const value_type&				const_reference;
		typedef Node<value_type> 				node_type;
		typedef Node<value_type>				*node_ptr;
		

		typedef	ft::rb_iterator<value_type, node_type> iterator;
		typedef	ft::rb_iterator<value_type const, node_type const> const_iterator;
		
		typedef typename	allocator_type::pointer					pointer;
		typedef	typename	allocator_type::const_pointer			const_pointer;
		

		typedef ft::reverseIterator<iterator> reverse_iterator;
		typedef ft::reverseIterator<const_iterator> const_reverse_iterator;

	/*			***				MEMBER CLASS				***		*/

		class value_compare {
			protected:
				Compare comp;
			public :
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;

				value_compare() : comp(Compare()) {} 
				
				bool operator()( const value_type& lhs, const value_type& rhs ) const {
					return comp(lhs.first, rhs.first);
				};
		};
	protected:
		typedef ft::rbTree<key_type, value_type, get_key<value_type, key_type>, key_compare, Alloc> type_tree;
		allocator_type		_alloc;
		key_compare			_keyComp;
		value_compare		_valComp;
		type_tree			_tree;

	/*			***				MEMBER FUNCTIONS				***		*/
	public:
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _keyComp(comp), _tree() {}

		template< class InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(),
			const allocator_type& alloc = allocator_type()) 
			: _alloc(alloc), _keyComp(comp), _valComp(value_compare()), _tree() {
				insert(first, last);
		}
		
		map( const map& other ) : _alloc(other._alloc), _keyComp(other._keyComp), 
			_valComp(other._valComp) {
				insert(other.begin(), other.end());
		}
	
		~map() {}

		map& operator=( const map& x ) {
			if (this == &x)	// if x is the same object as *this, 
				return *this;// return *this
			if (_tree.getRoot() != _tree.getEnd()) // if tree is not empty clear tree
				clear();
			_alloc = x._alloc;
			_keyComp = x._keyComp;
			_valComp = x._valComp;
			insert(x.begin(), x.end());
			return *this;
		}
		
		allocator_type get_allocator() const {
			return _alloc;
		}
	/*			***				ELEMENT ACCESS				***		*/
		
		mapped_type &operator[](const key_type &k)
		{
			node_ptr val = _tree.searchTree(k);

			if (val != _tree.getEnd())	// if key exist return value
				return (val->data.second);	//
			else
			{

				_tree.insertNode(value_type(k, mapped_type())); // if key not exist insert new pair (key, value)
				val = _tree.searchTree(k); // search new pair (key, value) and return value
				return (val->data.second);
			}
		}
	/*			***				ITERATOR				***		*/
		
		iterator	begin() { 
			return iterator(_tree.getRoot(), _tree.mini(), _tree.getEnd()); 
		}

		const_iterator			begin() const { 
			return const_iterator(_tree.getRoot(), _tree.mini(), _tree.getEnd()); 
		}
		iterator end() { 
			return iterator(_tree.getRoot(), _tree.getEnd(), _tree.getEnd());
		}

		const_iterator end() const { 
			return const_iterator(_tree.getRoot(), _tree.getEnd(), _tree.getEnd());
		}

		reverse_iterator		rbegin() {
			return reverse_iterator(end());
		}

		const_reverse_iterator	rbegin() const { 
			return const_reverse_iterator(end());
		}

		reverse_iterator		rend() {
			return reverse_iterator(begin());
		}

		const_reverse_iterator	rend() const {
			return const_reverse_iterator(begin());
		}
	
	/*			***				[CAPACITY]				***		*/
		
		bool empty() const {
			return _tree.getSize() == 0;
		}

		size_type size() const {
			return _tree.getSize();
		}
		
		size_type max_size() const {
			return _tree.max_size();
		}
		
	/*			***				[MODIFIERS]				***		*/
		
		/*	clear all the map */
		void clear() {
			_tree.clear_h(_tree.getRoot());
		}

		/*	Basic insert  */
		ft::pair<iterator, bool> insert( const value_type& value ) {
			iterator it = find(value.first);
			if (it != end())	// if key exist return iterator to key and false 
				return (ft::pair<iterator,bool>(it, false)); // because key not inserted 
			else
			{
				_tree.insertNode(value); // if key not exist insert new pair (key, value)
				it = find(value.first);// search new pair (key, value) and return iterator to key
				return (ft::pair<iterator,bool>(it, true)); // because key inserted	
			}
		}

		/*	insert with a hint */
		iterator insert(iterator hint, const value_type& value) {
			(void)hint;
			return insert(value).first;	
		}

		/*	insert with an iterator */
		template< class InputIt >
		void insert( InputIt first, InputIt last ){
			while (first != last)
				insert(*first++);
			return ;
		}

		/*	Erase with an iterator*/
		void erase (iterator position)
		{
			this->erase(position->first);
		}

		/*	Erase with a key*/
		size_type erase(const key_type& k)
		{

			if (_tree.deleteNode(k) == true)
				return 1;
			return 0;
		}

		/*	Erase with a first and last*/
		void erase (iterator first, iterator last)
		{
			while (first != last)
				this->erase((first++)->first);
		}

		void swap(map& x) {
			_tree.swap(x._tree);
		}
	/*			***				[LOOKUP	FOR]			***		*/
		/*	Search if the k is in the tree (search in all the map)*/
		size_type count(const key_type& k) const
		{
			const_iterator beg = this->begin();	 
			const_iterator end = this->end();

			while (beg != end)
			{
				if ((beg++)->first == k)
					return (1);
			}
			return (0);
		}

		/*	Search a key in the tree and return an iterator !*/
		iterator find(const key_type &k)
		{
			node_ptr tmp = _tree.searchTree(k);
			if (tmp == _tree.getEnd())
				return (end());
			return iterator(_tree.getRoot(), tmp, _tree.getEnd());
		}

		const_iterator find(const key_type &k) const
		{
			node_ptr tmp = _tree.searchTree(k);
			if (tmp == _tree.getEnd())
				return (end());
			return const_iterator(_tree.getRoot(), tmp, _tree.getEnd());
		}

		pair<const_iterator,const_iterator> equal_range(const key_type &k) const //	Search the first element that is not lower than k
		{
			return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); //	We return a pair of iterator
		}

		pair<iterator,iterator> equal_range(const key_type &k)
		{
			return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
		}
	
		iterator lower_bound(const key_type &k)	//	Search the first element that is not lower than k
		{
			iterator beg = this->begin();	//	iterator to the first element
			iterator end = this->end();		//	iterator to the last element

			while (beg != end)	//	While we are not at the end
			{
				if (_keyComp(beg->first, k) == false)	//	If the key is not lower than k
					break;	//	We stop
				beg++;	//	Else we go to the next eleme
			}
			return (beg);	//	We return the iterator
		}

		const_iterator lower_bound(const key_type& k) const
		{
			const_iterator beg = this->begin();
			const_iterator end = this->end();

			while (beg != end)
			{
				if (_keyComp(beg->first, k) == false)
					break;
				beg++;
			}
			return (beg);
		}

		iterator upper_bound(const key_type& k)	//	Search the first element that is lower than k
		{
			iterator beg = this->begin();	//	iterator to the first element
			iterator end = this->end();	//	iterator to the last element

			while (beg != end)	//	While we are not at the end
			{
				if (_keyComp(k ,beg->first))	//	If the key is lower than k
					break;	//	We stop
				beg++;	//	Else we go to the next element
			}
			return (beg);	//	We return the iterator
		}

		const_iterator upper_bound(const key_type& k) const
		{
			const_iterator beg = this->begin();
			const_iterator end = this->end();

			while (beg != end)
			{
				if (_keyComp(k, beg->first))
					break;
				beg++;
			}
			return (beg);
		}
		
		key_compare key_comp() const {	//	Compare the keys
			return this->_keyComp;	//	Return the key compare
		}

		value_compare value_comp() const {	//	Compare the values
			return this->_valComp;	//	Return the value compare
		}
}; 

template< class Key, class T, class Compare, class Alloc >
void swap( ft::map<Key,T,Compare,Alloc>& lhs,
           ft::map<Key,T,Compare,Alloc>& rhs )
{
	lhs.swap(rhs);
}

template<class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs,
	const ft::map<Key, T, Compare, Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template<class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs,
	const ft::map<Key, T, Compare, Alloc>& rhs) {
	return !(lhs == rhs);
}

template<class Key, class T, class Compare, class Alloc>
bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs,
	const ft::map<Key, T, Compare, Alloc>& rhs) {
	return ft::lexicographical_compare(
		lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<class Key, class T, class Compare, class Alloc>
bool operator<=(const ft::map<Key, T, Compare, Alloc>& lhs,
	const ft::map<Key, T, Compare, Alloc>& rhs) {
	return !(rhs < lhs);
}

template<class Key, class T, class Compare, class Alloc>
bool operator>(const ft::map<Key, T, Compare, Alloc>& lhs,
	const ft::map<Key, T, Compare, Alloc>& rhs) {
	return rhs < lhs;
}

template<class Key, class T, class Compare, class Alloc>
bool operator>=(const ft::map<Key, T, Compare, Alloc>& lhs,
	const ft::map<Key, T, Compare, Alloc>& rhs) {
	return !(lhs < rhs);
};
}
#endif