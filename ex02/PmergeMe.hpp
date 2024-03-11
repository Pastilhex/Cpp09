/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:52:39 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/08 17:35:38 by ialves-m         ###   ########.fr       */
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
	std::vector<int> _vectorFD;
	std::vector<std::pair<int,int> > _vecPairs;
	
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe& operator=(const PmergeMe&);
	
	std::vector<int> readVector();
	std::vector<std::pair<int, int> > readPairs();
	void	createVector(char *argv[]);
	void	createPairs();
	void	sortHighPairs();
	void	mergeSort(std::vector<std::pair<int, int> >&array);
	void	merge(std::vector<std::pair<int, int> >& array, std::vector<std::pair<int, int> > &leftArray, std::vector<std::pair<int, int> > &rightArray);

	class exception : public std::exception
	{
	public:
		exception();
		virtual ~exception() throw();
		virtual const char *what() const throw();
	};
};

#endif