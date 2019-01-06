#pragma once

#include "ofMain.h"
#define ARDUINO_LEN 6
#define ARDUINO_STRING 7

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		char		bytesRead[ARDUINO_LEN];						// data from serial, we will be trying to bytesRead it
		char		bytesReadString[ARDUINO_STRING];			// a string needs a null terminator, so we need one more
		ofSerial	serial;


};
