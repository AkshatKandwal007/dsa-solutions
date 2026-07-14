/*
 * Problem: 7. Reverse Integer
 * Pattern: Math (digit extraction)
 * Time:    O(log10(x)) — one iteration per digit
 * Space:   O(1)
 * Idea:    Pop last digit with %10, push onto rev via rev*10 + d.
 *          Don't strip the sign — C99 % keeps the dividend's sign,
 *          so negatives reverse correctly with no special case.
 *          Guard BEFORE the multiply: signed overflow is UB in C,
 *          so checking after the fact is not reliable.
 */

#include <limits.h>

int reverse(int x) {
    int rev = 0;

    while (x != 0) {
        int d = x % 10;
        x /= 10;

        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && d > 7))
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && d < -8))
            return 0;

        rev = rev * 10 + d;
    }

    return rev;
}
