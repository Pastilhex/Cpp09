/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:34:31 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/01 20:18:19 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	std::list<btc> pricesList;
	
	if (argc == 2)
	{
		if(is_validFile(&argv[1], &pricesList))
		{
			for (std::list<btc>::iterator it = pricesList.begin(); it != pricesList.end(); it++)
			{
				if (it->errorCode == -1)
					std::cout << "Error: number too large." << std::endl;
				else if (it->errorCode == -2)
					std::cout << "Error: not a positive number." << std::endl;
				else if (it->errorCode == -3)
					std::cout << "Error: bad input => " << it->date << std::endl;
				else
					std::cout << it->date << " => " << it->value << std::endl;
			}
		}
	}
}
