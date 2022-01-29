int NumberOfPath(int a, int b)
    {
        double ans = 1;
        int x = a+b - 2;
        int y = min(a,b) - 1;
        for(int i =1;i<=y;i++){
            ans = ans*(x-y+i)/i;
        }
        return ans;
    }