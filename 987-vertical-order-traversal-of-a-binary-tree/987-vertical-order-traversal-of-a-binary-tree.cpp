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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
            vector<vector<int>> ans;
        
            if(root==NULL) return ans;
        
        	map<int,map<int,multiset<int>>> mp;
	
	        queue<pair<TreeNode *,pair<int, int>>> q ;
	
	        q.push({root,{0,0}});
	
	  while(q.empty()==false)
	  {
			auto p=q.front();
			
			TreeNode *curr=p.first;
          
            int x=p.second.first;
            int y=p.second.second;
			
			
			mp[x][y].insert(curr->val);
			
			q.pop();
			
			if(curr->left!=NULL)
			{
				q.push({curr->left,{x-1,y+1}});
			}
			
			if(curr->right!=NULL)
			{
				q.push({curr->right,{x+1,y+1}});
			}
      }
        
         for (auto p: mp) 
         {
            vector < int > col;
            for (auto q: p.second) 
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
             
            ans.push_back(col);
        }
        
        return ans;
            
        }
};