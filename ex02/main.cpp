/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:52:14 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/11 18:53:55 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	PmergeMe vectorSort;

	if (argc > 1)
	{
		try
		{
			vectorSort.createVector(argv);
			vectorSort.createPairs();
			vectorSort.sortHighPairs();
			std::vector<std::pair<int, int> >* ptrPairs = vectorSort.readPairs();
			vectorSort.mergeSort(*ptrPairs);
			vectorSort.insertionSort();


			// std::vector<int> get = vectorSort.readVector();
			// std::vector<int>::iterator it;
			// for (it = get.begin(); it != get.end(); it++)
			// 	std::cout << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
}