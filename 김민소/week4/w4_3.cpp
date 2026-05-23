#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF=1e9;

struct Edge{
    int from;
    int to;
    double cost;
};

int main(){
    int N,M;
    cin>>N>>M;

    vector<Edge> edges;

    for(int i=0; i<M; i++){
        int u,v;
        double r;
        cin>>u,v,r;
        r=-log(r);
        edges.push_back({u,v,r});
    }

    vector<int> dist(N+1,INF);
    dist[1]=0;

    for(int i=1; i<N-1; i++){
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
        cout<<"-1"<<"\n";
        return 0;
    }

    for(int d:dist){
        if(d==INF){
            cout<<"INF"<<"\n";
        }
        else{
            cout<<"d"<<"\n";
        }
    }

    return 0;

}