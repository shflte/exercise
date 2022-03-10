#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V, E;
    cout << "Enter Vertices and Edges: ";
    cin >> V >> E;

    int x, y;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << "List: \n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++) cout << adj[i][j] << " ";
        cout << "\n";
    }

    int start_from;
    cout << "Enter the vertice to start bfs: ";
    cin >> start_from;
    queue<pair<int, int> > q;
    q.push(make_pair(start_from, 0));

    int d[V];
    for (int i = 0; i < V; ++i) d[i] = -1;
    int index, dist;
    while (!q.empty()) {
        index = q.front().first;
        dist = q.front().second;
        q.pop();
        d[index] = dist;

        for (int i : adj[index]) {
            if (d[i] == -1) {
                q.push(make_pair(i, dist + 1));
            }
        }

        //cout << "q: " << q.front().first << " " << q.front().second << "\n";
    }

    cout << "Distence from " << start_from << ": \n";
    for (int i = 0; i < V; i++) cout << i << ": " << d[i] << "\n";
}