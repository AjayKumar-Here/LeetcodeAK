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
    
    ListNode* rotate(ListNode* head)
    {
        
       ListNode* curr=head;
       ListNode* prev;
        
        while(curr->next!=NULL)
        {
            prev=curr;
            curr=curr->next;
        }
        
        curr->next=head;
        prev->next=NULL;
        
        head=curr;
        
        return head;
        
    }
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* curr=head;
        int length=0;
        
        while(curr!=NULL)
        {
            length++;
            curr=curr->next;
        }
        
        k=k%length;
        
        for(int i=0;i<k;i++)
        {
            head=rotate(head);
        }
        
        return head;
    }
};