class Solution {
public:

    bool isMatch(string s, string p) 
    {
          int pi = 0, si = 0, star = -1, count = 0;
        
            while (si < s.size()) 
            {

                if (p[pi] == '*') 
                {
                    count = si;
                    star = pi++;
                }

                else if (p[pi] == s[si] || p[pi] == '?') 
                {
                    pi++, si++;
                }

                else if (star >= 0)
                {
                    pi = star+1;
                    si = ++count;

                }
                else return false;
            }

            while (pi < p.size() && p[pi] == '*') pi++;
            return pi == p.size();
    }
};