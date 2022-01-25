int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        int maxNum = 0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            maxNum = max(maxNum,nums[i]);
        }
        int low = maxNum;
        int high = sum;
        while(low<=high){
            int n = 0;
            int k = 1;
            int mid = low +(high-low)/2;
            for(int i =0;i<nums.size();i++){
                n+=nums[i];
                if(n>mid){
                    k++;
                    n = nums[i];
                }
            }
            if(k<=m){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }