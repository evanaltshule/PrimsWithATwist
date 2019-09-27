#include "prim.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

prim::prim(int num_nodes){
	this->num_nodes = num_nodes;
	this->mstSet.assign(num_nodes, false);
	this->parent.assign(num_nodes, 0);
	for (int i = 0; i < num_nodes; i++){  
    	this->key.push_back(INT_MAX);
    }
}

int prim::minKey(std::vector<int> key, std::vector<bool> mstSet){
	// Initialize min value  
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < num_nodes; v++) { 
        if (mstSet.at(v) == false && key.at(v) < min){
            min = key.at(v), min_index = v;  
        }
  	}
    return min_index;  
}

int prim::printFirstMST(){
	for(int a = 1; a < parentTrack.size(); a++){
    	std::cout << parentTrack.at(a) << " " << destination.at(a) << std::endl; 
    }
    std::cout << std::endl;
}

int prim::printSecondMST(){
	for(int a = 1; a < num_nodes; a++){
		std::cout << parentTrack.at(a) << " " << destination.at(a) << std::endl;
	}
}

void prim::primMST(std::vector< std::vector<int> > graph){
    key[0] = 0;  
    parent[0] = -1; // First node is always root of MST
    // The MST will have V vertices  
    for (int count = 0; count < (num_nodes)/2; count++) 
    {  
        int u = minKey(key, mstSet);  

        mstSet[u] = true;  
        parentTrack.push_back(parent[u]);
        destination.push_back(u);
        for (int v = 0; v < num_nodes; v++)  {
            if ((graph.at(u)).at(v) && mstSet.at(v) == false && (graph.at(u)).at(v) < key.at(v))  {
                parent[v] = u, key[v] = (graph.at(u)).at(v); 
            }
        }
    }  
    
}

void prim::primMST2(std::vector< std::vector<int> > graph, std::vector<int> key, std::vector<bool> mstSet, std::vector<int> parent){
    for(std::string line; std::getline(std::cin, line) && line.compare(""); ) {
    std::stringstream ss(line);
    int from;
    int to;
    int cost;
    ss >> from;
    ss >> to;
    ss >> cost;

    graph[to][from] = graph[from][to] = cost;
    if(mstSet.at(to) == true && mstSet.at(from) == false){
        if(key.at(from) > cost){
          key[from] = cost;
          parent[from] = to;
        }
        else if(parent[from] == to){
        	int min = INT_MAX;
        	for(int i = 0; i < key.size(); ++i){
        		if(mstSet[i] && graph[from][i] < min){
        			min = graph[from][i];
        			parent[from] = i;
        			key[from] = min;
        		}
        	}
        }
    }
    if(mstSet.at(from) == true && mstSet.at(to) == false){
    	if(key.at(to) > cost){
          key[to] = cost;
          parent[to] = from;
      }
      	else if(parent[to] == from){
        	int min = INT_MAX;
        	for(int i = 0; i < key.size(); ++i){
        		if(mstSet[i] && graph[to][i] < min){
        			min = graph[to][i];
        			parent[to] = i;
        			key[to] = min;
        		}
        	}
        }
    }
  }
    for (int count = (num_nodes)/2; count < num_nodes; count++) 
    {  
        int u = minKey(key, mstSet);  
        mstSet[u] = true;  

        for (int v = 0; v < num_nodes; v++) { 

            if ((graph.at(u)).at(v) && mstSet.at(v) == false && (graph.at(u)).at(v) < key.at(v)) { 
                parent[v] = u, key[v] = (graph.at(u)).at(v);  
            }
        }
        parentTrack.push_back(parent[u]);
       	destination.push_back(u);
    }  
  

    
}