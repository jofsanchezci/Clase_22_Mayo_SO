//Paginación
//La paginación es una técnica en la que la memoria 
//virtual se divide en páginas y la memoria física en marcos de página. A continuación se muestra un ejemplo básico de cómo podrías implementar una tabla de páginas en C

#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4096
#define NUM_PAGES 256
#define FRAME_SIZE 4096
#define NUM_FRAMES 64

int page_table[NUM_PAGES];
int memory[NUM_FRAMES][FRAME_SIZE];

void initialize_page_table() {
    for (int i = 0; i < NUM_PAGES; i++) {
        page_table[i] = -1; // -1 indica que la página no está asignada a un marco
    }
}

int allocate_page(int page_number) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (page_table[i] == -1) {
            page_table[page_number] = i;
            return i;
        }
    }
    return -1; // No hay marcos libres
}

void access_memory(int page_number, int offset) {
    if (page_table[page_number] == -1) {
        printf("Fallo de página: página %d no está asignado.\n", page_number);
        return;
    }
    int frame_number = page_table[page_number];
    printf("Marco de acceso %d, offset %d\n", frame_number, offset);
}

int main() {
    initialize_page_table();
    
    int page = 1;
    int frame = allocate_page(page);
    
    if (frame != -1) {
        printf("Pagina %d Frame Asignado %d\n", page, frame);
    } else {
        printf("No hay marcos disponibles.\n");
    }
    
    access_memory(page, 100);
    access_memory(2, 50); // Provocará un fallo de página

    return 0;
}
