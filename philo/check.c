/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:28:32 by evocatur          #+#    #+#             */
/*   Updated: 2023/08/09 13:02:54 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int ft_isdigit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
     	if (str[i] < 48 && str[i] > 57)
		    return (0);
        i++;
    }
    return (1);
}

void check(char **argv)
{
    int i;

    i = 1;

    while (argv[i - 1])
    {
        if(ft_isdigit(argv[i]) == 0)
            exit_prog();
        i++;
    }
    
}

void exit_prog()
{
    printf("test\n");
    exit(0);
}
