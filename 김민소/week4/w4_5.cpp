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
    int F;
    cin>>F;
    for(int c=0; c<F; c++){
        int N,M,B;
        cin>>N>>M,B;

        vector<Edge> edges;

        for(int i=0; i<M; i++){
            int u,v,w;
            cin>>u>>v>>w;

            edges.push_back({u,v,w});
            edges.push_back({v,u,w});
        }

        for(int i=0; i<B; i++){
            int u,v,w;
            cin>>u>>v>>w;

            edges.push_back({u,v,-w});
        }

        int start;
        cin>>start;

        vector<int> dist(N+1,INF);

        dist[start]=0;

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

        for(int d:dist){
            if(d<0){
                cout<<"YES"<<"\n";
                break;
            }
        }
        cout<<"NO"<<"\n";

    return 0;

}