#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
void primsAlgo(int n, int cost[MAX][MAX]) {
    bool visited[MAX] = {0};
    int minCost = 0;
    visited[0] = true;
    for (int i = 1; i < n; i++) {
        int minWeight = INT_MAX;
        int row = -1, col = -1;
        for (int j = 0; j < n; j++) {
            if (visited[j]) {
                for (int k = 0; k < n; k++) {
                    if (!visited[k] && cost[j][k] < minWeight) 
                        minWeight = cost[j][k];
                        row = j;
                        col = k;
                    
                }
            }
        }
        if (row != -1 && col != -1) {
            minCost += minWeight;
            visited[col] = true;
            cout << "Edge: " << row + 1 << " - " << col + 1 << " Cost: " << minWeight << "\n";
            cost[row][col] = cost[col][row] = INT_MAX;
        }
    }
    cout << "Minimum Cost is equal to: " << minCost << "\n";
}
int main() {
    int n;
    cout << "Enter the number of vertices in MST: ";
    cin >> n;
    int cost[MAX][MAX];
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    primsAlgo(n, cost);
    return 0;
}
