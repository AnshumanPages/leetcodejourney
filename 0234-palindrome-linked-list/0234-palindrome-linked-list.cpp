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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr|| head->next==nullptr) return true;
         ListNode*fast=head;
         ListNode*slow=head;;
         while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
         }
        
         
        ListNode*temp=slow;
         ListNode*prev=nullptr;
         while(temp){
             ListNode*front=temp->next;
             temp->next=prev;
             prev=temp;
             temp=front;

         }
        ListNode*first=head;
        ListNode*second=prev;
        while(second!=nullptr){
            if(first->val!=second->val){
                 return false;

            }
           
            first=first->next;
            second=second->next;
        }
        return true;
    }
};