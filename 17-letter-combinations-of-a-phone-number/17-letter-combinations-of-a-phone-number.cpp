class Solution {
public:
    
    vector<string>v1;
    
    void print_combn(vector<string>keys,int i,string s)
{
    // base
    if(i==keys.size())
    {
        v1.push_back(s);
        return;
    }

    // recursion
     string temp=keys[i];
     for(int j=0;j<temp.length();j++)
     {
         print_combn(keys,i+1,s+temp[j]);
     }

}
    
    vector<string> letterCombinations(string digits) {    
        vector<string>v={"1","2","abc","def","ghi", "jkl" ,"mno","pqrs", "tuv", "wxyz"};
        
        vector<string>keys;
        for(int i=0;i<digits.length();i++)
        {
            keys.push_back(v[digits[i]-'0']);
        }
       
        print_combn(keys,0,"");
        if(v1[0]=="")
        {
            vector<string>ans;
            return ans;
        }
        else
        return v1;
    
    }
};