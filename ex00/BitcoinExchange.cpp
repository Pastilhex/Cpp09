/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:35:06 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/01 21:05:34 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool is_validFile(char** fileName, std::list<btc>* pricesList)
{
	std::ifstream inputFile(*fileName);
	if (inputFile.is_open())
	{
		std::string readedLine;
		while (std::getline(inputFile, readedLine))
		{
			btc newNode;
			
			newNode = validateDate(readedLine, newNode);
			pricesList->push_back(newNode);
		}
		inputFile.close();
		return true;
	}
	else
	{
		std::cerr << "Error opening file!" << std::endl; 
		return false;
	}
}

btc validateDate(std::string line, btc node)
{
	std::istringstream iss(line);
	int year, month, day;
	float val;
	char separator;

	if (iss >> year >> separator >> month >> separator >> day >> separator >> val)
		if (!(year < 0 || month < 1 || month > 12 || day < 1 || day > 31))
		{
			node.date = line.substr(0, 10);
			node.value = val;			
		} 
	return node;
}
