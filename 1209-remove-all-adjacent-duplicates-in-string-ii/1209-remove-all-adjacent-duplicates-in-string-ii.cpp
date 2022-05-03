class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>temp;
        
        for(int i=0;i<s.length();i++)
        {
            if(temp.empty() || s[i]!=temp.top().first)
            {
                temp.push({s[i],1});
            }
            else if(s[i]==temp.top().first)
            {
                temp.top().second++;
            }
            if(!temp.empty() && temp.top().second==k)
            {
                temp.pop();
            }
        }
        string ans="";
        while(!temp.empty())
        {
            while(temp.top().second--)
                ans+=temp.top().first;
            temp.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};