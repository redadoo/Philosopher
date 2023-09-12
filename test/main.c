/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:36:34 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/12 15:41:25 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <pthread.h>

// Global variable:
int i = 2;

void* foo(void* p){
  // Print value received as argument:
  pthread_mutex_t ciao;
/*   pthread_mutex_init(&ciao,NULL);
  pthread_mutex_lock(&ciao); */
  printf("Value recevied as argument in starting routine: ");
  printf("%i\n", * (int*)p);
/*   pthread_mutex_unlock(&ciao);
  pthread_mutex_destroy(&ciao); */
  // Return reference to global variable:
  return NULL;
}

int main(void){
  // Declare variable for thread's ID:
  pthread_t id;

  int j = 1;
  pthread_create(&id, NULL, foo, &j);
    
  int* ptr;

  // Wait for foo() and retrieve value in ptr;
  pthread_join(id, (void**)&ptr);
  printf("Value recevied by parent from child: ");
  printf("%i\n", *ptr);
}