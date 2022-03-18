/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        
        if(head==NULL)
        {
            return head;
        }
        
        Node *cur=head;
        
        Node *temp;
        
        
        while(cur!=NULL)
        {
            temp=cur->next;
            cur->next=new Node(cur->val);
            cur->next->next=temp;
            cur=temp;
        }
        
        cur=head;
        
         while(cur!=NULL)
        {
            cur->next->random=(cur->random!=NULL) ? cur->random->next : NULL;
            cur=cur->next->next; 
        }
        
    Node *original=head;
        
	Node *copy=head->next;
	
	temp=copy;
	
	while(original!=NULL && copy!=NULL)
	{
		
		original->next=original->next ? original->next->next : original->next;
		
		copy->next=copy->next ? copy->next->next : copy->next;
		
		original=original->next;
		
		copy=copy->next;
	}
	
	return temp;
    }
};