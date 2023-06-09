#include <stdio.h>

void mejorAjuste(int tamanoBloque[], int m, int tamanoProceso[], int n) {
    int asignacion[n];
    int i, j;

    for (i = 0; i < n; i++) {
        int mejorIndice = -1;
        for (j = 0; j < m; j++) {
            // Comprueba si el bloque puede acomodar el proceso
            if (tamanoBloque[j] >= tamanoProceso[i]) {
                // Actualiza el indice del mejor bloque si es mas pequeño que el anterior
                if (mejorIndice == -1 || tamanoBloque[j] < tamanoBloque[mejorIndice])
                    mejorIndice = j;
            }
        }

        if (mejorIndice != -1) {
            asignacion[i] = mejorIndice;

            // Imprime datos del proceso
            printf("Proceso %d: Tamaño Proceso %d - Bloque asignado %d - Tamaño bloque asignado %d - ",
            i + 1, tamanoProceso[i], mejorIndice + 1, tamanoBloque[mejorIndice]);

            tamanoBloque[mejorIndice] -= tamanoProceso[i];

            // Imprime la memoria restante
            printf("Memoria restante %d\n", tamanoBloque[mejorIndice]);
        } else {
            asignacion[i] = -1;
            printf("Proceso %d: No asignado\n", i + 1);
        }
    }
}

int main() {
    // Tamaños de los bloques de memoria disponibles
    int tamanoBloque[] = {100, 500, 200, 300, 600}; 

    // Tamaños de los procesos a asignar
    int tamanoProceso[] = {212, 417, 112, 426}; 

    // Numero de bloques de memoria disponibles
    int m = sizeof(tamanoBloque) / sizeof(tamanoBloque[0]); 

    // Numero de procesos a asignar
    int n = sizeof(tamanoProceso) / sizeof(tamanoProceso[0]); 

    mejorAjuste(tamanoBloque, m, tamanoProceso, n);

    return 0;
}

