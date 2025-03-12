#include "Set.h"

struct set {
    int *arr;
    int nelems;
    int arrSize;
};

Set SetNew(void) {
    Set new = malloc(sizeof(struct set));
    new->arr = malloc(8 * sizeof(int));
    new->arrSize = 8;
    new->nelems = 0;

    return new;
}

// amortized time complexity = O(1)
void SetInsert(Set s, int elem) {
    if (SetContains(s, elem)) return;

    if (s->arrSize == s->nelems) {
        s->arr = realloc(s->arr, 2 * s->arrSize * sizeof(int));
    }

    s->arr[s->nelems++] = elem;
}