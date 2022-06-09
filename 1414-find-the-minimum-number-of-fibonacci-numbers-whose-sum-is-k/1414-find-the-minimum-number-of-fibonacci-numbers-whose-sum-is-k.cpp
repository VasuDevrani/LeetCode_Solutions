class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if(k == 1)
            return 1;
        vector<int>v;
        int sum = 0;
        int a = 1, b = 1;
        v.push_back(1);
        v.push_back(1);
        
        while(sum<k)
        {
            sum = a+b;
            if(sum == k)
                return 1;
            v.push_back(sum);
            a = b;
            b = sum;
            cout << sum<<" ";
        }
        
        a = lower_bound(v.begin(), v.end(), k) - v.begin() -1;
        sum = 0;
        b = 0;
        
        while(a>=0)
        {
            if(sum+v[a] > k)
                a--;
            else
            {
                sum += v[a];
                a--;
                b++;
                if(sum == k)
                    return b;
            }
        }
        
        return -1;
    }
};