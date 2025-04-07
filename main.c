#include <stdio.h>
#include <stdlib.h>
#include "libs/heap.h"

int main() {
    Heap* heap = heap_create(100, MAX_HEAP);
    if (!heap) {
        fprintf(stderr, "Failed to create heap\n");
        return EXIT_FAILURE;
    }
    
    heap_push(heap, 2);
    heap_push(heap, 10);
    heap_push(heap, 5);

    if (!heap_is_empty(heap)) {
        printf("Top element: %d\n", heap_peek(heap));
    }

    while(!heap_is_empty(heap)) {
        printf("pop: %d\n", heap_pop(heap));
    }

    heap_destroy(heap);

    heap = heap_create(100, MIN_HEAP);
    if (!heap) {
        fprintf(stderr, "Failed to create heap\n");
        return EXIT_FAILURE;
    }
    
    heap_push(heap, 2);
    heap_push(heap, 10);
    heap_push(heap, 5);

    if (!heap_is_empty(heap)) {
        printf("Top element: %d\n", heap_peek(heap));
    }

    while(!heap_is_empty(heap)) {
        printf("pop: %d\n", heap_pop(heap));
    }
    return EXIT_SUCCESS;
}