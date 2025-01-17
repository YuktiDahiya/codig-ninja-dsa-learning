/**
 *  Prim's Algorithm:
 *  -   Another way of finding minimum spanning tree (mst).
 * 
 *  Algo:
 *  -   Take 3 arrays : visited[n], weights[n], parents[n] 
 *      -   default weight : INT_MAX, default parent : -1
 *  -   for all the vertices : v {
 *          min = pick the vertex with minimum weight
 *          for each unvisited neighbour of 'min' {
 *              decide where  to update the parent and weight.
 *          }
 *      }
 * 
 *  Time Complexity : O(V^2)
 * 
 *  Optimizations cann be done:
 *  1.  Adjacency List can be used in place of Adjacency Matrix
 *  2.  To find min, rather traversing all vertices, we can use the min priority queue.
 *      Using it - Time Complexity can be made like : (E+V)logV
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int findMinvertex(int* weights, bool* visited, int n){
    int minVertex = -1;
    for(int i=0; i<n; i++){
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void primsMST(int** edges, int n){
    bool* visited = new bool[n];
    int* parent = new int[n];
    int* weights = new int[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    parent[0] = -1;
    weights[0] = 0;

    for(int i=0; i<n; i++){
        // find min vertex
        int m = findMinvertex(weights, visited, n);
        visited[m] = true;
        // explore unvisited vertex neighbours
        for(int j=0; j<n; j++){
            if(!visited[j] && edges[m][j] != 0 && edges[m][j] < weights[j]){
                weights[j] = edges[m][j];
                parent[j] = m;
            }
        }
    }
    for(int i=1; i<n; i++){
        if(parent[i] < i){
            cout << parent[i] << " " << i <<  " " << weights[i] << endl;
        } else {
            cout << i <<  " " << parent[i] << " " << weights[i] << endl;
        }
    }
}

int main(){
    int v, e;
    cin >> v >> e;
    int** edges = new int*[v];
    for(int i=0; i<v; i++){
        edges[i] = new int[v];
        for(int j=0; j<v; j++){
            edges[i][j] = 0;
        }
    }
    for(int k=0; k<e; k++){
        int sv, lv, w;
        cin >> sv >> lv >> w;
        edges[sv][lv] = edges[lv][sv] =w; 
    }
    primsMST(edges, v);

    for(int i=0; i<v; i++){
        delete [] edges[i];
    }
    delete [] edges;
}