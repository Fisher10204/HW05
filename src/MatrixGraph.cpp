#include "MatrixGraph.h"
#include <cassert>
//look at graph.h for method descriptions
MatrixGraph::MatrixGraph(unsigned num_nodes){
	num_edges=0;
	M=std::vector<std::vector<EdgeWeight>>(num_nodes);
	for(int i=0; i<num_nodes; ++i){
		M[i]=std::vector<EdgeWeight>(num_nodes);
	}
}

MatrixGraph::~MatrixGraph(){
	//shouldn't need
}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	assert(0<=u && u<M.size() && 0<=v && v<M.size() && u!=v && weight>0);
	//add the edge
	if(M[u][v]==0){
		M[u][v]=weight;
		M[v][u]=weight;
		num_edges++;
	}
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v)const{
	assert(0<=u && u<M.size() && 0<=v && v<M.size() && u!=v);
	if(M[u][v]>0)
		return M[u][v];
	return 0;
}
std::list<NWPair> MatrixGraph::getAdj(NodeID u)const{
	EList neighbors;
	assert(0<=u && u<M.size());
	for(int i=0; i<M[u].size(); ++i)
	{
		if(M[u][i]!=0){
			neighbors.push_back(NWPair(i,M[u][i]));
		}
	}
	return neighbors;
}

unsigned MatrixGraph::degree(NodeID u) const{
	assert(0<=u && u<M.size());
	return getAdj(u).size();
}

unsigned MatrixGraph::size() const{
	return M.size();
}

unsigned MatrixGraph::numEdges() const{
	return num_edges;
}