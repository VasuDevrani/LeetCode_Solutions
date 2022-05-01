class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int>ngreat;
        stack<int>temp;
        ngreat.push_back(-1);
        temp.push(t.size()-1);
        vector<int>ans;
        
        
        for(int i=t.size()-2;i>=0;i--)
        {
            while(!temp.empty())
            {
                if(t[temp.top()]>t[i])
                {
                    ngreat.push_back(temp.top());
                    temp.push(i);
                    break;
                }
                else
                    temp.pop();
            }
            if(temp.empty())
            {
                temp.push(i);
                ngreat.push_back(-1);
            }
        }
            reverse(ngreat.begin(),ngreat.end());
        
        for(int i=0;i<ngreat.size();i++)
        {
            if(ngreat[i]==-1)
                ans.push_back(0);
            else
                ans.push_back(ngreat[i]-i);
        }
        return ans;
    }
};