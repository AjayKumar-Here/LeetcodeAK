bool palindrome(string &s,int i,int j)
{
while(i <= j)
{
if(s[i]!=s[j])
{
return false;
}
i++;
j--;
}
return true;
}
string longestPalindrome(string s)
{
if(s.length()==0) return "";
if(s.length()==1) return s;
if(s.length()==2)
{
if(s[0]==s[1]) return s;
string t=s.substr(0,1);
return t;
}
string temp;
int start=0,end=s.length()-1;
while(start < end)
{
if(palindrome(s,start,end))
{
temp=s.substr(start,end);
return temp;
}
start++;
end--;
}
return temp;
}