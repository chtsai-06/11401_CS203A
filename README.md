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
- table size is better to be prime numbers

| Collision Solution | Explanation |
| :--- | :--- |
| Chainning | Linked List ex: [3]->15->23->27 ( old -> new ) |
| Linear Probing | simple, crowded neighborhood, same as items may occupied others bucket  |
| Quadratic Probing | reduce secondary clustering(different keys in same index), but gaps grew,  |
| Double Probing | complex computing, better spread |

- Time complexity
- 1. Seperate chaining

| Operation| Best | Avg | Worst |
| :--- | :---: | :---: | :---: |
| insert | O(1) | O(n) | O(n) |
| search | O(1) | O(1+α) | O(n) |
| delete | O(1) | O(1) | O(n) |

- 2. Open Addressing

| Operation| Best | Avg | Worst |
| :--- | :---: | :---: | :---: |
| insert | x | O(1) | O(n) |
| search | x | O(1) | O(n) |
| delete | x | O(1) | O(n) |
---
## Tree
- fan out (degree): the number of children a node can have
- Binary tree: at most 2 children
- Binary Search tree: left < parent < right
- Traversal: __BFT__-> level by level, order: root-left-right
- Traversal: __DFT__-> (i) pre-order (順往下)
- Traversal: __BFT__-> (ii) in-order (到最左側, 往上找到父母, 向右下找子代, 結束後返回父母)
- Traversal: __BFT__-> (iii) postorder (左至右, 根需先走過再找父母)
- balanced: search, insertion -> O(logn)-->O(n)
---
## Heaps (Complete Binary Tree)

| properties | explanation |
| :--- | :---: |
| 1 | every level is filled except leaf |
| 2 | last level nodes are filled left --> right |
| 3 | stored efficiently |

- Max/Min heap -> maximum/minimum element always at root
- parent swap : 保持樹的完整性，無論是取代或新增皆從葉子點開始更動

- Time complexity

| Operation| time complexity |
| :--- | :---: |
| peek max/min | O(1) |
| build | O(n) |
| heapsort (extract) | O(n logn) |

__其餘都是 O(logn)__
---
## Graph
- Edges can have label (ex: z1) and weight (ex: 8)
- Solo vertex is also a subgraph
- Adjacency matrix: dense graph first edge lookup  _edge lookup O(1), but space O(^2)_
- Adjacenncy list: large, dynamic graph  _insert/delete O(1), space O(v+e)_
- Degree:

| In-degree | how many edges point into the vertex |
| Out-degree | how many edges start from the vertex |

-graph BFS/DFS:
| BFS | queue-> level does matter |
| DFS | track current path, backtracking memory |
