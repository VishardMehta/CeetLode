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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<int, vector<int>, greater<int>> q;

        for (ListNode* head : lists) {
            while (head) {
                q.push(head->val);
                head = head->next;
            }
        }

        if (q.empty())
            return NULL;

        ListNode* head = new ListNode(q.top());
        q.pop();

        ListNode* curr = head;

        while (!q.empty()) {
            curr->next = new ListNode(q.top());
            q.pop();
            curr = curr->next;
        }

        return head;
    }
};
