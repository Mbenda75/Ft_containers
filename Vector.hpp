#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include "Vector_iterator.hpp"
# include "equal.hpp"
# include "reverse_iterator.hpp"

/*	https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a01069_source.html#l00908 
	https://en.cppreference.com/w/cpp/container/vector 
	https://learn.microsoft.com/fr-fr/cpp/standard-library/vector-class?view=msvc-170 */

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
		_data(NULL), _size(0), _capacity(0), _allocator(alloc){
			return;
		}

		//fill (2)	
		explicit vector( size_type n, const T& value = T(), const Allocator& alloc = Allocator() ): 
		_data(NULL), _size(n), _capacity(n), _allocator(alloc){
			_data = _allocator.allocate(n);
			for (size_type i = 0; i < n; i++) {
				_allocator.construct(_data + i, value);
			}
		}

		//range (3)
		template< typename InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ): 
		_data(NULL), _size(0), _capacity(0), _allocator(alloc){
				while (first != last) {
					push_back(first);
					first++;
				}
		}

		//copy (4)	
		vector( const vector& cpy ): 
		_data(NULL), _size(0), _capacity(0), _allocator(cpy._allocator){
			*this = cpy;
		}

		~vector( void ){
			clear();
			_allocator.deallocate(_data, _size);
		}

		vector &	operator=( vector const & rhs )
		{
			if (this != &rhs)
			{
				clear();
				insert(end(), rhs.begin(), rhs.end());
			}
			return (*this);
		}
	/*-----------------------------------ELEMENT ACCESS-------------------------------------------------*/
		reference operator[](size_type pos)  { return _data[pos]; }
	
  		const_reference operator[](size_type pos) const { return _data[pos]; }

  		reference at(size_type pos) {
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
		    if (n < _size)
     			erase(begin() + n, end());
    		else
      			insert(end(), n - _size, val);
		}

	/*---------------------------MODIFIERS FUNCTIONS------------------------------------------*/

	 	size_type capacity() const { return _capacity; }

		size_type size() const { return _size; }

		void pop_back () {
			if (!_size)
				return ;
			_allocator.destroy(_data + _size - 1);
			_size--;
		}

		void push_back( const T & val ){
			if (_capacity == 0)
				reserve(1);
			if (_size + 1 > _capacity)
				reserve(_capacity * 2);
			_allocator.construct(_data + _size++, val);
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

		iterator erase (iterator pos) {
				vector	tmp(pos + 1, end());
				
				for (size_t i = 0; i <= tmp.size(); i++)
					pop_back();
				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					push_back(*it);
				return (pos);
			}


		iterator erase (iterator first, iterator last) {
				iterator tmp(first);

				while (tmp++ != last)
					erase(first);
				return (first);
			}     

		void clear(){
			if (_size > 0)
			{
				iterator it = this->begin();
				while (it != this->end())
					_allocator.destroy(&(*it++));
				_size = 0;
			}
		}

		void swap (vector& other) {
			std::swap(_data, other._data);
			std::swap(_size, other._size);
			std::swap(_capacity, other._capacity);
			std::swap(_allocator, other._allocator);
		}
	
		void insert(iterator position, const value_type &val)
		{
			difference_type index = position - begin();
			insert(position, 1, val);
			//return begin() + index;

		}
	
		void insert(iterator pos, size_type count, const T& val )
		{
			size_type index = pos - this->begin();
			if (_size + count > _capacity){
				size_t new_cap = 0;
				if (_capacity == 0)
					new_cap = 1;
				else
					new_cap = _size * 2;
				if (new_cap < _size + count)
					new_cap = _size + count;
				reserve(new_cap);
			}
			for (size_type i = _size; i > index; i--) {
				_allocator.construct(_data + i + count - 1, *(_data + i - 1));
				_allocator.destroy(_data + i - 1);
			}
			for (size_type i = 0; i < count; i++) {
				_allocator.construct(_data + index + i, val);
			} 
			_size = _size + count; 
		}
			template< class InputIt >
		void insert( iterator position, InputIt first, InputIt last)
		{ 
			size_type pos = position - begin();
			std::cout << "first =" << *first <<std::endl;
			std::cout << "position =" << *position <<std::endl;
			std::cout << "pos =" << pos<<std::endl;
			size_type nb = 0;
			
			for (InputIt tmp = first; tmp != last; tmp++) {
					 std::cout << "tmp = " <<*tmp << std::endl;  
				nb++;
			}
			if (nb + _size > _capacity)
			{
				size_t new_capacity = 0;
				if (_capacity == 0)
					new_capacity = 1;
				else
					new_capacity = _size * 2;
				if (new_capacity < _size + nb)
					new_capacity = _size + nb;
				reserve(new_capacity); // (otherwhise iterator `pos` is invalidated)
			}
			std::cout << "nb == " << nb << std::endl;
			std::cout << "size == " << _size << std::endl;
	 		for (size_t i = _size - 1; i >= (size_t)pos; i--){
				// move elements nb times to the right
				_allocator.construct(&_data[i + nb], _data[i]);
				 std::cout << "_data[i + nb] = " << _data[i + nb] << std::endl; 
				std::cout << "_data[i ] = " << _data[i] << std::endl;  // copy constructor
				_allocator.destroy(&_data[i]);					// call destructor
			}
	/* 		   for (iterator it = begin(); it != end(); *it++)
   			{
    			 std::cout << "it insert = " <<*it << std::endl;  
   			}   */
		
			for (InputIt ite = first; ite != last; ++ite)
			{
				 //std::cout << "it2 insert = " <<*ite << std::endl;  
				_allocator.construct(&_data[pos++], *ite); 
   			}  
			_size += nb;
		}
 
};
}

#endif /* ********************************************************** VECTOR_H */
