// Lorraine Bichara Assad A01193063
// Fecha: 11 de abril de 2018.
// P17. Threads
// Calculate the factorial of 5 different numbers using threads.
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_THREADS 5

int iArr[5]; //Arreglo que guardará los datos introducidos por el usuario.

//Función para calcular el factorial recursivamente de un número recibido como parámetro.
int factorial(int iN) {
    if(iN == 1)
        return 1;
    else
        return iN * factorial(iN - 1);
}

//Función que maneja los threads y hace llamadas a la función factorial.
void *factorialThread (void *threadid) {
    long tid;
    tid = (long)threadid;
    printf("Factorial #%ld of %d = %d\n", tid, iArr[tid], factorial(iArr[tid]));
    pthread_exit(NULL);
}

int main() {
    int n;
    printf("Introduzca 5 números para calcular su factorial: ");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &n);
        iArr[i] = n;
    }

	pthread_t threads[NUM_THREADS];
	int rc = 0; 

	for(long t = 0; t < NUM_THREADS; t++) {
        //printf("In main: creating thread %ld\n", t); 
		rc = pthread_create(threads + t, NULL, factorialThread, (void *) t); 
        if(rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc); 
            exit(-1);
        }
	}	
}