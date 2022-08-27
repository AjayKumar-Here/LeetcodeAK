class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        
        vector<int> dp(n,1);
        vector<int> count(n,1);
        
        
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev < i;prev++)
            {
                if(nums[prev] < nums[i] && dp[prev] + 1 > dp[i])
                {
                    dp[i]=dp[prev] + 1;
                    count[i]=count[prev];
                }
                else if( dp[prev] + 1==dp[i])
                {
                     count[i]+=count[prev];
                }
            }
        }
        
        int mx=0,cnt=0;
        
        for(int x:dp)
        {
            mx=max(mx,x);
        }
        
        for(int i=0;i<n;i++)
        {
            if(mx==dp[i])
            {
                cnt+=count[i];
            }
        }
        
        return cnt;
    }
};