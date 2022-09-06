class Solution {
public:
    int dp1[2000][2000];
    
    bool palindrome(string &str,int s,int e)
    {
        int i=s,j=e;
        if(dp1[s][e]!=-1) dp1[s][e];
        
        while(s<=e)
        {
            if(str[s]!=str[e])
            {
                return dp1[s][e]=false;
            }
            
            s++;
            e--;
        }
        
        return dp1[i][j]=true;
    }
    
    int minCut(string s) 
    {
        int n=s.length();
        
        vector<int> dp(n+1,0);
        
        memset(dp1, -1, sizeof(dp1));
        
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