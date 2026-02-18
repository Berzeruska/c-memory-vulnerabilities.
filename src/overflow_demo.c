#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Demonstração Acadêmica: Buffer Overflow
 * ---------------------------------------
 * Este código NÃO é malware real. Ele apenas simula como a sobrescrita de memória
 * pode alterar dados legítimos em um processo.
 *
 * Objetivo: Mostrar como a falta de validação em funções como strcpy()
 * pode comprometer a integridade da memória.
 */

int main() {
    // Buffer legítimo: representa dados críticos de um processo
    char target_process_data[10];
    strcpy(target_process_data, "ABCDEF");

    printf("[LOG] Estado Original: %s | Endereço: %p\n",
           target_process_data, (void*)target_process_data);

    // Alocação dinâmica no Heap
    char *payload = (char *) malloc(7 * sizeof(char));
    if (payload == NULL) return 1;

    // Conteúdo que será copiado para o buffer
    strcpy(payload, "XYZ123");

    // Vulnerabilidade: sobrescreve target_process_data sem checar limites
    strcpy(target_process_data, payload);

    printf("[LOG] Estado Modificado: %s | Endereço: %p\n",
           target_process_data, (void*)target_process_data);

    // Liberação da memória alocada
    free(payload);
    payload = NULL;

    return 0;
}
