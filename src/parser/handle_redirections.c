/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:19:22 by rpambhar          #+#    #+#             */
/*   Updated: 2024/05/12 17:15:31 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	handle_redirection_in(t_mini *mini, t_cmds *cmd, int *i);
static int	handle_redirection_out(t_mini *mini, t_cmds *cmd, int *i);
static int	set_fd(char *re, char *path, t_cmds *cmd, t_mini *mini);
int	check_if_file_exits(char *path);

void	handle_redirection(t_mini *mini)
{
	t_cmds	*temp;
	t_cmds	*next_temp;
	int		i;

	temp = mini->cmds;
	while (temp)
	{
		i = 0;
		while (temp->args[i])
		{
			next_temp = temp->next;
			if (temp->args[i][0] == '<' && temp->args[i][1] == '\0')
			{
				if (!handle_redirection_in(mini, temp, &i))
				{
					remove_cmd_node(mini, temp);
					break ;
				}
			}
			else if (temp->args[i][0] == '>')
				if (!handle_redirection_out(mini, temp, &i))
				{
					remove_cmd_node(mini, temp);
					break ;
				}
			i++;
		}
		temp = next_temp;
	}
}

static int	handle_redirection_in(t_mini *mini, t_cmds *cmd, int *i)
{
	if (!cmd->args[(*i) + 1])
		return (1);
	if (!ft_strcmp(cmd->args[*i], "<") && \
	!check_if_file_exits(cmd->args[(*i) + 1]))
	{
		mini->exit_code = 1;
		return (0);
	}
	if (!set_fd(cmd->args[*i], cmd->args[(*i) + 1], cmd, mini))
	{
		mini->exit_code = 1;
		remove_element(&cmd->args, *i);
		remove_element(&cmd->args, *i);
		return (0);
	}
	remove_element(&cmd->args, *i);
	remove_element(&cmd->args, *i);
	(*i)--;
	return (1);
}

static int	handle_redirection_out(t_mini *mini, t_cmds *cmd, int *i)
{
	if (!cmd->args[(*i) + 1])
		return (1);
	if (!set_fd(cmd->args[*i], cmd->args[(*i) + 1], cmd, mini))
	{
		mini->exit_code = 1;
		remove_element(&cmd->args, *i);
		remove_element(&cmd->args, *i);
		return (0);
	}
	remove_element(&cmd->args, *i);
	remove_element(&cmd->args, *i);
	(*i)--;
	return (1);
}

static int	set_fd(char *re, char *path, t_cmds *cmd, t_mini *mini)
{

	if ((!ft_strcmp(re, ">>") || !ft_strcmp(re, ">")) && cmd->fd_out != STDOUT_FILENO)
		close(cmd->fd_out);
	if (!ft_strcmp(re, ">"))
		cmd->fd_out = open(path, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (!ft_strcmp(re, ">>"))
		cmd->fd_out = open(path, O_CREAT | O_RDWR | O_APPEND, 0644);
	if ((!ft_strcmp(re, "<<") || !ft_strcmp(re, "<")) && cmd->fd_in != STDIN_FILENO)
		close(cmd->fd_in);
	if (!ft_strcmp(re, "<"))
		cmd->fd_in = open(path, O_RDONLY);
	if (!ft_strcmp(re, "<<"))
	{
		cmd->fd_in = open("lib/libft/.heredoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
		cmd->fd_in = open(path, O_RDONLY);
		heredoc(cmd->fd_in, path, mini);
		close(cmd->fd_in);
		cmd->fd_in = open("lib/libft/.heredoc", O_RDONLY);
	}
	if (cmd->fd_in == -1 || cmd->fd_out == -1)
	{
		perror("minishell: ");
		return (0);
	}
	return (1);
}

int	check_if_file_exits(char *path)
{
	struct stat	file_stat;

	if (stat(path, &file_stat) == 0)
	{
		if (S_ISDIR(file_stat.st_mode))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(path, 2);
			ft_putstr_fd(": is a directory\n", 2);
			exit(126);
		}
		else
			return (1);
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": is not a file or directory\n", 2);
	return (0);
}
