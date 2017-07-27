#include <iostream>
#include <stdio.h> // stdin
#include <cstdlib> // getenv
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f


class Vertex
{
  public:
    typedef pair<int, Vertex *> edge;
    vector<edge> adj;
    Vertex* parent;
    int id;
    int minCost; 
    bool visited;
};
typedef pair<int, Vertex *> edge;

class IsEqualComparator
{
  public:
    IsEqualComparator(Vertex *vertex) : mVertex(vertex) {}

    bool operator()(const pair<int, Vertex *> &mve)
    {
        return mve.second == mVertex;
    }

  private:
    Vertex *mVertex;
};

class GreaterComparator
{
  public:

    bool operator()(const Vertex *lhs, const Vertex *rhs)
    {
        return lhs->minCost >= rhs->minCost;
    }
};

typedef map<int, Vertex *> Vertices;
class Graph
{
  public:
    Vertices vertices;

    Vertex *addVertex(const int &u);
    bool addEdge(const int &u, const int &v, int w);
    void printGraph();

    int prim(int m, int n, int first, int weightSum);
};

Vertex *Graph::addVertex(const int &u)
{
    Vertices::iterator it = this->vertices.find(u);
    if (it == this->vertices.end())
    {
        Vertex *newVertex = new Vertex();
        newVertex->parent = nullptr;
        newVertex->minCost = INF;
        newVertex->id = u;
        newVertex->visited = false;
        this->vertices[u] = newVertex;
        return newVertex;
    }

    return it->second;
}

bool Graph::addEdge(const int &u, const int &v, int w)
{
    Vertex *vu, *vv;
    vector<edge>::iterator itEdge;
    bool added = false;

    vu = this->addVertex(u);
    vv = this->addVertex(v);

    itEdge = find_if(vu->adj.begin(), vu->adj.end(), IsEqualComparator(vv));
    if (itEdge == vu->adj.end())
    {
        edge edge = make_pair(w, vv);
        vu->adj.push_back(edge);
        added = true;
    }

    itEdge = find_if(vv->adj.begin(), vv->adj.end(), IsEqualComparator(vu));
    if (itEdge == vv->adj.end())
    {
        edge edge = make_pair(w, vu);
        vv->adj.push_back(edge);
        added = true;
    }

    return added;
}

void Graph::printGraph()
{
    Vertices::iterator itv;
    for (itv = this->vertices.begin(); itv != this->vertices.end(); ++itv)
    {
        cout << itv->first << " ";
        vector<edge>::iterator ite;
        for(ite = itv->second->adj.begin(); ite != itv->second->adj.end(); ++ite){
            cout << ite->second->id << "(" << ite->first <<")" << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int Graph::prim(int m, int n, int first, int weightSum){
    priority_queue<Vertex*, vector<Vertex*>, GreaterComparator> pq;
    int minWeigthSum = 0;
    Vertices::iterator itv;
    vector<edge>::iterator itAdj;

    // Forces it have the priority in pq
    this->vertices[first]->minCost = 0; 
    pq.push(this->vertices[first]);

    while(pq.size() != 0){
        Vertex *u = pq.top();
        pq.pop();
        if(!u->visited){
            u->visited = true;
            minWeigthSum += u->minCost;

            for(itAdj = u->adj.begin(); itAdj != u->adj.end(); ++itAdj){
                if(itAdj->second->visited == false && itAdj->first < itAdj->second->minCost){
                    itAdj->second->minCost = itAdj->first;
                    itAdj->second->parent = u;
                    pq.push(itAdj->second);
                }
            }
        }
        
    }

    return weightSum - minWeigthSum;
}

void solve()
{
    // My solution goes here
    int m, n, u, v, w, wsum, added;    
    
    cin >> m >> n;
    while (!(m == 0 && n == 0))
    {   
        Graph g;
        wsum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> u >> v >> w;
            added = g.addEdge(u, v, w);
            if(added)
                wsum += w;
        }

        cout << g.prim(m, n, u, wsum) << endl;
        

        cin >> m >> n;
    }

    
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