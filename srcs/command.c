/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:41:23 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/23 09:06:36 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		is_executable(char **com, char *bin, struct stat info)
{
	if (S_ISREG(info.st_mode))
	{
		if (info.st_mode & S_IXUSR)
			return (exec_path(bin, com));
		else
		{
			ft_putstr("minishell: permission denied: ");
			ft_putendl(bin);
		}
		free(bin);
		return (1);
	}
	free(bin);
	return (1);
}

char	*in_path(char **com)
{
	int				i;
	char			**bin;
	char			*path;
	struct stat		info;

	i = 0;
	bin = NULL;
	bin = ft_strsplit(get_env("PATH"), ':');
	if (bin != NULL)
	{
		while (bin[i])
		{
			if (ft_starts_with(bin[i], com[0]))
				path = ft_strdup(com[0]);
			else
				path = ft_pathjoin(bin[i], com[0]);
			if (lstat(path, &info) == -1)
				free(path);
			else
			{
				ft_freestrarray(bin);
				return (path);
			}
			i++;
		}
		ft_freestrarray(bin);
	}
	return (NULL);
}
