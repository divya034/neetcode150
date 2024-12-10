BFS:
class Solution {
public:
    int bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis){

        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {-1,1,0,0};
        queue<pair<int,int>> q;

        q.push({i,j});
        vis[i][j] = 1;
        
        int area = 1;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if(new_x >= 0 && new_x < rows &&
                    new_y >= 0 && new_y < cols &&
                    grid[new_x][new_y] == 1 &&
                    vis[new_x][new_y] == 0){

                    q.push({new_x, new_y});
                    vis[new_x][new_y] = 1;
                    area++;
                }
            }
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(), 0));
        int max_area = 0;

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){

                if(grid[i][j] == 1 && vis[i][j] == 0){
                   int area = bfs(i, j, grid, vis);
                   max_area = max(area, max_area);
                }

            }
        }

        return max_area;
    }
};


DFS:
class Solution {
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
public:
    int dfs(int i , int j, vector<vector<int>> &vis, vector<vector<int>> &grid, int &area){
        vis[i][j] = 1;
        int r = grid.size();
        int c = grid[0].size();

        for(int k = 0; k<4; k++){
            int new_x = i + dx[k];
            int new_y = j + dy[k];

            if(new_x >= 0 && new_x < r &&
                new_y >= 0 && new_y < c &&
                grid[new_x][new_y] == 1 && vis[new_x][new_y] != 1){
                    area = area + 1;
                    dfs(new_x, new_y, vis, grid, area);
            }
        }

        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        int max_area = 0;
        vector<vector<int>> vis(r, vector<int>(c, 0));

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int area = 1;
                    area = dfs(i, j, vis, grid, area);
                    max_area = max(area, max_area);
                }
            }
        }
        return max_area;
    }
};
// approach
// when we find a 1--->
// call dfs/bfs get the area, mark everything visited in path
// max_area = max(area, max_area);

// initial:
// max_area = 0;



