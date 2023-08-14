#include <bits/stdc++.h>
using namespace std;
class UGraph
{
public:
    int V;
    list<int> *adj;
    UGraph(int );
    void insert_edge(int, int);
    vector<int> BFS(int, int, int []);
};
UGraph::UGraph(int V)
{
    this->V = V;
    adj = new list<int>[V+1];
}
void UGraph::insert_edge(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
vector<int> UGraph::BFS(int componentNumber, int src,int visited[])
{
    queue<int> queue;
    queue.push(src);
    visited[src] = componentNumber;
    vector<int> reachableNodes;
    while(!queue.empty())
    {
        int x = queue.front();
        queue.pop();
        reachableNodes.push_back(x);
        for (auto itr = adj[x].begin();
                itr != adj[x].end(); itr++)
        {
            if (!visited[*itr])
            {
                visited[*itr] = componentNumber;
                queue.push(*itr);
            }
        }
    }
    return reachableNodes;
}
void showReachableNodes(int n,
            unordered_map <int, vector<int> > m)
{
    vector<int> tmpr = m[n];
    for (int i=0; i<tmpr.size(); i++)
        cout << tmpr[i] << " ";
    cout << endl;
}
void findReachableNodes(UGraph ug, int arr[], int n)
{
    int V = ug.V;
    int visited[V+1];
    memset(visited, 0, sizeof(visited));
    unordered_map <int, vector<int> > m;
    int componentNumber = 0;
    for (int i = 0 ; i < n ; i++)
    {
        int x = arr[i];
        if (!visited[x])
        {
            componentNumber++;
            m[visited[x]] = ug.BFS(componentNumber, x, visited);
        }
        cout << "Reachable Nodes from " << x <<" are\n";
        showReachableNodes(visited[x], m);
    }
}
int main()
{
    int V = 7;
    UGraph ug(V);
    ug.insert_edge(1, 2);
    ug.insert_edge(2, 3);
    ug.insert_edge(3, 4);
    ug.insert_edge(3, 1);
    ug.insert_edge(5, 6);
    ug.insert_edge(5, 7);
    int arr[] = {2, 3, 7};
    int n = sizeof(arr)/sizeof(int);
    findReachableNodes(ug, arr, n);

    return 0;
}
