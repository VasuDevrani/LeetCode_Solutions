class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int ct = n/3, sum = 0;
        
        for(int i=n-2;i>=0 && ct>0;i-=2)
        {
            sum += piles[i];
            ct--;
        }
        
        return sum;
    }
};