struct Node
{
    Node *prev;
    Node *next;
    
    int key,value;
    
    Node(int x,int y)
    {
        key=x;
        value=y;
        prev=NULL;
        next=NULL;
    }
   
};

class LRUCache 
{
public:
    
    unordered_map<int,Node*> mp;
    Node *head,*tail;
    
    int cap,count;
    
    LRUCache(int capacity) 
    {
        cap=capacity;
        count=0;
        
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        
        head->next=tail;
        tail->prev=head;
        head->prev=NULL;
		tail->next=NULL;
        
    }
    
    void DeleteNode(Node *curr)
   {
  	
  	    curr->prev->next=curr->next;
  	    curr->next->prev=curr->prev;
    }
  
   void AddNode(Node *temp)
   {
  	
  	    temp->next=head->next;
  	    temp->next->prev=temp;
  	
  	    temp->prev=head;
  	    head->next=temp;
   }
    
    int get(int key) 
    {
        int t=-1;
        
        //If found key,find the reference of the node in DLL
        //Move the node front of the DLL
        if(mp.find(key)!=mp.end())
        {
            Node *node=mp[key];
            
            t=node->value;
            
            mp.erase(key);
            DeleteNode(node);
            AddNode(node);
            
            mp[key]=head->next;
        }
        
        return t;
    }
    
    void put(int key, int value) 
    {
        //If found key,find the reference of the node in DLL
        //Move the node front of the DLL
        if(mp.find(key)!=mp.end())
  	    {
  		  Node *node=mp[key];
  		  mp.erase(key);
  		  DeleteNode(node);
            
          node=new Node(key,value);
          mp[key]=node;
            
  		  AddNode(node);
	    }
        //If Not found the key
        else
        { 
            //insert the node front of the DLL
            //insert an entry in map
            Node *temp=new Node(key,value);
            mp[key]=temp;
        
            if(count < cap)
            {
                AddNode(temp);
                count++;
            }
            else
            {
                mp.erase(tail->prev->key);
                DeleteNode(tail->prev);
            
                AddNode(temp);
            
            }
        
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */