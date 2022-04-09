class Solution 
{
public:
    struct Node
    {
        Node *child[2];
    };
    
    Node *main=new Node();
    
    void insert(int num) 
    {
        Node *root=main;
        for(int i=31;i>=0;i--)
        {
            int bit=(num >> i)&1;
            if(root->child[bit]==NULL)
            {
                root->child[bit]=new Node();
            }
            root=root->child[bit];
        }
    }
    
    int mx(int num)
    {
        Node *root=main;
        int maxNum=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num >> i)&1;
            if(root->child[!bit])
            {
                maxNum = maxNum | (1 << i);
                root=root->child[!bit];
            }
            else
            {
                root=root->child[bit];
            }
            
        }
        
        return maxNum;
    }
    
    int findMaximumXOR(vector<int>& nums) 
    {
        int n=nums.size();
        int res=0;
        
        for(auto x:nums)
        {
            insert(x);
        }
        for(auto x:nums)
        {
            res=max(res,mx(x));
        }
        
        return res;
    }
};