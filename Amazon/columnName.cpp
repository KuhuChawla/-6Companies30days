string colName (long long int n)
    {
        string ans = "";
        while(n>=26){
            int rem = n%26;
            n/=26;
            if(rem==0){
                ans = 'Z' + ans;
                n--;
            }
            else{
                ans = (char)(rem-1 + 'A')+ ans;
            }
        }
        if(n!=0){
            ans = (char)(n-1+ 'A')+ ans;
        }
        return ans;
    }