/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        ListNode * dummy;
        ListNode * p = dummy;
        while (p1 && p2) {
            if (p1 -> val <= p2 -> val) {
                p -> next = p1;
                p1 = p1 -> next;
            }
            else {
                p -> next = p2;
                p2 = p2 -> next;
            }
            p = p -> next;
        }
        if (p1 == nullptr)
            p -> next = p2;
        if (p2 == nullptr)
            p -> next = p1;
        return dummy -> next;
    }
};