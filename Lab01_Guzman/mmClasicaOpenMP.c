/*#######################################################################################
 #* Fecha:28/08/2025
 #* Autor:Francisco Guzman
 #* Tema: 
 #* 	- Programa Multiplicación de Matrices algoritmo clásico
 #* 	- Paralelismo con OpenMP
######################################################################################*/

#include <stdio.h>      // Librería estándar de entrada y salida
#include <stdlib.h>     // Librería estándar (malloc, calloc, atoi, rand, etc.)
#include <string.h>     // Funciones de manejo de strings
#include <time.h>       // Funciones de tiempo (srand, time)
#include <sys/time.h>   // gettimeofday para medir tiempos con microsegundos
#include <omp.h>        // Librería OpenMP para paralelismo

// Variables globales para medir tiempos
struct timeval inicio, fin; 

// Función para iniciar la medición de tiempo
void InicioMuestra(){
	gettimeofday(&inicio, (void *)0);
}

// Función para finalizar la medición de tiempo y mostrar el resultado
void FinMuestra(){
	gettimeofday(&fin, (void *)0);
	fin.tv_usec -= inicio.tv_usec;
	fin.tv_sec  -= inicio.tv_sec;
	double tiempo = (double) (fin.tv_sec*1000000 + fin.tv_usec); 
	printf("%9.0f \n", tiempo);   // Imprime el tiempo total en microsegundos
}

// Función para imprimir una matriz (solo si D < 9)
void impMatrix(double *matrix, int D){
	printf("\n");
	if(D < 9){
		for(int i=0; i<D*D; i++){
			if(i%D==0) printf("\n");
			printf("%f ", matrix[i]);
		}
		printf("\n**-----------------------------**\n");
	}
}

// Inicializa dos matrices con valores aleatorios entre 0 y 99
void iniMatrix(double *m1, double *m2, int D){
	for(int i=0; i<D*D; i++, m1++, m2++){
		*m1 =  rand()%100;	
		*m2 =  rand()%100;	
	}
}

// Multiplicación clásica de matrices: C = A * B
void multiMatrix(double *mA, double *mB, double *mC, int D){
	double Suma, *pA, *pB;
	#pragma omp parallel   // Bloque paralelo de OpenMP
	{
		#pragma omp for    // Distribuye las iteraciones del for entre hilos
		for(int i=0; i<D; i++){
			for(int j=0; j<D; j++){
				pA = mA+i*D;	
				pB = mB+j;    // Accede a la columna j de la matriz B
				// pB = mB+(j*D);  // Opción alternativa comentada
				Suma = 0.0;
				for(int k=0; k<D; k++, pA++, pB+=D){
					Suma += *pA * *pB;
				}
				mC[i*D+j] = Suma;
			}
		}
	}
}

// Función principal
int main(int argc, char *argv[]){
	// Verifica que se pasen los parámetros SIZE y Hilos
	if(argc < 3){
		printf("\n Use: $./clasicaOpenMP SIZE Hilos \n\n");
		exit(0);
	}

	// Se leen los parámetros
	int N = atoi(argv[1]);    // Tamaño de la matriz
	int TH = atoi(argv[2]);   // Número de hilos a utilizar

	// Reserva dinámica de memoria para las matrices
	double *matrixA  = (double *)calloc(N*N, sizeof(double));
	double *matrixB  = (double *)calloc(N*N, sizeof(double));
	double *matrixC  = (double *)calloc(N*N, sizeof(double));

	// Inicializa la semilla para los números aleatorios
	srand(time(NULL));

	// Fija el número de hilos para OpenMP
	omp_set_num_threads(TH);

	// Inicializa matrices A y B con valores aleatorios
	iniMatrix(matrixA, matrixB, N);

	// Imprime matrices A y B (si son pequeñas)
	impMatrix(matrixA, N);
	impMatrix(matrixB, N);

	// Inicia la medición, realiza la multiplicación y finaliza la medición
	InicioMuestra();
	multiMatrix(matrixA, matrixB, matrixC, N);
	FinMuestra();

	// Imprime la matriz resultante (si es pequeña)
	impMatrix(matrixC, N);

	/* Liberación de memoria */
	free(matrixA);
	free(matrixB);
	free(matrixC);
	
	return 0;
}

