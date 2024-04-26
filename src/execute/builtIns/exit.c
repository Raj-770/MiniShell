/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 05:39:09 by sshahary          #+#    #+#             */
/*   Updated: 2024/04/25 16:25:27 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	errcode(t_mini *mini)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);
	exit(mini->exit_code);
}

void	mini_exit(t_mini *mini)
{
	int	i;

	i = 0;
	if (mini->preflag == 1)
		return ;
	while (mini->cmds->args[i] != NULL)
		i++;
	if (i == 1)
		errcode(mini);
	else if (i == 2 && str_is_digit(mini->cmds->args[1]))
		mini->exit_code = ft_atoi(mini->cmds->args[1]);
	else if (i > 2 && str_is_digit(mini->cmds->args[1]))
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		ft_execute_err_1("exit", "too many arguments");
		mini->exit_code = 1;
		return ;
	}
	else
	{
		ft_execute_err_2("exit", mini->cmds->args[1], "numeric argument required");
		mini->exit_code = 255;
		exit(mini->exit_code & 255);
	}
	errcode(mini);
}