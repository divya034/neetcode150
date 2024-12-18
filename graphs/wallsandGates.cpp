class Solution {
public:
    int findTre(int i, int j, vector<vector<int>>& grid){

        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> vis(r, vector<int>(c,0));
        vis[i][j] = 1;

        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {-1,1,0,0};

        queue<pair<int,int>> q;
        q.push({i,j});
        int steps = 0;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            if(grid[x][y] == 0) return steps;
            q.pop();

            for(int i = 0; i<4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if(new_x >= 0 && new_x < r &&
                    new_y >= 0 && new_y < c &&
                    grid[new_x][new_y] != -1 && vis[new_x][new_y] != 1){
                        vis[new_x][new_y] = 1;
                        q.push({new_x, new_y});
                }
            }
        }


        return steps;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int inf = 2147483647;
        // vector<vector<int>> vis(r, vector<int>(c,0));

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == inf){
                    grid[i][j] = findTre(i, j, grid);
                }
            }
        }
    }
};
