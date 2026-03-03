// This method is used to find the shortest distance possible to reach every node from source node in a graph
// It works only when cost of every node is 1 (equal) 
vector<int> shortestReach(int n, vector<vector<int>> l, int s) {
        map<int,vector<pair<int,int>>>m;
        for(auto temp : l) {
            m[temp[0]].push_back({temp[1],temp[2]});
            m[temp[1]].push_back({temp[0],temp[2]});
        }
        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int,int>>q;
        q.push({s,0});
        dis[s]=0;
        while(!q.empty()) {
            pair<int,int>p = q.top();
            q.pop();
            for(auto adj : m[p.first]) {
                int node=adj.first;
                int weight=adj.second;
                if((p.second+weight)<dis[node]) {
                    dis[node]=p.second+weight;
                    q.push({node,p.second+weight});
                }
            }
        }
        //adjusting non-reachable paths distance as -1
        for(int i=0;i<dis.size();i++) if(dis[i]==INT_MAX) dis[i]=-1;
        return dis;
}
