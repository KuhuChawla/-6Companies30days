//Count the subarrays having product less than k

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
        long long int temp = 1,j=0,ans=0;
        for(int i = 0;i<n;i++){
            temp *= a[i];
            while(j<n && temp>=k){
                temp/=a[j++];
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};