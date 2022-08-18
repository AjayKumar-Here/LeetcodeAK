class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit=prices[0],mx=0;
        
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i] > profit)
            {
                mx+=prices[i]-profit;
            }
            
            profit=prices[i];
        }
        
        return mx;
        
    }
};