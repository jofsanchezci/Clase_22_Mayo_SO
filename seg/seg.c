//La segmentación divide la memoria en segmentos de diferentes tamaños
// según la función. A continuación se muestra un ejemplo básico de 
//cómo podrías implementar la segmentación en C

#include <stdio.h>
#include <stdlib.h>

#define MAX_SEGMENTS 10

typedef struct {
    int base;
    int limit;
} Segment;

Segment segment_table[MAX_SEGMENTS];

void initialize_segment_table() {
    for (int i = 0; i < MAX_SEGMENTS; i++) {
        segment_table[i] = (Segment){-1, -1};
    }
}

int allocate_segment(int base, int limit) {
    for (int i = 0; i < MAX_SEGMENTS; i++) {
        if (segment_table[i].base == -1) {
            segment_table[i] = (Segment){base, limit};
            return i;
        }
    }
    return -1; // No hay segmentos libres
}

void access_memory(int segment_number, int offset) {
    if (segment_table[segment_number].base == -1) {
        printf("Fallo de segmentación: segmento %d no está asignado.\n", segment_number);
        return;
    }
    if (offset >= segment_table[segment_number].limit) {
        printf("Fallo de segmentación: offset %d fuera de los límites del segmento %d.\n", offset, segment_number);
        return;
    }
    printf("Acceso a la memoria en la dirección %d\n", segment_table[segment_number].base + offset);
}

int main() {
    initialize_segment_table();
    
    int segment = allocate_segment(1000, 500);
    
    if (segment != -1) {
        printf("Segmento %d asignado con base %d y limite %d\n", segment, 1000, 500);
    } else {
        printf("No hay segmentos libres disponibles.\n");
    }
    
    access_memory(segment, 100);
    access_memory(segment, 600); // Provocará un fallo de segmentación

    return 0;
}
