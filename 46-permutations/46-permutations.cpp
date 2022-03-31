class Solution {
public:
    
    void permutation(int ind,vector<int> &nums,vector<vector<int>> &res)
    {
        if(ind==nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[ind],nums[i]);
            permutation(ind+1,nums,res);
            swap(nums[ind],nums[i]);
            
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        
        permutation(0,nums,res);
        
        
        return res;
    }
};