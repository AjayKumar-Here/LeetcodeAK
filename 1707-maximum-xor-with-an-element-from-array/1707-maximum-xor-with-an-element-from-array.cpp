class Solution {
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
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) 
    {
         vector<int> ans(queries.size(), 0); 
         vector<pair<int, pair<int,int>>> offlineQueries; 
         sort(arr.begin(), arr.end()); 
        
        int index = 0;
        for(auto &it: queries) 
        {
            offlineQueries.push_back({it[1],{it[0], index++}}); 
        }
    
        sort(offlineQueries.begin(), offlineQueries.end()); 
    
        int i = 0; 
        int n = arr.size(); 
    
        for(auto &it : offlineQueries) 
        {
        
            while(i < n && arr[i] <= it.first) 
            {
                insert(arr[i]); 
                i++; 
            }
        
            if(i!=0) ans[it.second.second] = mx(it.second.first); 
        
            else ans[it.second.second] = -1; 
    
        }
    
        return ans; 
    }
};