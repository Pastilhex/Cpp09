/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:52:14 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/08 17:31:35 by ialves-m         ###   ########.fr       */
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
			
			vectorSort.mergeSort();




			std::vector<int> get = vectorSort.readVector();
			std::vector<int>::iterator it;
			for (it = get.begin(); it != get.end(); it++)
				std::cout << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
}