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
	
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe& operator=(const PmergeMe&);
	
	std::vector<int> readVectorFD();
	void	createVector(char *argv[]);
	void	createPairs(const std::vector<int> &vec);

	class exception : public std::exception
	{
	public:
		exception();
		virtual ~exception() throw();
		virtual const char *what() const throw();
	};
};

#endif