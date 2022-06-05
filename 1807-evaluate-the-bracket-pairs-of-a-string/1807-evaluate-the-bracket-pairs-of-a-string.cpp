class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>m;
        
        for(int i=0;i<knowledge.size();i++)
        {
            m[knowledge[i][0]] = knowledge[i][1];
        }
        
        int check = -1;
        string ans = "";
        string temp = "";
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '('){
                check = 0;
                continue;
            }
            if(check == -1)
                ans+=s[i];
            else
            {
                if(s[i] == ')')
                {
                    check = -1;
                    if(!m.empty() && m.find(temp)!=m.end())
                    ans+=m[temp];
                    else
                        ans+='?';
                    temp = "";
                    continue;
                }
                temp+=s[i];
            }   
        }
        
        return ans;
    }
};