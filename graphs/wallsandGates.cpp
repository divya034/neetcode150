class Solution {
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
public:
    int bfs(int i, int j, vector<vector<int>>& grid){
        int r = grid.size();
        int c = grid[0].size();

        // priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>> greater<pair<pair<int,int>, int>>> q;

         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0, {i, j}});

        while(!q.empty()){
            int x = q.top().second.first;
            int y = q.top().second.second;

            int dist = q.top().first;
            q.pop();

            if(grid[x][y] == 0){
                return dist;
            }

            for(int k = 0; k < 4; k++){
                int new_x = x + dx[k];
                int new_y = y + dy[k];

                if(new_x >= 0 && new_x < r &&
                    new_y >= 0 && new_y < c &&
                    grid[new_x][new_y] != -1){

                    q.push({dist + 1, {new_x, new_y}});

                }

            }
        }

        return INT_MAX;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == 2147483647){
                    grid[i][j] = bfs(i, j, grid);
                }
            }
        }
    }
};

// NOTES
// -1 - water
// 0 - tre
// INF - land

// find a land cell
// -if found, bfs/dfs in all 4 direction to find tre cell
// BFS:
// no need for visited, as we need to recheck for tre


// -1  -1    0
// 12  inf   -1
// inf  inf  inf
