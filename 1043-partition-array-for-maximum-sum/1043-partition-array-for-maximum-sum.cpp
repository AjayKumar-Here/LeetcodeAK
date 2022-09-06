class Solution {
public:    
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n=arr.size();
        
        vector<int> dp(n+1,0);
        
        for(int ind=n-1;ind>=0;ind--)
        {
            int maxi=INT_MIN;
            int mxsum=INT_MIN;
            int len=0;

            for(int i=ind;i<min(ind+k,n);i++)
            {
                len++;
                maxi=max(maxi,arr[i]);

                int sum=len*maxi + dp[i+1];

                mxsum=max(mxsum,sum);
            }
            dp[ind]=mxsum;
        }
      
        return dp[0];
    }
};