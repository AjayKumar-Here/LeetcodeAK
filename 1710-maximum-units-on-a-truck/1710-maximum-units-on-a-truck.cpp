class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        int maxi=0;
        
        priority_queue<pair<int,int>> pq;
    
        for(int i=0;i<boxTypes.size();i++)
        {
            pq.push({boxTypes[i][1],boxTypes[i][0]});
        }
        
        while(!pq.empty())
        {
            int unit=pq.top().first;
            int box=pq.top().second;
            pq.pop();
            
            if(box < truckSize)
            {
                truckSize-=box;
                maxi+=box * unit;
            }
            else
            {
                maxi+= truckSize * unit;
                break;
            }
        }
        
        
        return maxi;
    }
};