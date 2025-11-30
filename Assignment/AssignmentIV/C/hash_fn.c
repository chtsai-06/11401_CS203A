// hash_fn.c
#include "hash_fn.h"
#include <limits.h>

// 乘法雜湊常數 (基於黃金比例倒數的 32 位元近似值)
#define HASH_MULTIPLIER 0x9e3779b9UL 
#define WORD_SIZE 32 // 假設使用 32 位元系統

size_t hash_c(uint32_t key, size_t table_size) {
    // 乘法操作：確保乘積為 32 位元
    uint32_t hash_value = key * HASH_MULTIPLIER;

    // 判斷 table_size 是否為 2 的冪次 (優化)
    if ((table_size & (table_size - 1)) == 0) {
        // Log2(table_size): 計算 P (所需位元數)
        // 這裡使用手動迴圈計算 P，以確保與標準 C 兼容
        int p = 0;
        size_t temp_size = table_size;
        while (temp_size > 1) {
            temp_size >>= 1;
            p++;
        }
        
        // 透過右移 (32 - P) 位來提取 hash_value 的高 P 位
        return (size_t)hash_value >> (WORD_SIZE - p);
    } 
    else {
        // 如果 table_size 不是 2 的冪次，則使用標準取模運算
        // 雖然乘法雜湊在此情況下的性能優勢降低，但仍是一個有效的雜湊
        return (size_t)hash_value % table_size;
    }
}