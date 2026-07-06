/*
 * Problem: Add Two Numbers (LeetCode 2)
 * Pattern: Linked List
 * Time: O(max(m, n)) | Space: O(max(m, n))
 *
 * Idea: Traverse both lists together, adding digit by digit and
 * carrying over into the next node. Continue while either list has
 * nodes remaining or a carry is still pending.
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* last = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int v1 = (l1 != NULL) ? l1->val : 0;
        int v2 = (l2 != NULL) ? l2->val : 0;
        int sum = v1 + v2 + carry;

        carry = sum / 10;

        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;

        if (head == NULL) {
            head = node;
        } else {
            last->next = node;
        }
        last = node;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return head;
}
