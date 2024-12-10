1. Number of islands:
BFS, DFS, and disjoint union
-if we find 1 && unvisited, count++ 
call a bfs/dfs call, mark all 1s around it as vis, 
-go on traversing the grid for next unvisited "1" and count++ so on.

NOTE: traverse the grid to find 1, do count++ here as this is an island for sure, traverse its neighbors so you cover all island
mark all nbr as vis, return the count in the end;

2. Max area of an Island
BFS, DFS, disjoint set union
  global max_area = 0; // default return 0 if no island is found
-if we find 1 && unvisited, declare local area = 1
-call bfs/dfs, mark all in path as visited, do area = area + 1 each time we find neighboring 1

NOTE: traverse the grid to find a 1, the bfs/dfs from that point to see the attached area of the neighbors,
  calculate area in each call dfs/bfs, return the maximum
