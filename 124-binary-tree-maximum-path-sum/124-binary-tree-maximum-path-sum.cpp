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
    int res=INT_MIN;
    
    int maxPathSum1(TreeNode* root) 
    {
        if(root==NULL) return 0;
        
            int sum1=max(0,maxPathSum1(root->left));
            int sum2=max(0,maxPathSum1(root->right));
        
        int s=sum1+sum2+root->val;
        
        res=max(res,s);
        
        return root->val+max(sum1,sum2);
            
        
    }
    
    int maxPathSum(TreeNode* root) 
    {
        maxPathSum1(root);
        return res;
    }
    
};