#ifndef __MY_LIBARY_FUN_H
#define __MY_LIBARY_FUN_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h> 

extern int global_counter;
extern pthread_mutex_t mutex;
extern pthread_mutex_t print_mutex; 
// Define the range structure here
typedef struct {
    int thread_num;
    int low;
    int high;
    int num_of_primes;
} range;

void* count_primes(void* arg);

bool is_prime(int num);

#endif
