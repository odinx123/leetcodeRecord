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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);

        int n = 0;
        ListNode* curNode = head;
        while (curNode) {
            curNode = curNode->next;
            ++n;
        }

        int times = n / k, mod = n % k;

        for (int i = 0; head && i < k; ++i) {
            ListNode* root = new ListNode();
            ListNode* temp = root;
            for (int j = mod-- <= 0; j <= times; ++j) {  // 不合條件從0開始(會多執行一次)
                temp = temp->next = new ListNode(head->val);
                head = head->next;
            }
            ans[i] = root->next;
        }

        return ans;
    }
};