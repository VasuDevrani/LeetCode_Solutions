class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
//         one of the method is brute force using three loops that will take O(n3)
        
//         other is by using pointer method
    
        sort(arr.begin(),arr.end());
    
        vector<vector<int>>ans;
        
        if(arr.size() < 3 )
        {
        return ans;
        }
        
        int n=arr.size();
    
          for(int i=0;i<=n-3;i++)
          {
               if(i==0 || i>0 && arr[i] != arr[i-1]){
              int j=i+1;
              int k=n-1;
              while(j<k)
              {
                  
                  if(arr[i]+arr[j]+arr[k]==0)
                  {
                      ans.push_back({arr[i],arr[j],arr[k]});
                      
                while(j<k && arr[j] == arr[j+1]){
                    j++;
                }
                while(j<k && arr[k] == arr[k-1]){
                    k--;
                }
                     
                      j++;
                      k--;
                  }
                  else if((arr[i]+arr[j]+arr[k])<0)
                      j++;
                  else 
                      k--;
              }
          }
          }
        return ans;
    }
};