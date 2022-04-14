class Solution 
{
public:
 int largestRectangleArea(vector<int>& arr) 
 {
     int n=arr.size();
    int ps[n];
	int ns[n];
	
	stack <int> s ;
	int res=0;
	
	for(int i=0;i<n;i++)
	{
		while(s.empty()==false && arr[s.top()] >= arr[i])
		{
			s.pop();
		}
		
		int span=s.empty() ? -1 : s.top();
		
		ps[i]=span;
			
		s.push(i);
	}	
	
	 while(s.empty()==false)
	 {
        s.pop();
     }
	
	for(int i=n-1;i>=0;i--)
	{
		while(s.empty()==false && arr[s.top()] >= arr[i])
		{
			s.pop();
		}
		
		int span=s.empty() ? n : s.top() ;
		
		ns[i]=span;
		
		s.push(i);
	}
	

	for(int i=0;i<n;i++)
	{
		int curr=arr[i];
		
		curr+=(i-ps[i]-1) *arr[i];
		curr+=(ns[i]-i-1) *arr[i];
		
		res=max(res,curr);
		
	}
	
	return res;
  }
};