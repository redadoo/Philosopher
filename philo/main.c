/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:17:57 by evocatur          #+#    #+#             */
/*   Updated: 2023/08/09 12:50:51 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void *myThreadFun(void *vargp);

  
int main(int argc, char **argv)
{
    int             i;
    t_philosophers  p;
    pthread_t       tid;

    if (argc < 5)
        exit(0);
    check(argv);
    return 0;
}
