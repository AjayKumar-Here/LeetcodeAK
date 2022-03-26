class Solution {
public:
    
    void subset(int ind,vector<int>& nums,vector <int> &res, vector<vector<int>> &ans) 
    {
        ans.push_back(res);
        
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i]==nums[i-1]) continue;
            
            res.push_back(nums[i]);
            
            subset(i+1,nums,res,ans);
            
            res.pop_back();
        }
    }
    
    
    
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector <int> res;
        
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        subset(0,nums,res,ans);
        
        return ans;
    }
};