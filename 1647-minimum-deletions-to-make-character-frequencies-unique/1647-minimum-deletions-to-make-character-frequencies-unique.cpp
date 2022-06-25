class Solution {
public:
    int minDeletions(string s) {
        if(s.length() == 1)
            return 0;
       unordered_map<char,int>m;
        
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        
        vector<int>v;
        for(auto x:m)
            v.push_back(x.second);
        
        sort(v.begin(), v.end(), greater<int>());
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
        
        int prev = v[0], ans = 0;
        for(int i=1;i<v.size();i++)
        {
            if(v[i] >= prev)
            {
                if(prev - 1 <= 0){
                    ans = ans + v[i];
                    v[i] = 0;
                }
                else{
                    ans = ans + v[i] - prev + 1;
                    v[i] = prev - 1;
                }
            }
            prev = v[i];
            cout<<prev<<" ";
        }
        
        return ans;
    }
};