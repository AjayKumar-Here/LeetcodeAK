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
    TreeNode* ctree(vector<int>& postorder, vector<int>& inorder,int s,int e,int &postindex)
    {
        if(s > e) return NULL;
        
        TreeNode* root=new TreeNode(postorder[postindex--]);
        
        int index;
        for(int i=s;i<=e;i++)
        {
            if(inorder[i]==root->val)
            {
                index=i;
                break;
            }
        }
        
        root->right=ctree(postorder,inorder,index+1,e,postindex);
        root->left=ctree(postorder,inorder,s,index-1,postindex);
                                       
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int postindex=postorder.size()-1;
        
        return ctree(postorder,inorder,0,inorder.size()-1,postindex);
    }
};