/**
* @file main.cpp
* @brief This is a test of CMake, doxygen, and GitHub.
* @details This is the long brief at the top of main.cpp.
* @author Bona Tufa
* @date 4/7/2021
*
*/

#include <iostream>
#include <vector>
using namespace std;
class graph {
public:
   int B;   
   int TheMatrix[7][7] = {0};
 
   graph(int input) {
       B = input;
   }
 
void addEdge(int O, int E) {
   TheMatrix[O][E] = true;
}
void removeEdge(int O, int E) {
   TheMatrix[O][E] = false;
}
bool hasEdge(int O, int j) {
return TheMatrix[O][j];
}
void displayM() {
   for(int O = 0; O < B; O++) {
       for(int E = 0; E < B; E++) {
           cout << TheMatrix[O][E];
       }
       cout << endl;
   }
}    
 
void outEdges(int O, vector<int> &edges) {
   for (int E = 0; E < B; E++)
       if (TheMatrix[E][O]) edges.push_back(E);
}
void inEdges(int O, vector<int> &edges) {
   for (int E = 0; E < B; E++)
       if (TheMatrix[O][E]) edges.push_back(E);
}
int nVertices(){
   return B * B;
}
 
 
void dfs2(graph &g, int r) {
   bool *f = new bool[g.nVertices()];
   vector<int> s;
   s.push_back(r);
   while (s.size() > 0) {
       int O = s.back();
       cout << endl << " > " << "This is DFS" << endl;
       s.pop_back();
       if (f[O] == *f) {
           f[O] = f;
           vector<int> edges;
           g.outEdges(O, edges);
           for (int k = 0; k < edges.size(); k++)
               s.push_back(edges[k]);
   }
   }
   delete[] f;
}
//Extra credit
 
void bfs(graph &g, int r) {
   bool *seen = new bool[g.nVertices()];
   vector<int> q;
   q.push_back(r);
   seen[r] = true;
   while (q.size() > 0) {
       int O = q.back();
       cout << endl << O << " > " << "This is BFS" << endl;
       q.pop_back();
       vector<int> edges;
       g.outEdges(O, edges);
       for (int k = 0; k < edges.size(); k++) {
           int E = edges[k];
           if (!seen[E]) {
               q.push_back(E);
               seen[E] = true;
   }
}
}
delete[] seen;
}
};
int main(int, char**) {
   graph value(7);
   value.addEdge(3,0);
   value.addEdge(6,3);
   value.displayM();
   value.bfs(value, 1);
   value.removeEdge(4,4);
   value.displayM();
   value.addEdge(1,2);
   value.addEdge(2,4);
   value.hasEdge(1,2);
   value.dfs2(value, 3);
   value.displayM();
  //value.dfs2(value, 3);
 
}
 
