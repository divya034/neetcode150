https://neetcode.io/problems/count-number-of-islands
BFS
class Solution {
public:
    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>>& grid){
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        int rows = vis.size();
        int cols = vis[0].size();

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newx < rows &&
                    newy >=0 && newy < cols && 
                    grid[newx][newy] == '1' &&
                    vis[newx][newy] != 1){
                        q.push({newx,newy});
                        vis[newx][newy] = 1;
                    }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // fill 2d grid with 0
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int count = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }

        return count;

    }
};

DFS:
class Solution {
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
public:
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int i, int j){
        vis[i][j] = 1;
        int r = grid.size();
        int c = grid[0].size();

        for(int k = 0; k < 4; k++){
            int new_x = i + dx[k];
            int new_y = j + dy[k];

            if(new_x >= 0 && new_x < r &&
             new_y >= 0 && new_y < c &&
             grid[new_x][new_y] == '1' && vis[new_x][new_y] == 0){
                dfs(grid, vis, new_x, new_y);
             }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(r, vector<int> (c, 0));

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == '1' && vis[i][j] != 1){
                    dfs(grid, vis, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

// approach:

// if we find 1 -call a bfs/dfs call, mark all 1s arround it as vis, 
// count++ for island

// go on traversing the grid for next unvisited "1"
