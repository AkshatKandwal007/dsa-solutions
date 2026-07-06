/*
 * Problem: Count the Number of Special Characters II (LeetCode 3120)
 * Pattern: Arrays & Hashing / String
 *
 * Two approaches included:
 *   1. Brute force baseline  — O(n^2) time, O(1) space
 *   2. Optimized (lookup)    — O(n)   time, O(1) space
 *
 * Key insight: instead of re-scanning the string for each letter,
 * record in a single pass whether each letter appears in lower and
 * upper case, then count letters seen in both.
 */

#include <ctype.h>
#include <string.h>

/* ---------- Approach 1: Brute force baseline — O(n^2) ---------- */
int numberOfSpecialChars_brute(char* word) {
    int c = 0;
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        if (!islower(word[i])) continue;

        int duplicate = 0;
        for (int k = 0; k < i; k++) {
            if (word[k] == word[i]) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate) continue;

        for (int j = 0; j < len; j++) {
            if (toupper(word[i]) == word[j]) {
                c++;
                break;
            }
        }
    }
    return c;
}

/* ---------- Approach 2: Optimized single-pass lookup — O(n) ---------- */
int numberOfSpecialChars(char* word) {
    int lower[26] = {0};
    int upper[26] = {0};
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        char ch = word[i];
        if (ch >= 'a' && ch <= 'z') lower[ch - 'a'] = 1;
        else if (ch >= 'A' && ch <= 'Z') upper[ch - 'A'] = 1;
    }

    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (lower[i] && upper[i]) count++;
    }
    return count;
}
