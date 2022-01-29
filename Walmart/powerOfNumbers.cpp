#define mod 1000000007
    long long power(int N,int R)
    {
       if(R == 0){
           return 1;
       }
       if(R==1){
           return N;
       }
       long long res = power(N,R/2)%mod;
       res = (res*res)%mod;
       if(R%2==0){
           return res%mod;
       }
       else{
           return (res*N)%mod;
       }
        
    }