# Definimos el compilador a utilizar
GCC = gcc

# Opciones de compilación
CFLAGS = -lm              # Librería matemática
FOPENMP = -fopenmp -O3    # Activar OpenMP y optimización O3
POSIX = -lpthread         # Librería POSIX para hilos

# Módulo adicional (no se usa en este caso)
modulo = inter.c

# Programas a compilar
PROGRAMAS = mmClasicaOpenMP 

# Regla principal
ALL: $(PROGRAMAS)

# Regla para compilar mmClasicaOpenMP
mmClasicaOpenMP:
	$(GCC) $(CLFAGS) $@.c -o $@ $(FOPENMP)

# Regla para limpiar los ejecutables
clean:
	$(RM) $(PROGRAMAS) 

