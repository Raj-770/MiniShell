/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:17:07 by sshahary          #+#    #+#             */
/*   Updated: 2024/03/20 22:47:51 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	cd(char *path)
{
	if (chdir(path) != 0)
	{
		ft_error("chdir", 1);
		return (-1);
	}
	return (0);
}
