class Solution {
public:
    
    void merge(vector<int>&nums,int l,int h)
    {
        int mid=(h+l)/2;
         int n1=mid-l+1;
        int n2=h-mid;
        
        int a[n1],b[n2]; //left and right parts resp.
             
        int k=0;
        for(int i=l;i<=mid;i++)
            a[k++]=nums[i];
        k=0;
        for(int j=mid+1;j<=h;j++)
            b[k++]=nums[j];
        
        int i=0,j=0; k=l;
        while(i<n1 && j<n2)
        {
            if(a[i]>=b[j])
                nums[k++]=b[j++];
            else
                nums[k++]=a[i++];
        }
        while(i<n1)
        {
          nums[k++]=a[i++];  
        }
        while(j<n2)
        {
            nums[k++]=b[j++];
        }
    }
    
    void merge_sort(vector<int>&nums ,int l,int h)
    {
        if(l>=h)
            return;
        int mid=(h+l)/2;
        
        merge_sort(nums,l,mid);
        
        merge_sort(nums,mid+1,h);
        
        merge(nums,l,h);
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
       int l=0,h=nums.size()-1;
        merge_sort(nums,l,h);
        return nums;
    }
};