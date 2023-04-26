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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        for (int i = 0; i < n; ++i)
            fast = fast->next;

        // 刪除head
        if (fast == nullptr) {
            auto temp = head->next;
            delete head;
            return temp;
        }

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        fast = slow->next;
        slow->next = fast->next;
        delete fast;

        return head;
    }
};