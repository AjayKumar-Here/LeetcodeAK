class Solution {
public:
    
    int largestrect(vector<int> &arr)
    {
        stack <int> s ;
	    int res=0;
	    int tp;
	    int curr;
	    int i;
        int n=arr.size();
	
	for(i=0;i<n;i++)
	{
		while(s.empty()==false && arr[s.top()] >= arr[i])
		{
			tp = s.top();
			s.pop();
		
			curr= arr[tp] * (s.empty() ? i : (i-s.top()-1));
		
			res=max(res,curr);
		}
			
			s.push(i);
	}	
	
		while(s.empty()==false )
		{
			tp = s.top();
			s.pop();
		
			curr=arr[tp] * (s.empty() ? i : (i-s.top()-1) ) ;
		
			res=max(res,curr);
		}

	
	return res;
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
         if(matrix.empty())
            return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        
        vector<int> height(n, 0);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            
            res = max(res, largestrect(height));
            
        }
        
        return res;
    }
};