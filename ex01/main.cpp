/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:01:03 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/17 12:07:24 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

int main(void) {
	Span s(5);
	s.addNumber(5);
	try {
		s.shortestSpan();
	} catch (Span::NotEnoughNumbersException &e) {
		std::cout << "exception caught: " << e.what() << std::endl;
	}
	s.addNumber(3);
	s.addNumber(17);
	s.addNumber(9);
	s.addNumber(11);
	try {
		s.addNumber(11);
	} catch (Span::FullException &e) {
		std::cout << "exception caught: " << e.what() << std::endl;
	}
	std::cout << "shortest span: " << s.shortestSpan() << std::endl;
	std::cout << "longest span: " << s.longestSpan() << std::endl;

	std::vector<int> bigVector;
	Span randSpan(10000);

	for (int i = 0; i < 10000; i++) {
		srand(rand() * i + time(NULL));
		bigVector.push_back(rand());
	}
	try {
		randSpan.addNumber(bigVector);
	} catch (std::exception &e) {
		std::cout << "exception caught: " << e.what() << std::endl;
	}
	std::cout << "shortest span: " << randSpan.shortestSpan() << std::endl;
	std::cout << "longest span: " << randSpan.longestSpan() << std::endl;
	return (0);
}