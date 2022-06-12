class Solution {
public:
    string customSortString(string order, string s) {
        string s1 = "";
        map<char,int>p;
        for(auto i : s)
        {
            if(order.find(i)!=-1)
                p[i]++;
            else
                s1 += i;
        }
        string ans = "";
        for(auto i : order)
        {
            if(p.find(i)!=p.end())
            {
                int k=p[i];
                while(k--)
                {
                    ans += i;
                }
            }
        }
        return ans += s1;
    }
};