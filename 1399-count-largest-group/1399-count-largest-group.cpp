class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>m;
        
        for(int i=1;i<=n;i++)
        {
            int sum=0;
            int num=i;
            while(num>0)
            {
                sum+=num%10;
                num/=10;
            }
            m[sum]++;
        }
        
        int max=INT_MIN;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if((*it).second>max)
                max=(*it).second;
        }
        int ct=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if((*it).second==max)
                ct++;
        }
        return ct;
    }
};