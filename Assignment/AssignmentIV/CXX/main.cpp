// main.cpp
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>


template<typename K>
class MultiplicativeHasher {
public:
    size_t operator()(K key, size_t table_size) const;
};

#define TABLE_SIZE_CPP 1024
#define NUM_KEYS_CPP 20000

void run_cpp_test() {
    MultiplicativeHasher<int> hasher;
    std::vector<size_t> distribution(TABLE_SIZE_CPP, 0);
    
    std::cout << "====================================================\n";
    std::cout << "C++ 語言雜湊函數測試與分佈分析\n";
    std::cout << "表大小: " << TABLE_SIZE_CPP << ", 測試鍵數: " << NUM_KEYS_CPP << std::endl;
    std::cout << "====================================================\n";

    std::cout << "\n--- 1. 測試連續鍵值分佈 (1 到 20000) ---\n";
    for (int i = 1; i <= NUM_KEYS_CPP; i++) {
        size_t index = hasher(i, TABLE_SIZE_CPP);
        distribution[index]++;
    }


    std::cout << "部分桶子 (Bucket) 命中次數:\n";
    for (size_t i = 0; i < 10; i++) {
        std::cout << "Bucket [" << i << "]: " << distribution[i] << std::endl;
    }
    
    double average_hits = (double)NUM_KEYS_CPP / TABLE_SIZE_CPP;
    std::cout << "\n理論平均命中次數: " << average_hits << std::endl;
    std::cout << "(完整分佈請參考 README.md 的分析)\n";
}

int main() {
    run_cpp_test();
    return 0;
}