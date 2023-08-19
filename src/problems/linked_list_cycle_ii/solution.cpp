/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        // 找到相遇點，或是不是cycle
        // 假設slow到達cycle起點，fast在圈上任一點，slow要繞一整圈n，fast已經繞2n了，一定會碰到
        while (fast && fast->next) {
            // 先移動，不然起點一定一樣
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        // 如果沒有cycle
        if (!fast || !fast->next) return nullptr;

        // 從相遇的位置出發到cycle的起點為x，從head出發到cycle起點為m，cycle長n,y=n-x
        // k為fast在slow到達起點前繞的圈數
        /*
        fast = 2*slow
        m + k*n + y = 2 * (m + y)
        m + k*n = 2*m + y
        m = k*n - y = k*n - (n-x)
        m = n*(k-1) + x
        當k為認一數時代表繞多少圈，x是相遇位置到達cycle起點距離，所以head到cycle起點走m，等於
        從相遇位置繞任意圈+x，當兩者相遇就是起點了。
        */

        while (head != fast) {
            head = head->next;
            fast = fast->next;
        }

        return head;
    }
};