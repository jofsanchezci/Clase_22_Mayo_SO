
# Ejemplo de Paginación en C

Este repositorio contiene un ejemplo básico de cómo implementar la técnica de paginación en un sistema operativo utilizando el lenguaje de programación C. La paginación es una técnica de gestión de memoria en la que la memoria virtual se divide en páginas y la memoria física en marcos de página. Este ejemplo simula una tabla de páginas y la asignación de marcos a páginas.

## Archivos

- `pagination_example.c`: Implementación del ejemplo de paginación en C.

## Descripción del Código

### Definiciones y Estructuras de Datos

- `PAGE_SIZE`: Tamaño de una página en bytes.
- `NUM_PAGES`: Número total de páginas en la memoria virtual.
- `FRAME_SIZE`: Tamaño de un marco de página en bytes (igual al tamaño de una página).
- `NUM_FRAMES`: Número total de marcos en la memoria física.
- `page_table`: Arreglo que mapea cada página a un marco. Si el valor es -1, la página no está asignada.
- `memory`: Matriz que representa la memoria física, con marcos y su contenido.

### Inicialización de la Tabla de Páginas

La función `initialize_page_table()` inicializa todas las entradas de la tabla de páginas a -1, indicando que ninguna página está asignada inicialmente.

```c
void initialize_page_table() {
    for (int i = 0; i < NUM_PAGES; i++) {
        page_table[i] = -1; // -1 indica que la página no está asignada a un marco
    }
}
```

### Asignación de Páginas

La función `allocate_page(int page_number)` busca un marco libre en la memoria física y asigna la página especificada a ese marco. Devuelve el número del marco asignado o -1 si no hay marcos libres.

```c
int allocate_page(int page_number) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (page_table[i] == -1) {
            page_table[page_number] = i;
            return i;
        }
    }
    return -1; // No hay marcos libres
}
```

### Acceso a la Memoria

La función `access_memory(int page_number, int offset)` verifica si la página está asignada. Si no está asignada, se produce un fallo de página. Si está asignada, se accede al marco correspondiente y se imprime el acceso.

```c
void access_memory(int page_number, int offset) {
    if (page_table[page_number] == -1) {
        printf("Page fault: page %d is not allocated.
", page_number);
        return;
    }
    int frame_number = page_table[page_number];
    printf("Accessing frame %d, offset %d
", frame_number, offset);
}
```

### Ejemplo Completo en C

```c
#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4096
#define NUM_PAGES 256
#define FRAME_SIZE 4096
#define NUM_FRAMES 64

// Tabla de páginas: almacena el número de marco al que está asignada cada página
int page_table[NUM_PAGES];
// Memoria física: matriz de marcos y su contenido
int memory[NUM_FRAMES][FRAME_SIZE];

// Inicializar la tabla de páginas con -1 indicando que ninguna página está asignada
void initialize_page_table() {
    for (int i = 0; i < NUM_PAGES; i++) {
        page_table[i] = -1; // -1 indica que la página no está asignada a un marco
    }
}

// Asignar un marco a una página específica
int allocate_page(int page_number) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (page_table[i] == -1) {
            page_table[page_number] = i;
            return i;
        }
    }
    return -1; // No hay marcos libres
}

// Acceder a la memoria simulando el acceso a través de la tabla de páginas
void access_memory(int page_number, int offset) {
    if (page_table[page_number] == -1) {
        printf("Page fault: page %d is not allocated.
", page_number);
        return;
    }
    int frame_number = page_table[page_number];
    printf("Accessing frame %d, offset %d
", frame_number, offset);
}

int main() {
    // Inicializar la tabla de páginas
    initialize_page_table();
    
    // Asignar una página a un marco
    int page = 1;
    int frame = allocate_page(page);
    
    if (frame != -1) {
        printf("Page %d allocated to frame %d
", page, frame);
    } else {
        printf("No free frames available.
");
    }
    
    // Acceder a la memoria
    access_memory(page, 100); // Acceso válido
    access_memory(2, 50); // Provocará un fallo de página

    return 0;
}
```

## Compilación y Ejecución

Para compilar y ejecutar el código, puedes usar un compilador de C como `gcc`. Aquí tienes los comandos:

```bash
gcc -o pagination_example pagination_example.c
./pagination_example
```

## Licencia

Este proyecto está licenciado bajo la Licencia MIT - consulta el archivo LICENSE para más detalles.
