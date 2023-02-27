/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_uchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikaismou <ikaismou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:35:37 by ikaismou          #+#    #+#             */
/*   Updated: 2023/02/27 23:52:45 by ikaismou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*quote_2(char *line, char *str)
{
	int		i;
	int		i2;
	char	c;

	str = ft_calloc(sizeof(char), (ft_strlen(line) - 2 + 1));
	i = 0;
	i2 = 0;
	while (line[i2])
	{
		if (line[i2] && ft_strchr("\'\"", line[i2]))
		{
			c = line[i2++];
			while (line[i2] && line[i2] != c)
				str[i++] = line[i2++];
			i2++;
		}
		else if (line[i2])
			str[i++] = line[i2++];
	}
	str[i] = 0;
	return (str);
}

char	*quote(char *line)
{
	char	*str;

	str = NULL;
	if (!line)
		return (0);
	if (ft_strchr(line, '\'') || ft_strchr(line, '\"'))
		str = quote_2(line, str);
	else
		return (line);
	return (str);
}

static void del_char(t_minishell *ms)
{
    int size;
    int i;
	int j;
    
    i = 0;
    size = 0;
    while (ms->line[i])
    {
        if (ms->line[i] != 92 && ms->line[i] != ';')
            size++;
		i++;
    }
    ms->uchar = malloc(sizeof(char) * (size + 1));
    if (!ms->uchar)
    {
        free(ms->uchar);
        return ;
    }
    i = 0;
    j = 0;
    while (ms->line[i])
    {
        if (ms->line[i] != 92 && ms->line[i] != ';')
		{
            ms->uchar[j] = ms->line[i];
			j++;
		}
		i++;

    }
    ms->uchar[i] = 0;
    ft_printf("%s\n",ms->uchar); 
}

void new(t_minishell *ms)
{
    char  **pars;
    
    while (pars[i])
        i++;
    ms->parsed = malloc(sizeof(char *) * i + 1);
    i = 0;
    while (pars[i])
    {
        ms->parsed[i] = quote(pars[i]);
        i++;
    }
    ms->parsed[i] = 0;
    i = 0;
    while (ms->parsed[i])
    {
        ft_printf("%s\n", ms->parsed[i]);
        i++;
    } 
}

void check_uchar(t_minishell *ms)
{
    int i;
    char **pipe;
    
    i = 0;
    if (ft_strchr(ms->line, 92) || ft_strchr(ms->line, ';'))
        del_char(ms);
 
    int j = 0;
    pipe = ft_split(ms->line, '|');
    while (pipe[j])
    {
        pars = ft_split(ms->line, ' ');
        j++;
    }

    
}