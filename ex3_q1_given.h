#ifndef EX3_Q1_GIVEN
#define EX3_Q1_GIVEN

#define _POSIX_C_SOURCE 200809L
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
//-------------------------------------------
void thread_going_to_exit(int thread_num);
void report_thread_primes(int thread_num, int count, int lo, int hi);
void report_total_primes(char* prog_name, int total);
void prime_sleep();
void increment_counter(int* counter);
void thread_sleep_before_terminate(int num);

#endif

