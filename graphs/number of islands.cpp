https://neetcode.io/problems/count-number-of-islands

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
