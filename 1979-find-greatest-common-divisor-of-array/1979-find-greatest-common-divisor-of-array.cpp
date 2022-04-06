class Solution {
public:
    int findGCD(vector<int>& arr) {
        int max=INT_MIN,min=INT_MAX;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<min)
                min=arr[i];
        }
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>max)
                max=arr[i];
        }
        
        int gcd;
        while(min!=0)
        {
          int r=max%min;
          max=min;
           min=r;   
        }
        return max;
    }
};