// Ninja is given an integer ‘N’. Ninja wants to find whether the binary representation of integer ‘N’ is palindrome or not.
// A palindrome is a sequence of characters that reads the same backward as forward.
// Ninja is busy with his training. Help Ninja in finding out whether the binary representation of ‘N’ is palindrome or not.

#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

int decimal_binary(long long N) {
    int i = 0;
    int ans = 0;
    while (N != 0) {
        int bit = N & 1;
        ans = bit * pow(10, i) + ans;
        N = N >> 1;
        i++;
    }
    return ans;
}

bool palindrome(long long N, int i) {
    int chk = decimal_binary(N);
    string chk_str=to_string(chk);
    int n = chk_str.size();
    int j = n - i - 1;
    
    if (i >= j) {
        return true;
    }

    if (chk_str[i] != chk_str[j]) {
        return false;
    } else {
        return palindrome(N, i + 1);
    }
}

bool checkPalindrome(long long N) {
    return palindrome(N, 0);
}
int main(){
    int n;
    cin>>n;
    if(checkPalindrome(n)){
        cout<<"it is a palindrome";

    }
    else{
        cout<<"not a palindrome";
    }
}