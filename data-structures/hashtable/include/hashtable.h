#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stddef.h>

typedef struct {
    char *key;
    char *value;
} bucket;

typedef struct {
    size_t capacity;
    size_t size;
    bucket **lookup;
} hashtable;

void bucket_init(bucket *b, const char* key, const char *value);

bucket *new_bucket(const char *k, const char *v);

void bucket_destroy(bucket *b);

void table_init(hashtable *t, size_t capacity);

hashtable *new_table(size_t capacity);

#endif