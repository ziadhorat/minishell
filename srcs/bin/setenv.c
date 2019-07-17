/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:44:41 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/17 14:36:46 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int		find_env_index(char *key)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strjoin(key, "=");
	while (g_env[i])
	{
		if (ft_starts_with(temp, g_env[i]))
		{
			free(temp);
			return (i);
		}
		i++;
	}
	free(temp);
	return (-1);
}

static void		new_env_var(char *key, char *value)
{
	int		i;
	int		len;
	char	*key_temp;
	char	*new_var;
	char	**new_env;

	i = 0;
	len = env_len(g_env) + 1;
	new_env = (char **)malloc(sizeof(char *) * (len + 1));
	new_env[len--] = 0;
	while (g_env[i])
	{
		new_env[i] = ft_strdup(g_env[i]);
		free(g_env[i]);
		i++;
	}
	free(g_env);
	key_temp = ft_strjoin(key, "=");
	new_var = ft_strjoin(key_temp, value);
	new_env[i] = ft_strdup(new_var);
	free(key_temp);
	free(new_var);
	g_env = new_env;
}

int				set_env_var(char *key, char *value)
{
	int		i;
	char	*key_temp;
	char	*temp;

	i = find_env_index(key);
	if (i != -1)
	{
		key_temp = ft_strjoin(key, "=");
		temp = ft_strjoin(key_temp, value);
		free(key_temp);
		free(g_env[i]);
		g_env[i] = ft_strdup(temp);
		free(temp);
		return (0);
	}
	else if (i == -1)
		new_env_var(key, value);
	return (0);
}

int				setenv_b(char **command)
{
	if (!command[1])
		ft_putstr("setenv: too few arguments\n");
	else if (command[1] && command[2] && command[3])
		ft_putstr("setenv: too many arguments\n");
	else
	{
		if (!command[2])
			return (set_env_var(command[1], ""));
		return (set_env_var(command[1], command[2]));
	}
	return (1);
}
