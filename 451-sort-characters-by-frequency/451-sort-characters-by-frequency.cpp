class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(),s.end());
        
        priority_queue<pair<int,char>>q;
        
        int ct=1;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
                ct++;
            else{
                cout<<s[i]<<" ";
                q.push(make_pair(ct,s[i]));
                ct=1;
            }
        }
        if(ct!=1)
        {
            q.push(make_pair(ct,s[s.length()-1]));
        }
        if(s[s.length()-1]!=s[s.length()-2])
            q.push(make_pair(1,s[s.length()-1]));
            
        string ans="";
        while(!q.empty())
        {
            // cout<<q.top().second<<" ";
            
            int t=q.top().first;
            while(t--)
            {
                ans+=q.top().second;
            }
            q.pop();
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};