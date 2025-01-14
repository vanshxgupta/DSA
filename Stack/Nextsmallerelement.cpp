#include<bits/stdc++.h>
#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(s.top()>=curr){//[2,1,4,3] iss example mai sbse pehele ye condition false ho jayegi becuase (-1>=3 is false )
                                            //second case mai bhi ye condition nahi chalegi(becuase 3(top)>=4 is false ))
                                            //third case mai ye condition chalegi becuase(4>=1 is true) tooh 4 pop ho jayega , fir (3>=1 is true) tooh 3 bhi pop hoga , fir (-1>=1 is false )so condition nahi chalegi ye  
                                            //fourth case mai (1>=2 is false )so condtion nahi chalegi 
                s.pop();
            }

            //ans is stack ka top
            ans[i]=s.top(); //top matlab sabse pehle -1 print ho jayega ,fir 3 print hoga, fir -1, fir 1

            s.push(curr);//first element 3 current mai update hua //dusra element 4 aya , tisra element 1 aya , fourth element 2 aya 
    }
    return ans;
    
}