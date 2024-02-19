/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:32:35 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/09 12:46:30 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*find_or_make_lst(t_list **root, int fd)
{
	t_list	*node;

	node = *root;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = (t_list *)malloc(1 * sizeof(t_list));
	if (!node)
		return (0);
	if (!init_node(node, fd))
	{
		free(node);
		return (0);
	}
	ft_lstadd_back(root, node);
	return (node);
}

int	init_node(t_list *node, int fd)
{
	char	*str1;

	str1 = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!str1)
		return (0);
	node->str = str1;
	node->fd = fd;
	node->len = 0;
	node->size = BUFFER_SIZE;
	node->loc = 0;
	node->next = 0;
	return (1);
}

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*p;

	if (*lst == 0)
	{
		*lst = new_node;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new_node;
}

char	*list_free_and_connect(t_list **lst, int fd)
{
	t_list	*bef;
	t_list	*now;

	bef = *lst;
	now = *lst;
	if (now->next == 0)
		*lst = 0;
	else
	{
		while (now->fd != fd)
		{
			bef = now;
			now = now->next;
		}
		bef->next = now->next;
	}
	if (bef == now)
		*lst = now->next;
	free(now->str);
	free(now);
	return (0);
}
