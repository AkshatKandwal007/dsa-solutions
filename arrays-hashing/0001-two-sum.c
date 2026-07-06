/*
 * Problem: Two Sum (LeetCode 1)
 * Pattern: Arrays & Hashing
 *
 * Two approaches included:
 *   1. Brute force baseline — O(n^2) time, O(1) space
 *   2. Optimized hash map   — O(n)   time, O(n) space
 *
 * Key insight: instead of checking every pair, store each value's
 * index as you go and look up whether its complement (target - num)
 * has already been seen — reducing the search to a single pass.
 */

#include <stdlib.h>

/* ---------- Approach 1: Brute force baseline — O(n^2) ---------- */
int* twoSum_brute(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* result = malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

/* ---------- Approach 2: Optimized hash map — O(n) ---------- */
/*
 * C has no built-in hash map, so we implement a simple open-addressing
 * hash table keyed by value. Each slot stores a value and its index.
 */

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
