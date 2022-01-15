int minSteps(int D){
       D = abs(D);
       int s = 0;
       int i = 1;
       while(s<D || (s-D)%2 !=0){
           s+=i;
           i++;
       }
       return i-1;
    }