
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash_fn.h"

#define TABLE_SIZE 1024 
#define NUM_KEYS 20000 

void run_c_test() {
    size_t distribution[TABLE_SIZE] = {0};
    int i;
    
    printf("====================================================\n");
    printf("C 語言雜湊函數測試與分佈分析\n");
    printf("表大小: %zu, 測試鍵數: %d\n", TABLE_SIZE, NUM_KEYS);
    printf("====================================================\n");

    srand((unsigned int)time(NULL));


    printf("\n--- 1. 測試隨機鍵值分佈 ---\n");
    for (i = 0; i < NUM_KEYS; i++) {
        uint32_t key = rand() * rand(); 
        size_t index = hash_c(key, TABLE_SIZE);
        
        if (index < TABLE_SIZE) {
            distribution[index]++;
        }
    }

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