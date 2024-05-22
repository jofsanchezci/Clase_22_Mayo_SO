//El swapping mueve procesos entre la memoria principal y el disco
 //cuando no hay suficiente memoria disponible. A continuación se
//muestra un ejemplo básico de cómo podrías simular el swapping en C:


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
    printf("Proceso %d intercambiado a disco desde %d a %d\n", process_id, start, start + size - 1);
}

void swap_in(int process_id, int start, int size) {
    // Simular la lectura del proceso desde el área de swap
    for (int i = start; i < start + size; i++) {
        memory[i] = swap[i];
    }
    printf("Proceso %d intercambiado a disco desde %d a %d\n", process_id, start, start + size - 1);
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
