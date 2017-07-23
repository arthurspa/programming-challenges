#include <iostream>
#include <stdio.h> // stdin
#include <cstdlib> // getenv
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;


class Vertex
{
  public:
    typedef pair<int, Vertex *> ve;
    vector<ve> adj;
    int id;
    int minCost;
};

class IsEqualComparator
{
  public:
    IsEqualComparator(Vertex *vertex) : mVertex(vertex) {}

    typedef pair<int, Vertex *> ve;
    bool operator()(const ve &mve)
    {
        return mve.second == mVertex;
    }

  private:
    Vertex *mVertex;
};

typedef map<int, Vertex *> Vertices;
class Graph
{
  public:
    typedef pair<int, Vertex *> ve;
    Vertices vertices;

    Vertex *addVertex(const int &u);
    void addEdge(const int &u, const int &v, int w);
    void printGraph();
};

Vertex *Graph::addVertex(const int &u)
{
    Vertices::iterator it = this->vertices.find(u);
    if (it == this->vertices.end())
    {
        Vertex *newVertex = new Vertex();
        newVertex->id = u;
        this->vertices[u] = newVertex;
        return newVertex;
    }

    return it->second;
}

void Graph::addEdge(const int &u, const int &v, int w)
{
    Vertex *vu, *vv;
    vector<ve>::iterator itEdge;

    vu = this->addVertex(u);
    vv = this->addVertex(v);

    itEdge = find_if(vu->adj.begin(), vu->adj.end(), IsEqualComparator(vv));
    if (itEdge == vu->adj.end())
    {
        ve edge = make_pair(w, vv);
        vu->adj.push_back(edge);
    }

    itEdge = find_if(vv->adj.begin(), vv->adj.end(), IsEqualComparator(vu));
    if (itEdge == vv->adj.end())
    {
        ve edge = make_pair(w, vu);
        vv->adj.push_back(edge);
    }
}

void Graph::printGraph()
{
    Vertices::iterator itv;
    for (itv = this->vertices.begin(); itv != this->vertices.end(); ++itv)
    {
        cout << itv->first << " ";
        vector<ve>::iterator ite;
        for(ite = itv->second->adj.begin(); ite != itv->second->adj.end(); ++ite){
            cout << ite->second->id << "(" << ite->first <<")" << " ";
        }
        cout << endl;
    }
}

void solve()
{
    // My solution goes here
    int m, n, u, v, w;
    Graph g;

    cin >> m >> n;
    while (m != 0 && n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        }
        cin >> m >> n;
    }

    g.printGraph();
}

int main()
{
    if (getenv("IS_DEBUG"))
        FILE *f = freopen("input", "r", stdin);

    solve();

    // Workaround for issue
    // https://github.com/Microsoft/vscode-cpptools/issues/466
    if (getenv("IS_DEBUG"))
        cout << endl;

    return 0;
}


// Sample Input
// 7 11
// 0 1 7
// 0 3 5
// 1 2 8
// 1 3 9
// 1 4 7
// 2 4 5
// 3 4 15
// 3 5 6
// 4 5 8
// 4 6 9
// 5 6 11
// 0 0

// Sample Output
// 0 1(7) 3(5) 
// 1 0(7) 2(8) 3(9) 4(7) 
// 2 1(8) 4(5) 
// 3 0(5) 1(9) 4(15) 5(6) 
// 4 1(7) 2(5) 3(15) 5(8) 6(9) 
// 5 3(6) 4(8) 6(11) 
// 6 4(9) 5(11)