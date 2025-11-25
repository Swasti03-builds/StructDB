#include "../include/Graph.h"

int main() {
    Graph g;

    g.addPathFromCSV("src/data.csv");

    vector<string> shortest = g.shortestPath("cs", "automata");

    
    cout << "Shortest path from cs to automata:\n";
    for (const string& node : shortest) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
