class Solution {
public:
    int minCost(string s, vector<int>& time) {
        int tot = time[time.size()-1], sum = 0, mx = INT_MIN, i;
        
        for(i=0;i<s.length()-1;i++)
        {
            tot += time[i];
            
            if(s[i] == s[i+1]){
                mx = max(mx, time[i]);
            }
            else
            {
                mx = max(mx, time[i]);
                sum += mx;
                mx = INT_MIN;
            }
        }
        
        mx = max(mx, time[i]);
        sum += mx;
        
        cout<<tot<<" "<<sum<<" ";
        return tot - sum;
    }
};