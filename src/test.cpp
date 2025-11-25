#include "../include/MaxHeap.h"
#include <iostream>
using namespace std;

int main() {
    MaxHeap mh;

    // Simulate topic access
    mh.accessTopic("Graph");
    mh.accessTopic("DFS");
    mh.accessTopic("Graph");
    mh.accessTopic("AVL Tree");
    mh.accessTopic("DFS");
    mh.accessTopic("Graph");

    // Display top 5 most accessed topics
    auto top = mh.getTopN(5);
    cout << "\n Top 5 Most Viewed Topics:\n";
    for (auto &p : top) {
        cout << p.first << " -> accessed " << p.second << " times\n";
    }

    // Also print raw heap structure
    mh.printHeap();

    return 0;
}
