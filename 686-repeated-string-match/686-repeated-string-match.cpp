#define d 256
const int q=101;

class Solution 
{
public:
    
    bool check(string a,string b)
    {
        int m=a.size();
        int n=b.size();
        
        for(int i=0;i<=m-n;i++)
        {
            int j;
            for(j=0;j<n;j++)
            {
                if(a[i+j]!=b[j])
                {
                    break;
                }
            }
            
            if(j==n) return true;
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