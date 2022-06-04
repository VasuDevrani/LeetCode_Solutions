class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int n = arr.size();
        int XOR[n];
        
        int x=0;
        for(int i=0;i<n;i++)
        {
            x = x^arr[i];
            XOR[i] = x;
        }
        
        int ct=0;
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                
                for(int k=j;k<n;k++){
                    int a,b;
    //                 getting a
                    if(i == 0)
                        a = XOR[j-1];
                    else
                        a = XOR[j-1] ^ XOR[i-1];

    //                 getting b
                    b = XOR[k] ^ XOR[j-1];
                    if(a == b)
                    {
                        ct++;
                    }
                }
            }
        }
        
        return ct;
    }
};