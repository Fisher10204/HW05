#include "GraphAlgs.h"

int* fastestTour;
std::vector<NodeID> fastestTourID;
double fastestLength=0.0;


EdgeWeight totalLength(int* inputTour, Graph* G){
	EdgeWeight lengthOfTour=0;
	for(int i=0; i<G->size()-1; ++i){
		lengthOfTour+=G->weight(inputTour[i], inputTour[i+1]);
		//add the length from the first node to the last node only once
		if(i==0)
			lengthOfTour+=G->weight(inputTour[0],inputTour[G->size()-1]);
	}
	return lengthOfTour;
}

void swap(int* arr, int index1, int index2){
	int temp=arr[index1];
	arr[index1]=arr[index2];
	arr[index2]=temp;
}

void tour(int* arr, int p, int startingIndex, Graph* G){
	int size= G->size();
	if((p-startingIndex)==1){

		double newLength=totalLength(arr,G);

		if(newLength<fastestLength){

			fastestLength=newLength;

			for(int i=0; i<size; ++i){
				fastestTourID[i]=arr[i];
			}
		}
	}
	else{
		for(int i=startingIndex; i<p; ++i){
			swap(arr,startingIndex,i);
			tour(arr,p,startingIndex+1,G);
			swap(arr,startingIndex,i);
		}
	}
}

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G) {
	int size= G->size();
	fastestTour = new int[size];
	
	for(int i=0; i<size; ++i){
		fastestTour[i]=i;
		fastestTourID.push_back(i);
	}
	fastestLength=totalLength(fastestTour,G);
	tour(fastestTour, size, 1, G);

	std::pair<std::vector<NodeID>,EdgeWeight> finalSolution (fastestTourID, fastestLength);
	return finalSolution;
}