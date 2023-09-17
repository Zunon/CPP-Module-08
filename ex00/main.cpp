/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:46:36 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/17 10:56:51 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void) {
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		l.push_back(i);
		d.push_back(i);
	}

	std::cout << "vector: ";
	for (int i = 0; i < 10; i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	std::cout << "list: ";
	for (int i = 0; i < 10; i++)
		std::cout << l.front() << " ";
	std::cout << std::endl;

	std::cout << "deque: ";
	for (int i = 0; i < 10; i++)
		std::cout << d[i] << " ";
	std::cout << std::endl;

	std::cout << "easyfind(v, 5): " << easyfind(v, 5) << std::endl;
	std::cout << "easyfind(l, 5): " << easyfind(l, 5) << std::endl;
	std::cout << "easyfind(d, 5): " << easyfind(d, 5) << std::endl;

	std::cout << "easyfind(v, 42): ";
	try {
		std::cout << easyfind(v, 42) << std::endl;
	} catch (std::exception &e) {
		std::cout << "not found" << std::endl;
	}
	return (0);
}