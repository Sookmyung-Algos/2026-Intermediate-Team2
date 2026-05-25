#include <iostream>
#include <vector>
using namespace std;

const int INF=1e9;

struct Edge{
    int from;
    int to;
    int cost;
};

int main(){
    int N,R,W;
    cin>>N>>R>>W;

    vector<Edge> edges;

    for(int i=0; i<R; i++){
        int u,v,w;
        cin>>u>>v>>w;

        edges.push_back({u,v,w});
        edges.push_back({v,u,w});
    }

    for(int i=0; i<W; i++){
        int u,v,w;
        cin>>u>>v>>w;

        edges.push_back({u,v,w});
    }

    vector<int> dist(N+1,INF);

    dist[1]=0;

    for(int i=1; i<=N-1; i++){
        for(Edge e:edges){
            if(dist[e.from]==INF) continue;
            if(dist[e.to]>dist[e.from]+dist[e.cost]){
                dist[e.to]=dist[e.from]+dist[e.cost];
            }
        }
    }

    bool negativeCycle=false;

    for(Edge e:edges){
        if (dist[e.from] == INF)
            continue;
        if(dist[e.to]>dist[e.from]+dist[e.cost]){
            negativeCycle=true;
        }
    }

    if(negativeCycle){
        cout<<"-INF"<<"\n";
        return 0;
    }

    if(dist[N]==INF){
        cout<<"INF"<<"\n";
    }
    else{
        cout<<dist[N]<<"\n";
    }

    return 0;

}