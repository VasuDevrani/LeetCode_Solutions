class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        
        if(s.size()==1)
            return s[0];
        
        while(s.size()>1)
        {
            sort(s.begin(),s.end());
            int n=s.size()-1;
            
            if(s[n]>s[n-1])
            {
                int temp=s[n]-s[n-1];
                s.pop_back();
                s.pop_back();
                s.push_back(temp);
            }
            else
            {
                s.pop_back();
                s.pop_back();
            }
        }
        if(s.empty())
            return 0;
        else
            return s[0];
    }
};