/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        
        if(root==NULL) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        
        bool flag=true;
        
        
            
        while(!q.empty())
        {
            
            int n=q.size();
            int sz=n;
            
            vector<int> v(n);
            
            for(int i=0;i<n;i++)
            {
              TreeNode *cur=q.front();
              q.pop();
                
              if(flag)
              {
                  v[i]=cur->val;
              }
              else
              {
                  v[sz-1-i]=cur->val;
              }
            
              if(cur->left!=NULL) q.push(cur->left);
            
              if(cur->right!=NULL) q.push(cur->right);
           }
            ans.push_back(v);
            flag=!flag;
        }
        
        return ans;
    }
};