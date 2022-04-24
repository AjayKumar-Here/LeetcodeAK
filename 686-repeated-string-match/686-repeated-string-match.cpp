#define d 256
const int q=101;

class Solution 
{
public:
    
    bool check(string txt,string pat)
    {
        int n=txt.length();
	    int m=pat.length();
	
	
	//compute (d ^m-1)%q
	int h=1;
	
	for(int i=1;i<=m-1;i++)
	{
		
		h=(h*d)%q;					//h=88
		
	}
	
	//Compute P and Q
	int p=0,t=0;
	
	for(int i=0;i<m;i++)
	{
		p=(p*d + pat[i])%q;			//p=34
		t=(t*d + txt[i])%q;			//t=34
	}
	
	for(int i=0;i<=n-m;i++)
	{
		//Check For spurious hit
		if(p==t)
		{
			bool flag=true;
			for(int j=0;j<m;j++)
			{
				if(txt[i+j]!=pat[j])
				{
					flag=false;
					break;
				}
				
			}
			
			if(flag==true)
			{
				return true;
			}
			
			
		}
		//Compute t i+1
		if(i <n-m)
		{
			// value of a ascii value is =97 
			
			t=( d*(t-txt[i]*h) + txt[i+m])%q;				//t=-67
			
			if(t<0)
			{
				t=t+q;										//t=-67+101=34
			}
			
		}
	}
        
        return false;
    }
    
    int repeatedStringMatch(string a, string b) 
    {
        int count=1;
        
        int m=a.size();
        int n=b.size();
        
        string s=a;
    
        
        while(a.size() < b.size())
        {
            a+=s;
            count++;
        }
        
        if(check(a,b)) return count;
        
        a+=s;
        
        if(check(a,b)) return count+1;
   
        
        return -1;
    }
};