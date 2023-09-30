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
private:
    ListNode* helper(ListNode* slow,ListNode* fast){
    if(fast->next==NULL){
        return slow;
    }
    if(fast->next->next==NULL){
        return slow->next;
    }
    return helper(slow->next,fast->next->next);
}
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        return helper(slow,fast);
    }
};