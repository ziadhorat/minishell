/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:44:14 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/17 14:19:58 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int				change_dir(char *path, int print)
{
	char	cwd_path[PATH_MAX + 1];

	getcwd(cwd_path, PATH_MAX);
	if (chdir(path) == 0)
	{
		set_env_var("OLDPWD", cwd_path);
		if (print)
			ft_putendl(path);
		getcwd(cwd_path, PATH_MAX);
		set_env_var("PWD", cwd_path);
		return (0);
	}
	else
	{
		if (access(path, 0) == -1)
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putendl(path);
		}
		else if (access(path, 1) == -1)
		{
			ft_putstr("cd: permission denied: ");
			ft_putendl(path);
		}
		return (1);
	}
}

static int		check_cd_error(char **command)
{
	if (command[2])
	{
		ft_putstr("cd: too many arguments\n");
		return (1);
	}
	return (0);
}

int				cd_b(char **command, int print)
{
	if ((!command[1] && ft_strequ("cd", command[0])) ||
	ft_strequ(command[1], "--"))
		return (change_dir(get_env("HOME"), 0));
	else if (ft_strequ(command[1], "-"))
		return (change_dir(get_env("OLDPWD"), 1));
	else
	{
		if (check_cd_error(command))
			return (1);
		return (change_dir(command[1], print));
	}
}
