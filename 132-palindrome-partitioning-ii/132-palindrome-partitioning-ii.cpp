class Solution {
public:
    int dp1[2000][2000];
    bool palindrome(string &s,int i,int j)
    {
        if(i >= j) return dp1[i][j] = true;
        if(dp1[i][j] != -1) return dp1[i][j];
        if(s[i] == s[j]) return dp1[i][j] = palindrome(s, i + 1, j - 1);
        return dp1[i][j] = false;
    }
    
    int minCut(string s) 
    {
        int n=s.size();
        
        vector<int> dp(n+1,0);
        
        memset(dp1, -1, sizeof(dp1));
        
        dp[n]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            int ans=INT_MAX;
            for(int j=i;j<n;j++)
            {
               if(palindrome(s,i,j))
                {
                    int cost=1+dp[j+1];
                    ans=min(ans,cost);
                }
            }
            dp[i]=ans;
        }
        
        return dp[0]-1;
    }
};