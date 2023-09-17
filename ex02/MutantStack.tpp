/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:19:37 by kalmheir          #+#    #+#             */
/*   Updated: 2023/09/17 17:33:48 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
class MutantStack: public std::stack<T> {
	private:
	public:
		MutantStack		(void) : std::stack<T>() {};
		MutantStack		(const MutantStack &source) : std::stack<T>() {
			if (this != &source)
				*this = source;
		};
		~MutantStack	(void) {};
		MutantStack		&operator=(const MutantStack &) {
			return *this;
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void) { return this->c.begin(); };
		iterator end(void) { return this->c.end(); };
};