
# Ejemplo de Swapping en C

Este repositorio contiene un ejemplo básico de cómo implementar la técnica de swapping en un sistema operativo utilizando el lenguaje de programación C. El swapping es una técnica de gestión de memoria en la que los procesos se mueven entre la memoria principal y el disco cuando no hay suficiente memoria disponible.

## Archivos

- `swapping_example.c`: Implementación del ejemplo de swapping en C.

## Descripción del Código

### Definiciones y Estructuras de Datos

- `MEMORY_SIZE`: Tamaño de la memoria principal.
- `SWAP_SIZE`: Tamaño del área de swap (disco).
- `memory`: Arreglo que representa la memoria principal.
- `swap`: Arreglo que representa el área de swap.

### Función para Swapping Out

La función `swap_out(int process_id, int start, int size)` simula la escritura del proceso en el área de swap.

```c
void swap_out(int process_id, int start, int size) {
    // Simular la escritura del proceso en el área de swap
    for (int i = start; i < start + size; i++) {
        swap[i] = process_id;
    }
    printf("Process %d swapped out to disk from %d to %d
", process_id, start, start + size - 1);
}
```

### Función para Swapping In

La función `swap_in(int process_id, int start, int size)` simula la lectura del proceso desde el área de swap.

```c
void swap_in(int process_id, int start, int size) {
    // Simular la lectura del proceso desde el área de swap
    for (int i = start; i < start + size; i++) {
        memory[i] = swap[i];
    }
    printf("Process %d swapped in from disk from %d to %d
", process_id, start, start + size - 1);
}
```

### Ejemplo Completo en C

```c
#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1024
#define SWAP_SIZE 2048

int memory[MEMORY_SIZE];
int swap[SWAP_SIZE];

void swap_out(int process_id, int start, int size) {
    // Simular la escritura del proceso en el área de swap
    for (int i = start; i < start + size; i++) {
        swap[i] = process_id;
    }
    printf("Process %d swapped out to disk from %d to %d
", process_id, start, start + size - 1);
}

void swap_in(int process_id, int start, int size) {
    // Simular la lectura del proceso desde el área de swap
    for (int i = start; i < start + size; i++) {
        memory[i] = swap[i];
    }
    printf("Process %d swapped in from disk from %d to %d
", process_id, start, start + size - 1);
}

int main() {
    int process_id = 1;
    int start = 0;
    int size = 512;

    // Simular el swapping de salida e ingreso
    swap_out(process_id, start, size);
    swap_in(process_id, start, size);

    return 0;
}
```

## Compilación y Ejecución

Para compilar y ejecutar el código, puedes usar un compilador de C como `gcc`. Aquí tienes los comandos:

```bash
gcc -o swapping_example swapping_example.c
./swapping_example
```

## Licencia

Este proyecto está licenciado bajo la Licencia MIT - consulta el archivo LICENSE para más detalles.
