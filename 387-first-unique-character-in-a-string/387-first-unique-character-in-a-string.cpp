class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]={0};
        queue<int>q;
        
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
            if(q.empty())
            {
                q.push(i);
                continue;
            }
            
            while(!q.empty() && (s[i]==s[q.front()] || freq[s[q.front()]-'a']>1) )
            {
                q.pop();
            }
                q.push(i);
            
        }
        // queue<int>q1=q;
        // while(!q1.empty())
        // {
        //     cout<<q1.front()<<" ";
        //     q1.pop();
        // }
        if(q.empty())
        {
            return -1;
        }
        if(freq[s[q.front()]-'a']>1)
            return -1;
        return q.front();
    }
};