// You are given a three integers 'X', 'N', and 'M'. Your task is to find ('X' ^ 'N') % 'M'. 
//A ^ B is defined as A raised to power B and A % C is the remainder when A is divided by C.

#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
    int res=1;

    while(n>0){
        if(n&1){
            //if  n is odd
            res=(1LL*(res)*(x%m))%m;//1LL is long long integer , basically we type casted it into log long int
                //  becuase agr dono agr extreme case aa jaye 10^9 ke tooh multiply hoke aur jyada ho jayega isliye
            
        }
        x=(1LL*(x%m)*x%m)%m;
        n=n>>1;//yaad karo right shift karne se number divide by 2 ho jata hai, 
        //bitwise operator jyad optimised hota hai nahi tooh divide by 2 bhi likh skte the 

    }
	return res;

}