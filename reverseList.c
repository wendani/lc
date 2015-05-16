/*
  struct ListNode {
  int val;
  struct ListNode *next;
  };
*/

struct ListNode *reverseList(struct ListNode *head) {

  struct ListNode *curr;
  if (!head)
    return head;

  struct ListNode *nhd = head->next;
  head->next = NULL;
  while (nhd) {
    curr = nhd;
    nhd = curr->next;

    curr->next = head;
    head = curr;
  }

  return head;
}
