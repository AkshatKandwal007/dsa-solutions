bool isPalindrome(int x) {
    if (x < 0) return false;

    int digits[10];
    int n = 0;
    do {
        digits[n++] = x % 10;
        x /= 10;
    } while (x > 0);

    int left = 0, right = n - 1;
    while (left < right) {
        if (digits[left] != digits[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
