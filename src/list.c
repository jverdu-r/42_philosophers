/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:49:42 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/03/15 18:35:06 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_list	*lst_new(t_philo philo)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->philo = philo;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	lst_add_back(t_list **head, t_list *new, int index)
{
	t_list	*aux;
	t_list	*end;
	int		i;

	i = 1;
	aux = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (i++ < index)
			aux = aux->next;
		end = aux->next;
		aux->next = new;
		new->next = end;
		new->index = i;
	}
}

void	new_list(t_list *head, t_list *end, int	phil_total)
{
	int	i;

	i = 2;
	head->next = end;
	end->next = head;
	head->index = 1;
	end->index = phil_total;
	while (i < phil_total)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			return (NULL);
		lst_add_back(&head, lst_new(philo), i);
		i++;
	}
}
