/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * digitL1 = NULL;
    struct ListNode * digitL2 = NULL;
    struct ListNode * sum = NULL;
    struct ListNode * digitSum = NULL;
    int addition = 0;
    int carry = 0;

    sum = l1;

    digitL1 = l1;
    digitL2 = l2;
    while (digitL1 != NULL || digitL2 != NULL) {
        digitSum = (digitL1 != NULL ? digitL1 : digitL2);
        addition = carry - 10;

        if (digitL1 != NULL) {
            addition += digitL1->val;
            digitSum = digitL1;
        } else {
            digitSum = digitL2;
            sum = l2;
        }

        if (digitL2 != NULL) {
            addition += digitL2->val;
        }

        carry = 0;
        if (-10 <= addition && addition < 0) {
            addition += 10;
        } else {
            carry = 1;
        }

        if (digitL1 != NULL) {
            digitL1->val = addition;
            digitL1 = digitL1->next;
        }

        if (digitL2 != NULL) {
            digitL2->val = addition;
            digitL2 = digitL2->next;
        }
    }

    if (carry) {
        digitSum->next = (struct ListNode *) malloc(sizeof (struct ListNode));
        digitSum->next->val = carry;
        digitSum->next->next = NULL;
    }

    return sum;
}
