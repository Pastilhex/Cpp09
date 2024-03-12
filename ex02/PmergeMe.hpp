/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:52:39 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/12 19:06:12 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PMERGEME_
# define _PMERGEME_

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

class PmergeMe
{
private:
	std::vector<int> _vectorUnsorted;
	std::vector<std::pair<int,int> > _vectorPairs;
	std::vector<int> _vectorMainChain;
	std::vector<int> _vectorPending;
	int	_counter;

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe& operator=(const PmergeMe&);
	
	std::vector<int> readVector();
	std::vector<std::pair<int, int> >* readPairs();
	std::vector<int> readVectorMainChain();
	void	createVector(char *argv[]);
	void	createPairs();
	void	sortPairs();
	void	merge(std::vector<std::pair<int, int> >& array, std::vector<std::pair<int, int> > &leftArray, std::vector<std::pair<int, int> > &rightArray);
	void	mergeSort(std::vector<std::pair<int, int> >&array);
	void	insertionSort();
	void	binaryInsertion(std::vector<int>&, int pos);

	class exception : public std::exception
	{
	public:
		exception();
		virtual ~exception() throw();
		virtual const char *what() const throw();
	};
};

#endif