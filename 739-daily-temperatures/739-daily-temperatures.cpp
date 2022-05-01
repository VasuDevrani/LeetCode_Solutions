class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        
        vector<int>ans(n,0);
        stack<int>temp;
        
        for(int i=n-1;i>=0;i--)
        {
        while(!temp.empty() && t[i] >= t[temp.top()])
            temp.pop();
        if(temp.empty())
            ans[i] = 0;
        else
            ans[i] = temp.top() - i;
        
        temp.push(i);
        }
        return ans;
      
    }
};