/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec 
{
public:
    
    // Encodes a tree to a single string.
    void Buildserialize(TreeNode* root,string &s) 
    {
        if(root==NULL)
        {
            s+=" null";
            return;
        }
        
        s+=" "+to_string(root->val);
        
        Buildserialize(root->left,s);
        Buildserialize(root->right,s);
    }
    
    string serialize(TreeNode* root) 
    {
        string s="";
        Buildserialize(root,s);
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream ss(data);
        return buildTree(ss);
    }
    
    private:
    
    TreeNode* buildTree(istringstream& ss)
    {
        string s;
        ss >> s;
        
        if (s == "null")
			return NULL;
        
        TreeNode* node = new TreeNode(stoi(s));
        node->left = buildTree(ss);
        node->right = buildTree(ss);
            
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));