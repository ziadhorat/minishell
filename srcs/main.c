/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:42:00 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/17 14:33:08 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		exec_commands(char **commands)
{
	int		i;
	int		ret;
	char	**command;

	i = 0;
	while (commands[i])
	{
		command = ft_strsplit(commands[i], ' ');
		parse_input(command);
		ret = exec_command(command);
		ft_freestrarray(command);
		if (ret == -1)
			return (-1);
		i++;
	}
	return (0);
}

static void		set_sh_level(int ac, char *av[])
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
	int		ret;
	char	*line;
	char	*prompt;
	char	**commands;

	init_env(env);
	set_sh_level(ac, av);
	while (1)
	{
		prompt = get_handled_path();
		line = readline(prompt);
		free(prompt);
		add_history(line);
		commands = ft_strsplit(line, ';');
		free(line);
		ret = exec_commands(commands);
		ft_freestrarray(commands);
		if (ret == -1)
			break ;
	}
	ft_freestrarray(g_env);
	return (0);
}
