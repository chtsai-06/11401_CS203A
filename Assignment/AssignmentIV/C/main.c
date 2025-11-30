// main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash_fn.h"

#define TABLE_SIZE 1024 // 雜湊表大小 (2^10)
#define NUM_KEYS 20000  // 測試鍵值數量

void run_c_test() {
    size_t distribution[TABLE_SIZE] = {0};
    int i;
    
    printf("====================================================\n");
    printf("C 語言雜湊函數測試與分佈分析\n");
    printf("表大小: %zu, 測試鍵數: %d\n", TABLE_SIZE, NUM_KEYS);
    printf("====================================================\n");

    // 設置隨機種子
    srand((unsigned int)time(NULL));

    // 1. 測試隨機均勻分佈的鍵值
    printf("\n--- 1. 測試隨機鍵值分佈 ---\n");
    for (i = 0; i < NUM_KEYS; i++) {
        uint32_t key = rand() * rand(); // 產生較大的隨機鍵
        size_t index = hash_c(key, TABLE_SIZE);
        
        if (index < TABLE_SIZE) {
            distribution[index]++;
        }
    }
    
    // 輸出部分結果 (僅顯示前 10 個桶子的分佈)
    printf("部分桶子 (Bucket) 命中次數:\n");
    for (i = 0; i < 10; i++) {
        printf("Bucket [%04d]: %zu\n", i, distribution[i]);
    }
    
    double average_hits = (double)NUM_KEYS / TABLE_SIZE;
    printf("\n理論平均命中次數: %.2f\n", average_hits);
    printf("(完整分佈請參考 README.md 的分析)\n");
}

int main() {
    run_c_test();
    return 0;
}