#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

#include "Iterator_traits.hpp"


/*	https://en.cppreference.com/w/cpp/iterator/reverse_iterator 
	https://learn.microsoft.com/fr-fr/cpp/standard-library/reverse-iterator-class?view=msvc-170#op_at 
	https://www.youtube.com/watch?v=V89gtNl4pZM
*/
namespace ft {

template < class Ite >
	class reverseIterator 
    {       
	    public :
            typedef Ite iterator_type;
            typedef typename iterator_traits<Ite>::iterator_category iterator_category;
            typedef typename iterator_traits<Ite>::value_type value_type;
            typedef typename iterator_traits<Ite>::difference_type difference_type;
            typedef typename iterator_traits<Ite>::pointer pointer;
            typedef typename iterator_traits<Ite>::reference reference;

        private :
			iterator_type _ptr;

        public:
		    reverseIterator() : _ptr(iterator_type()) {}
		    reverseIterator(iterator_type it) : _ptr(it) {}
		    template<class Iterator>
		    reverseIterator(reverseIterator<Iterator> const &it) : _ptr(it._ptr) {}
		    reverseIterator &operator=(reverseIterator const &ite1)
		    {
			  if (this == &ite1)
				  return (*this);
			  _ptr = ite1._ptr;
			  return (*this);
		    }
		    ~reverseIterator() {}

		    iterator_type base() const
		    {
		    	return _ptr;
		    }

		    reverseIterator operator++() {
				_ptr--;
				return (*this);
			}
		
			reverseIterator operator++(int) {
                reverseIterator tmp = *this;
				--_ptr;
				return (tmp);
			}
		
			reverseIterator operator--() {
				_ptr++;
				return (*this);
			}
		
			reverseIterator operator--(int) {
                reverseIterator tmp = *this;
				_ptr++;
				return (tmp);
			}

			reverseIterator operator +=(difference_type n) { _ptr -= n; return *this;}
			reverseIterator operator -=(difference_type n) { _ptr += n; return *this;}

			reverseIterator operator+(difference_type n) { return reverseIterator(_ptr - n); }
			reverseIterator operator-(difference_type n) { return reverseIterator(_ptr + n); }

			reference operator*() const { return *_ptr; }

			pointer operator->() const { return _ptr; }

			reference operator[](difference_type n) const { return *(_ptr + n); }


			difference_type _comp(const reverseIterator rhs) const
			{
				return (rhs.base() - this->_ptr);
			}

	}; 
    
	
        template <class Iterator, class Iter>
	    bool operator==(const reverseIterator<Iterator> &ite1, const reverseIterator<Iter> &ite2)
	    {
	    	return (ite1.base() == ite2.base());
	    }  
	    template <class Iterator, class Iter>
	    bool operator!= (const reverseIterator<Iterator> &ite1, const reverseIterator<Iter> &ite2)
	    {
	    	return (ite1.base() != ite2.base());
	    }  
	    template <class Iterator, class Iter>
	    bool operator<(const reverseIterator<Iterator> &ite1, const reverseIterator<Iter> &ite2)
	    {
	    	return (ite1.base() > ite2.base());
	    }  
	    template <class Iterator, class Iter>
	    bool operator<=(const reverseIterator<Iterator> &ite1, const reverseIterator<Iter> &ite2)
	    {
	    	return (ite1.base() >= ite2.base());
	    }  
	    template <class Iterator, class Iter>
	    bool operator>(const reverseIterator<Iterator> &ite1, const reverseIterator<Iter> &ite2)
	    {
	    	return (ite1.base() < ite2.base());
	    }  
	    template <class Iterator, class Iter>
	    bool operator>=(const reverseIterator<Iterator> &ite1, const reverseIterator<Iter> &ite2)
	    {
	    	return (ite1.base() <= ite2.base());
	    }  
	    template <class Iterator>
	    reverseIterator<Iterator> operator+(typename reverseIterator<Iterator>::difference_type n, const reverseIterator<Iterator> &it)
	    {
	    	return (it + n);
	    }  
	    template <class Iterator>
	    typename reverseIterator<Iterator>::difference_type operator-(const reverseIterator<Iterator> &ite1, const reverseIterator<Iterator> &ite2)
	    {
	    	return (ite1._comp(ite2));
	    }  
	    template <class Iterator, class Iter>
	    reverseIterator<Iterator> operator+(typename reverseIterator<Iterator>::difference_type n, const reverseIterator<Iter> &it)
	    {
	    	return (it + n);
	    }  
	    template <class Iterator, class Iter>
	    typename reverseIterator<Iterator>::difference_type operator-(const reverseIterator<Iterator> &ite1, const reverseIterator<Iter> &ite2)
	    {
	    	return (ite1._comp(ite2));
	    }
}
  
#endif