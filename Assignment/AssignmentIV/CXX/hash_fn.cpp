// hash_fn.cpp
#include <cstdint>
#include <stddef.h>
#include <cmath>

// 乘法雜湊常數
constexpr uint32_t HASH_MULTIPLIER = 0x9e3779b9UL;
constexpr int WORD_SIZE = 32;

// 類別定義與實作
template<typename K>
class MultiplicativeHasher {
public:
    size_t operator()(K key, size_t table_size) const {
        // 確保鍵轉換為 32 位元無符號整數
        uint32_t u_key = static_cast<uint32_t>(key);

        uint32_t hash_value = u_key * HASH_MULTIPLIER;

        // 判斷 table_size 是否為 2 的冪次 (優化)
        if ((table_size & (table_size - 1)) == 0) {
            // 計算 Log2(table_size)
            int p = 0;
            size_t temp_size = table_size;
            while (temp_size > 1) {
                temp_size >>= 1;
                p++;
            }
            
            // 提取高 P 位
            return (size_t)(hash_value >> (WORD_SIZE - p));
        } else {
            // 使用標準取模運算
            return (size_t)hash_value % table_size;
        }
    }
};

// 顯式實例化常用類型，以便編譯器知道要為這些類型生成程式碼
template class MultiplicativeHasher<int>;
template class MultiplicativeHasher<uint32_t>;