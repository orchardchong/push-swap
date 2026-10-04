/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 01:28:34 by ochong            #+#    #+#             */
/*   Updated: 2026/10/03 01:28:34 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check is it a real number
int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0') //how should it handle "- 2"?
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

//using long just to handle overflow or underflow like 999999999999
long	ft_atol(const char *str)
{
	int		i;
	int		symbol;
	long	num;

	i = 0;
	symbol = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			symbol = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * symbol);
}

//each num only can show up once '0' means no duplicates, '1' means yes, there is a duplicate
/*int	check_duplicate(t_node **stack_a, int num)
{
	t_node	*current

	if (stack_a == NULL || *stack_a == NULL)
		return (0);
	current = *stack_a;
	do
	{
		if (current->value == num)
			return (1);
		current = current->next;
	}
	while (current != *stack_a);
	return (0)
}
1 2 3 4
1
2
2
3
4
i.split
ii.atol
iii. */