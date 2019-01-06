#ifndef _DISTO_HALOS_H
#define _DISTO_HALOS_H

#include "ofMain.h"
#include "distometry.h"


void haloDistoLine(int x, int y, int r, float startAngle, float endAngle, int steps, float jitter);
void haloDistoLineHC(int x, int y, int r, float startAngle, float endAngle, int steps, float jitter, int width, int cMin, int cMax);
void haloDistoLineV(int x, int y, int r, float startAngle, float endAngle, int steps, float jitter, int width);
void haloDistoLineVC(int x, int y, int r, float startAngle, float endAngle, int steps, float jitter, int width, int cMin, int cMax);
	//arc of jittered points


#endif