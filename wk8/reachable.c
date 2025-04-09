#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Set.h"

void dfs(Graph g, Vertex v, bool *visited) {
    if (visited[v]) return;

    visited[v] = true;

    for (Vertex w = 0; w < GraphNumVertices(g); w++) {
        if (GraphIsAdjacent(g, v, w)) {
            dfs(g, w, visited);
        }
    }
}

Set reachable(Graph g, Vertex src) {
    bool *visited = calloc(GraphNumVertices(g), sizeof(bool));

    dfs(g, src, visited);

    Set res = SetNew();
    for (Vertex v = 0; v < GraphNumVertices(g); v++) {
        if (visited[v]) {
            SetInsert(res, v);
        }
    }

    free(visited);

    return res;
}
