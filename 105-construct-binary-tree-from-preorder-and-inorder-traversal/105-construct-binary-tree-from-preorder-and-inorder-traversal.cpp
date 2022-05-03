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
    int preindex=0;
    TreeNode* ctree(vector<int>& preorder, vector<int>& inorder,int s,int e)
    {
        if(s > e) return NULL;
        
        TreeNode* root=new TreeNode(preorder[preindex++]);
        
        int index;
        for(int i=s;i<=e;i++)
        {
            if(inorder[i]==root->val)
            {
                index=i;
                break;
            }
        }
        
        root->left=ctree(preorder,inorder,s,index-1);
                         
        root->right=ctree(preorder,inorder,index+1,e);
                         
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return ctree(preorder,inorder,0,inorder.size()-1);
    }
};