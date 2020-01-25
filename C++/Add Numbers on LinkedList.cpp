'''
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

workflow

add a carry out variable
add two values if not NULL else add by 0 until both lls are NULL;
'''


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* cOne = l1;
        ListNode* cTwo = l2;
        ListNode* cRes = res;
        int cout = 0;
        while (cOne != NULL || cTwo != NULL){
            int x = cOne != NULL ? cOne->val: 0;
            int y = cTwo != NULL ? cTwo->val: 0;
            int sum = cout + x + y;
            cout = sum / 10;
            cRes->next = new ListNode(sum%10);
            cRes = cRes -> next;
            if (cOne != NULL) cOne = cOne ->next;
            if (cTwo != NULL) cTwo = cTwo ->next;
        }
        if (cout > 0) cRes -> next = new ListNode(cout);
        return res->next;
}
};