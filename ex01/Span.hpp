/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:02:37 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/17 12:05:23 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>

class	Span {
	private:
		std::vector<int>	*_vector;
		unsigned int		_used;
		unsigned int		_size;
		
	public:
		Span	(void);
		Span	(unsigned int);
		Span	(const Span &);
		~Span	(void);
		Span	&operator=(const Span &);

		void							addNumber(int);
		template <typename T>	void	addNumber(T);
		template <typename T>	void	addNumber(T, T);
		int								shortestSpan(void);
		int								longestSpan(void);
		unsigned int					getSize(void) const;
		unsigned int					getUsed(void) const;
		std::vector<int>				*getVector(void) const;

		class FullException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

template <typename T>
void	Span::addNumber(T source) {
	if (getUsed() + source.size() > getSize())
		throw FullException();
	_vector->insert(_vector->end(), source.begin(), source.end());
	std::sort(_vector->begin(), _vector->end());
	_used += source.size();
};

template <typename T>
void	Span::addNumber(T begin, T end) {
	if (getUsed() + std::distance(begin, end) > getSize())
		throw FullException();
	_vector->insert(_vector->end(), begin, end);
	std::sort(_vector->begin(), _vector->end());
	_used += std::distance(begin, end);
};

#endif