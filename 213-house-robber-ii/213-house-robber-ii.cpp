class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size()==1) return nums[0];
        int p1=nums[0];
	    int p2=0;
	   
	   for(int i=1;i<nums.size()-1;i++)
	   {
	       int take=nums[i];
           
	       if(i > 1)
           {
               take+=p2;
               
           }
           
	       int pick=0+p1;
	       
	       int curr=max(take,pick);
	       
	       p2=p1;
	       p1=curr;
        }
        
        int ans1=p1;
        
        p1=nums[1];
        p2=0;
        
       for(int i=2;i<nums.size();i++)
	   {
	       int take=nums[i];
           
	       if(i > 1)
           {
               take+=p2;
               
           }
           
	       int pick=0+p1;
	       
	       int curr=max(take,pick);
	       
	       p2=p1;
	       p1=curr;
        }
        
        
        int ans2=p1;
        
        
        return max(ans1,ans2);
        
    }
};