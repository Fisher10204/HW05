#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
//copied from Controller.cpp
#include <assert.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <MMSystem.h>

#include "StarbucksMap.h"
#include "Tester.h"
#include "MatrixGraph.h"
#include "ListGraph.h"
#include "GraphAlgs.h"

#pragma comment (lib, "winmm.lib")

using namespace ci;
using namespace ci::app;
using namespace std;

class HW05App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};
//copied from Controller.cpp
Graph* createStarbucksGraph(vector<Store> storeList, bool use_matrix) {
  Graph* G;
  if (use_matrix)
    G = new MatrixGraph(storeList.size());
  else
    G = new ListGraph(storeList.size());

  for (NodeID u=0; u < G->size()-1; u++)
    for (NodeID v = u+1; v < G->size(); v++)
      G->addEdge(u, v, dist(storeList[u], storeList[v]));

  return G;
}

void deleteStarbucksGraph(Graph* G, bool use_matrix) {
  if (use_matrix)
    delete (MatrixGraph*)G;
  else
    delete (ListGraph*)G;
}

/********************************
   * The following section is commented out so you can test your graph code
	* before you have written your TSP code.  Once you are ready to test your
	* TSP code, remove the comments (along with the comments taking out 
	* a portion of the main function, below).
	********************************/
//void testSingleTSP(StarbucksMap& SB, int size, bool use_matrix) {
//  vector<Store> R = SB.randomSet(size);
//  Graph* G = createStarbucksGraph(R, use_matrix);
//  pair<vector<NodeID>, EdgeWeight> p = TSP(G);
//
//  EdgeWeight actual = 0;
//  for (int i=0; i < size-1; i++)
//    actual += G->weight(p.first[i], p.first[i+1]);
//  actual += G->weight(p.first[size-1], p.first[0]);
//
//  console() << "Best cycle length: " << p.second << " ";
//  if (fabs(p.second - actual) > 0.00000001)
//    console() << "(ERROR -- the length returned is not equal to the actual length)";
//  else
//    console() << "(Path length matches)" << endl;
//  console() << "\n\n";
//  for (int i=0; i < size; i++)
//    console() << R[p.first[i]] << "\n";
//  deleteStarbucksGraph(G, use_matrix);
//}
//
//pair<int,int> testSpeedTSP(StarbucksMap& SB, double time_limit, bool use_matrix) {
//	int n = 3;
//	int totalTime = 0;
//	while (true) {
//		  vector<Store> R = SB.randomSet(n);
//		  Graph* G = createStarbucksGraph(R, use_matrix);
//
//		  int startTime = timeGetTime();
//		  pair<vector<NodeID>, EdgeWeight> p = TSP(G);
//		  int newTime = timeGetTime() - startTime;
//		  console() << "TSP Speed: Finished " << n << " cities in " << newTime/1000.0 << " seconds." << endl;
//		  if (newTime/1000.0 > time_limit)
//			  break;
//		  totalTime = newTime;
//		  n++;
//	}
//	return make_pair(n,totalTime);
//}

void HW05App::setup()
{
	int n = 5;

  srand(1);

  // Apply each of the Tester methods to your MatrixGraph class.
  Tester T1(true);
  T1.test_all();

  console() << endl;

  // Apply each of the Tester methods to your ListGraph class.
  Tester T2(false);
  T2.test_all();

  /********************************
   * The following section is commented out so you can test your graph code
	* before you have written your TSP code.  Once you are ready to test your
	* TSP code, remove the comments (along with the comments taking out 
	* testSingleTSP and testSpeedTSP, above).
	********************************/
  //// Read in Starbucks Locations, test your TSP algorithm on a random MatrixGraph 
  //// of size n, and test your TSP algorithm on a random ListGraph of size n.

  //// Uncomment the following three lines once your TSP function has been written
  //StarbucksMap SB;

  //testSingleTSP(SB, 5, true);
  //testSingleTSP(SB, 5, false);

  //pair<int,int> p = testSpeedTSP(SB, 60, true);

  //return 0;
}

void HW05App::mouseDown( MouseEvent event )
{
}

void HW05App::update()
{
}

void HW05App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW05App, RendererGl )
