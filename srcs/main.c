/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:42:00 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/23 08:19:00 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		exec_com(char **coms)
{
	int		i;
	int		ret;
	char	**com;

	i = 0;
	while (coms[i])
	{
		com = ft_strsplit(coms[i], ' ');
		handle_input(com);
		ret = exec_command(com);
		ft_freestrarray(com);
		if (ret == -1)
		{
			ft_freestrarray(coms);
			return (-1);
		}
		i++;
	}
	return (0);
}

static void		sh_level(int ac, char *av[])
{
	char	*level;

	(void)ac;
	(void)av;
	level = ft_itoa(ft_atoi(get_env("SHLVL")) + 1);
	set_env_var("SHLVL", level);
	free(level);
}

int				main(int ac, char *av[], char *env[])
{
	char	*line;
	char	*prompt;
	char	**coms;

	initialize_env(env);
	sh_level(ac, av);
	while (1)
	{
		prompt = get_handled_path();
		line = readline(prompt);
		free(prompt);
		add_history(line);
		coms = ft_strsplit(line, ';');
		free(line);
		if (exec_com(coms) == -1)
			break ;
	}
	ft_freestrarray(g_env);
	return (0);
}
