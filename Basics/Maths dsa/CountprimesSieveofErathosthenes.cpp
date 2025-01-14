// Given an integer n, return the number of prime numbers that are strictly less than n.



//Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {

        int cnt=0;
        vector<bool> prime(n+1,true);//pehle sbko prime maan liya
        prime[0]=prime[1]=false;//0 aur 1 ko non prime mark kar diya as vo prime number nahi hote hai

        for(int i=2;i<n;i++){
            if(prime[i]){
                cnt++;
                for(int j=2*i;j<n;j=j+i){
                    prime[j]=0;//ye 0 kar diya hai tooh ab upr if waali statement nahi
                    // chalegi tooh uske kaaran number reject ho jayega jo prime number ki table mai aata hoga
                }
            }
        }
        return cnt;
        
    }
};