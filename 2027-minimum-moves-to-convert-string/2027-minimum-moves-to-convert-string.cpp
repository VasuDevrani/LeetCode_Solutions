class Solution {
public:
    int minimumMoves(string s) {
        
        int x = 0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == 'X')
                x++;
        }
        
        if(s.length() == x)
        {
            if(x%3 == 0)
                return x/3;
            else
                return x/3+1;
        }
        else if(x == 0)
            return 0;
        else
        {
            int i = 0, ct = 0;
            while(i<s.length())
            {
                if(s[i] == 'X')
                {
                    i+=3;
                    ct++;
                }
                else
                    i++;
            }
            return ct;
        }
    }
};