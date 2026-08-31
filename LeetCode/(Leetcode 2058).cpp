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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        if (!head || !head->next || !head->next->next)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        int maxDist = -1;

        while (curr->next) {
            int nextVal = curr->next->val;

            // Check if curr is a critical point
            bool isMax = curr->val > prev->val && curr->val > nextVal;
            bool isMin = curr->val < prev->val && curr->val < nextVal;

            if (isMax || isMin) {
                if (first == -1) {
                    // First critical point
                    first = index;
                } else {
                    // Distance from previous critical point
                    minDist = min(minDist, index - last);

                    // Distance from first critical point
                    maxDist = max(maxDist, index - first);
                }

                last = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (maxDist == -1)
            return {-1, -1};

        return {minDist, maxDist};
    }
};
