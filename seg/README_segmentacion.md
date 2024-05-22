
# Ejemplo de Segmentación en C

Este repositorio contiene un ejemplo básico de cómo implementar la técnica de segmentación en un sistema operativo utilizando el lenguaje de programación C. La segmentación es una técnica de gestión de memoria en la que la memoria se divide en segmentos de diferentes tamaños según la función del segmento, como el código, los datos o la pila.

## Archivos

- `segmentation_example.c`: Implementación del ejemplo de segmentación en C.

## Descripción del Código

### Definiciones y Estructuras de Datos

- `Segment`: Estructura que representa un segmento con su base y límite.
- `segment_table`: Arreglo que almacena los segmentos asignados a un proceso.

### Inicialización de la Tabla de Segmentos

La función `initialize_segment_table()` inicializa todas las entradas de la tabla de segmentos a -1, indicando que ninguna base o límite de segmento está asignado inicialmente.

```c
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
```

### Asignación de Segmentos

La función `allocate_segment(int base, int limit)` asigna un segmento con la base y el límite especificados. Devuelve el índice del segmento asignado o -1 si no hay segmentos libres.

```c
int allocate_segment(int base, int limit) {
    for (int i = 0; i < MAX_SEGMENTS; i++) {
        if (segment_table[i].base == -1) {
            segment_table[i] = (Segment){base, limit};
            return i;
        }
    }
    return -1; // No hay segmentos libres
}
```

### Acceso a la Memoria

La función `access_memory(int segment_number, int offset)` verifica si el segmento está asignado y si el desplazamiento está dentro de los límites del segmento. Si no está asignado o el desplazamiento está fuera de los límites, se produce un fallo de segmentación. Si está asignado y el desplazamiento es válido, se accede a la memoria y se imprime el acceso.

```c
void access_memory(int segment_number, int offset) {
    if (segment_table[segment_number].base == -1) {
        printf("Segmentation fault: segment %d is not allocated.
", segment_number);
        return;
    }
    if (offset >= segment_table[segment_number].limit) {
        printf("Segmentation fault: offset %d out of bounds for segment %d.
", offset, segment_number);
        return;
    }
    printf("Accessing memory at address %d
", segment_table[segment_number].base + offset);
}
```

### Ejemplo Completo en C

```c
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
        printf("Segmentation fault: segment %d is not allocated.
", segment_number);
        return;
    }
    if (offset >= segment_table[segment_number].limit) {
        printf("Segmentation fault: offset %d out of bounds for segment %d.
", offset, segment_number);
        return;
    }
    printf("Accessing memory at address %d
", segment_table[segment_number].base + offset);
}

int main() {
    initialize_segment_table();
    
    int segment = allocate_segment(1000, 500);
    
    if (segment != -1) {
        printf("Segment %d allocated with base %d and limit %d
", segment, 1000, 500);
    } else {
        printf("No free segments available.
");
    }
    
    access_memory(segment, 100);
    access_memory(segment, 600); // Provocará un fallo de segmentación

    return 0;
}
```

## Compilación y Ejecución

Para compilar y ejecutar el código, puedes usar un compilador de C como `gcc`. Aquí tienes los comandos:

```bash
gcc -o segmentation_example segmentation_example.c
./segmentation_example
```

## Licencia

Este proyecto está licenciado bajo la Licencia MIT - consulta el archivo LICENSE para más detalles.
