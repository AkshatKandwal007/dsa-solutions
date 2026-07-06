/*
 * Problem: Two Sum (LeetCode 1)
 * Pattern: Arrays & Hashing
 * Time: O(n) | Space: O(n)
 *
 * Idea: Store each value's index in a hash table as we go. For each
 * number, check whether its complement (target - num) has already
 * been seen — if so, we have our pair in a single pass.
 *
 * Note: C has no built-in hash map, so we implement a simple
 * open-addressing table with linear probing.
 */

#include <stdlib.h>

#define TABLE_SIZE 20011   /* a prime larger than the max input size */

typedef struct {
    int key;
    int index;
    int used;
} Entry;

static int hashIndex(int key) {
    /* handle negatives, keep result within table bounds */
    long h = (long)key % TABLE_SIZE;
    if (h < 0) h += TABLE_SIZE;
    return (int)h;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Entry* table = calloc(TABLE_SIZE, sizeof(Entry));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        /* look for the complement in the table */
        int h = hashIndex(complement);
        while (table[h].used) {
            if (table[h].key == complement) {
                int* result = malloc(2 * sizeof(int));
                result[0] = table[h].index;
                result[1] = i;
                *returnSize = 2;
                free(table);
                return result;
            }
            h = (h + 1) % TABLE_SIZE;   /* linear probing on collision */
        }

        /* insert current value */
        int slot = hashIndex(nums[i]);
        while (table[slot].used) {
            slot = (slot + 1) % TABLE_SIZE;
        }
        table[slot].key = nums[i];
        table[slot].index = i;
        table[slot].used = 1;
    }

    *returnSize = 0;
    free(table);
    return NULL;
}
