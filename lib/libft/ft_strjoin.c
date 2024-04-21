/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:10:05 by rpambhar          #+#    #+#             */
/*   Updated: 2024/04/21 12:20:43 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	str = (char *) malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		if (i < ft_strlen(s1))
			*(str + i) = *(s1 + i);
		else
			*(str + i) = *(s2 + (i - ft_strlen(s1)));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
