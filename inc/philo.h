/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:35:17 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/03/15 18:35:11 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct	s_philo
{
	int				eats;
	bool			eating;
	bool			sleeping;
	bool			thinking;
	pthread_mutex_t	fork;
}t_philo

typedef struct	s_list
{
	int				index;
	struct t_philo	philo;
	struct s_list	*next;
}t_list

t_list  *lst_new(t_philo philo);
void    lst_add_back(t_list **head, t_list *new, int index);
void    new_list(t_list *head, t_list *end, int phil_total);

# endif
