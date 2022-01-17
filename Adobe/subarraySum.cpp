vector<int> subarraySum(int a[], int n, long long s)
    {
        vector<int> v;
        long long sum = 0;
        int i = 0;
        int j=0;
        while(j<n && sum+a[j]<=s){
            sum+=a[j];
            j++;
        }
        if(sum == s){
            v.push_back(i+1);
            v.push_back(j);
            return v;
        }
        while(j<n){
            sum+=a[j];
            while(sum>s){
                sum-=a[i];
                i++;
            }
            if(sum == s){
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            j++;
        }
        v.push_back(-1);
        return v;
        
    }