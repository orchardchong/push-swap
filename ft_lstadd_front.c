/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochong <ochong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 19:23:01 by ochong            #+#    #+#             */
/*   Updated: 2026/08/10 21:36:52 by ochong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **head, t_list *new)
{
	t_list	*last;

	if (head == NULL || new == NULL)
		return ;
	if (*head == NULL)
	{
		*head = *new;
		new->next = *new;
		new->prev = *last;
		return;
	}
	last = (*head)->prev;
	last->next = new;
	new->prev = last;
	new->next = *head;
	(*head)->prev = new;
	*head = new;
}
