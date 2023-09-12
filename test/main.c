/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:24:11 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/12 21:37:36 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

void *myFunction(void *p_arg)
{
    int i = *((int *) p_arg);
    printf("%i \n",i);
    if (i == 0)
        return NULL;
}


int main(void)
{
    int i = 0;
    pthread_t p1[2];

    while (i < 3)
    {
        pthread_create(&p1[i],NULL,myFunction,&i);
        i++;
    }
    i = 0;
    while (i < 3)
    {
        pthread_join(p1[i],NULL);
        i++;
    }

}