class Solution {
public:
    
    vector<int>nextGreatElm(vector<int>num)
    {
        stack<int>s;
        vector<int>ans;
        
        for(int i=num.size()-1;i>=0;i--)
        {
            while(!s.empty()){
            if(s.top()>num[i])
            {
                ans.push_back(s.top());
                s.push(num[i]);
                break;
            }
            else
            {
                s.pop();
            }
        }
            if(s.empty())
            {
                ans.push_back(-1);
                s.push(num[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        
        vector<int>next=nextGreatElm(nums2);
        
        int j;
        for(int i=0;i<nums1.size();i++)
        {
            for(j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j]){
                ans.push_back(next[j]);
                break;
                }
            }  
        }
        return ans;
    }
};