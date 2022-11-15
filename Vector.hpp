#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include "Vector_iterator.hpp"
# include "reverse_iterator.hpp"

//typename mot clé indique que ce paramètre est un espace réservé pour un type

namespace ft{

template<class T, class Allocator = std::allocator<T>>
class vector
{
	public:
		/*-------------------------MEMBER TYPE--------------------------------------------*/
		//The first template parameter (T)
		typedef T value_type;

		//The second template parameter (Allocator)
		typedef Allocator allocator_type;
		
		typedef std::ptrdiff_t  difference_type;
		typedef std::size_t size_type;

		/*----------------------POINTER & REFERENCE -------------------------------------*/

		typedef typename allocator_type::pointer    pointer;
		typedef	typename allocator_type::const_pointer const_pointer;

		typedef typename allocator_type::reference reference;
  		typedef typename allocator_type::const_reference const_reference;

		/*------------------------VECTOR ITERATOR ------------------------------------*/

		typedef ft::vectorIterator<value_type> iterator;
		typedef ft::const_vectorIterator<value_type> const_iterator;


		typedef ft::reverseIterator<iterator> reverse_iterator;
		typedef ft::const_reverseIterator<iterator> const_reverse_iterator;

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
			//std::cout << "default vectore const" << std::endl;
			return;
		}

		//fill (2)	
		explicit vector( size_type n, const T& value = T(), const Allocator& alloc = Allocator() ): 
		_data(NULL), _size(0), _capacity(0), _allocator(alloc)
		{
			resize(n, value);
		}

		//range (3)
		template< typename InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ): 
		_data(NULL), _size(0), _capacity(0), _allocator(alloc)
		{
				while (first != last) {
					push_back(*first);
					first++;
				}
		}

		//copy (4)	
		vector( const vector& cpy ): 
		_data(NULL), _size(0), _capacity(0), _allocator(cpy._allocator)
		{
			*this = cpy;
		}

		~vector( void )
		{
			clear();
			_allocator.deallocate(_data, _size);
		}

	/*-----------------------------------ELEMENT ACCESS-------------------------------------------------*/
		reference operator[](size_type pos)  { return _data[pos]; }
	
  		const_reference operator[](size_type pos) const { return _data[pos]; }

  		reference at(size_type pos) 
		{
  		  if (pos >= _size) throw std::out_of_range("vector");
  		  return _data[pos];
  		}

  		const_reference at(size_type pos) const {
  		  if (pos >= _size) throw std::out_of_range("vector");
  		  return _data[pos];
  		}

  		reference front() { return _data[0]; }

  		const_reference front() const { return _data[0]; }

  		reference back() { return _data[_size - 1]; }

  		const_reference back() const { return _data[_size - 1]; }


	/*----------------------------------ITERATOR FUNCTION-----------------------------------------------*/
		iterator begin() 
     		{ return iterator(_data); }
	
		const_iterator begin() const
     		{ return const_iterator(_data); }

		iterator end() 
     		{ return iterator(_data + _size); }
		
 		const_iterator end() const
     		{ return const_iterator(_data + _size); }

	/*----------------------------------REVERSE ITERATOR FUNCTION-----------------------------------------------*/
	
		reverse_iterator rbegin() { return reverse_iterator(_data + _size - 1); }

		const_reverse_iterator rbegin() const { return rbegin(); }

		reverse_iterator rend() { return reverse_iterator(_data - 1); }
		
		const_reverse_iterator rend() const { return rend(); }


		vector &	operator=( vector const & rhs );


 	/*-----------------------------CAPACITY FUNCTIONS--------------------------------------- */
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
			clear();
			while (first != last)
				push_back(first++);}

		void assign (size_type n, const value_type& val) {
			clear();
			while (n--)
				push_back(val);}

		bool empty() const { return _size == 0; }
		
		size_type max_size() const {return _allocator.max_size();}
 
		void resize (size_type n, value_type val = value_type()) 
		{
			value_type *new_data = _allocator.allocate(n);
			if (n > _size) {
				for (size_t i = 0; i < _size; i++)
					_allocator.construct(new_data + i, *(_data + i));
				for (size_t i = 0; i < n - _size; i++)
					_allocator.construct(new_data + _size + i, val);
			}
			else {
				for (size_t i = 0; i < n; i++)
					_allocator.construct(new_data + i, *(_data + i));
			}
			if (_size) {
				_allocator.destroy(_data);
				_allocator.deallocate(_data, _capacity);
			}
			_capacity = n;
			_size = n;
			_data = new_data;
			_allocator.destroy(new_data);
			_allocator.deallocate(new_data, n);
		} 
/* 
		void resize (size_type n, value_type val = value_type()) 
		{
		    if (n < _size)
     			erase(begin() + n, end());
    		else
      			insert(end(), n - _size, val);
		} */

	/*---------------------------MODIFIERS FUNCTIONS------------------------------------------*/

	 	size_type capacity() const { return _capacity; }

		size_type size() const { return _size; }

		void pop_back () 
		{
			if (!_size)
				return ;
			_allocator.destroy(_data + _size - 1);
			_size--;
		}

		void push_back( const T & val )
		{
			if (_capacity == 0)
				reserve(1);
			while (_size + 1 > _capacity)
				reserve(_capacity * 2);
			_data[_size] = val;
			_size++;
		}

		void reserve(size_type new_cap) 
		{
    		if (new_cap == 0 || new_cap <= _capacity) return;

    		value_type *new_data = _allocator.allocate(new_cap);

    		for (size_type i = 0; i < _size; i++)
			{
    		  _allocator.construct(new_data + i, _data[i]);
    		  _allocator.destroy(_data + i);
    		}
    		_allocator.deallocate(_data, _capacity);
    		_capacity = new_cap;
    		_data = new_data;
		}

		iterator erase (iterator position) {
				vector	tmp(position + 1, end());
				
				for (size_t i = 0; i <= tmp.size(); i++)
					pop_back();
				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					push_back(*it);
				return (position);
			}


			iterator erase (iterator first, iterator last) {
				iterator tmp(first);

				while (tmp++ != last)
					erase(first);
				return (first);
			}     

	void clear()
	{
		if (_size > 0)
		{
			iterator it = this->begin();
			while (it != this->end())
				_allocator.destroy(&(*it++));
			_size = 0;
		}
	}

	void swap (vector& other) 
	{
		std::swap(_data, other._data);
		std::swap(_size, other._size);
		std::swap(_capacity, other._capacity);
		std::swap(_allocator, other._allocator);
	}
 
	void insert(iterator pos, const T& val )
	{
		value_type *new_d = _allocator.allocate(_size + 1);

		size_t i  = 0;
		size_t j  = 0;
		for (iterator it = this->begin(); it != this->end() + 1 ;*it++)
		{
			if (it == pos )
			{
				_allocator.construct(new_d + i, val);
				i++;
			}
			else
			{
				_allocator.construct(new_d + i, _data[j]);
				i++;
				j++;
			}
		}
		resize(_size + 1, val);
		_data = new_d;
	}
 
	void insert(iterator pos, size_type count, const T& val )
	{
		value_type *new_ins = _allocator.allocate(count + _size);

		size_t j =0;
		for (iterator it = this->begin();it != pos;*it++)
		{
			_allocator.construct(new_ins + j, _data[j]);
			//_allocator.destroy(_data + j);
			j++;
		}
		size_t save = j;
	  	for (size_t i = 0; i < count;i++)
		{
			_allocator.construct(new_ins + j, val);
			j++;
		}   
   	 	for (size_t i = j ; i < _size + count ;i++)
		{
			_allocator.construct(new_ins+ i, _data[save]);
			 //_allocator.destroy(_data + save);
			save++;
		}  
		resize(_size + count, val);  
		_data = new_ins;
	}

/* 	public:
		template< class InputIt >
		iterator insert( iterator pos, InputIt first, InputIt last);	
 */
};
}

#endif /* ********************************************************** VECTOR_H */
