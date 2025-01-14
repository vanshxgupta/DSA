//simple tarika mil gya 2 ghnte baad (bc)

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    if(n==1 || n==3){
        cout<<-1<<endl;
    }

    else{
        if(n%2==0){//even
            string result;
            for(int i=0;i<n-2;i++){
            result.push_back('3');
            }
            result.push_back('6');
            result.push_back('6');
            cout<<result<<endl;
        }
        else{
            //odd
            string result;
            for(int i=0;i<n-4;i++){
            result.push_back('3');
            }
            result.push_back('6');
            result.push_back('3');
            result.push_back('6');
            result.push_back('6');
            cout<<result<<endl;
            result
        }

    }

}   
  return 0;
}



//using recursion (tle maar gya bc )

// #include <bits/stdc++.h>
// using namespace std;

// bool checkDiv(vector<int>& arr) {
//     int n = arr.size();
//     int sum = accumulate(arr.begin(), arr.end(), 0);
//     if (sum % 3 != 0 || arr[n - 1] != 6) return false; 

//     int oddSum = 0, evenSum = 0;
//     for (int i = 0; i < arr.size(); ++i) {
//         if (i % 2 == 0)
//             oddSum += arr[i];
//         else
//             evenSum += arr[i];
//     }
//     return (oddSum - evenSum) % 11 == 0;
// }

// void solve(int idx, vector<int>& arr, int n, vector<string>& strings) {
//     if (idx == n) {
//         if (checkDiv(arr)) {
//             string num = "";
//             for (int val : arr) {
//                 num += to_string(val);
//             }
//             strings.push_back(num);
//         }
//         return;
//     }
    
//     arr[idx] = 6;
//     solve(idx + 1, arr, n, strings);
//     arr[idx] = 3;

//     solve(idx + 1, arr, n, strings);
// }

// bool comp(string &a,string &b){
//     if(a.length()!=b.length()){
//         return a.length()<b.length();
//     }
//     return a<b;

// }
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         if (n == 1 || n == 3) {
//             cout << -1 << endl;
//             continue;
//         }

//         vector<int> arr(n);
//         vector<string> strings;

//         solve(0, arr, n, strings);

//         if (strings.empty()) {
//             cout <<-1<< endl;
//         } else {
//             sort(strings.begin(), strings.end(),comp);
//             cout << strings[0] << endl;
//         }
//     }

//     return 0;
// }
