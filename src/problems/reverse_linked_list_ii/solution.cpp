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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev = nullptr, *root, *last;
        ListNode* cur = head;
        int n = 0;
        while (cur) {
            ++n;
            if (n == left-1)
                prev = cur;
            if (n == left)
                root = cur;
            if (n == right)
                last = cur;
            if (cur->next)
                cur = cur->next;
            else
                break;
        }

        ListNode* con = last->next;
        reverseList(root, con);
        root->next = con;
        if (prev)
            prev->next = last;

        if (right-left+1 == n)
            return cur;
        else if (left == 1)
            return last;

        return head;
    }

    ListNode* reverseList(ListNode* head, ListNode* last) {
        ListNode* prev = nullptr;
        while (head != last) {
            auto nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }

        return prev;
    }
};