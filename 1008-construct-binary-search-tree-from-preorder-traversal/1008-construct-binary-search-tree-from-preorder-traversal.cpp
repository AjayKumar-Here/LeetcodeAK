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
        if(root==NULL)
        {
            return new TreeNode(x);
            
        }
        
        else if(root->val > x)
        {
            root->left=ConstructTree(x,root->left);
        }
        else if(root->val < x)
        {
            root->right=ConstructTree(x,root->right);
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