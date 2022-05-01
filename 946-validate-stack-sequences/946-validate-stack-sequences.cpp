class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>ans;
        
        stack<int>pus;
        stack<int>popp;
        
        if(pushed.size()!=popped.size())
            return false;
        
        for(int i=pushed.size()-1;i>=0;i--)
            pus.push(pushed[i]);
        for(int i=popped.size()-1;i>=0;i--)
            popp.push(popped[i]);
    
        while(!pus.empty() && !popp.empty())
        {
            ans.push(pus.top());
            pus.pop();
            while(!ans.empty() && ans.top()==popp.top())
            {
                ans.pop();
                popp.pop(); 
            }
        }
        if(ans.empty())
            return true;
        else 
            return false;
        
        
        
    }
};