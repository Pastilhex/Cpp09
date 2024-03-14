/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:52:14 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/14 18:16:36 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	PmergeMe	vectorSort;
	PmergeMe	dequeSort;
	double		vecElapsedTime;
	double		deqElapsedTime;

	if (argc > 1)
	{
		try
		{
			vecElapsedTime = vectorPmergeMe(argv, vectorSort);
			deqElapsedTime = dequePmergeMe(argv, dequeSort);
			
			std::vector<int> vecUnsorted = vectorSort.readVector();
			std::vector<int> vecSorted = vectorSort.readVectorMainChain();
			
			std::deque<int> deqUnsorted = dequeSort.readDeque();
			std::deque<int> deqSorted = dequeSort.readDequeMainChain();
			
			std::cout << "Before: ";
			printVector(vecUnsorted);
			std::cout << std::endl;
			
			std::cout << "After: ";
			printVector(vecSorted);
			std::cout << std::endl;
			
			std::cout << "Time to process a range of " << vecSorted.size() << " elements with std::vector<int>: " << vecElapsedTime << " us." << std::endl;
			std::cout << "Time to process a range of " << deqSorted.size() << " elements with std::deque<int>: " << deqElapsedTime << " us." << std::endl;

			// PmergeMe copy;
			// copy = vectorSort;
			// std::vector<int> vecUCopy = copy.readVector();
			// std::vector<int> vecSCopy = vectorSort.readVectorMainChain();

			// std::cout << "Before: ";
			// printVector(vecUCopy);
			// std::cout << std::endl;
			
			// std::cout << "After: ";
			// printVector(vecSCopy);
			// std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	
	}
}