class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        if(k == cp.size())
        {
            return accumulate(cp.begin(),cp.end(),0);
        }
        long int sum = 0;
        
        for(int i=0;i<k;i++)
            sum += cp[i];
        long int ans = sum;
        
        int i = k-1, j = cp.size()-1;
        while(j >= 0 && i >= 0)
        {
            sum -= cp[i];
            sum += cp[j];
            j--;
            i--;
            ans = max(sum, ans);
        }
        return ans;
    }
};