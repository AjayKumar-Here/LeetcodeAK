class Solution {
public:
    int findmin(int n,vector<int>& coins, int amount, vector<vector<int>> &dp)
    {
        if(n == 0)
        {
            if(amount % coins[0] == 0) return amount/coins[0];
            else return 1e9;
         }
        
        if(dp[n][amount]!=-1) return dp[n][amount];
        
        int notpick=0 + findmin(n-1,coins,amount,dp);
        
        int pick=1e9;
        
        if(coins[n] <= amount)
        {
            pick = 1 + findmin(n,coins,amount-coins[n],dp);
        }
        
        
        
        return dp[n][amount]=min(notpick,pick);
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        
        
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        
        int ans= findmin(n-1,coins,amount,dp);
        
        if(ans >= 1e9) return -1;
        
        return ans;
    }
};