/*
 * Problem: LC 26 - Remove Duplicates from Sorted Array
 * Pattern: Two Pointers
 * Time:    O(n)  - single pass, fast visits each element once
 * Space:   O(1)  - only two index variables, modified in-place
 * Idea:    Sorted array => duplicates are adjacent. slow marks the
 *          next write slot; last kept unique value is at slow-1.
 *          fast scans; when nums[fast] differs from nums[slow-1],
 *          it's a new unique value: copy it to slow and advance.
 *          nums[0] is never a duplicate, so both start at 1.
 */

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int slow = 1;

    for (int fast = 1; fast < numsSize; fast++) {
        if (nums[fast] != nums[slow - 1]) {
            nums[slow] = nums[fast];
            slow++;
        }
    }

    return slow;
}
