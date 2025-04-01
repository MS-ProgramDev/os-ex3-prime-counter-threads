#include "ex3_q1_given.h"

#define deb 1
#define func_line if (deb) fprintf(stdout, "func: %s, Line: %d\n", __func__, __LINE__);
#define PRINT_INT(var) if (deb) printf(#var " = %d\n", var);

//-------------------------------------------
void thread_going_to_exit(int thread_num)
{
  printf("Thread #%d ", thread_num);
  printf("going to exit.\n");
}

//-------------------------------------------
void report_thread_primes(int thread_num, int count, int lo, int hi)
{
  printf("Thread #%d terminated, ", thread_num);
  printf("it found %d primes ", count);
  printf("in the range %d - %d.\n", lo, hi);
}

//-------------------------------------------
void report_total_primes(char* prog_name, int count)
{
  printf("Program %s terminated. ", prog_name);
  printf("Total of %d primes were found.\n", count);
}

//-------------------------------------------
void prime_sleep()
{
  int d = (rand() ^ ((int) pthread_self()) % 40) + 10;
  const struct timespec ts = {0, d * 1000 * 1000 * 10};
  nanosleep(&ts, NULL);
}

//-------------------------------------------
void increment_counter(int* counter)
{
  (*counter)++;
}

//-------------------------------------------
void thread_sleep_before_terminate(int num)
{
  if (num %3 == 0)
    sleep(2);
}

