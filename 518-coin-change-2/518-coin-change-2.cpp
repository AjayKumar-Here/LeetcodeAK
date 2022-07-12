class Solution 
{
public:
    int combi(int n,vector<int>& coins, int amount, vector<vector<int>> &dp)
    {
       
        if(n == 0)
        {
            return (amount%coins[0]==0);
            return 0;
         }
        
        if(dp[n][amount]!=-1) return dp[n][amount];
        
        int notpick=combi(n-1,coins,amount,dp);
        
        int pick=0;
        
        if(coins[n] <= amount)
        {
            pick =combi(n,coins,amount-coins[n],dp);
        }
        
        
        
        return dp[n][amount]=notpick + pick;
    }
    
    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();
        
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        
        int ans= combi(n-1,coins,amount,dp);
        
        
        return ans;
    }
};