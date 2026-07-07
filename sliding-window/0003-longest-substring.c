/*
 * Problem: Longest Substring Without Repeating Characters (LeetCode 3)
 * Pattern: Sliding Window
 * Time: O(n) | Space: O(1)
 *
 * Idea: Expand a window with the right pointer; store each char's last-seen
 * index in a fixed [128] array. When the current char was already seen inside
 * the window (last[c] >= left), jump left to last[c] + 1 to skip past the
 * duplicate in one move. Track the max window length as you go.
 */

#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int last[128];
    for (int i = 0; i < 128; i++)
        last[i] = -1;

    int maxLen = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        char c = s[right];

        if (last[c] >= left)
            left = last[c] + 1;

        last[c] = right;

        int windowLen = right - left + 1;
        if (windowLen > maxLen)
            maxLen = windowLen;
    }

    return maxLen;
}
