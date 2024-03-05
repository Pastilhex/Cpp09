/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:58:19 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/05 11:00:15 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[])
{
	if (argc == 2)
		if (validDigit(argv[1]))
			RPN(argv[1]);
		else
		std::cout << "Error" << std::endl;
	else
		std::cout << "Error" << std::endl;
	return 0;
}
