  
#include "my_libary_fun.h"
#include "ex3_q1_given.h"

void* count_primes(void* arg)
{
    int local_counter = 0;
    range* r = (range*)arg;

    for (int i = r->low; i <= r->high; i++)
    {
        if (is_prime(i))
        {
            local_counter++;
            pthread_mutex_lock(&mutex);
            global_counter++;
            pthread_mutex_unlock(&mutex);          
            prime_sleep();
        }
    }
    r->num_of_primes=local_counter;
            pthread_mutex_lock(&print_mutex);
      thread_sleep_before_terminate(r->thread_num);
      thread_going_to_exit(r->thread_num);
              pthread_mutex_unlock(&print_mutex);
  return NULL;
}
  

bool is_prime(int num)
{
if(num<=1)
  return false;
int limit = sqrt(num);
for(int i=2; i<=limit;i++)
  {
    if(num%i==0)
      return false;
  }
  return true;
}





