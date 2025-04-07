#ifndef HEAP
#define HEAP
#include <stdbool.h>
#include <stddef.h>

typedef enum {
    MIN_HEAP,
    MAX_HEAP
} HeapType;

typedef struct Heap Heap;

Heap* heap_create(size_t capacity, HeapType type);
void heap_destroy(Heap *heap);
bool heap_push(Heap *heap, int value);
int heap_pop(Heap *heap);
bool heap_is_empty(const Heap *heap);
int heap_peek(const Heap *heap);

static void heap_shiftup(Heap *heap, size_t index);
static void heap_shiftdown(Heap *heap, size_t index);
static bool should_swap(Heap *heap, int a, int b);
static size_t heap_left_index(size_t index);
static size_t heap_right_index(size_t index);
static size_t heap_parent_index(size_t index);
static void swap(int *a, int *b);
#endif