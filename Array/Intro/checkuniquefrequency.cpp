// C++ code for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to check whether the
// frequency of elements in array
// is unique or not.
bool checkUniqueFrequency(int arr[], int n)
{

  vector<int> frequency(2*n);

  // For counting the frequency of each element
  for (int i = -n; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[j] == i) {
        frequency[i - 1]++;
      }
    }
  }

  // Checking if frequency array contains any duplicate
  // or not
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j || frequency[i] == 0)
        continue;
      if (frequency[i] == frequency[j]) {

        // If any duplicate frequency then return
        // false
        return false;
      }
    }
  }

  // If no duplicate frequency found, then return true
  return true;
}

// Driver Code
int main()
{
  // Given array arr[]
  int arr[] = { -2, 2, 5, 10, 2, 5, 10, 2 ,2,2};
  int n = sizeof arr / sizeof arr[0];

  // Function Call
  bool res = checkUniqueFrequency(arr, n);

  // Print the result
  if (res)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
