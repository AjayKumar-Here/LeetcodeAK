class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        int n=nums.size();
        
        vector<int> dp(n,1);
        
        vector<int> hash(n,1);
        
        sort(nums.begin(), nums.end());
        
        
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<=i-1;prev++)
            {
                if(nums[i]%nums[prev]==0 && 1+dp[prev] > dp[i])
                {
                    dp[i]=max(dp[i],1+dp[prev]);
                    hash[i]=prev;
                }
            }
        }
        
        int ans=-1,lastind;
        
        for(int i=0;i<n;i++)
        {
            if(dp[i] > ans)
            {
                ans=dp[i];
                lastind=i;
            }
        }
        
        vector<int> temp;
        
        temp.push_back(nums[lastind]);
        
        while(hash[lastind]!=lastind)
        {
            lastind=hash[lastind];
            temp.push_back(nums[lastind]);
            
        }
      
        reverse(temp.begin(),temp.end());

    
        return temp;
        
        
    }
};