/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:34:52 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/01 20:52:37 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BTC_
# define _BTC_

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>

typedef struct s_btc
{
	int			errorCode;
	std::string	date;
	float		value;
} btc;

bool	is_validFile(char** fileName, std::list<btc>* pricesList);
btc		validateDate(std::string line, btc node);
float	valueAtDate(std::string inputLine);

#endif
