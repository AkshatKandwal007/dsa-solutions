// Problem: 27. Remove Element
// Pattern: Two Pointers
// Time:  O(1)
// Space: O(1)
// Idea:  Reader scans all elements; writer places keepers at front.
int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
