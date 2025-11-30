
#include "hash_fn.h"
#include <limits.h>


#define HASH_MULTIPLIER 0x9e3779b9UL 
#define WORD_SIZE 32 

size_t hash_c(uint32_t key, size_t table_size) {

    uint32_t hash_value = key * HASH_MULTIPLIER;

    if ((table_size & (table_size - 1)) == 0) {

        int p = 0;
        size_t temp_size = table_size;
        while (temp_size > 1) {
            temp_size >>= 1;
            p++;
        }

        return (size_t)hash_value >> (WORD_SIZE - p);
    } 
    else {
        return (size_t)hash_value % table_size;
    }
}