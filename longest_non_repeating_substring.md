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
              if (currentLength > maxLength) {
                    maxLength = currentLength;
                    startIndex = i;
                }
            }
        }
    }
    printf("Brute Force: Substring = ");
    for (int i = 0; i < maxLength; i++)
        putchar(str[startIndex + i]);
    printf("\nLength = %d\n", maxLength);

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
        if (currentLength > maxLength) {
            maxLength = currentLength;
            startIndex = start;
        }
    }

    printf("Sliding Window: Substring = ");
    for (int i = 0; i < maxLength; i++)
        putchar(str[startIndex + i]);
    printf("\nLength = %d\n", maxLength);

    return maxLength;
}

int main() {
    char str[] = "abcabcbb";
    printf("Sliding Window: Length of longest substring = %d\n", longestUniqueSubstrSliding(str));
    return 0;
}
```

## 3. # Pointer-Based Sliding Window Method 

```c
#include <stdio.h>

void longest_unique_substring_pointer(char *str) {
    int visited[256] = {0};
    char *start = str, *end = str;
    char *max_start = str;
    int max_len = 0;

    while (*end) {
        if (!visited[(unsigned char)*end]) {
            visited[(unsigned char)*end] = 1;
            int window_len = end - start + 1;
            if (window_len > max_len) {
                max_len = window_len;
                max_start = start;
            }
            end++;
        } else {
            visited[(unsigned char)*start] = 0;
            start++;
        }
    }

    printf("Longest Unique Substring (Pointer version): ");
    for (int i = 0; i < max_len; i++)
        putchar(*(max_start + i));
    printf("\nLength: %d\n", max_len);
}

int main() {
    char str[] = "abcbdeac";
    longest_unique_substring_pointer(str);
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
            if (currLen > maxLen) {
                maxLen = currLen;
                startIndex = i;
            }
        }
    }

    printf("Bitmasking: Substring = ");
    for (int i = 0; i < maxLen; i++)
        putchar(str[startIndex + i]);
    printf("\nLength = %d\n", maxLen);

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
      if (currLength > maxLength) {
            maxLength = currLength;
            startIndex = start;
        }
    }

    printf("Struct Array: Substring = ");
    for (int i = 0; i < maxLength; i++)
        putchar(str[startIndex + i]);
    printf("\nLength = %d\n", maxLength);

    return maxLength;
}

int main() {
    char str[] = "abcbdeafg";
    printf("Structure Array Method: Length = %d\n", longestUniqueSubstrStructArray(str));
    return 0;
}
```

