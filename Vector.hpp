#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include "Vector_iterator.hpp"


//typename mot clé indique que ce paramètre est un espace réservé pour un type
template<typename vector>
class vectorIterator;

namespace ft{

template<class T, class Allocator = std::allocator<T>>
class vector
{
	//The first template parameter (T)
		typedef T value_type;

      	//typedef 		T&       reference;
      	//typedef const 	T& const_reference;

		//The second template parameter (Allocator)
		typedef Allocator allocator_type;

		typedef std::ptrdiff_t  difference_type;
		typedef std::size_t size_type;
		typedef typename allocator_type::pointer    pointer;
		//typedef	typename allocator_type::const_pointer const_pointer;
		typedef vectorIterator<value_type> iterator;
		typedef vectorIterator<value_type> const_iterator;
		typedef vectorIterator<value_type> reverse_iterator;
		typedef vectorIterator<value_type> const_reverse_iterator;

	private:
			value_type		*_data;
			pointer 		 _ptr;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_allocator;


	/*----------------------------VECTOR CONSTRUCTOR -----------------------------------------------------*/

	public:
		//default (1)
		explicit vector( const Allocator &alloc = Allocator() ):
		_data(NULL), _size(0), _capacity(0), _allocator(alloc)
		{
			//std::cout << "default vectore const" << std::endl;
			return;
		}

		//fill (2)	
		//l'allocator permet d allouer ou desallouer de la memoire
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
/* 		bool empty() const;
		{
			return begin() == end();
		}
		size_type size() const;
		size_type max_size() const;
		size_type capacity() const;
		void resize (size_type n, ValueType val = value_type()); //_Size = capacity --> multiplier x2 capacity
		void reserve( size_type new_cap );
 */
	/*---------------------------MODIFIERS FUNCTIONS------------------------------------------*/
		void push_back( const T & val )//(since C++11) (until C++20) // faire le alloc construct
		{
			_data = _allocator.allocate(1);
			_allocator.construct(_data, val);
			_data[_size] = val;
			_size++;
		}
/* 	public:
		void clear();

		iterator insert( const_iterator pos, const T& value );
		iterator insert( const_iterator pos, size_type count, const T& value );
		template< class InputIt >
		iterator insert( const_iterator pos, InputIt first, InputIt last );	

		iterator erase( iterator pos ); //(until C++11)
		iterator erase( iterator first, iterator last );
		
		void resize( size_type count );// (since C++11) (until C++20)
		void swap( vector& other );//(until c++17) */
};
}

//std::ostream &			operator<<( std::ostream & o, Vector<T> const & i );

#endif /* ********************************************************** VECTOR_H */
