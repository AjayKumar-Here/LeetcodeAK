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

struct Node
{
    int maximum;
    int minimum;
    int sum;
    bool isbst;
    Node()
    {
        maximum = INT_MIN;
        minimum = INT_MAX;
        sum = 0;
        isbst = true;
    }
};


class Solution 

{
public:
    
    int res=INT_MIN;
    
    Node Sum(TreeNode *root)
    {
        if(root==NULL) return Node();
        
        Node ans;
        
        Node l=Sum(root->left);
        Node r=Sum(root->right);
        
        if(l.isbst && r.isbst && l.maximum < root->val && root->val < r.minimum)
        {
            ans.sum=l.sum+r.sum+root->val;
            
            ans.isbst=true;
            
            ans.maximum=max(root->val,max(l.maximum,r.maximum));
            ans.minimum=min(root->val,min(l.minimum,r.minimum));
        }
        else
        {
            ans.sum=0;
            ans.isbst=false;
        }
        
        res=max(res,ans.sum);
            
        return ans;
    }
   
    int maxSumBST(TreeNode* root)
    {
        Sum(root);
        return res > 0 ? res : 0;
    }
};