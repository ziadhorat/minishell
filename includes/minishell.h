/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:36:09 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/23 08:15:30 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PATH_MAX 4096
# define NOT_SPECIAL(c) ((c != '$' && c != ':') ? 1 : 0)
# define SUCCESS 0
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

/*
**	Global variable/s
*/

char			**g_env;

/*
**	prototypes
*/

char			*get_env(char *env_var);
void			handle_input(char **command);
void			initialize_env(char *env[]);
void			display_prompt(void);
int				exec_command(char **command);
int				env_len(char *env[]);

/*
**	Bin prototypes
*/

int				env_b(void);
int				cd_b(char **command, int print);
int				set_env_var(char *key, char *value);
int				setenv_b(char **command);
int				unsetenv_b(char **command);
int				echo_b(char **command);
int				exec_path(char *ex_path, char **command);
char			*in_path(char **command);
int				is_executable(char **command, char *bin, struct stat info);
char			*get_handled_path(void);
int				change_dir(char *path, int print);

#endif
