#ifndef TYPE_HPP
#define TYPE_HPP

#include <stdio.h>
#include <uchar.h>


/*	https://learn.microsoft.com/fr-fr/cpp/standard-library/enable-if-class?view=msvc-170 
	https://en.cppreference.com/w/cpp/types/enable_if */
namespace ft {
	
template <typename T>
struct is_integral {
	const static bool value = false;
};

template <>
struct is_integral<char> {
	const static bool value = true;
};

template <>
struct is_integral<wchar_t> {
	const static bool value = true;
};

template <>
struct is_integral<short> {
	const static bool value = true;
};

template <>
struct is_integral<int> {
	const static bool value = true;
};

template <>
struct is_integral<long> {
	const static bool value = true;
};

template <>
struct is_integral<long long> {
	const static bool value = true;
};

template <> 
struct is_integral<unsigned short> 
{ 
	static const bool value = true; 
};
	
template <>
struct is_integral<unsigned int> {
	static const bool value = true;
};

template <>
struct is_integral<unsigned long> {
	static const bool value = true;
};

template <>
struct is_integral<unsigned long long> {
	static const bool value = true;
};

/* */
template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> {
	typedef T type;
};
}

#endif 