/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:20:50 by rpambhar          #+#    #+#             */
/*   Updated: 2024/04/30 14:26:49 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	executor(t_mini *mini)
{
	if (count_cmds(mini->cmds) == 1)
	{
		handle_single_cmd(mini);
	}
	else
	{
		handle_multiple_cmds(mini);
	}
}