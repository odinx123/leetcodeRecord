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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode();
        ListNode *nextNode = ans;
        
        int carry = 0;
        while (nextNode) {
            int a = 0, b = 0;
            if (l1) {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                b = l2->val;
                l2 = l2->next;
            }
            nextNode->val = (a + b + carry)%10;
            carry = (a + b + carry)/10;
            if (l1 || l2 || carry)  // 只要l1、l2或是carry還有數字就繼續
                nextNode->next = new ListNode();
            nextNode = nextNode->next;
        }        
        
        return ans;
    }
};