#include "../include/Graph.h"

int main() {
    Graph g;

    g.addPath({"A","B","C"});
    g.addPath({"X","B","Y"});
    g.printGraph();

    return 0;
}
