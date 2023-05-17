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
    int ans=0;
    ListNode *a;
    void solve(ListNode* b){
        if(!b)
            return;
        solve(b->next);
        ans=max(ans,a->val+b->val);
        a=a->next;
    }
    int pairSum(ListNode* head) {
        a=head;
        solve(head);
        return ans;
    }
};