#!/usr/bin/perl
#**************************************************************
#         		Pontificia Universidad Javeriana
#     Autor: Francisco GUzman
#     Fecha: 15/08/2025
#     Materia: INtroduccion distribuidos
#     Tema: Taller de EvaluaciÃ³n de Rendimiento
#     Fichero: script automatizaciÃ³n ejecuciÃ³n por lotes 
#****************************************************************/

$Path = `pwd`;
chomp($Path);

#nombres de ejecutables
$Nombre_Ejecutable = "mmClasicaOpenMP";
@Size_Matriz = ("4080", "4800", "5600");
@Num_Hilos = (1,2,4,8,16,20);
$Repeticiones = 30;

foreach $size (@Size_Matriz){
	foreach $hilo (@Num_Hilos) {
		$file = "$Path/$Nombre_Ejecutable-".$size."-Hilos-".$hilo.".dat";
		for ($i=0; $i<$Repeticiones; $i++) {
system("$Path/$Nombre_Ejecutable $size $hilo  >> $file");
			printf("$Path/$Nombre_Ejecutable $size $hilo \n");
		}
		close($file);
	$p=$p+1;
	}
}

