// hash_fn.h
#ifndef HASH_FN_H
#define HASH_FN_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief 乘法雜湊函數 (C 語言版)
 * * @param key 輸入的 32 位元無符號整數鍵
 * @param table_size 雜湊表的大小 (為獲得最佳性能，應為 2 的冪次)
 * @return size_t 計算出的雜湊索引 (0 到 table_size - 1)
 */
size_t hash_c(uint32_t key, size_t table_size);

#endif // HASH_FN_H