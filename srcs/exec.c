/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:41:54 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/17 14:05:00 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	is_bulitin and exec_builtin could definitely be combined, or re formatted
**	as a dispatch table for cleaner code. I'll implement it later.
*/

int				exec_path(char *ex_path, char **command)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(ex_path, command, g_env);
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

static int		is_builtin(char *cmd)
{
	if (ft_strcmp("cd", cmd) == 0 ||
	ft_strcmp("exit", cmd) == 0 ||
	ft_strcmp("env", cmd) == 0 ||
	ft_strcmp("setenv", cmd) == 0 ||
	ft_strcmp("unsetenv", cmd) == 0 ||
	ft_strcmp("echo", cmd) == 0)
		return (1);
	return (0);
}

static int		exec_builtin(char **command)
{
	if (ft_strcmp("cd", command[0]) == 0)
		return (cd_b(command, 0));
	else if (ft_strcmp("env", command[0]) == 0)
		return (env_b());
	else if (ft_strcmp("exit", command[0]) == 0)
		return (-1);
	else if (ft_strcmp("setenv", command[0]) == 0)
		return (setenv_b(command));
	else if (ft_strcmp("unsetenv", command[0]) == 0)
		return (unsetenv_b(command));
	else if (ft_strcmp("echo", command[0]) == 0)
		return (echo_b(command));
	return (1);
}

int				exec_command(char **command)
{
	char			*path;
	struct stat		info;

	if (!command || !*command)
		return (1);
	if (is_builtin(command[0]))
		return (exec_builtin(command));
	else if ((path = in_path(command)))
	{
		lstat(path, &info);
		return (is_executable(command, path, info));
	}
	if (lstat(command[0], &info) != -1)
	{
		if (S_ISREG(info.st_mode))
			return (is_executable(command, ft_strdup(command[0]), info));
		else if (S_ISDIR(info.st_mode))
			return (change_dir(command[0], 0));
	}
	ft_putstr("minishell: command not found: ");
	ft_putendl(command[0]);
	return (1);
}
