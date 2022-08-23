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
class Solution {  // Linked List 反轉可以把後面的指標指向前一個來達成
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* mid = head, *end = head;
        
        while (end && end->next) {
            mid = mid->next;
            end = end->next->next;
        }
        
        ListNode* prev = nullptr, *temp;
        while (mid != nullptr) {
            temp = mid->next;
            mid->next = prev;
            prev = mid;
            mid = temp;
        }
        
        while (prev) {
            if (prev->val != head->val) return false;
            prev = prev->next;
            head = head->next;
        }        
        
        return true;
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};