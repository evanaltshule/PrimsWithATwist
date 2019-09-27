#ifndef PRIM_H
#define PRIM_H
#include <vector>
class prim{
public:
	prim(int num_nodes);
	int minKey(std::vector<int> key, std::vector<bool> mstSet);
	int printFirstMST();
	int printSecondMST();
	void primMST(std::vector< std::vector<int> > graph);
	void primMST2(std::vector< std::vector<int> > graph, std::vector<int> key, std::vector<bool> mstSet, std::vector<int> parent);
	std::vector<bool> getMstSet(){
		return mstSet;
	}
	std::vector<int> getParent(){
		return parent;
	}
	std::vector<int> getKey(){
		return key;
	}
private:
	int num_nodes;
	std::vector<int> parentTrack;
	std::vector<int> destination; 
	std::vector<int> keyTrack;
	std::vector<bool> mstSet;
	std::vector<int> parent; 
	std::vector<int> key;  
};
#endif