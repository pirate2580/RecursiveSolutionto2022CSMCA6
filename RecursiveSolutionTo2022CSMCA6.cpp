#include<bits/stdc++.h>
using namespace std;

// Link to 2022 CSMC: https://www.cemc.uwaterloo.ca/contests/past_contests/2022/2022CSMC.pdf


int ans = 0;

int factorial (int num){        //recursive implementation of factorial function
    if (num==1){
        return 1;
    }
    else {
        return num*factorial(num-1);
    }
}

void isValid(int R,int B, int G){
    //cout<<"R B G"<<R<<' '<<B<<' '<<G<<endl;
    if (R==3 && B<5 && G<7){                                                // we prune the search when 3 red balls are placed
        ans = ans + factorial((15-R-G-B))/(factorial(5-B)*factorial(7-G));
    }
    else if (R<3 && B==5 && G<7){                                           // we don't count this because all blue balls placed before red
        return;
    }
    else if (R<3 && B<5 && G==7){                                           // we don't count this because all green balls placed before red
        return;
    }
    else{
        isValid(R+1,B,G);
        isValid(R,B+1,G);
        isValid(R,B,G+1);
    }
}

int main(){
    isValid(0,0,0);
    cout<<"number of permutations satisfying our condition: "<<ans<<endl;

    cout<<"thus, the probability is : "<< ans/360360.0<<endl;
    return 0;
}
