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
				std::cout << it->date << std::endl;
				std::cout << it->value << std::endl;
			}
		}
	}
}
