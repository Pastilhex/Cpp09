/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/12 20:25:31 by ialves-m         ###   ########.fr       */
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

std::vector<int> PmergeMe::readVectorMainChain()
{
	return this->_vectorMainChain;
};

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
	_counter = 0; // Contador de comparações

	for (std::vector<std::pair<int, int> >::iterator it = _vectorPairs.begin(); it != _vectorPairs.end(); it++)
	{
		if ((*it).first < (*it).second)
		{
			int tmp = (*it).first;
			(*it).first = (*it).second;
			(*it).second = tmp;
		}
		_counter++; // Contador de comparações
	}
}

void	PmergeMe::mergeSort(std::vector<std::pair<int, int> >&array)
{
	int length = array.size();
	if (length <= 1)
		return ;
	
	int middle = length / 2;
	std::vector<std::pair<int, int> > leftArray(middle);
	std::vector<std::pair<int, int> > rightArray(length - middle);
	
	int i = 0, j = 0;

	for(; i < length; i++) 
	{
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

void	PmergeMe::merge(std::vector<std::pair<int, int> >& array, std::vector<std::pair<int, int> > &leftArray, std::vector<std::pair<int, int> > &rightArray)
{
	int leftSize = array.size() / 2;
	int rightSize = array.size() - leftSize;
	int i = 0, l = 0, r = 0;
	
	while(l < leftSize && r < rightSize) 
	{
		if(leftArray[l].first < rightArray[r].first) 
		{
			array[i] = leftArray[l];
			i++;
			l++;
		}
		else 
		{
			array[i] = rightArray[r];
			i++;
			r++;
		}
		_counter++; // Contador de comparações
	}
	while(l < leftSize) 
	{
		array[i] = leftArray[l];
		i++;
		l++;
	}
	while(r < rightSize) 
	{
		array[i] = rightArray[r];
		i++;
		r++;
	}
}

void	PmergeMe::binaryInsertion(std::vector<int> &array, int value)
{
	int begin = 0;
	int end = array.size();
	
	while (begin < end)
	{
		int mid = begin + (end - begin) / 2;

		if (array[mid] <= value)
			begin = mid + 1;
		else
			end = mid;
		_counter++; // Contador de comparações
	}
	array.insert(array.begin() + begin, value);
}

void	PmergeMe::insertionSort()
{
	long unsigned int i = 0;
	long unsigned int j = 0;
	
	_vectorMainChain.push_back(_vectorPairs[j++].second);
	_vectorMainChain.push_back(_vectorPairs[i++].first);
	_vectorMainChain.push_back(_vectorPairs[j++].first);

	while (i < _vectorPairs.size() / 2)
	{
		binaryInsertion(_vectorMainChain, _vectorPairs[i + 1].second);
		binaryInsertion(_vectorMainChain, _vectorPairs[i].second);
		i += 2;
	}

	while (j < _vectorPairs.size() / 2)
	{
		_vectorMainChain.push_back(_vectorPairs[j++].first);
	}

	if (_vectorUnsorted.size() % 2 != 0)
		binaryInsertion(_vectorMainChain, _vectorUnsorted[_vectorUnsorted.size() - 1]);
	
	i = _vectorPairs.size() - 1;
	while (i > _vectorPairs.size() / 2)
	{
		binaryInsertion(_vectorMainChain, _vectorPairs[i--].second);
	}

	while (j < _vectorPairs.size())
	{
		_vectorMainChain.push_back(_vectorPairs[j++].first);
	}
	
	std::cout << "Comparações efetuadas: " << _counter << std::endl;
}
