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

    struct ListNode *mid, *curr, *comp_head, *nxt;
    int step;

    if (!head)
        return true;

    // find the mid element along the list
    mid = head;
    curr = head->next;
    step = 0;
    while (curr) {
        curr = curr->next;
        step++;
        if (step == 2) {
            mid = mid->next;
            step = 0;
        }
    }

    // reverse the second half of the list
    comp_head = NULL;
    curr = mid->next;
    while (curr) {
        nxt = curr->next;
        
        curr->next = comp_head;
        
        comp_head = curr;
        curr = nxt;
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
