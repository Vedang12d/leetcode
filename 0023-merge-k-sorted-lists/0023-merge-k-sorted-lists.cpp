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
        vector<int> v;
        for(int i=0;i<lists.size();i++){
            while(lists[i]){
                v.push_back(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        if(v.empty())
            return nullptr;
        sort(v.begin(),v.end());
        ListNode* ans=nullptr;
        for(int i=v.size()-1;i>=0;i--){
            ListNode* node=new ListNode(v[i],ans);
            ans=node;
        }
        return ans;
    }
};