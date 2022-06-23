class Solution {
public:
    string mostCommonWord(string para, vector<string>& ban) {
        
        unordered_map<string, int>m;
        
        string temp = "";
        for(int i=0;i<para.length();i++)
        {
            if(para[i] != ' ' && ((para[i] >= 97 && para[i] <=122) || (para[i] >= 65 && para[i] <= 90)))
                temp += tolower(para[i]);
            else
            {
                if(temp != "")
                m[temp]++;
                temp = "";
            }
        }
        if(temp != "")
            m[temp]++;
        
        for(auto x:m)
            cout<<x.first<<" "<<x.second<<" ";
        
        for(int i=0;i<ban.size();i++){
            m.erase(ban[i]);
        }
        
        string ans;
        int mx = 0;
        for(auto x:m)
        {
            // cout<<x.first<<" ";
            if(x.second > mx)
            {
                mx = x.second;
                ans = x.first;
            }
        }
        
        return ans;
    }
};