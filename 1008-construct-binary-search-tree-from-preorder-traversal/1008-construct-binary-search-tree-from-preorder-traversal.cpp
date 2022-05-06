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
    TreeNode* ConstructTree(int x,TreeNode* root) 
    {
        TreeNode* cur=root,*prev;
        
        while(cur!=NULL)
        {
            prev=cur;
            if(cur->val > x)
            {
                cur=cur->left;
            }
            else if(cur->val < x)
            {
                cur=cur->right;
            } 
        }
        
        if(prev->val > x)
        {
            prev->left = new TreeNode(x);
            
        }
        else
        {
            prev->right = new TreeNode(x);
        }
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        if(preorder.size()==0) return NULL;
        
        TreeNode *root= new TreeNode(preorder[0]);
        
        if(preorder.size()==1) return root;
        
        for(int i=1;i < preorder.size();i++)
        {
            root=ConstructTree(preorder[i],root);
        }
    
        return root;
    }
};