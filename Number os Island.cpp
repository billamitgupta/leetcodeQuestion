class Disjoint {
    vector<int> par, rank;

public:
    Disjoint(int n) {
        par.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int findPar(int n) {
        if (par[n] == n)
            return n;
        return par[n] = findPar(par[n]);
    }

    void unionByRank(int i, int j) {
        int utp_i = findPar(i);
        int utp_j = findPar(j);
        if (utp_i == utp_j)
            return;
        if (rank[utp_i] > rank[utp_j]) {
            par[utp_j] = utp_i;
        } else if (rank[utp_j] > rank[utp_i]) {
            par[utp_i] = utp_j;
        } else {
            par[utp_i] = utp_j;
            rank[utp_j]++;
        }
    }
};

class Solution {
    bool isValid(int adcr, int adcc, int n, int m) {
        return adcr >= 0 && adcc >= 0 && adcc < m && adcr < n;
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        Disjoint ds(n * m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        vector<int> ans;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == '1' && vis[row][col] == 0) {
                    vis[row][col] = 1;
                    cnt++;
                    int dx[] = {-1, 0, 1, 0};
                    int dy[] = {0, 1, 0, -1};
                    for (int i = 0; i < 4; i++) {
                        int adcr = row + dx[i];
                        int adcc = col + dy[i];
                        if (isValid(adcr, adcc, n, m) && grid[adcr][adcc] == '1') {
                            int node = row * m + col;
                            int adj = adcr * m + adcc;
                            if (ds.findPar(node) != ds.findPar(adj)) {
                                cnt--;
                                ds.unionByRank(node, adj);
                            }
                        }
                    }
                }
                ans.push_back(cnt);
            }
        }
        return ans[ans.size() - 1];
    }
};
