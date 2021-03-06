/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution 
{
public:
    
    unordered_map<Node*,Node*> mp;
    
    void dfs(Node* node)
    {
        Node *clone=new Node(node->val);
        
        mp[node]=clone;
        
        for(auto x:node->neighbors)
        {
            if(mp.find(x)==mp.end())
            {
                dfs(x);
            }
            
           clone->neighbors.push_back(mp[x]);
        }
    }
    
    Node* cloneGraph(Node* node) 
    {
        if(node==NULL) return NULL;
        
        dfs(node);
        
        return mp[node];
    }
};