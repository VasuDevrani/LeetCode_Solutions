class Solution {
public:
    int largestInteger(int num) {
       stack<int>s;
        
        priority_queue<int>odd;
        priority_queue<int>even;
        
        while(num>0)
        {
            int a=num%10;
            if(a&1)
            {
                odd.push(a);
            }
            else
                even.push(a);
            s.push(a);
            num/=10;
        }
        
        int ans=0;
        while(!s.empty())
        {
            if(s.top()&1)
            {
                ans=ans*10+odd.top();
                odd.pop();
            }
            else
            {
                ans=ans*10+even.top();
                even.pop();
            }
            s.pop();
        }
        
        return ans;
    }
};