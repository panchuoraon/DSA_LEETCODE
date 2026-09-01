class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sx = 0, sy = 0;

        // Assign every litter a number: 0,1,2...
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        int targetMask = (1 << litterCount) - 1;

        /*
          visited[x][y][mask] stores the maximum energy
          with which we've reached this state.
        */
        vector<vector<vector<int>>> bestEnergy(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << litterCount, -1)
            )
        );

        // row, col, mask, remaining energy
        queue<array<int, 4>> q;

        q.push({sx, sy, 0, energy});
        bestEnergy[sx][sy][0] = energy;

        int moves = 0;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [x, y, mask, currEnergy] = q.front();
                q.pop();

                // All litter collected
                if (mask == targetMask)
                    return moves;

                // No energy means we cannot move anymore
                if (currEnergy == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= m ||
                        ny < 0 || ny >= n)
                        continue;

                    if (classroom[nx][ny] == 'X')
                        continue;

                    int newEnergy = currEnergy - 1;
                    int newMask = mask;

                    // Collect litter
                    if (classroom[nx][ny] == 'L') {

                        int id = litterId[nx][ny];

                        newMask |= (1 << id);
                    }

                    // Recharge
                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }

                    /*
                      If we reached the same
                      (cell, collected litter)
                      before with >= energy,
                      current state is useless.
                    */
                    if (bestEnergy[nx][ny][newMask] >= newEnergy)
                        continue;

                    bestEnergy[nx][ny][newMask] = newEnergy;

                    q.push({
                        nx,
                        ny,
                        newMask,
                        newEnergy
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};