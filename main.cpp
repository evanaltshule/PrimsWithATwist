#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "prim.h"

int main(int argc, char* argv[]) {
  // parse the expected input
  // first, the number of nodes for the complete graph part
  int num_nodes;
  std::cin >> num_nodes;

  // second, read in the complete graph
  std::vector< std::vector<int> > graph;
  for(int i=0; i<num_nodes; ++i) {
    std::vector<int> row;
    for (int j=0; j<num_nodes; ++j) {
      int cost;
      std::cin >> cost;
      row.push_back(cost);
    }
    graph.push_back(row);
  }

  prim prims(num_nodes);
  prims.primMST(graph);


  // last bit until newline from last cin followed by a blank line
  std::string skip;
  std::getline(std::cin, skip);
  std::getline(std::cin, skip);

  // // // read in the new edges
  // // // parse input lines until I find newline
  prims.printFirstMST();
  prims.primMST2(graph, prims.getKey(), prims.getMstSet(), prims.getParent());
  prims.printSecondMST();
  return 0;
}