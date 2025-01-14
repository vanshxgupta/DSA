
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Make a distance array which stores the distances (initialized with INT_MAX).
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        
        // The source node in the distance array should be initialized with 0.
        distance[source.first][source.second] = 0;
        
        // We need a queue in which the source and its distance is pushed initially.
        // The structure of an element of the queue will be {distance, (sourcei, sourcej)}.
        queue<pair<int, pair<int, int>>> q;
        q.push({0,{source.first,source.second}});
        
        
        // Adjacent nodes ko nikalne ke liye
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        
        
          // Edge Case: if the source is only the destination.
        if (source.first == destination.first &&
            source.second == destination.second)
            return 0;
                
        while (!q.empty()) {
            
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            
            
            for (int i = 0; i < 4; i++) {
                 int newRow = row + dr[i];
                 int newCol = col + dc[i];
                 
                 
                 // If new position is out of bounds, skip it.
                 if (newRow>= 0 && newRow < n && newCol >=0 && newCol <m && grid[newRow][newCol] == 1 && (dist + 1 < distance[newRow][newCol])) {
                        distance[newRow][newCol] = dist + 1;
                                                          // If destination reached
                        if (newRow == destination.first && newCol == destination.second) {
                            return distance[row][col] + 1;
                        }
                        
                        q.push({dist + 1, {newRow, newCol}});
                 }

                }
            
        }
        
        // If destination is not reachable
        return -1;
    }
};
