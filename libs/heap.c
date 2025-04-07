#include "heap.h"
#include <stdlib.h>
#include <assert.h>

struct Heap {
    int *data;
    size_t size;
    size_t capacity;
    HeapType type;
};

Heap* heap_create(size_t capacity, HeapType type) {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    if(!heap) return NULL;

    heap->data = (int*)malloc(heap->capacity * sizeof(int));
    if(!heap->data) {
        free(heap);
        return NULL;
    }

    heap->size = 0;
    heap->capacity = capacity;
    heap->type = type;

    return heap;
}

void heap_destroy(Heap *heap) {
    if(heap) {
        free(heap->data);
        free(heap);
    }
}

bool heap_push(Heap *heap, int value) {
    if(heap->size >= heap->capacity) return false;

    heap->data[heap->size] = value;
    heap_shiftup(heap, heap->size);
    heap->size++;

    return true;
}

int heap_pop(Heap *heap) {
    assert(!heap_is_empty(heap));
    
    int result = heap->data[0];
    heap->size--;
    
    if (!heap_is_empty(heap)) {
        heap->data[0] = heap->data[heap->size];
        heap_shiftdown(heap, 0);
    }
    
    return result;
}

bool heap_is_empty(const Heap *heap) {
    return heap->size == 0;
}

int heap_peek(const Heap *heap) {
    assert(!heap_is_empty(heap));
    return heap->data[0];
}

static void heap_shiftup(Heap *heap, size_t index) {
    if(index == 0) return;
    
    size_t parent_index  = heap_parent_index(index);

    if(should_swap(heap, heap->data[index], heap->data[parent_index])) {
        swap(&heap->data[index], &heap->data[parent_index]);
        heap_shiftup(heap, parent_index);
    }
}

static void heap_shiftdown(Heap *heap, size_t index) {
    size_t left_child_index = heap_left_index(index);
    size_t right_child_index = heap_right_index(index);
    size_t selected = index;

    if(left_child_index < heap->size) {
        if(should_swap(heap, heap->data[left_child_index], heap->data[index])) {
            selected = left_child_index;
        }
    } else if(right_child_index < heap->size) {
        if(should_swap(heap, heap->data[right_child_index], heap->data[index])) {
            selected = right_child_index;
        }
    }

    if(selected != index) {
        swap(&heap->data[index], &heap->data[selected]);
        heap_shiftdown(heap, selected);
    }
}

static size_t heap_left_index(size_t index) {
    return 2 * index + 1;
}

static size_t heap_right_index(size_t index) {
    return 2 * (index + 1);
}

static size_t heap_parent_index(size_t index) {
    return (index - 1) / 2;
}

static bool should_swap(Heap *heap, int a, int b) {
    return heap->type == MAX_HEAP
        ? a > b
        : a < b;
}

static void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}