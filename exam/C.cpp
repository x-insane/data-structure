#include <iostream>
using namespace std;

class Graph {
public:
    Graph(int N) {
        for (int i=1;i<=N;++i)
        	for (int j=1;j<=N;++j)
        		map[i][j] = false;
        this->N = N;
    }
    void add_edge(int v1, int v2) {
        map[v1][v2] = map[v2][v1] = true;
    }
    unsigned int num_connected_components() {
        unsigned int num = 0;
        bool mark[1001];
        for (int i=1;i<=N;++i)
        	mark[i] = false;
        for (int i=1;i<=N;++i) {
        	if (mark[i])
        		continue;
        	DFS(i, mark);
        	num ++;
		}
		return num;
    }
    int N;
    bool map[1001][1001];
    void DFS(int i, bool* mark) {
    	mark[i] = true;
    	for (int j=1;j<=N;++j) {
    		if (map[i][j] && !mark[j])
    			DFS(j, mark);
		}
	}
};

int main() {
    int M;
    cin >> M;
    while (M--) {
        int N, C;
        cin >> N >> C;
        Graph graph(N);
        for(int i=0;i<C;i++) {
            int v1, v2;
            cin>>v1>>v2;
            graph.add_edge(v1, v2);
        }
        cout << graph.num_connected_components() << endl;
    }
    return 0;
}