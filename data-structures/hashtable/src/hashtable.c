#include <stdlib.h>
#include "hashtable.h"

void bucket_init(bucket *b, const char* key, const char *value) {
    b->key = strdup(key);
    b->value = strdup(value);
}

bucket *new_bucket(const char *k, const char *v) {
    bucket *b = malloc(sizeof(bucket));
    bucket_init(b, k, v);
    return b;
}

void bucket_destroy(bucket *b) {
    free(b->key);
    free(b->value);
    free(b);
}

void table_init(hashtable *t, size_t capacity) {
    t->capacity = capacity;
    t->size = 0;
    t->lookup = calloc(capacity, sizeof(bucket *));
}

hashtable *new_table(size_t capacity) {
    hashtable *t = malloc(sizeof(hashtable));
    table_init(t, capacity);
    return t;
}