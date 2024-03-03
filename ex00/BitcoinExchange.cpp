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

float valueAtDate(std::string inputLine)
{
	std::ifstream inputFile("data.csv");
	if (inputFile.is_open())
	{
		std::string readedLine, lastLine, databaseLine;
		int year, month, day;
		float val;
		char separator;

		while(std::getline(inputFile, readedLine))
		{
			databaseLine = readedLine.substr(0, 10);
			if (readedLine.compare("date,exchange_rate"))
			{
				if(inputLine.compare("2010-08-17") <= 0)
					return 0;
				else if (inputLine.compare(databaseLine) > 0)
					lastLine = readedLine;
				else if (inputLine.compare(databaseLine) == 0)
				{
					std::istringstream iss(readedLine);
					if (iss >> year >> separator >> month >> separator >> day >> separator >> val)
						return val;
				}
				else
				{
					std::istringstream iss(lastLine);
					if (iss >> year >> separator >> month >> separator >> day >> separator >> val)
						return val;
				}
			}
			else
				lastLine = "2010-08-17";
		}
	}
	else
	{
		std::cerr << "Error opening file!" << std::endl; 
		return false;
	}
	return 0;
}

bool is_validFile(char** fileName, std::list<btc>* pricesList)
{
	std::ifstream inputFile(*fileName);
	if (inputFile.is_open())
	{
		std::string readedLine;
		while (std::getline(inputFile, readedLine))
		{
			if (readedLine.compare("date | value"))
			{
				btc newNode;
				newNode = validateDate(readedLine, newNode);
				pricesList->push_back(newNode);
			}
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
	float val = -1.0f;
	char separator;

	node.errorCode = 0;
	if (!line.empty())
	{
		if (iss >> year >> separator >> month >> separator >> day >> separator >> val)
		{
			if (!(year < 0 || month < 1 || month > 12 || day < 1 || day > 31))
			{
				node.date = line.substr(0, 10);
				if (val > 1000)
					node.errorCode = -1; // value to large
				else if (val < 0)
					node.errorCode = -2; // value negative
				else
					node.value = val * valueAtDate(node.date);
			}
			else
			{
				node.date = line.substr(0, 10);
				node.errorCode = -3; // bad input
			}
			if (separator != '|')
				node.errorCode = -5; // wrong format
		}
		else if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		{
			node.date = line.substr(0, 10);
			node.errorCode = -3; // bad input
		}
		else if (separator != '|')
				node.errorCode = -5; // wrong format
		else if (val == -1)
				node.errorCode = -4; // missing value
	}
	else
		node.errorCode = -6; // empty line
	return node;
}
