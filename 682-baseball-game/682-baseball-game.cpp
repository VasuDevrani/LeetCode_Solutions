class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]!="C" && ops[i]!="D" && ops[i]!="+")
                s.push(stoi(ops[i]));
            else if(ops[i]=="+")
            {
                int top=s.top();
                int sum=0;
                s.pop();
                sum=top+s.top();
                s.push(top);
                s.push(sum);
                
            }
            else if(ops[i]=="D")
            {
                s.push(2*s.top());
            }
            else if(ops[i]=="C")
            {
                s.pop();
            }
        }
        
        long int ans=0;
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};