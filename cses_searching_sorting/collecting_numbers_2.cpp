//collecting numbers 1:
// Store the position of every number. A new round is needed whenever i+1 appears before i in the array (pos[i] > pos[i+1]).
// The problem is about the order of consecutive values (1→2→3...), not adjacent array elements. Count position inversions of consecutive numbers.

//collecting numbers 2:
//observe that the swap values x and y , will only affect( x-1 ,x) or (x,x+1) or (y-1,y) or (y,y+1) 
//so remove the old contributions of this , and add the new contributions of this after swapping 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1), pos(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i + 1]) rounds++;
    }

    while (m--) {
        int i, j;
        cin >> i >> j;

        int x = arr[i];
        int y = arr[j];

        set<pair<int, int>> affected;

        if (x > 1) affected.insert({x - 1, x});
        if (x < n) affected.insert({x, x + 1});
        if (y > 1) affected.insert({y - 1, y});
        if (y < n) affected.insert({y, y + 1});

        // Remove old contribution
        for (auto [a, b] : affected) {
            if (pos[a] > pos[b]) rounds--;
        }

        // Swap values
        swap(arr[i], arr[j]);
        swap(pos[x], pos[y]);

        // Add new contribution
        for (auto [a, b] : affected) {
            if (pos[a] > pos[b]) rounds++;
        }

        cout << rounds << '\n';
    }

    return 0;
}