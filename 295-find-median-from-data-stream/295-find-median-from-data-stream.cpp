class MedianFinder {
public:
    
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    double mid=INT_MIN;
    
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(mid==INT_MIN){
            left.push(num);
            mid=num;
            return;}
        
        if(left.size()>right.size())
        {
            if(num<=mid)
            {
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            else
            {
                right.push(num);
            }
            mid=(left.top()+right.top())/2.0;
            return;
        }
        else if(left.size()<right.size())
        {
            if(num>mid)
            {
                left.push(right.top());
                right.pop();
                right.push(num);
            }
            else
            {
                left.push(num);
            }
            mid=(left.top()+right.top())/2.0;
            return;
        }
        else
        {
            if(num<=mid){
                left.push(num);
                mid=left.top();
            }
            else{
                right.push(num);
                mid=right.top();
            }
            return;
        }
    }
    
    double findMedian() {
        return mid;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */