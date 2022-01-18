int atoi(string str) {
        int ans = 0;
        int len = str.length();
        int i =0;
        int flag = 0;
         while(i<len){
             if(i==0 && str[i] == '-'){
                 flag = 1;
                 i++;
                 continue;
             }
             if(str[i]<'0' || str[i]>'9'){
                 return -1;
             }
             int q = str[i] - '0';
             ans = ans*10 + q;
             i++;
         }
         return flag == 1 ? (-1*ans) : ans;
    }