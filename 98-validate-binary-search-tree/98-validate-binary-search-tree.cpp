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
class Solution 
{
public:
    
    TreeNode* x=NULL;
 
    bool isValidBST(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        
        if(isValidBST(root->left)==false)
        {
            return false;
        }
        
        if(x && x->val >= root->val)
        {
            return false;
        }
        
        x=root;
        
        if(isValidBST(root->right)==false) return false;
        
        return true;
    }
};