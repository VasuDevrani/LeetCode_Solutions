class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        fb.push_back(0);
        
        for(int i = 0; n>0 && i < fb.size() - 1; ) 
        {
            if (!fb[i] && !fb[i+1])
                n--;
            
            i += fb[i+1] ? 3 : 2;
        }
        return !n;
    }
};