class Solution {
public:
    int FindMinDist(string s1,string s2,int n,int m,vector<vector<int>> &dp)
    {
        if(n < 0) return m+1;
        if(m < 0) return n+1;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(s1[n]==s2[m])
        {
            return dp[n][m] = 0 + FindMinDist(s1,s2,n-1,m-1,dp);
        }
        
        
        return dp[n][m] = 1 + min(FindMinDist(s1,s2,n,m-1,dp),min(FindMinDist(s1,s2,n-1,m,dp),FindMinDist(s1,s2,n-1,m-1,dp)));
    }
    
    int minDistance(string word1, string word2) 
    {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        return FindMinDist(word1,word2,n-1,m-1,dp);
    }
};