/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:41:54 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/23 09:02:45 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				exec_path(char *ex_path, char **com)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(ex_path, com, g_env);
	else if (pid < 0)
	{
		ft_putstr("minishell: fork: process creation failed!\n");
		free(ex_path);
		return (1);
	}
	free(ex_path);
	wait(&pid);
	return (0);
}

static int		is_builtin(char *com)
{
	if (ft_strcmp("cd", com) == 0 ||
		ft_strcmp("exit", com) == 0 ||
		ft_strcmp("env", com) == 0 ||
		ft_strcmp("setenv", com) == 0 ||
		ft_strcmp("unsetenv", com) == 0 ||
		ft_strcmp("echo", com) == 0)
		return (1);
	return (0);
}

static int		exec_builtin(char **com)
{
	if (ft_strcmp("cd", com[0]) == 0)
		return (cd_b(com, 0));
	else if (ft_strcmp("env", com[0]) == 0)
		return (env_b());
	else if (ft_strcmp("exit", com[0]) == 0)
		return (-1);
	else if (ft_strcmp("setenv", com[0]) == 0)
		return (setenv_b(com));
	else if (ft_strcmp("unsetenv", com[0]) == 0)
		return (unsetenv_b(com));
	else if (ft_strcmp("echo", com[0]) == 0)
		return (echo_b(com));
	return (1);
}

int				exec_command(char **com)
{
	char			*path;
	struct stat		info;

	if (!com || !*com)
		return (1);
	if (is_builtin(com[0]))
		return (exec_builtin(com));
	else if ((path = in_path(com)))
	{
		lstat(path, &info);
		return (is_executable(com, path, info));
	}
	if (lstat(com[0], &info) != -1)
	{
		if (S_ISREG(info.st_mode))
			return (is_executable(com, ft_strdup(com[0]), info));
		else if (S_ISDIR(info.st_mode))
			return (change_dir(com[0], 0));
	}
	ft_putstr("minishell: command not found: ");
	ft_putendl(com[0]);
	return (1);
}
