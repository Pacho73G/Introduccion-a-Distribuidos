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
- Los resultados se consolidaron en archivos `.dat` y en un PDF con la tabla final de tiempos promedios y desviaciones estándar.

---

## 📂 Archivos incluidos

- **`mmClasicaOpenMP.c`** → Código fuente en C del algoritmo corregido y documentado.  
- **`mmClasicaOpenMP`** → Ejecutable generado a partir del código fuente.  
- **`Makefile`** → Script para compilar automáticamente el programa con soporte OpenMP.  
- **`lanzador.pl`** → Script en Perl que ejecuta el programa con los diferentes tamaños y hilos, generando resultados en `.dat`.  
- **`dat.zip`** → Carpeta comprimida que contiene todos los resultados de las pruebas experimentales.  
- **`Tabla_Resultados.pdf`** → Documento que presenta la tabla consolidada de tiempos promedios y desviaciones estándar.  
- **`README.md`** → Este documento, que incluye el análisis y las conclusiones del laboratorio.  

---

## 🧪 Plan de pruebas

- **Dimensiones usadas:** 11 tamaños diferentes de matrices, todos menores a 14.000.  
- **Niveles de paralelismo:** 1, 4, 8, 16 y 20 hilos.  
- **Repeticiones:** Cada combinación se ejecutó 30 veces para reducir el ruido del sistema operativo y sustentar estadísticamente los resultados.  

Cada corrida registra el **tiempo de ejecución en microsegundos**, permitiendo calcular promedios y desviaciones estándar para cada configuración.

---

## 📊 Resultados

- Los resultados detallados de todas las corridas están disponibles en [`dat.zip`](./dat.zip).  
- La tabla consolidada de tiempos promedios y desviaciones estándar se encuentra en **[`Tabla_Resultados.pdf`](./Tabla_Resultados.pdf)**.  

---

## 🔎 Análisis de resultados

Al observar los valores promedios y sus desviaciones estándar (véase `Tabla_Resultados.pdf`), se aprecia una tendencia consistente: **los tiempos descienden al aumentar el número de hilos**, pero el beneficio depende del tamaño de la matriz. En **tamaños pequeños**, la sobrecarga asociada a la creación y sincronización de hilos reduce la ganancia de paralelizar y, en algunos casos, la **variabilidad relativa** (desviación estándar/medio) resulta más perceptible. A medida que el tamaño **crece a escalas medianas y grandes**, el trabajo útil por hilo aumenta, el **tiempo promedio** cae de manera más marcada y la desviación estándar se mantiene en rangos acotados, lo que sugiere **estabilidad** en las mediciones pese a las cargas alternas del sistema operativo.

El patrón de **escalamiento** muestra mejoras claras al pasar de 1 a 4 u 8 hilos; sin embargo, al escalar hacia 16 y 20 hilos la **mejora marginal** tiende a disminuir, reflejando la típica **eficiencia decreciente** de la paralelización en memoria compartida: parte del tiempo se consume en sincronización y en límites propios de la arquitectura (ancho de banda de memoria, jerarquía de cachés). En conjunto, el **promedio** sirve como estimador robusto del rendimiento esperado, mientras que la **desviación estándar** acota la variación entre corridas repetidas, cumpliendo el objetivo de **sustento estadístico**. Así, los datos respaldan que **OpenMP resulta provechoso** especialmente para matrices medianas y grandes, con un punto de equilibrio donde añadir más hilos aporta cada vez menos reducción de tiempo.

---

## ✅ Conclusiones

El laboratorio demuestra que la **multiplicación de matrices con OpenMP** obtiene **mejoras de rendimiento significativas** al incrementar el número de hilos en tamaños medianos y grandes, mientras que en tamaños pequeños la sobrecarga de paralelización limita los beneficios. El tratamiento estadístico mediante **promedios y desviaciones estándar** —calculados a partir de múltiples repeticiones— **sustenta la validez** de los resultados frente a ruidos y variaciones del sistema operativo. Se cumplieron los objetivos: **corregir, documentar y probar** el algoritmo; **automatizar** su compilación y ejecución; y **diseñar** un plan de pruebas de carga **con respaldo estadístico**.
