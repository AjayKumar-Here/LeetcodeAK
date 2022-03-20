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
	
	Node *curr=head;
	Node *next;
	
	while(curr!=NULL)
	{
		
		next=curr->next;
		curr->next=new Node(curr->val);
		curr->next->next=next;
		curr=next;
	
	}

	
	for(curr=head;curr!=NULL;curr=curr->next->next)
	{
		curr->next->random=(curr->random!=NULL) ? curr->random->next : NULL;
	}
	
	Node *original=head;
	Node *copy=head->next;
	
	Node *temp=copy;
	
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