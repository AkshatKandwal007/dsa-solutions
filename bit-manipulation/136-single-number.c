/*
 * Problem: 136. Single Number
 * Pattern: bit-manipulation
 * Time:    O(n)
 * Space:   O(1)
 * Idea:    <your words>
 */

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}
