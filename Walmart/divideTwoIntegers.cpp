int divide(int dividend, int divisor) {
        if(divisor == 1){
            return dividend;
        }
        if(divisor == -1 && dividend == INT_MIN){
            return INT_MAX;
        }
        if(dividend == 0){
            return 0;
        }
        int sign = 1;
        if(dividend>0){
            dividend = -dividend;
            if(divisor > 0){
                divisor = -divisor;
            }
            else{
                sign = -1;
            }
        }
        else{
            if(divisor>0){
                sign = -1;
                divisor = -divisor;
            }
        }
        int left = dividend;
        int ans = 0;
        while(left<=divisor){
            int tempAns =1;
            int tempSum = divisor;
            while(tempSum > INT_MIN/2  && tempSum+tempSum > left){
                tempSum+=tempSum;
                tempAns+=tempAns;
            }
            left -= tempSum;
            ans+=tempAns;
        }
        return ans*sign;
    }