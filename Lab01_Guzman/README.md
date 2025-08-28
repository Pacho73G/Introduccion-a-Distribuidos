# Laboratorio 01 – Multiplicación de Matrices con OpenMP

Este laboratorio corresponde al curso **Introducción a Sistemas Distribuidos**.  
El objetivo fue implementar, corregir, documentar y probar un algoritmo de **multiplicación de matrices clásica (MM)** en C, paralelizado con **OpenMP**, y diseñar un plan de pruebas de carga que permita evaluar su rendimiento.

---

## 📌 Descripción del laboratorio

- Se partió de un código base en C que implementa la multiplicación de matrices.  
- Se corrigió y documentó el código, agregando soporte a paralelismo con OpenMP.  
- Se adaptó un **Makefile** para automatizar la compilación del programa.  
- Se creó un **script de automatización (`lanzador.pl`)** para ejecutar múltiples pruebas con diferentes tamaños de matrices y distintos niveles de paralelismo.  
- Se diseñó un **plan de pruebas de carga** con 12 dimensiones menores a 14.000 y con hilos: **1, 4, 8, 16 y 20**.  
- Los resultados se consolidaron en archivos `.dat`, que posteriormente fueron analizados estadísticamente.

---

## 📂 Archivos incluidos

- **`mmClasicaOpenMP.c`** → Código fuente en C del algoritmo corregido y documentado.  
- **`mmClasicaOpenMP`** → Ejecutable generado a partir del código fuente.  
- **`Makefile`** → Script para compilar automáticamente el programa con soporte OpenMP.  
- **`lanzador.pl`** → Script en Perl que ejecuta el programa con los diferentes tamaños y hilos, generando resultados en `.dat`.  
- **`dat.zip`** → Carpeta comprimida que contiene todos los resultados de las pruebas experimentales.  
- **`README.md`** → Este documento. 

---

## 🧪 Plan de pruebas

- **Dimensiones usadas:** 11 tamaños diferentes de matrices, todos menores a 14.000.  
- **Niveles de paralelismo:** 1, 4, 8, 16 y 20 hilos.  
- **Repeticiones:** Cada combinación se ejecutó 30 veces para reducir el ruido del sistema operativo y sustentar estadísticamente los resultados.  

Cada corrida registra el **tiempo de ejecución en microsegundos**, permitiendo calcular promedios y desviaciones estándar para cada configuración.

---

## 📊 Resultados

- Los resultados detallados de todas las corridas están disponibles en [`dat.zip`](./dat.zip).  
- Se generó además un **documento con la tabla consolidada de promedios y desviaciones estándar**, así como informes en PDF que presentan el análisis y las conclusiones.  

---

## 🔎 Conclusiones

El laboratorio permitió comprobar que el **paralelismo con OpenMP** reduce significativamente los tiempos de ejecución en tamaños medianos y grandes, mientras que en matrices pequeñas la sobrecarga de hilos limita los beneficios.  

El análisis estadístico (promedios y desviaciones estándar) respaldó la validez de los resultados frente a variaciones y cargas alternas del sistema operativo.  
En conclusión, se logró cumplir con los objetivos planteados: **corregir, documentar y probar el algoritmo, automatizar su compilación y ejecución, y diseñar un plan de pruebas de carga sustentado estadísticamente**.
