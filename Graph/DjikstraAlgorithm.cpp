//using set
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int>distance(vertices);
    for(int i=0;i<vertices;i++)
        distance[i]=INT_MAX;
        
    set<pair<int,int>>s;
    s.insert(make_pair(0,source));
    distance[source]=0;

    while(!s.empty()){
        auto top=*(s.begin());
        int NodeDistance=top.first;
        int Node=top.second;
        s.erase(s.begin());
        for(auto neighbour:adj[Node]){
            if(NodeDistance+neighbour.second<distance[neighbour.first]){
                auto record=s.find(make_pair(distance[neighbour.first],neighbour.first));
                if(record!=s.end()){
                    s.erase(record);
                }
                distance[neighbour.first]=NodeDistance+neighbour.second;
                s.insert(make_pair(distance[neighbour.first],neighbour.first));
            }
        }
    }
    return distance;

}
