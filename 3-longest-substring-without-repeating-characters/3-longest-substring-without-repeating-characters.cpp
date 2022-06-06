class Solution {
public:
	int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
		int l = 0, r = 0;
        
        unordered_set<int>st;
        int max = 0;
        
        while(r<s.length())
        {
            if(st.empty())
            {
                st.insert(s[r]);
            }
            else{
                while(!st.empty() && st.find(s[r])!=st.end())
                {
                    st.erase(s[l]);
                    l++;
                }
                st.insert(s[r]);
            }
            if(r-l+1>max)
                max = r-l+1;
            r++;
        }
        
        return max;
	}
};