#include "halos.h"


void haloDistoLine(int x, int y, int r, float startAngle, float endAngle, int steps, float jitter){
	ofPushMatrix();
	ofTranslate(x,y);

	float step = (abs(startAngle)+abs(endAngle))/(float)steps;

	for(float theta = startAngle; theta<endAngle; theta+=step){
		float x_jit = cos(theta)*r+ofRandom(-jitter, jitter);
		float y_jit = sin(theta)*r+ofRandom(-jitter, jitter);
		ofLine(x_jit, y_jit, x_jit+1, y_jit+1);
	}

	ofPopMatrix();
}

void haloDistoLineHC(	int x, int y, int r, float startAngle, float endAngle, 
						int steps, float jitter, int width, int cMin, int cMax){
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(x,y);

	float step = (abs(startAngle)+abs(endAngle))/(float)steps;

	for(float theta = startAngle; theta<endAngle; theta+=step){
		ofSetColor(ofRandom(cMin, cMax));		
		float x_jit = cos(theta)*r+ofRandom(-jitter, jitter);
		float y_jit = sin(theta)*r+ofRandom(-jitter, jitter);
		ofLine(x_jit-width, y_jit, x_jit+width, y_jit);
	}

	ofPopStyle();
	ofPopMatrix();
}

void haloDistoLineV(int x, int y, int r, float startAngle, float endAngle, int steps, float jitter, int width){
	ofPushMatrix();
	ofTranslate(x,y);

	float step = (abs(startAngle)+abs(endAngle))/(float)steps;

	for(float theta = startAngle; theta<endAngle; theta+=step){
		float x_jit = cos(theta)*r+ofRandom(-jitter, jitter);
		float y_jit = sin(theta)*r+ofRandom(-jitter, jitter);
		ofLine(x_jit, y_jit-width, x_jit, y_jit+width);
	}
	ofPopMatrix();
}

void haloDistoLineVC(	int x, int y, int r, float startAngle, float endAngle, 
						int steps, float jitter, int width, int cMin, int cMax){
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(x,y);

	float step = (abs(startAngle)+abs(endAngle))/(float)steps;

	for(float theta = startAngle; theta<endAngle; theta+=step){
		ofSetColor(ofRandom(cMin,cMax));
		float x_jit = cos(theta)*r+ofRandom(-jitter, jitter);
		float y_jit = sin(theta)*r+ofRandom(-jitter, jitter);
		ofLine(x_jit, y_jit-width, x_jit, y_jit+width);
	}

	ofPopStyle();
	ofPopMatrix();
}