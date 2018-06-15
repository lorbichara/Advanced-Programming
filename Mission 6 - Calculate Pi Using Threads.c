//Lorraine Bichara Assad
//A01193063
//Misión 6
//Con ayuda (especialmente en la parte de unir threads porque sin eso, el resultado se desplegaba antes de que los threads se terminaran de ejecutar) de:
//https://cs.calvin.edu/courses/cs/374/homework/threads/01/pi.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 10

double resultado = 0.0; 
pthread_mutex_t piLock;       
long cantidadIntervalos = 1000000000;

clock_t start,end;

void *computePI(void *id)
{
    start = clock();
    long double x, baseIntervalo, fdx = 0;
    int i, tid = *((int*)id);

    baseIntervalo = 1.0 / cantidadIntervalos;

    for(i = tid ; i < cantidadIntervalos; i += NUM_THREADS) {
        x = (i+0.5) * baseIntervalo;
        fdx += 4.0 / (1.0 + x*x);
    }

    fdx *= baseIntervalo; 

    pthread_mutex_lock(&piLock);
    resultado += fdx;
    pthread_mutex_unlock(&piLock); 

    end = clock();
    return NULL;
} 

int main()
{
    pthread_t *threads;        
    int *tid;
    int i;

    threads = malloc(NUM_THREADS*sizeof(pthread_t));
    tid = malloc(NUM_THREADS*sizeof(int));
    pthread_mutex_init(&piLock, NULL);

    for (i = 0; i < NUM_THREADS; i++) {
      tid[i] = i;
      pthread_create(&threads[i], NULL, computePI, tid+i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
       pthread_join(threads[i], NULL);
    }

    printf("Resultado = %20.18lf (%ld)\n",resultado,end-start);

    return 0;
}