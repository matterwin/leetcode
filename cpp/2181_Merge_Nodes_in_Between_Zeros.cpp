// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* lhs_0 = head, *trail = nullptr;
        while (lhs_0->next)
        {
            int sum = 0;
            ListNode* it = lhs_0->next;

            while (it->val != 0)
            {
                sum += it->val;
                it = it->next;
                if (it->val != 0)
                    trail = it;
            }

            lhs_0->val = sum;
            if (it->next == nullptr)
                lhs_0->next = nullptr;
            else 
                lhs_0->next = it;
            lhs_0 = it;
        }

        trail->next = nullptr;
        return head;
    }
};


