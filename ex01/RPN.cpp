/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:58:52 by ialves-m          #+#    #+#             */
/*   Updated: 2024/03/05 11:31:43 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void RPN(char* args)
{
	int argsSize = strlen(args), x = 0, y = 0;
	std::stack<int> rpnStack;

	for (int i = 0; i < argsSize; i++)
	{
		if (args[i] != ' ')
		{
			switch (args[i])
			{
			case '+':
				x = rpnStack.top();
				rpnStack.pop();
				y = rpnStack.top();
				rpnStack.pop();
				rpnStack.push(y + x);
				break;
			case '-':
				x = rpnStack.top();
				rpnStack.pop();
				y = rpnStack.top();
				rpnStack.pop();
				rpnStack.push(y - x);
				break;
			case '*':
				x = rpnStack.top();
				rpnStack.pop();
				y = rpnStack.top();
				rpnStack.pop();
				rpnStack.push(y * x);
				break;
			case '/':
				x = rpnStack.top();
				rpnStack.pop();
				y = rpnStack.top();
				rpnStack.pop();
				rpnStack.push(y / x);
				break;
			default:
				rpnStack.push(args[i] - 48);
				break;
			}
		}
	}
	std::cout << rpnStack.top() << std::endl;
}

bool validDigit(char* args)
{
	int argsSize = strlen(args);

	for (int i = 0; i < argsSize; i++)
	{
		if (args[i] != ' ')
			if (!((args[i] >= '0' && args[i] <= '9') || args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/'))
				return false;
	}
	return true;
}

bool validArgs(char* args)
{
	int argsSize = strlen(args);
	int nbr = 0;
	int ops = 0;
	
	if (argsSize % 2 == 0)
		return false;
	
	for (int i = 0; i < argsSize; i++)
	{
		if (args[i] >= '0' && args[i] <= '9')
			nbr++;
		if (args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/')
			ops++;
	}

	return (nbr == ops + 1);
}
