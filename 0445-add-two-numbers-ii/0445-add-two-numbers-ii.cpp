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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        while(head){
            auto temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h1=reverse(l1),*h2=reverse(l2);
        ListNode* ans=new ListNode(), *res=ans;
        int carry=0;
        while(h1||h2||carry){
            int sum=carry;
            if(h1){
                sum+=h1->val;
                h1=h1->next;
            }
            if(h2){
                sum+=h2->val;
                h2=h2->next;
            }
            carry=sum/10;
            sum%=10;
            ans->next=new ListNode(sum);
            ans=ans->next;
        }
        return reverse(res->next);
    }
};