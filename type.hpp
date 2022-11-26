/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:31:33 by snarain           #+#    #+#             */
/*   Updated: 2022/11/25 18:57:54 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_HPP
#define TYPE_HPP

#include <uchar.h>

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