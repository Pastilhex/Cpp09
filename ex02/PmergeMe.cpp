/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/14 18:15:15 by ialves-m         ###   ########.fr       */
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
	{
		std::vector<int> _vectorUnsorted;
		std::vector<std::pair<int,int> > _vectorPairs;
		std::vector<int> _vectorMainChain;

		this->_vectorUnsorted = obj._vectorUnsorted;
		this->_vectorPairs = obj._vectorPairs;
		this->_vectorMainChain = obj._vectorMainChain;
	}
	return *this;
};

PmergeMe::exception::exception() {}

PmergeMe::exception::~exception() throw() {}

const char*	PmergeMe::exception::what() const throw()
{
	return ("Error detected!");
}

double	vectorPmergeMe(char *argv[], PmergeMe &vectorSort)
{
	struct timeval start, end;

	vectorSort.createVector(argv);

	gettimeofday(&start, NULL);
	vectorSort.createVectorPairs();
	vectorSort.sortVectorPairs();
	std::vector<std::pair<int, int> >* ptrPairs = vectorSort.readVectorPairs();
	vectorSort.mergeVectorSort(*ptrPairs);
	vectorSort.insertionSortVector();
	gettimeofday(&end, NULL);

	return (end.tv_usec - start.tv_usec);
}

double	dequePmergeMe(char *argv[], PmergeMe &dequeSort)
{
	struct timeval start, end;

	dequeSort.createDeque(argv);

	gettimeofday(&start, NULL);
	dequeSort.createDequePairs();
	dequeSort.sortDequePairs();
	std::deque<std::pair<int, int> >* ptrPairs = dequeSort.readDequePairs();
	dequeSort.mergeDequeSort(*ptrPairs);
	dequeSort.insertionSortDeque();
	gettimeofday(&end, NULL);

	return (end.tv_usec - start.tv_usec);
}

std::vector<int>	PmergeMe::readVectorMainChain()
{
	return this->_vectorMainChain;
};

std::vector<int>	PmergeMe::readVector()
{
	return this->_vectorUnsorted;
};

std::vector<std::pair<int, int> >*	PmergeMe::readVectorPairs()
{
	return &this->_vectorPairs;
}

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

void	PmergeMe::createVectorPairs()
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

void	PmergeMe::sortVectorPairs()
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

void	PmergeMe::mergeVectorSort(std::vector<std::pair<int, int> >&array)
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
	
	mergeVectorSort(leftArray);
	mergeVectorSort(rightArray);
	mergeVector(array, leftArray, rightArray);
}

void	PmergeMe::mergeVector(std::vector<std::pair<int, int> >& array, std::vector<std::pair<int, int> > &leftArray, std::vector<std::pair<int, int> > &rightArray)
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

void	PmergeMe::binaryInsertionVector(std::vector<int> &array, int value)
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
	}
	array.insert(array.begin() + begin, value);
}

void	PmergeMe::insertionSortVector()
{
	long unsigned int i = 0;
	long unsigned int j = 0;
	
	_vectorMainChain.push_back(_vectorPairs[j++].second);
	_vectorMainChain.push_back(_vectorPairs[i++].first);
	_vectorMainChain.push_back(_vectorPairs[j++].first);

	while (i < _vectorPairs.size() / 2)
	{
		binaryInsertionVector(_vectorMainChain, _vectorPairs[i + 1].second);
		binaryInsertionVector(_vectorMainChain, _vectorPairs[i].second);
		i += 2;
	}

	while (j < _vectorPairs.size() / 2)
	{
		_vectorMainChain.push_back(_vectorPairs[j++].first);
	}

	if (_vectorUnsorted.size() % 2 != 0)
		binaryInsertionVector(_vectorMainChain, _vectorUnsorted[_vectorUnsorted.size() - 1]);
	
	i = _vectorPairs.size() - 1;
	while (i > _vectorPairs.size() / 2)
	{
		binaryInsertionVector(_vectorMainChain, _vectorPairs[i--].second);
	}

	while (j < _vectorPairs.size())
	{
		_vectorMainChain.push_back(_vectorPairs[j++].first);
	}
	
}

void	printVector(std::vector<int> &vector)
{
	std::vector<int>::iterator it;

	for (it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
}

void	printDeque(std::deque<int> &deque)
{
	std::deque<int>::iterator it;

	for (it = deque.begin(); it != deque.end(); it++)
		std::cout << *it << " ";
}

std::deque<int>	PmergeMe::readDequeMainChain()
{
	return this->_dequeMainChain;
};

std::deque<int>	PmergeMe::readDeque()
{
	return this->_dequeUnsorted;
};

std::deque<std::pair<int, int> >*	PmergeMe::readDequePairs()
{
	return &this->_dequePairs;
}

void	PmergeMe::createDeque(char* argv[])
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

		this->_dequeUnsorted.push_back(value);
		i++;
	}
}

void	PmergeMe::createDequePairs()
{
	int size = _dequeUnsorted.size() / 2;
	int i = 0;

	while (size > 0)
	{
		_dequePairs.push_back(std::make_pair(_dequeUnsorted[i], _dequeUnsorted[i+1]));
		size--;
		i += 2;
	}
}

void	PmergeMe::sortDequePairs()
{
	for (std::deque<std::pair<int, int> >::iterator it = _dequePairs.begin(); it != _dequePairs.end(); it++)
	{
		if ((*it).first < (*it).second)
		{
			int tmp = (*it).first;
			(*it).first = (*it).second;
			(*it).second = tmp;
		}
	}
}

void	PmergeMe::mergeDequeSort(std::deque<std::pair<int, int> >&array)
{
	int length = array.size();
	if (length <= 1)
		return ;
	
	int middle = length / 2;
	std::deque<std::pair<int, int> > leftArray(middle);
	std::deque<std::pair<int, int> > rightArray(length - middle);
	
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
	
	mergeDequeSort(leftArray);
	mergeDequeSort(rightArray);
	mergeDeque(array, leftArray, rightArray);
}

void	PmergeMe::mergeDeque(std::deque<std::pair<int, int> >& array, std::deque<std::pair<int, int> > &leftArray, std::deque<std::pair<int, int> > &rightArray)
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

void	PmergeMe::binaryInsertionDeque(std::deque<int> &array, int value)
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
	}
	array.insert(array.begin() + begin, value);
}

void	PmergeMe::insertionSortDeque()
{
	long unsigned int i = 0;
	long unsigned int j = 0;
	
	_dequeMainChain.push_back(_dequePairs[j++].second);
	_dequeMainChain.push_back(_dequePairs[i++].first);
	_dequeMainChain.push_back(_dequePairs[j++].first);

	while (i < _dequePairs.size() / 2)
	{
		binaryInsertionDeque(_dequeMainChain, _dequePairs[i + 1].second);
		binaryInsertionDeque(_dequeMainChain, _dequePairs[i].second);
		i += 2;
	}

	while (j < _dequePairs.size() / 2)
	{
		_dequeMainChain.push_back(_dequePairs[j++].first);
	}

	if (_dequeUnsorted.size() % 2 != 0)
		binaryInsertionDeque(_dequeMainChain, _dequeUnsorted[_dequeUnsorted.size() - 1]);
	
	i = _dequePairs.size() - 1;
	while (i > _dequePairs.size() / 2)
	{
		binaryInsertionDeque(_dequeMainChain, _dequePairs[i--].second);
	}

	while (j < _dequePairs.size())
	{
		_dequeMainChain.push_back(_dequePairs[j++].first);
	}
	
}
