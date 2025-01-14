// #include<iostream>
// using namespace std;
// char tolowercase(char ch){
//     if(ch>'a' && ch<'z'){
//         return ch;

//     }
//     else{
//         char temp =ch - 'A'+'a';
//         return temp;


//     }
// }
 
// bool checkpalindrome(char a[],int n){
//     int s=0;
//     int e=n-1;
//     while(s<=e){
//         if(tolowercase(a[s])!=tolowercase(a[e])){//iski madad se saare charcters lowercase hoke compare honge ;
//         //lowercase and uppercase characters same mane jayenge 
//             return 0;

//         }
//         else{
//             s++;
//             e--; 

//         }
//     }
//     return 1;

// }
// int getlength(char name[]){
//     int count=0;

//     for(int i=0;name[i]!='\0';i++){//loop tabh tak chalega jab tak name mai null character nahi aa jata
//         count++;

//     }
//     return count;

// }



// int main(){
//     char name[20];
//     cout<<"enter your name "<<endl;
//     cin>>name;
//     int len=getlength(name);



//     cout<<"is palindrome :"<<checkpalindrome(name,len)<<endl;

//     cout<<"Character is "<<tolowercase('b')<<endl;
//     cout<<"Character is "<<tolowercase('C')<<endl;//lower case mai convert ho jayega 
 
    


// } 




//Method 2 

#include<iostream>
using namespace std;
//for len of character array
int getlen(char name[]){
    int count = 0;
    for(int i = 0;name[i] != '\0'; i++){
        count ++;
    }
    return count;
}
//for reversing a chr array
void reversest( char name[]){
    int s =0;
    int e = getlen(name) -1;
    while(s<e){
        swap(name[s],name[e]);
        s++;
        e--;
    }
}
char tolowercase(char ch){
    if ((ch>='a' && ch<='z')||(ch>='0' && ch <='9'))
    return ch;
    else{
        char temp = ch -'A'+ 'a';
        return temp;
    }
}


bool validchar(char ch){
    if(( ch >='a'&& ch<='z')||(ch>='A'&& ch<= 'Z')||(ch>='0' && ch<='9')){
            return 1;
    }
    else{
        return 0;
    }

}
bool checkp2(string s){
    // faltu character hataoo
    string temp ="";
    for ( int j =0;j<s.length();j++){
        if (validchar(s[j])){
            temp.push_back(s[j]);
        }
    }
    //lowecase kr do
    for(int j=0; j<temp.length();j++){
        temp[j] = tolowercase(temp[j]);
    }
    int start =0;
    int end = s.size()-1;
    while(start<end)
{
    if(temp[start]!=temp[end]){
        return 0;
    }
    else{
        start++;
        end--;

    }
    }
return 1;
}
int main(){
    string name;
    cout<<" ENter your name ";
    cin>>name;
    //name[5]='\0';
    //cout << "your name is ";
     //cout << name <<endl;
     //reversest(name);
    //cout <<"reverse string is "<< name <<endl;
    cout<<" is pralindrome "  << checkp2(name);
    //char array n string me diff
    char a[10]={'s','f'};
    string s="anshu";
    //cout << a<<" "<< s<<endl;
     //cout << getlen(a)<<" "<< s.size()<<endl;
}

 