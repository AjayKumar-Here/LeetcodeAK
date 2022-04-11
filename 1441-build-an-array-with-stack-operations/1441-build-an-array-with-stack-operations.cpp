class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
       vector<string> ans;
        
       //Current Element tells the element to be added in the stack, first element added will be 1
       int currElem=1; 
        for(int i=0;i<target.size();i++)
        {
            //While we do not make current element equal to corresponding element in target array 
            while(currElem!=target[i])
            { 
                 //We will simply push and pop those elements which are not in final target array
                ans.push_back("Push"); 
                ans.push_back("Pop");
                currElem++;
            }
             //Pushing the target element in stack 
            ans.push_back("Push");
            currElem++;
        }
        return ans;
    }
};