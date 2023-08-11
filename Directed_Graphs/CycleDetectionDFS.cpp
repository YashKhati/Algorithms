#include <iostream>
#include <vector>
using namespace std;
bool dfs(vector<int> adj[], vector<bool> &vis, vector<bool> &pathvis, int node)
{
    vis[node] = true;
    pathvis[node] = true;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(adj, vis, pathvis, it) == true)
                return true;
        }
        else if (pathvis[it])
        {
            return true;
        }
    }
    pathvis[node] = false;
    return false;
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
    vector<bool> pathvis(N, false);
    for (int i = 0; i < N; i++)
    {
        if (vis[i] == false)
        {
            if (dfs(adj, vis, pathvis, i) == true)
            {
                cout << "Cycle Exist ";
                return 0;
            }
        }
    }
    cout << "Cycle Does Not Exist ";
}