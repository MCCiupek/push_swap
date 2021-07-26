/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:16:42 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/23 18:16:52 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_copy_array(char **tab)
{
	int		i;
	char	**new;

	i = -1;
	new = (char **)malloc(sizeof(char *) * (ft_arraysize(tab) + 1));
	if (!new)
		return (NULL);
	while (tab[++i])
		new[i] = ft_strdup(tab[i]);
	new[i] = NULL;
	return (new);
}
