/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow, *fast;

    if (!head) return NULL;

    fast = head->next;
    if (!fast) return NULL;
    fast = fast->next;
    if (!fast) return NULL; 

    slow = head->next;
    while (slow != fast) {
        fast = fast->next;
        if (!fast) return NULL;
        fast = fast->next; 
        if (!fast) return NULL; 
        
        slow = slow->next;
    }

    while (head != fast) {
        head = head->next;
        fast = fast->next;
    }
    return fast;
}
