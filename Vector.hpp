#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>

template<class T, class Allocator = std::allocator<T> >
class vector
{

				/* VECTOR CONSTRUCTOR */
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
			printf( )
			//this->clear();
			//_allocator.deallocate(this->_data, this->_capacity);
		}
	public:
		using ValueType = T;
		using Iterator = vectorIterator<vector<T>>;


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

	private:

			value_type		*_data;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_allocator;


};

//std::ostream &			operator<<( std::ostream & o, Vector<T> const & i );

#endif /* ********************************************************** VECTOR_H  
