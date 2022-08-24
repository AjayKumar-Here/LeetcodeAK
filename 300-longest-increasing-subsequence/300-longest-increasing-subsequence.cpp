class Solution {
public:
    int lengthoflis(vector<int>& nums,int n,int i,int prev, vector<vector<int>> &dp)
    {
        if(i==n)
        {
            return 0;
        }
        
         if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        
        int l2 = 0 + lengthoflis(nums,n,i+1,prev,dp);
        
        int l1=0;
        
        if( (prev==-1) || nums[prev] < nums[i])
        {
            l1 = 1 + lengthoflis(nums,n,i+1,i,dp);
        }
        
        return dp[i][prev+1]=max(l1,l2);
    }
    
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
        return lengthoflis(nums,n,0,-1,dp);
        
    }
};