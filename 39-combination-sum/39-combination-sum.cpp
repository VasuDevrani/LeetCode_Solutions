class Solution {
public:
    
    vector<vector<int>>ans;
    
    void combin_sum(vector<int>v,int t,int j,int sum,string s)
    {
//         base case
        if(sum>t)
            return;
        else if(sum==t)
        {
            vector<int>a;
            for(int i=0;i<s.size();i++)
            {
                a.push_back(v[(int)(s[i]-'0')]);
            }
            ans.push_back(a);
            return;
        }
        
        
        
//         recursive case
        for(int i=j;i<v.size();i++){
            char c=i+48;
          combin_sum(v,t,i,sum+v[i],s+c);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& cand, int t) {
         combin_sum(cand,t,0,0,"");
        return ans;
    }
};