/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nxt = NULL;

    while (curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}
    ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL and fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *merge(ListNode *head, ListNode *head2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;

    while (head2 != NULL)
    {
        curr->next = head;
        curr = curr->next;
        head = head->next;

        curr->next = head2;
        curr = curr->next;
        head2 = head2->next;
    }

    // Append the remaining nodes of either list (if any)
    curr->next = head;

    ListNode *result = dummy->next;
    delete dummy; // Freeing memory allocated for the dummy node

    return result;
}
    void reorderList(ListNode* head) {
        ListNode* dummy = head;
        ListNode* temp = findMiddle(head);
        ListNode* head2 = reverse(temp->next);
        temp->next = NULL;
        head = merge(head , head2);
    }
};