class Solution {
public:
    int findcom(int n,vector<int> nums,int target, vector<vector<int>> &dp)
    {
       
        if(n==0)
        {
             if(target==0 && nums[0] == 0) return 2;
            
             if(target==0 ||  nums[0] == target) return 1;
            
             return 0; 
        }
        
        if(dp[n][target]!=-1) return dp[n][target];
        
        int minus = findcom(n-1,nums,target,dp );
        
        int plus  = 0;
            
        if(nums[n]<=target) plus=findcom (n-1,nums,target - nums[n],dp);
        
        return  dp[n][target]=minus+plus;
    
    }
    
    int findTargetSumWays(vector<int>& nums, int target)
    {
            int totSum = 0;
        
            for(int i=0; i<nums.size();i++)
            {
                totSum += nums[i];
            }

            
            if(totSum-target<0) return 0;
        
            if((totSum-target)%2==1) return 0;

            int s2 = (totSum-target)/2;

            vector<vector<int>> dp(nums.size(),vector<int>(s2+1,-1));
        
            return findcom(nums.size()-1,nums,s2,dp);
    }
};