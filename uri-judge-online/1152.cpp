#include <iostream>
#include <stdio.h> // stdin
#include <cstdlib> // getenv
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define MAX_ROAD_SIZE 4000000000

class Vertex
{
  public:
    typedef pair<int, Vertex *> ve;
    vector<ve> adj;
    int id;
    int minCost;
    bool visited = false;
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

class LessComparator
{
  public:

    bool operator()(const Vertex *lhs, const Vertex *rhs)
    {
        return lhs->minCost < rhs->minCost;
    }
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

    int prim(int m, int n, int first, int weightSum);
};

Vertex *Graph::addVertex(const int &u)
{
    Vertices::iterator it = this->vertices.find(u);
    if (it == this->vertices.end())
    {
        Vertex *newVertex = new Vertex();
        newVertex->id = u;
        newVertex->minCost = MAX_ROAD_SIZE;
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

int Graph::prim(int m, int n, int first, int weightSum){
    priority_queue<Vertex*, vector<Vertex*>, LessComparator> pq;
    int minWeigthSum = 0;
    Vertices::iterator itv;
    vector<ve>::iterator itAdj;

    // Forces it have the priority in pq
    this->vertices[first]->minCost = 0;    
    for (itv = this->vertices.begin(); itv != this->vertices.end(); ++itv)
    {
        pq.push(itv->second);
    }

    while(pq.size() != 0){
        Vertex *u = pq.top();
        pq.pop();

        for(itAdj = u->adj.begin(); itAdj != u->adj.end(); ++itAdj){
            if(itAdj->second->visited == false && itAdj->first < itAdj->second->minCost){
                itAdj->second->minCost = itAdj->first;
                itAdj->second->visited = true;
                minWeigthSum += itAdj->second->minCost;
            }
        }        

    }

    return weightSum - minWeigthSum;
}

void solve()
{
    // My solution goes here
    int m, n, u, v, w, wsum;
    Graph g;

    cin >> m >> n;
    while (m != 0 && n != 0)
    {   
        wsum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
            wsum += w;
        }

        cout << g.prim(m, n, u, wsum) << endl;
        //g.printGraph();

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