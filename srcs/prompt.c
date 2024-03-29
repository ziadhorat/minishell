/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:42:18 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/23 13:56:20 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*handle_env_path(char *path)
{
	if (!path)
		return (NULL);
	if (get_env("HOME") != NULL)
	{
		if (ft_strcmp(path, get_env("HOME")) == 0)
			return (ft_strdup("~"));
		else if (ft_starts_with(get_env("HOME"), path))
			return (ft_strjoin("~", &path[ft_strlen(get_env("HOME"))]));
	}
	return (ft_strdup(path));
}

char			*get_handled_path(void)
{
	char	*h_path;
	char	*result;
	char	path[PATH_MAX + 1];
	char	*tmp;

	getcwd(path, PATH_MAX);
	h_path = handle_env_path(path);
	tmp = ft_strjoin("\033[1;31m", h_path);
	result = ft_strjoin(tmp, "> \033[0m");
	free(h_path);
	free(tmp);
	return (result);
}
