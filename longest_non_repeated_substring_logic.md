
# Longest Non-Repeating Substring – Methods Explained (Markdown)

---

## **1. Sliding Window (Indexing)**

**Input**: `"hihelloworld"`
**Output**: `"world"`

| Step | Index | Char | Action            | Substring    | Current Index   | Current Length |
| ---- | ----- | ---- | ----------------- | ------------ | --------------- | -------------- |
| 1    | 0     | h    | h → 1             | \[h]         | 0               | 1              |
| 2    | 1     | i    | i → 1             | \[hi]        | 0               | 2              |
| 3    | 2     | h    | h → 0 (duplicate) | \[hih]       | index = 1 \[ih] | 2              |
| 4    | 3     | e    | e → 1             | \[ihe]       | 1               | 3              |
| 5    | 4     | l    | l → 1             | \[ihel]      | 1               | 4              |
| 6    | 5     | l    | l → 0 (duplicate) | \[ihell]     | index = 5 \[l]  | 1              |
| 7    | 6     | o    | o → 1             | \[lo]        | 5               | 2              |
| 8    | 7     | w    | w → 1             | \[low]       | 5               | 3              |
| 9    | 8     | o    | o → 0 (duplicate) | \[lowo]      | index = 7 \[wo] | 2              |
| 10   | 9     | r    | r → 1             | \[wor]       | 7               | 3              |
| 11   | 10    | l    | l → 1             | \[worl]      | 7               | 4              |
| 12   | 11    | d    | d → 1             | **\[world]** | 7               | **5**          |

**Result**: Substring from index `7`, length `5` → **`world`**

---

## **2. Sliding Window (Pointers)**

**Input**: `"hihelloworld"`
**Variables**:

* `start`, `end`, `start_ind`: pointers
* `visited[256] = {0}`

| Step | `*start` | `*end` | Action        | Window       | max\_len | start\_ind |
| ---- | -------- | ------ | ------------- | ------------ | -------- | ---------- |
| 0    | h        | h      | h → 1         | \[h]         | 1        | 0          |
| 1    | h        | i      | i → 1         | \[hi]        | 2        | 0          |
| 2    | h        | h      | h → 0, shrink | \[ih]        | 2        | 1          |
| 3    | i        | e      | e → 1         | \[ihe]       | 3        | 1          |
| 4    | i        | l      | l → 1         | \[ihel]      | 4        | 1          |
| 5    | i        | l      | l → 0, shrink | \[l]         | 4        | 5          |
| 6    | l        | o      | o → 1         | \[lo]        | 4        | 5          |
| 7    | l        | w      | w → 1         | \[low]       | 4        | 5          |
| 8    | l        | o      | o → 0, shrink | \[wo]        | 4        | 7          |
| 9    | w        | r      | r → 1         | \[wor]       | 4        | 7          |
| 10   | w        | l      | l → 1         | \[worl]      | 4        | 7          |
| 11   | w        | d      | d → 1         | **\[world]** | **5**    | **7**      |

**Result**: Substring from pointer `start_ind = 7`, length `max_len = 5` → **`world`**

---

## **3. Brute Force**

**Input**: `"hihelloworld"`
**Time Complexity**: O(n²)

### 3. Brute Force

| i | j  | Character | Action                        | Substring | cur_len | max_len | start_ind |
|---|----|-----------|-------------------------------|-----------|----------|----------|------------|
| 0 | 0  | 'h'       | h=1                           | [h]       | 1        | 1        | 0          |
| 0 | 1  | 'i'       | i=1                           | [hi]      | 2        | 2        | 0          |
| 0 | 2  | 'h'       | already visited → break       |           |          | 2        | 0          |
| 1 | 1  | 'i'       | i=1                           | [i]       | 1        | 2        | 0          |
| 1 | 2  | 'h'       | h=1                           | [ih]      | 2        | 2        | 0          |
| 1 | 3  | 'e'       | e=1                           | [ihe]     | 3        | 3        | 1          |
| 1 | 4  | 'l'       | l=1                           | [ihel]    | 4        | 4        | 1          |
| 1 | 5  | 'l'       | already visited → break       |           |          | 4        | 1          |
| 2 | 2  | 'h'       | h=1                           | [h]       | 1        | 4        | 1          |
| 2 | 3  | 'e'       | e=1                           | [he]      | 2        | 4        | 1          |
| 2 | 4  | 'l'       | l=1                           | [hel]     | 3        | 4        | 1          |
| 2 | 5  | 'l'       | already visited → break       |           |          | 4        | 1          |
| 3 | 3  | 'e'       | e=1                           | [e]       | 1        | 4        | 1          |
| 3 | 4  | 'l'       | l=1                           | [el]      | 2        | 4        | 1          |
| 3 | 5  | 'l'       | already visited → break       |           |          | 4        | 1          |
| 4 | 4  | 'l'       | l=1                           | [l]       | 1        | 4        | 1          |
| 4 | 5  | 'l'       | already visited → break       |           |          | 4        | 1          |
| 5 | 5  | 'l'       | l=1                           | [l]       | 1        | 4        | 1          |
| 5 | 6  | 'o'       | o=1                           | [lo]      | 2        | 4        | 1          |
| 5 | 7  | 'w'       | w=1                           | [low]     | 3        | 4        | 1          |
| 5 | 8  | 'o'       | already visited → break       |           |          | 4        | 1          |
| 6 | 6  | 'o'       | o=1                           | [o]       | 1        | 4        | 1          |
| 6 | 7  | 'w'       | w=1                           | [ow]      | 2        | 4        | 1          |
| 6 | 8  | 'o'       | already visited → break       |           |          | 4        | 1          |
| 7 | 7  | 'w'       | w=1                           | [w]       | 1        | 4        | 1          |
| 7 | 8  | 'o'       | o=1                           | [wo]      | 2        | 4        | 1          |
| 7 | 9  | 'r'       | r=1                           | [wor]     | 3        | 4        | 1          |
| 7 | 10 | 'l'       | l=1                           | [worl]    | 4        | 4        | 1          |
| 7 | 11 | 'd'       | d=1                           | [world]   | 5        | 5        | 7          |
| 8 | 8  | 'o'       | o=1                           | [o]       | 1        | 5        | 7          |
| 8 | 9  | 'r'       | r=1                           | [or]      | 2        | 5        | 7          |
| 8 | 10 | 'l'       | l=1                           | [orl]     | 3        | 5        | 7          |
| 8 | 11 | 'd'       | d=1                           | [orld]    | 4        | 5        | 7          |
| 9 | 9  | 'r'       | r=1                           | [r]       | 1        | 5        | 7          |
| 9 | 10 | 'l'       | l=1                           | [rl]      | 2        | 5        | 7          |
| 9 | 11 | 'd'       | d=1                           | [rld]     | 3        | 5        | 7          |
|10 | 10 | 'l'       | l=1                           | [l]       | 1        | 5        | 7          |
|10 | 11 | 'd'       | d=1                           | [ld]      | 2        | 5        | 7          |
|11 | 11 | 'd'       | d=1                           | [d]       | 1        | 5        | 7          |

**Result**: Substring from index `7`, length `5` → **`world`**


---

### 4. Bit Masking

**Input**: `"hihelloworld"`
**Logic**: Use a 32-bit integer to represent set of characters using bitwise.


| i | j  | Character | mask operation         | Substring | cur_len | max_len | start_ind |
|---|----|-----------|------------------------|-----------|----------|----------|------------|
| 0 | 0  | 'h'       | mask |= (1<<7)         | [h]       | 1        | 1        | 0          |
| 0 | 1  | 'i'       | mask |= (1<<8)         | [hi]      | 2        | 2        | 0          |
| 0 | 2  | 'h'       | already in mask → break|           |          | 2        | 0          |
| 1 | 1  | 'i'       | mask |= (1<<8)         | [i]       | 1        | 2        | 0          |
| 1 | 2  | 'h'       | mask |= (1<<7)         | [ih]      | 2        | 2        | 0          |
| 1 | 3  | 'e'       | mask |= (1<<4)         | [ihe]     | 3        | 3        | 1          |
| 1 | 4  | 'l'       | mask |= (1<<11)        | [ihel]    | 4        | 4        | 1          |
| 1 | 5  | 'l'       | already in mask → break|           |          | 4        | 1          |
| 2 | 2  | 'h'       | mask |= (1<<7)         | [h]       | 1        | 4        | 1          |
| 2 | 3  | 'e'       | mask |= (1<<4)         | [he]      | 2        | 4        | 1          |
| 2 | 4  | 'l'       | mask |= (1<<11)        | [hel]     | 3        | 4        | 1          |
| 2 | 5  | 'l'       | already in mask → break|           |          | 4        | 1          |
| 3 | 3  | 'e'       | mask |= (1<<4)         | [e]       | 1        | 4        | 1          |
| 3 | 4  | 'l'       | mask |= (1<<11)        | [el]      | 2        | 4        | 1          |
| 3 | 5  | 'l'       | already in mask → break|           |          | 4        | 1          |
| 4 | 4  | 'l'       | mask |= (1<<11)        | [l]       | 1        | 4        | 1          |
| 4 | 5  | 'l'       | already in mask → break|           |          | 4        | 1          |
| 5 | 5  | 'l'       | mask |= (1<<11)        | [l]       | 1        | 4        | 1          |
| 5 | 6  | 'o'       | mask |= (1<<14)        | [lo]      | 2        | 4        | 1          |
| 5 | 7  | 'w'       | mask |= (1<<22)        | [low]     | 3        | 4        | 1          |
| 5 | 8  | 'o'       | already in mask → break|           |          | 4        | 1          |
| 6 | 6  | 'o'       | mask |= (1<<14)        | [o]       | 1        | 4        | 1          |
| 6 | 7  | 'w'       | mask |= (1<<22)        | [ow]      | 2        | 4        | 1          |
| 6 | 8  | 'o'       | already in mask → break|           |          | 4        | 1          |
| 7 | 7  | 'w'       | mask |= (1<<22)        | [w]       | 1        | 4        | 1          |
| 7 | 8  | 'o'       | mask |= (1<<14)        | [wo]      | 2        | 4        | 1          |
| 7 | 9  | 'r'       | mask |= (1<<17)        | [wor]     | 3        | 4        | 1          |
| 7 | 10 | 'l'       | mask |= (1<<11)        | [worl]    | 4        | 4        | 1          |
| 7 | 11 | 'd'       | mask |= (1<<3)         | [world]   | 5        | 5        | 7          |
| 8 | 8  | 'o'       | mask |= (1<<14)        | [o]       | 1        | 5        | 7          |
| 8 | 9  | 'r'       | mask |= (1<<17)        | [or]      | 2        | 5        | 7          |
| 8 | 10 | 'l'       | mask |= (1<<11)        | [orl]     | 3        | 5        | 7          |
| 8 | 11 | 'd'       | mask |= (1<<3)         | [orld]    | 4        | 5        | 7          |
| 9 | 9  | 'r'       | mask |= (1<<17)        | [r]       | 1        | 5        | 7          |
| 9 | 10 | 'l'       | mask |= (1<<11)        | [rl]      | 2        | 5        | 7          |
| 9 | 11 | 'd'       | mask |= (1<<3)         | [rld]     | 3        | 5        | 7          |
|10 | 10 | 'l'       | mask |= (1<<11)        | [l]       | 1        | 5        | 7          |
|10 | 11 | 'd'       | mask |= (1<<3)         | [ld]      | 2        | 5        | 7          |
|11 | 11 | 'd'       | mask |= (1<<3)         | [d]       | 1        | 5        | 7          |



**Result**: Substring from index `7`, length `5` → **`world`**

---


