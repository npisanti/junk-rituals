#ifndef _DISTOMETRY_H
#define _DISTOMETRY_H

#include "ofMain.h"
#include "halos.h"
	
	void distoSquares(int x, int y, int s, int n, float jitter);
	//jitter amount is normalized in range 0-1 and is the amount of jitter. 1=full jitter, 0= useless
	
	void distoRects(int x1, int y1, int x2, int y2, int n);
	void distoRectsC(int x1, int y1, int x2, int y2, int n, int cMin, int cMax);
	//starting point / destination point
	
	void distoSquareSwarm(int x, int y, int n, int jitter);
	void distoSquareSwarmH(int x, int y, int n, int jitter, int width);
	void distoSquareSwarmV(int x, int y, int n, int jitter, int width);
	//dots swarm, square shape, jitter is side/2, H/V for horizontal or vertical lines, width!=0
	
	void distoCircleSwarm(int x, int y, int n, int jitter);
	void distoCircleSwarmH(int x, int y, int n, int jitter, int width);
	void distoCircleSwarmV(int x, int y, int n, int jitter, int width);
	//dots swarm, circle shape, jitter is radius, H/V for horizontal or vertical lines, width!=0
	
	void distoGrid(int x1, int y1, int x2, int y2, int n);
	//again, two opposit corners, but what corners is not important this time

	void distoConglomerate(int x, int y, int n, int deviation);
	//some kind of labirynth center on, x/y, deviation is the radius

	void distoPath1(int x1, int y1, int x2, int y2, float check, float jitter);
	void distoPath1horiz(int x1, int y1, int x2, int y2, float check, float jitter);
	void distoPath1vert(int x1, int y1, int x2, int y2, float check, float jitter);
	void distoPath2(int x1, int y1, int x2, int y2, float step);
	void distoPath2horiz(int x1, int y1, int x2, int y2, float step);
	void distoPath2vert(int x1, int y1, int x2, int y2, float step);
	void distoPath3(int x1, int y1, int x2, int y2, int deviation);
	//opposite corners, jitter must be 0-1 (it is not internally controlled)
	
	void distoLine(int x1, int y1, int x2, int y2, float steps, float jitter);
	void distoLineH(int x1, int y1, int x2, int y2, float steps, float jitter, int width);
	void distoLineV(int x1, int y1, int x2, int y2, float steps, float jitter, int width);
	void distoLineHC(int x1, int y1, int x2, int y2, float steps, float jitter, int width, int cMin, int cMax);
	void distoLineVC(int x1, int y1, int x2, int y2, float steps, float jitter, int width, int cMin, int cMax);
	//draw a line with jittery single points, spacing is the distance between successive x coordinates

	void distoTree1(int x1, int y1, int x2, int y2, bool horizontal, int levels);
	void distoTree2(int x1, int y1, int x2, int y2, bool horizontal, int levels);
	//recursive tree, one / two branch, starting with horizontal (or vertical line), levels number

	void distoRectLines(int x1, int y1, int x2, int y2, int n);
	//line starting from x1/y1 and going with a square angle 
	//to a random point in the rectangle included between x1/y1/x2/y2

	/*TODO:
		-class implementation of drawing methods for variable rate update
		-halos / arcs 
		-cellular automata shapes (based on ofImage), ofImage initializers
		-text based shapes
	*/
#endif