class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        if(n == 0)
            return true;
        
        int ct = 0;
        if(fb.size() < 2)
        {
            if(fb[0] == 0)
                return true;
            else
                return false;
        }
        if(fb[0] == 0 && fb[1] != 1)
        {
            ct++;
            fb[0] = 1;
        }
        for(int i=1;i<fb.size()-1;i++)
        {
            if(fb[i] == 0 && fb[i-1] == 0 && fb[i+1] == 0)
            {
                ct++;
                fb[i] = 1;
            }
        }
        if(fb[fb.size()-1] == 0 && fb[fb.size()-2] == 0)
            ct++;
        
        return ct >= n; 
    }
};