
#include <cstdint>
#include <stddef.h>
#include <cmath>


constexpr int WORD_SIZE = 32;


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

template class MultiplicativeHasher<int>;
template class MultiplicativeHasher<uint32_t>;