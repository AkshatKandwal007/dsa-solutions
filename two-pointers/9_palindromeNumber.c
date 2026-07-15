bool isPalindrome(int x) {
    if (x < 0) return false;

    char str[12];
    sprintf(str, "%d", x);

    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) return false;
        left++;
        right--;
    }
    return true;
}
