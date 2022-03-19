class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++)
        {
            
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) 
            {
                int low=i+1;
                int end=n-1;
                int sum=0;
            
            while(low < end)
            {
                 sum=nums[i]+nums[low]+nums[end];
                
                if(sum > 0)
                {
                    end--;
                }
                else if(sum < 0)
                {
                    low++;
                }
                else
                {
                    
                    res.push_back( vector<int> {nums[i],nums[low],nums[end]});
                    
                    while(low < end && nums[low]==nums[low+1])
                    {
                          low++;
                    }
                    
                    while(low < end && nums[end]==nums[end-1])
                    {
                            end--;
                    }
                        low++; end--;
                }
            }
        }
      }
        
        return res;
    }
};