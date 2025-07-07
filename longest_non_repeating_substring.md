# Longest Non-Repeating Substring Methods in C

## 1. Brute Force Method

```c
#include <stdio.h>
#include <string.h>

int areDistinct(char *str, int start, int end) {
    int visited[256] = {0};
    for (int i = start; i <= end; i++) {
        if (visited[(unsigned char)str[i]])
            return 0;
        visited[(unsigned char)str[i]] = 1;
    }
    return 1;
}

int longestUniqueSubstrBrute(char *str) {
    int maxLength = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (areDistinct(str, i, j)) {
                int currentLength = j - i + 1;
                if (currentLength > maxLength)
                    maxLength = currentLength;
            }
        }
    }
    return maxLength;
}

int main() {
    char str[] = "abcabcbb";
    printf("Brute Force: Length of longest substring = %d\n", longestUniqueSubstrBrute(str));
    return 0;
}
```

## 2. Sliding Window Method

```c
#include <stdio.h>
#include <string.h>

int longestUniqueSubstrSliding(char *str) {
    int visited[256];
    for (int i = 0; i < 256; i++) visited[i] = -1;

    int maxLength = 0, start = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (visited[(unsigned char)str[i]] >= start) {
            start = visited[(unsigned char)str[i]] + 1;
        }
        visited[(unsigned char)str[i]] = i;
        int currentLength = i - start + 1;
        if (currentLength > maxLength)
            maxLength = currentLength;
    }
    return maxLength;
}

int main() {
    char str[] = "abcabcbb";
    printf("Sliding Window: Length of longest substring = %d\n", longestUniqueSubstrSliding(str));
    return 0;
}
```

## 3. Optimized Sliding Window (Hashing)

```c
#include <stdio.h>
#include <string.h>

int longestUniqueSubstrOptimized(char *str) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLength = 0;
    int start = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (lastIndex[(unsigned char)str[i]] >= start) {
            start = lastIndex[(unsigned char)str[i]] + 1;
        }
        lastIndex[(unsigned char)str[i]] = i;
        int currentLength = i - start + 1;
        if (currentLength > maxLength)
            maxLength = currentLength;
    }
    return maxLength;
}

int main() {
    char str[] = "pwwkew";
    printf("Optimized Sliding Window: Length = %d\n", longestUniqueSubstrOptimized(str));
    return 0;
}
```

## 4. Bit Masking

```c
#include <stdio.h>
#include <string.h>

int longestUniqueSubstrBitmask(char *str) {
    int maxLen = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        int mask = 0;
        int currLen = 0;

        for (int j = i; j < len; j++) {
            int bit = str[j] - 'a';
            if (bit < 0 || bit > 25) break;  // Not a lowercase letter

            if ((mask & (1 << bit)) > 0)
                break;

            mask |= (1 << bit);
            currLen++;
            if (currLen > maxLen)
                maxLen = currLen;
        }
    }
    return maxLen;
}

int main() {
    char str[] = "abacdefgh";
    printf("Bitmasking Method: Length of longest substring = %d\n", longestUniqueSubstrBitmask(str));
    return 0;
}
```

## 5. Structure + Array

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    int lastIndex;
} CharInfo;

int longestUniqueSubstrStructArray(char *str) {
    CharInfo charMap[256];
    for (int i = 0; i < 256; i++)
        charMap[i].lastIndex = -1;

    int start = 0, maxLength = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        unsigned char ch = str[i];

        if (charMap[ch].lastIndex >= start)
            start = charMap[ch].lastIndex + 1;

        charMap[ch].lastIndex = i;

        int currLength = i - start + 1;
        if (currLength > maxLength)
            maxLength = currLength;
    }

    return maxLength;
}

int main() {
    char str[] = "abcbdeafg";
    printf("Structure Array Method: Length = %d\n", longestUniqueSubstrStructArray(str));
    return 0;
}
```

