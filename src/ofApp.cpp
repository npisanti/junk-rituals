#include "ofApp.h"
#include "distometry.h"
#define HYSTERESIS 1.2
//lower number are greater hysteresis 

bool align;
int piezo_now;
int piezo_last_trigger;
int piezo_bang;
int lastTrigger;

float vibration;

int sides=16;
int inner=150;
float separation = 50;

//int outer = (int)inner*1.25;
int sqr = inner/3;
float step=TWO_PI/sides;

//--------------------------------------------------------------
void ofApp::setup(){


	ofSetFrameRate(30);
	ofHideCursor();

	align = false;
	serial.setup("/dev/ttyACM0", 9600); //linux example
	memset(bytesReadString, 0, ARDUINO_STRING);

	piezo_now=0;
	piezo_bang=0;
	lastTrigger=0;
	vibration = 0.0;
}


//--------------------------------------------------------------
void ofApp::update(){
	
	if(!align && ofGetFrameNum()>150){
		while(!align){
			char test = serial.readByte();
			if(test=='.') align=true;
		}

	}


	unsigned char bytesReturned[ARDUINO_LEN];
	memset(bytesReadString, 0, ARDUINO_STRING);
	memset(bytesReturned, 0, ARDUINO_LEN);
	if(serial.available()>=ARDUINO_LEN){	

		serial.readBytes( bytesReturned, ARDUINO_LEN);
		memcpy(bytesReadString, bytesReturned, ARDUINO_LEN);

		if(align){		//parsing
			string parsing = ofToString(bytesReadString);
			piezo_now = ofToInt(parsing.substr(0,3));
			piezo_bang = ofToInt(parsing.substr(4,1));
		}
	}

	/*
	if(piezo_bang==1){
		if(piezo_now > piezo_last_trigger-(ofGetFrameNum()-lastTrigger)*HYSTERESIS){
				lastTrigger=ofGetFrameNum();
				piezo_last_trigger = piezo_now;
		}
		//and now restore some pulsing variable here
	}

	//NOW MAP THE VALUES
	*/

	vibration = ofMap(piezo_now, 12.0, 40.0, 0.0, 1.0, true);

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofNoFill();
	ofSetColor(255);
	
	if(align){
		ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
	
		distoConglomerate(0,0, 20, sqr*vibration);
		//distoTree2(-sqr, -sqr, sqr, sqr, ofRandom(1)<0.5, 6);
		ofFill();
		ofSetColor(0);
		ofRect(-6, -6, 12, 12);
		ofNoFill();
		ofSetColor(255);

		haloDistoLineVC(0,0, (int)inner*0.7, 0, TWO_PI, 90, 3, 4, 255*vibration, 255);
		//haloDistoLineVr(0,0, inner+60, 0, TWO_PI, 90, 3, 3);
		
		float start = -HALF_PI;//+step/2;
		float limit = TWO_PI+start;
		for(float theta = start; theta<limit; theta+=step ){
			//distoSquares(cos(theta)*inner,sin(theta)*inner, 20, 4, 0.6);
			//distoRects(cos(theta)*inner,sin(theta)*inner, cos(theta)*outer,sin(theta)*outer, 4);
			distoRectLines(cos(theta)*inner,sin(theta)*inner, cos(theta)*(inner+vibration*separation),sin(theta)*(inner+vibration*separation), 4);
		}

	}else{

		string msg;
		msg+="aligning input stream";
		for(int i=0; i<ofGetFrameNum()/ARDUINO_LEN; i++){
			msg+=".";
		}
		ofDrawBitmapString(msg, 50, 100);
	}
	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
