/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:02:35 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/17 12:05:14 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _vector(new std::vector<int>), _used(0), _size(0) {}

Span::Span(unsigned int size) : _vector(new std::vector<int>()), _used(0), _size(size) {}

Span::Span(const Span &source) : _vector(new std::vector<int>(*source._vector)), _used(source._used), _size(source._size) {}

Span::~Span(void) {
	delete _vector;
}

Span			&Span::operator=(const Span &source) {
	if (this != &source) {
		delete _vector;
		_vector = new std::vector<int>(*source._vector);
		_used = source._used;
		_size = source._size;
	}
	return (*this);
}

void			Span::addNumber(int number) {
	if (getUsed() == getSize())
		throw FullException();
	_vector->push_back(number);
	_used++;
	std::sort(_vector->begin(), _vector->end());
}

int				Span::shortestSpan(void) {
	if (getUsed() < 2)
		throw NotEnoughNumbersException();
	int shortest = abs(_vector->at(0) - _vector->at(1));
	std::vector<int>::iterator iter = _vector->begin();
	while (iter != _vector->end() - 1) {
		int diff = abs(*(iter + 1) - *iter);
		if (diff < shortest)
			shortest = diff;
		iter++;
	}
	return (shortest);
}

int				Span::longestSpan(void) {
	if (getUsed() < 2)
		throw NotEnoughNumbersException();
	return (_vector->back() - _vector->front());
}

unsigned int	Span::getSize(void) const {
	return (_size);
}

unsigned int	Span::getUsed(void) const {
	return (_used);
}

std::vector<int>	*Span::getVector(void) const {
	return (_vector);
}

const char		*Span::FullException::what() const throw() {
	return ("Unable to add number: span is full");
}

const char		*Span::NotEnoughNumbersException::what() const throw() {
	return ("Not enough numbers to calculate span");
}