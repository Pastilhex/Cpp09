/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:52:39 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/14 17:51:11 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PMERGEME_
# define _PMERGEME_

#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <cstdlib>
#include <sys/time.h>

class PmergeMe
{
private:
	std::vector<int> _vectorUnsorted;
	std::vector<std::pair<int,int> > _vectorPairs;
	std::vector<int> _vectorMainChain;

	std::deque<int> _dequeUnsorted;
	std::deque<std::pair<int, int> > _dequePairs;
	std::deque<int> _dequeMainChain;

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe& operator=(const PmergeMe&);
	
	std::vector<int> readVector();
	std::vector<std::pair<int, int> >* readVectorPairs();
	std::vector<int> readVectorMainChain();

	std::deque<int> readDeque();
	std::deque<std::pair<int, int> >* readDequePairs();
	std::deque<int> readDequeMainChain();

	void	createVector(char *argv[]);
	void	createVectorPairs();
	void	sortVectorPairs();
	void	mergeVector(std::vector<std::pair<int, int> >& array, std::vector<std::pair<int, int> > &leftArray, std::vector<std::pair<int, int> > &rightArray);
	void	mergeVectorSort(std::vector<std::pair<int, int> >&array);
	void	insertionSortVector();
	void	binaryInsertionVector(std::vector<int>&, int pos);

	void	createDeque(char *argv[]);
	void	createDequePairs();
	void	sortDequePairs();
	void	mergeDeque(std::deque<std::pair<int, int> >& array, std::deque<std::pair<int, int> > &leftArray, std::deque<std::pair<int, int> > &rightArray);
	void	mergeDequeSort(std::deque<std::pair<int, int> >&array);
	void	insertionSortDeque();
	void	binaryInsertionDeque(std::deque<int>&, int pos);
	
	class exception : public std::exception
	{
	public:
		exception();
		virtual ~exception() throw();
		virtual const char *what() const throw();
	};
};

double	vectorPmergeMe(char *argv[], PmergeMe &vectorSort);
double	dequePmergeMe(char *argv[], PmergeMe &dequeSort);
void	printVector(std::vector<int>&);
void	printDeque(std::deque<int>&);

#endif