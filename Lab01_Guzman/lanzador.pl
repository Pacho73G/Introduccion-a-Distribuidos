#!/usr/bin/perl
#**************************************************************
#         		Pontificia Universidad Javeriana
#     Autor: Francisco GUzman
#     Fecha: 28/08/2025
#     Materia: INtroduccion distribuidos
#     Tema: Laboratorio 01
#     Fichero: script automatizacion ejecucion por lotes 
#****************************************************************/

# Guardamos en $Path la ruta actual (directorio donde estamos)
$Path = `pwd`;
chomp($Path);

# Nombre del ejecutable que vamos a correr
$Nombre_Ejecutable = "mmClasicaOpenMP";

# Lista de tamaños de matrices a evaluar (los que se usaron en el laboratorio)
@Size_Matriz = ("240", "480", "960", "1440", "1680", "1920", "2400", "2880", "3120", "3360", "3600");

# Lista de hilos a utilizar en las ejecuciones
@Num_Hilos = (1, 4, 6, 8, 16, 20);

# Número de repeticiones por cada combinación de tamaño e hilos
$Repeticiones = 30;

# Bucle principal: recorre cada tamaño de matriz
foreach $size (@Size_Matriz){
	
	# Bucle interno: recorre cada número de hilos
	foreach $hilo (@Num_Hilos) {
		
		# Nombre del archivo de salida donde se guardarán los resultados
		$file = "$Path/$Nombre_Ejecutable-".$size."-Hilos-".$hilo.".dat";
		
		# Ejecutar el programa varias veces (según $Repeticiones)
		for ($i=0; $i<$Repeticiones; $i++) {
			system("$Path/$Nombre_Ejecutable $size $hilo  >> $file");
			printf("$Path/$Nombre_Ejecutable $size $hilo \n");
		}
		
		# Cierra el archivo de resultados
		close($file);
		$p=$p+1;
	}
}
