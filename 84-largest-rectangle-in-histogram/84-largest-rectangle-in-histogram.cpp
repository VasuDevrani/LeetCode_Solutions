class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        int left[n], right[n];
        
        stack<int>s;
        s.push(n-1);
        int k=n-1;
        right[k]=-1;
        
        for(k=n-2;k>=0;k--)
        {
            while(!s.empty() && h[k]<=h[s.top()])
                s.pop();
            
            if(s.empty())
                right[k]=-1;
            else
                right[k]=s.top();
            s.push(k);
        }
        
        while(!s.empty())
            s.pop();
        
        k=0;
        s.push(0);
        left[k]=-1;
        
        for(k=1;k<n;k++)
        {
            while(!s.empty() && h[k]<=h[s.top()])
                s.pop();
            if(s.empty())
                left[k]=-1;
            else
                left[k]=s.top();
            
            s.push(k);
        }
        
        int max_area=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int area;
            
            if(left[i]!=-1 && right[i]!=-1)
                area=h[i]*(right[i]-left[i]-1);
            else if(right[i]==-1 && left[i]==-1)
                area=h[i]*n;
            else if(right[i]==-1)
                area=h[i]*(n-left[i]-1);
            else if(left[i]==-1)
                area=h[i]*(right[i]);
            
            if(area>max_area)
                max_area=area;
        }
        
        return max_area;
    }
};