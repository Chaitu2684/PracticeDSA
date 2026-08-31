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
        if(!head || !head->next || !head->next->next){
            return {-1,-1};
        }
        int fc=-1;
        int pc=-1;
        int mini=INT_MAX;
        ListNode* prev=head;
        ListNode* curr=head->next;
        int index=1;
        while(curr->next){
            bool is_max=(curr->val>prev->val && curr->val>curr->next->val);
            bool is_min=(curr->val<prev->val && curr->val<curr->next->val);
            if(is_max || is_min){
                if(fc==-1) fc=index;
                else mini=min(mini,index-pc);
                pc=index;
            }
            prev=curr;
            curr=curr->next;
            index++;
        }
        if(fc==-1 || pc==fc) return {-1,-1};
        return {mini,pc-fc};
        
    }
};