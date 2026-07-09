/*
 * Problem: Valid Anagram (LeetCode 242)
 * Pattern: Arrays & Hashing
 * Time: O(n) | Space: O(1)
 *
 * Idea: The int[26] array IS a hash map — key is the letter (hashed via
 * letter - 'a'), value is its count. Increment counts for s, decrement for t
 * in a single pass. If every slot is zero at the end, every letter cancelled,
 * so it's an anagram. Length mismatch is a free early exit.
 */

#include <string.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t))
        return false;

    int count[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0)
            return false;
    }

    return true;
}
