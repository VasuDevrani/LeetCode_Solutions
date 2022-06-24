class Solution {
public:
    int minFlips(string target) {
        int ct = 0, n = target.size();
        for(int i=0;i<target.length()-1;i++)
        {
            if(target[i] != target[i+1])
                ct++;
        }
       
        if(target[n-1] == '0' && ct%2 != 0)
            ct++;
        if(target[n-1] == '1' && ct%2 == 0)
            ct++;
        
        return ct;
    }
};