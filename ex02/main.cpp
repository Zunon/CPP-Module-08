/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:19:18 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/17 17:37:58 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>

int	main(void) {
	std::cout << "=== MutantStack ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "stack: ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	std::cout << "=== std::list ===" << std::endl;
	std::list<int> nlist;
	nlist.push_back(5);
	nlist.push_back(17);
	std::cout << "top: " << nlist.back() << std::endl;
	nlist.pop_back();
	std::cout << "size: " << nlist.size() << std::endl;
	nlist.push_back(3);
	nlist.push_back(5);
	nlist.push_back(737);
	nlist.push_back(0);
	std::list<int>::iterator nit = nlist.begin();
	std::list<int>::iterator nite = nlist.end();
	++nit;
	--nit;
	std::cout << "stack: ";
	while (nit != nite) {
		std::cout << *nit << " ";
		++nit;
	}
	std::cout << std::endl;
	std::list<int> ns(nlist);
	return 0;
}