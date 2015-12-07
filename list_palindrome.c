/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * optimization oppertunity:
 * in finding the mid element, reverse the first half of the list at the same time
 */


bool isPalindrome(struct ListNode* head) {

    struct ListNode *mid, *curr, *new_mid;
    struct ListNode *comp_head, *nxt;
    int step;

    if (!head)
        return true;

    // find the mid element along the list
    mid = head;
    curr = head->next;
    step = 0;
    head = NULL;
    while (curr) {
        curr = curr->next;
        step++;
        if (step == 2) {
            new_mid = mid->next;
            mid->next = head;
            head = mid;
            mid = new_mid;
            step = 0;
        }
    }

    comp_head = mid->next;
    if (step == 1) {
        // even # of elements
        mid->next = head;
        head = mid;
    }

    // one-by-one comparison along the list
    while (comp_head) {
        if (comp_head->val != head->val)
            return false;
        comp_head = comp_head->next;
        head = head->next;
    }

    return true; 
}
