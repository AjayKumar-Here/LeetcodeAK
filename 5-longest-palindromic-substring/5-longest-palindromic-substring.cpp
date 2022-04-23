class Solution {
public:
    
    int lenexpandcheck(string s,int left,int right)
    {
        if(s.length() < 1 || left > right) return 0;
        
        while(left >=0 && right < s.length() && s[left]==s[right])
        {
            left--;
            right++;
        }
        
        
        return right-left-1;
        
    }
    string longestPalindrome(string s) 
    {
        int n=s.length();
        
        int start=0,mx=INT_MIN,len=0;
        
        for(int i=0;i<n;i++)
        {
            int len1=lenexpandcheck(s,i,i);
            int len2=lenexpandcheck(s,i,i+1);
            len=max(len1,len2);
            
            if(len > mx)
            {
                start = i-(len-1)/2;
                mx=len;
            }  
            
        }
        
        return s.substr(start,mx);
    }
};