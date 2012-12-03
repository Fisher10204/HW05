#include "ListGraph.h"
//needed to use assert statements, as recommended by my tutor Julie Rogers
#include <cassert>
// look at graph.h for method descriptions
ListGraph::ListGraph(int numNodes)
{
	edgeList=std::vector<EList>();
	for (int i = 0; i < numNodes; i++){
		edgeList.push_back(EList(NULL));
	}	
	num_edges=0;
}
ListGraph::~ListGraph()
{
	//Probably not going to use
}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{//Checking pre-conditions with assert statement
	//assert statements don't work well, use if statements
	//assert( 0 <= u && u < edgeList.size() && 0 <= v && v < edgeList.size() && u!=v && weight>0);
	if( 0 <= u && u < edgeList.size() && 0 <= v && v < edgeList.size() && u!=v && weight>0){
		//make sure no edge there already via iterator
		bool dupEdge=false;
		//iterator methodology from in class lecture
		for(EList::const_iterator i = edgeList[u].begin(); i!=edgeList[u].end(); ++i){
			if(i->first == v && i ->second == weight){
				dupEdge=true;
			}
		}
		for(EList::const_iterator i = edgeList[v].begin(); i!=edgeList[v].end(); ++i){
			if(i->first == u && i ->second ==weight){
				dupEdge = true;
			}
		}
		//if this edge wouldn't be a duplicate edge add the edge from u to v and v to u and increase the number of edges by 1
		if(!dupEdge){
			edgeList[v].push_back(NWPair(u, weight));
			edgeList[u].push_back(NWPair(v, weight));
			num_edges++;
		}
	}
}
std::list<NWPair> ListGraph::getAdj(NodeID u)const{
	if(0 <= edgeList.size()){
		return edgeList[u];
	}
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	//assert(0<=u && u < edgeList.size() && 0 <= v && v<edgeList.size());
	if(0<=u && u < edgeList.size() && 0 <= v && v<edgeList.size()){
		for(EList::const_iterator i = edgeList[u].begin(); i != edgeList[u].end(); ++i){
			if(i->first==v){
				return i->second;
			}
		}
	}
	return 0;
}

unsigned ListGraph::degree(NodeID u) const{
	//assert(0 <= u && u<edgeList.size());
	if(0 <= u && u<edgeList.size())
		return getAdj(u).size();
}

unsigned ListGraph::size() const{
	return edgeList.size();
}

unsigned ListGraph::numEdges() const{
	return num_edges;
}