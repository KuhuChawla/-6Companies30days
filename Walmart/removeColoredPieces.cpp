//brute force solution passed

bool winnerOfGame(string colors) {
        if(colors.size()<3){
            return false;
        }
        int countA = 0;
        int countB = 0;
        for(int i=0;i<colors.size()-2;i++){
            if(colors[i]=='A' && colors[i+1]=='A' && colors[i+2]=='A'){
                countA++;
            }
            if(colors[i]=='B' && colors[i+1]=='B' && colors[i+2]=='B'){
                countB++;
            }
        }
            return countA>countB;
    }