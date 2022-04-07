class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()==1)
        {
            return true;
        }
        string n=s;
        for(int i=1;i<s.size();i++)
        {
            s=n;
            rotate(s.begin(),s.begin()+i,s.end());
            if(s==goal)
            {
                return true;
            }
        }
        return false;
    }
};