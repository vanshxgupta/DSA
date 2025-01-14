#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
  vector<int> size, parent;

 public:
  DisjointSet(int n) {
    size.resize(n + 1, 0);
    parent.resize(n + 1);

    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }

  int findUparent(int u) {
    if (u == parent[u]) {
      return u;
    }

    return parent[u] = findUparent(parent[u]);
  }

  void unionbysize(int u, int v) {
    int ulp_u = findUparent(u);
    int ulp_v = findUparent(v);
    if (ulp_u == ulp_v)
      return;
    if (size[ulp_u] < size[ulp_v]) {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    } else {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

class Solution {
  bool isvalid(int adjr, int adjc, int n, int m) {
    return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
  }

 public:
  vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    DisjointSet ds(n * m);
    int vis[n][m];
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    vector<int> ans;

    // going through all the queries
    for (auto it : operators) {
      int row = it[0];
      int col = it[1];

      // if this query is previously visited means it is already an island and will not add more to the answer(cnt)and will return the same cnt
      if (vis[row][col] == 1) {
        ans.push_back(cnt);
        continue;
      }
      vis[row][col] = 1;
      cnt++;

      int dr[] = {-1, 0, 1, 0};
      int dc[] = {0, 1, 0, -1};

      for (int ind = 0; ind < 4; ind++) {
        int adjr = row + dr[ind];
        int adjc = col + dc[ind];

        if (isvalid(adjr, adjc, n, m)) {
          // if the neighbours are also island then
          if (vis[adjr][adjc] == 1) {
            // then check for connectivity ,i.e if there parent are same,means they are connected
            int nodeno = row * m + col;
            int adjnodeno = adjr * m + adjc;

            // if they are not connected then connect them
            if (ds.findUparent(nodeno) != ds.findUparent(adjnodeno)) {
              cnt--;  // island cnt will decrease because two islands are connected and formed one
              ds.unionbysize(nodeno, adjnodeno);
            }
          }
        }
      }
      ans.push_back(cnt);
    }

    return ans;
  }
};