#include "ex3_q1_given.h"
#include "my_libary_fun.h"

int global_counter=0;
pthread_mutex_t mutex; 
pthread_mutex_t print_mutex; 

int main(int argc, char *argv[])
{
pthread_mutex_init(&mutex, NULL); 
pthread_mutex_init(&print_mutex, NULL);
if(argc!=4)
{
  printf("ERROR");
  return -1;
}
int low= atoi(argv[1]);
int high= atoi(argv[2]);
int step= atoi(argv[3]);

if(low>high)
{
 int temp=low;
 low=high;
 high=temp;
 printf("# note the 1st argument bigger then 2nd");
} 
  
int num_thread= (high-low+step)/step;

if (num_thread <= 0 || num_thread>10 ) 
{
  printf("Invalid range or step.\n");
  return 1;
}
pthread_t* threads = malloc(num_thread * sizeof(pthread_t));
if (!threads)
{
  printf("Memory allocation failed for threads\n");
  return 1;
}    
range* ranges = malloc(num_thread * sizeof(range));
if (!ranges)
{
  printf("Memory allocation failed for ranges\n");
  free(threads);
}   

for(int i=0; i<num_thread;i++)
{
  int range_low= low + i*step;
  int range_high=range_low+step -1;
  if(range_high>high)
   {  range_high=high;
     
    }
     ranges[i].thread_num=i+1;
     ranges[i].low=range_low;
     ranges[i].high=range_high;
     ranges[i].num_of_primes=0;
     
  pthread_create(&threads[i], NULL, count_primes, &ranges[i]);
}
    for (int i = num_thread-1; i>=0 ; i--)
    {
     pthread_join(threads[i], NULL);
            pthread_mutex_lock(&print_mutex); report_thread_primes(ranges[i].thread_num,ranges[i].num_of_primes,ranges[i].low,ranges[i].high);
        pthread_mutex_unlock(&print_mutex);
    }
    pthread_mutex_lock(&print_mutex);
    report_total_primes(argv[0],global_counter);
    pthread_mutex_unlock(&print_mutex);
 pthread_mutex_destroy(&mutex);
 pthread_mutex_destroy(&print_mutex);
  free(ranges);
  free(threads);

return 0;
}

