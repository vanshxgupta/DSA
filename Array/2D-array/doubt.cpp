#include <vector>
#include <iostream>

using namespace std;

bool containdigit(int element ,int digit){
    
        while(element>0){
            int digitx=element%10;
            if(digitx==digit){
                return true;
            }
            element/=10;

        }
        return false;
   
  
}

bool sumgreater(int element){
    int digitx=0;
    int sumofdigit=0;
    while(element>0){
        sumofdigit =sumofdigit+digitx;
        digitx=element%10;
        element/=10;
        if(sumofdigit>=digitx){
            return true;
        }
    }
    return false;

}

vector<int> goodNumbers(int a, int b, int digit) {
    vector<int> arr;

    while (a<b) {
        arr.push_back(a);
        a++;
    }
    int n=arr.size();

    for(int i=0;i<n;i++){
        if((containdigit(arr[i],digit)) || sumgreater(arr[i])){
            arr.erase(arr.begin()+i);
        }
        
    }
    return arr;
}

int main(){
    int a, b, digit;
    cin >> a >> b >> digit;

    vector<int> result = goodNumbers(a, b, digit);

    for (int number : result) {
        cout << number << " ";
    }
}
