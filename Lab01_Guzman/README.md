# Laboratorio 01 – Multiplicación de Matrices con OpenMP

Este laboratorio tuvo como objetivo evaluar el rendimiento de la multiplicación de matrices clásica paralelizada mediante **OpenMP**, ejecutada en un entorno Linux. Se buscó analizar el comportamiento del tiempo de ejecución al variar el tamaño de la matriz y el número de hilos utilizados, incorporando además un sustento estadístico frente al ruido y las cargas alternas del sistema operativo.

---

## Estructura del laboratorio

- **`mmClasicaOpenMP.c`** → código fuente en C con la implementación de la multiplicación de matrices utilizando OpenMP.  
- **`mmClasicaOpenMP`** → ejecutable generado en Linux a partir del código fuente.  
- **`Makefile`** → archivo de automatización que permite compilar fácilmente el proyecto y generar el ejecutable. Fue creado tomando como base un archivo auxiliar (`auto.txt`).  
- **`lanzador.pl`** → script en Perl para ejecutar automáticamente el programa con distintos tamaños de matriz y números de hilos, almacenando los resultados en archivos `.dat`.  
- **`dat.zip`** → contiene todos los archivos de salida `.dat` con las corridas experimentales.  
- **`Tabla_Resultados.pdf`** → tabla consolidada con los resultados finales del laboratorio, que incluye **promedio de tiempo** y **desviación estándar** para cada combinación de tamaño e hilos.  

---

## Resultados

Los resultados experimentales se consolidaron en el archivo [`Tabla_Resultados.pdf`](./Tabla_Resultados.pdf), donde se presenta por cada tamaño de matriz y número de hilos el **tiempo promedio** y la **desviación estándar**.  

---

## Análisis

Los resultados muestran que, en general, los tiempos promedio disminuyen al aumentar el número de hilos, aunque este efecto depende del tamaño de la matriz. En tamaños pequeños, la sobrecarga de la creación y sincronización de hilos limita las ganancias e incrementa la variabilidad. Para tamaños medianos y grandes, el paralelismo ofrece beneficios claros: el tiempo promedio disminuye y la desviación estándar se mantiene en márgenes aceptables, lo que indica estabilidad en las mediciones.  

En conjunto, los experimentos confirman que la estrategia de repetir múltiples veces cada prueba permitió obtener valores representativos y cuantificar con precisión la variabilidad inherente del sistema. El desempeño mejora con más hilos, aunque con una eficiencia decreciente debido a la naturaleza de la paralelización y las restricciones de la arquitectura.

---

## Conclusión

Este laboratorio demuestra que la multiplicación de matrices con OpenMP alcanza mejoras de rendimiento notables al incrementar el número de hilos, especialmente en tamaños de matrices grandes. Sin embargo, en tamaños pequeños la sobrecarga limita las ventajas. El análisis estadístico basado en promedios y desviaciones estándar sustenta de forma rigurosa los resultados frente al ruido del sistema operativo, validando el impacto de OpenMP en el rendimiento de la multiplicación de matrices.  
