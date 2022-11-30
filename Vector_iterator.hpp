#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

/* 
                | acces      | read         | write    | iterate      | compare
input :         | ->         | =*i          |          | ++           | == , !=             
outpout :       |            |              |*i =      | ++           |          
forward :       | ->         |  =*i         |*i =      | ++           | == , !=                 
bi-directional :|            |  =*i         |*i =      | ++,--        | == , !=                  
random-access : | >          |  =*i         |*i =      | ++,--,+,-,+= | == , != , <,>,<=,>=  */        


/* https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a01052_source.html
   https://www.geeksforgeeks.org/introduction-iterators-c 
   https://www.geeksforgeeks.org/bidirectional-iterators-in-cpp/
   https://www.geeksforgeeks.org/random-access-iterators-in-cpp/ 
   https://stacklima.com/introduction-aux-iterateurs-en-c/ */
   

namespace ft
{
    template<typename T>
    class vectorIterator
    {
        public:
            typedef T               value_type;
            typedef size_t          size_type;
            typedef std::ptrdiff_t difference_type;
            typedef T *             pointer;
            typedef T &             reference;
            typedef std::random_access_iterator_tag iterator_category;

        private:
            pointer _ptr;

        public:
            vectorIterator()  {}

            vectorIterator(pointer ptr): _ptr(ptr) {}

            vectorIterator(const vectorIterator&lhs) : _ptr(lhs._ptr) {}

            operator vectorIterator<value_type const>() const
		        {
		        	return vectorIterator<value_type const>(_ptr);
		        }
            
            vectorIterator& operator++()//incre apres assisn
            {
                _ptr++;
                return *this;
            }

            vectorIterator operator++(int)//incre avant assign
            {
                vectorIterator iterator = *this;
                ++(*this);
                return iterator;
            }

            vectorIterator& operator--()//incr e apres assign
            {
                _ptr--;
                return *this;
            }

            vectorIterator operator--(int)//incre avant assign
            {
                vectorIterator iterator = *this;
                --(*this);
                return iterator;
            }


		        vectorIterator &operator+=(difference_type n)
		        {
		        	_ptr += n;
		        	return (*this);
		        }

            	vectorIterator &operator-=(difference_type n)
		        {
		        	_ptr -= n;
		        	return (*this);
		        }


            reference operator[](int index)
            {
                return *(_ptr + index);//_ptr[index]
            }

            reference operator*() const { return *_ptr; }

  		      pointer operator->() const { return _ptr; }

            vectorIterator operator +(difference_type other) { return vectorIterator(_ptr + other); }
			      vectorIterator operator -(difference_type other) { return vectorIterator(_ptr - other); }
			      difference_type operator +(vectorIterator other) { return _ptr + other._ptr; }
			      difference_type operator -(vectorIterator other) { return _ptr - other._ptr; }

          
            bool operator==(const vectorIterator &rhs) {
              return _ptr == rhs._ptr;
            }
            
            bool operator!=(const vectorIterator &rhs) {
              return !(_ptr == rhs._ptr);
            }
            
            bool operator<(const vectorIterator &rhs) {
              return _ptr < rhs._ptr;
            }
            
            bool operator>(const vectorIterator &rhs) {
              return rhs._ptr < _ptr;
            }
            
            bool operator<=(const vectorIterator &rhs) {
              return !(_ptr > rhs._ptr);
            }
            
            bool operator>=(const vectorIterator &rhs) {
              return !(_ptr < rhs._ptr);
            } 

    };

}

#endif