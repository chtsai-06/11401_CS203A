# 1131509 DATA STRUCTURES

- 11401_CS203A.  
- 蔡杰宏-1131509.  
- Some records for data structures.

---
ADT vs. DT  
- ADT:a conceptual model,showing what operations can be performed.   
- DT: implemention details of the language.
---
## Array
- 連續且位置固定(static)
- 排序： insert, delete, update, lookup (complexity)
- Application: tree; inbalanced-> balanced *sorting* (find the center let it be root)

| operation | BIG O |
| :--- | :---: |
| random access | O(1) |
| sequential search | O(n) |
| sorting | O(log n) *minimize space complexity* |
---
## Linked List
- 沒有 random access, 要 traverse 才會知道位置-> time complexity: O(n)

| operation | BIG O |
| :--- | :---: |
| traverse issue | O(n) |
| sequential search | O(n) |
| insert | O(1) |
| delete | O(1) |
---
| Aspect/Operation | Array | Linked List | Explaination |
| :--- | :---: | :---: | :---: |
| Access Element | O(1) | O(n) | Array allows direct indexing; Linked List needs traversal |
| Space Complexity | O(1) | O(1) | Both sorts are inplace if swapping values, not nodes |
| Implementation | Low | Moderate | Linked List needs pointer operation and carefull null checks |
---
## Stack
- 存放狀態：先進後出(FILO)
- *array 較優 (stack 資料只有一個出入口), 看 top 在哪*

| operation | BIG O |
| :--- | :---: |
| push | O(1) |
| pop | O(1) |
---
## Queue
- 存放狀態：先進先出(FIFO)
- front, end -> 記住 data position
---
## Hash Table
- Bucket (space) : ** Array + Linked List **
- Sorting (key-value) pairs -> Linked List
- Hash function: Convert key into index
- Load factor(α): 檢查 table 空間使用率 *靜態有差異*
- Collision: different keys but come into same index

| Solution | Explanation |
| :--- | :--- |
| Chainning | Linked List ex: [3]->15->23->27 ( old -> new ) |
| Probing | linear |
| Probing | quadratic |
| Probing | double |
