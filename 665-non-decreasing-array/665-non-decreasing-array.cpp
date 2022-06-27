class Solution {
public:
    bool checkPossibility(vector<int>& arr) {
        int ct = 0;             
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i] < arr[i-1])
            {
                ct++;
                if(ct > 1) 
                    return false;
                if(i == 1 || arr[i-2] <= arr[i]) 
                    arr[i-1] = arr[i];    
                else 
                    arr[i] = arr[i-1];
            }
        }
        return true;
    }
};