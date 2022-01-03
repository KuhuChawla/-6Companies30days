// Given an unsorted array Arr of size N of positive integers. One number 'A' from     set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.
int *findTwoElement(int *arr, int n) {
        unordered_map<int,int> mp;
        int *ans = new int[2];
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i = 1;i<n+1;i++){
            if(mp[arr[i]]>1){
                ans[0]=arr[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(mp[i]==0){
                ans[1]=i;
                break;
            }
        }
        return ans;
        
        
    }