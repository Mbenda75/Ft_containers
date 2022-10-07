#include "Vector.hpp"

template<typename vector>
class vectorIterator
{

    public:
        using ValueType = typename vector::ValueType;
        //typedef typename vector::ValueType Valuetype
        using PointerType = ValueType*;
        //typedef ValueType PointerType;
        using ReferenceType = ValueType&;
        //typedef ValueType ReferenceType;

    public:
        vectorIterator(PointerType ptr): _ptr(ptr);


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

        vectorIterator& operator--()//incre apres assign
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

        ReferenceType operator[](int index)
        {
            return *(_ptr + index);//_ptr[index]
        }
        
        PointerType operator->()
        {
            return(_ptr);
        }
        ReferenceType operator*()
        {
            return *(_ptr);
        }
        
        bool operator== (const vectorIterator& equal) const
        {
            return *this == equal._ptr;
        }

        bool operator!= (const vectorIterator& equal) const
        {
            return *(this == equal._ptr);
        }
    private:
        PointerType _ptr;
};