class Solution {
public:
    int minTimeToType(string word) {
        int ct = 0;
        char prev = 'a';
        
        for(int i=0;i<word.length();i++)
        {
            int x,y;
                x = abs(word[i]-prev);
            if((int)prev < (int)word[i])
                y = abs((prev-'a')+('z'-word[i]));
            else
                y = abs(('z'-prev)+(word[i]-'a'));
            
            cout<<x<<" "<<y<<" "<<min(x,y+1)<<endl;
            ct += min(x,y+1);  
            prev = word[i];
            ct++;
        }
        
        return ct;
    }
};