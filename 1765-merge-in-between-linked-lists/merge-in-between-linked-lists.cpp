class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tail2 = list2;
        
        // Find tail of list2
        while (tail2->next != NULL) {
            tail2 = tail2->next;
        }
        
        ListNode* prev1 = nullptr;
        ListNode* prev2 = nullptr;
        ListNode* getA = list1;
        ListNode* getB = list1;

        // Get to the node at position a
        for (int i = 1; i <= a; ++i) {
            prev1 = getA;
            getA = getA->next;
        }

        // Get to the node at position b
        for (int i = 0; i < b; ++i) {
            prev2 = getB;
            getB = getB->next;
        }

        // Connect the previous node of a to list2
        if (prev1 != nullptr)
            prev1->next = list2;

        // Connect the last node of list2 to the node after b
        tail2->next = getB->next;

        return list1;
    }
};
