class Solution {
public:
    
    static bool mycmp(vector<int>& a, vector<int>& b)
    {
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        int maxi=0;
        
        sort(boxTypes.begin(),boxTypes.end(),mycmp);
        
        for(int i=0;i<boxTypes.size();i++)
        {
            
            if(boxTypes[i][0] < truckSize)
            {
                truckSize-=boxTypes[i][0];
                maxi+=boxTypes[i][0] * boxTypes[i][1];
            }
            else
            {
                maxi+= truckSize * boxTypes[i][1];
                break;
            }
        }
        return maxi;
    }
};