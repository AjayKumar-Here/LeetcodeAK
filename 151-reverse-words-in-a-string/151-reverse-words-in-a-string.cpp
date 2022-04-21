//Idea
//         stringstream str(s);
//         string word;
//         while (str >> word) // store separated words in vector
//             vec.push_back(word);
        
//         reverse(vec.begin(), vec.end()); // reverse vector
        
//         string res;
//         for (const auto &it : vec) // concatenate strings
//             res+=" "+it;
//         res.erase(0,1); // first place is always a space - extra
        
//         return res;

class Solution 
{
public:
    void reverse(string &s,int i,int j)
    {
        while(i < j)
        {
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            
            i++;
            j--;
        }
    }
    string reverseWords(string s) 
    {
        stringstream str(s);
        string word;
        string ss;
        
        while (str >> word)
        {
            ss+=word;
            ss+=" ";
        }
        
        int m=ss.length();
        
        ss.erase(m-1,m);
            
        
        int n=ss.length();
        
        int start=0;
        int end;
        
        for(int i=0;i<n;i++)
        {
            if(ss[i]==' ')
            {
                reverse(ss,start,i-1);
                start=i+1;
            }
        }
        
        reverse(ss,start,n-1);
        
        reverse(ss,0,n-1);
        
        return ss;
        
        
    }
};