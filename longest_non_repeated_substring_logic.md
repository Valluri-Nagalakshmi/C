
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

Iterate over all substrings and check for distinct characters:

| i | j    | Substring | Action            | max\_len | start\_ind |
| - | ---- | --------- | ----------------- | -------- | ---------- |
| 0 | 0-2  | h, hi     | Valid             | 2        | 0          |
| 1 | 1-4  | ihel      | Valid             | 4        | 1          |
| 7 | 7-11 | **world** | Valid, Max Found! | **5**    | **7**      |

**Result**: Substring from index `7`, length `5` → **`world`**

---

## **4. Bit Masking** (Lowercase letters only: assumes a-z)

**Input**: `"hihelloworld"`
**Logic**: Use a 32-bit integer to represent set of characters using bitwise.

| i | j    | Char      | Bitmask Operation | Substring    | max\_len | start\_ind |   |   |
| - | ---- | --------- | ----------------- | ------------ | -------- | ---------- | - | - |
| 0 | 0-1  | h,i       | \`mask            | = (1<<7      | 8)\`     | \[hi]      | 2 | 0 |
| 1 | 1-4  | ihel      | Unique, Valid     | \[ihel]      | 4        | 1          |   |   |
| 7 | 7-11 | **world** | All unique        | **\[world]** | **5**    | **7**      |   |   |


**Result**: Substring from index `7`, length `5` → **`world`**

---


