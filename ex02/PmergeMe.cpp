/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/08 19:06:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe& original)
{
	*this = original;
};

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if (this != &obj)
		*this = obj;
	return *this;			// ajustar no final
};

PmergeMe::exception::exception()
{
}

PmergeMe::exception::~exception() throw()
{
}

const char* PmergeMe::exception::what() const throw()
{
	return ("Error detected!");
}

std::vector<int> PmergeMe::readVectorFD()
{
	return this->_vectorFD;
};

void	PmergeMe::createVector(char* argv[])
{
	int i = 1, value = 0;
	char* ptr;

	while (argv[i])
	{
		if (argv[i][0] == '\0')
			throw (PmergeMe::exception());
		value = std::strtol(argv[i], &ptr, 10);
		if (*ptr != '\0' || value < 0)
			throw (PmergeMe::exception());
		this->_vectorFD.push_back(value);
		i++;
	}
}

void	PmergeMe::createPairs(const std::vector<int> &vec)
{
	std::vector<std::pair<int,int> > vecPairs;
	int size = vec.size() / 2;
	int i = 0;

	while (size > 0)
	{
		vecPairs.push_back(std::make_pair(vec[i], vec[i+1]));
		size--;
		i += 2;
	}
}