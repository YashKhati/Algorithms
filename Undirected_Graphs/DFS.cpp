#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<int> adj[], vector<bool> &vis, int node)
{
    vis[node] = true;
    cout << node << " ";
    for (auto it : adj[node])
    {
        if (vis[it] != true)
        {
            dfs(adj, vis, it);
        }
    }
}
int main()
{
    int N, V;
    cout << "Enter Number Of Nodes : ";
    cin >> N;
    cout << "Enter Number of Edges : ";
    cin >> V;

    vector<int> adj[N];

    cout << "Enter Edges : ";
    for (int i = 0; i < V; i++)
    {
        int from, to;
        cout << "Edge from - to ";
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    cout << "Adjancy List : " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << i << " : ";
        for (auto it : adj[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }

    vector<bool> vis(N, false);
    for (int i = 0; i < N; i++)
    {
        if (vis[i] == false)
        {
            dfs(adj, vis, i);
        }
    }
}