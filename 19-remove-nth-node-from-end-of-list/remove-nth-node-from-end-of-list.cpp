class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. Create a dummy node pointing to head
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // 2. Advance fast pointer so there's a gap of n nodes
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // 3. Move both until fast reaches the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 4. Skip the nth node from the end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Clean up memory (optional in LeetCode, but good practice)
        delete nodeToDelete;

        return dummy->next;
    }
};