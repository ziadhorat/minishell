/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:44:14 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/23 08:48:57 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void			cd_error(char *path, char *str)
{
	ft_putstr(str);
	ft_putendl(path);
}

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
			cd_error(path, "cd: no such file or directory: ");
		else if (access(path, 1) == -1)
			cd_error(path, "cd: permission denied: ");
		return (1);
	}
}

static int		check_cd_error(char **com)
{
	if (com[2])
	{
		ft_putstr("cd: too many arguments\n");
		return (1);
	}
	return (0);
}

int				cd_b(char **com, int print)
{
	if ((!com[1] && ft_strequ("cd", com[0])) ||
	ft_strequ(com[1], "--"))
		return (change_dir(get_env("HOME"), 0));
	else if (ft_strequ(com[1], "-"))
		return (change_dir(get_env("OLDPWD"), 1));
	else
	{
		if (check_cd_error(com))
			return (1);
		return (change_dir(com[1], print));
	}
}
