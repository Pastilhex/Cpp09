/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/11 18:54:02 by ialves-m         ###   ########.fr       */
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

std::vector<int> PmergeMe::readVector()
{
	return this->_vectorUnsorted;
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
		this->_vectorUnsorted.push_back(value);
		i++;
	}
}

std::vector<std::pair<int, int> >* PmergeMe::readPairs()
{
	return &this->_vectorPairs;
}

void	PmergeMe::createPairs()
{
	int size = _vectorUnsorted.size() / 2;
	int i = 0;

	while (size > 0)
	{
		_vectorPairs.push_back(std::make_pair(_vectorUnsorted[i], _vectorUnsorted[i+1]));
		size--;
		i += 2;
	}
}

void	PmergeMe::sortPairs()
{
	for (std::vector<std::pair<int, int> >::iterator it = _vectorPairs.begin(); it != _vectorPairs.end(); it++)
	{
		if ((*it).first < (*it).second)
		{
			int tmp = (*it).first;
			(*it).first = (*it).second;
			(*it).second = tmp;
		}
	}
}

void	PmergeMe::mergeSort(std::vector<std::pair<int, int> >&array)
{
	int length = array.size();
	if (length <= 1)
		return ;
	
	int middle = length / 2;
	std::vector<std::pair<int, int> > leftArray(middle);
	std::vector<std::pair<int, int> > rightArray(middle);
	
	int i = 0, j = 0;

	for(; i < length; i++) {
		if(i < middle) {
			leftArray[i] = array[i];
		}
		else {
			rightArray[j] = array[i];
			j++;
		}
	}
	
	mergeSort(leftArray);
	mergeSort(rightArray);
	merge(array, leftArray, rightArray);
}

int PmergeMe::binarySearch(std::vector<int> array, int item, int low, int high)
{
	while (low <= high) 
	{
		int mid = low + (high - low) / 2;

		if (item == array[mid])
			return mid + 1;
		else if (item > array[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return low;
}

void	PmergeMe::binaryInsertion(std::vector<int> array, int pos)
{
	
}

void	PmergeMe::insertionSort()
{
	_vectorMainChain.push_back(_vectorPairs[0].second);

	int j = 1, pos = 0;

	for (std::vector<int>::iterator it = _vectorMainChain.begin(); it < _vectorMainChain.end(); it++)
	{
		pos = binarySearch(_vectorMainChain, _vectorPairs[j].second, *it, _vectorMainChain.size() - 1);
		std::cout << pos;
	}
}

void	PmergeMe::merge(std::vector<std::pair<int, int> >& array, std::vector<std::pair<int, int> > &leftArray, std::vector<std::pair<int, int> > &rightArray)
{
	int leftSize = array.size() / 2;
	int rightSize = array.size() - leftSize;
	int i = 0, l = 0, r = 0;
	
	while(l < leftSize && r < rightSize) {
		if(leftArray[l].first < rightArray[r].first) {
			array[i] = leftArray[l];
			i++;
			l++;
		}
		else {
			array[i] = rightArray[r];
			i++;
			r++;
		}
	}
	while(l < leftSize) {
		array[i] = leftArray[l];
		i++;
		l++;
	}
	while(r < rightSize) {
		array[i] = rightArray[r];
		i++;
		r++;
	}
}
