#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>

namespace ft{

template<class T, class Allocator = std::allocator<T> >
class vector
{
	private:

			value_type		*_data;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_allocator;


	/*----------------------------VECTOR CONSTRUCTOR -----------------------------------------------------*/

	public:
		//default (1)
		explicit vector( const Allocator &alloc = Allocator() ):
		_data(NULL), _size(0), _capacity(0), _allocator(alloc)
		{
			return;
		}

		//fill (2)	
		explicit vector( size_type n, const T& value = T(), const Allocator& alloc = Allocator() ): 
		_data(NULL), _size(0), _capacity(0), _allocator(alloc)
		{
			//resize(n, value);
		}

		//range (3)
		template< typename InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ): 
		_data(NULL), _size(0), _capacity(0), _allocator(alloc)
		{
			//assignDispatch(first, last);
		}

		//copy (4)	
		vector( const vector& cpy ): 
		_data(NULL), _size(0), _capacity(0), _allocator(cpy._allocator)
		{
			*this = cpy;
		}

		~vector( void )
		{

			//this->clear();
			//_allocator.deallocate(this->_data, this->_capacity);
		}
	public:
		using ValueType = T;
		using Iterator = vectorIterator<vector<T>>;

	/*---------------------------------------ITERATOR FUNCTION-----------------------------------------*/
		iterator begin() 
     		{ return iterator(this->_data); }
	
		const_iterator begin() const
     		{ return const_iterator(this->_data); }

		iterator end() 
     		{ return iterator(this->_data[_size]); }
		
		const_iterator end() const
     		{ return const_iterator(this->_data[_size]); }

		reverse_iterator rbegin()
      		{ return reverse_iterator(end()); }

	  	const_reverse_iterator rbegin() const
      		{ return const_reverse_iterator(end()); }

		reverse_iterator rend() 
		    { return reverse_iterator(begin()); }

		const_reverse_iterator rend() const 
      		{ return const_reverse_iterator(begin()); }

		vector &	operator=( vector const & rhs );


	/*-----------------------------CAPACITY FUNCTIONS--------------------------------------- */
	public:
		bool empty() const;
		{
			return begin() == end();
		}
		size_type size() const;
		size_type max_size() const;
		size_type capacity() const;
		void resize (size_type n, ValueType val = value_type());
		void reserve( size_type new_cap );

	/*---------------------------MODIFIERS FUNCTIONS------------------------------------------*/
	public:
		void clear();
		iterator insert( const_iterator pos, size_type count, const T& value );
		constexpr iterator insert( const_iterator pos, size_type count, const T& value );
		iterator erase( iterator pos ); (until C++11)
		void push_back( T&& value );(since C++11) (until C++20)
		void resize( size_type count ); (since C++11) (until C++20)
		void swap( vector& other );(until c++17)





};
}

//std::ostream &			operator<<( std::ostream & o, Vector<T> const & i );

#endif /* ********************************************************** VECTOR_H */
