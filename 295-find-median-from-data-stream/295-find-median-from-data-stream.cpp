class MedianFinder 
{
public:
    priority_queue <int> mx; //greater half...max heap
	priority_queue <int ,vector<int>,greater<int>> mi; //smaller half...min heap
    
    MedianFinder() {}
    
    void addNum(int num) 
    {
        if(mx.empty())
        {
            mx.push(num);
            return;
        }
        else if(mx.size() > mi.size())
        {
            if(mx.top() > num)
            {
                mi.push(mx.top());
                mx.pop();
                mx.push(num);
            }
            else
            {
                mi.push(num);
            }
        }
        else
        {
            if(mi.top() > num)
            {
                mx.push(num);
            }
            else
            {
                mi.push(num);
                mx.push(mi.top());
                mi.pop();
            }
        }
        
    }
    
    double findMedian() 
    {
        if( (mx.size() + mi.size()) %2==0)
        {
            return (mx.top()+mi.top())/2.0;
        }
        else
        {
            return mx.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */