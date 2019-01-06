#include "distometry.h"

void distoSquares(int x, int y, int s, int n, float jitter){
	ofPushStyle();
	ofSetRectMode(OF_RECTMODE_CORNER);

	float side = s*(1-jitter);
	float jitSide = s*jitter/2;
	float halfSide = side/2;

	for (int i=0; i<n; i++){
		ofRect(x+ofRandom(-jitSide, jitSide)-halfSide, y+ofRandom(-jitSide, jitSide)-halfSide, side, side);
	}

	ofPopStyle();
}	

void distoRects(int x1, int y1, int x2, int y2, int n){
	ofPushStyle();
	ofSetRectMode(OF_RECTMODE_CORNER);	

	float w = x2-x1;
	float h = y1-y2;

	for (int i=0; i<n; i++){
		float rnd_x = w*ofRandom(1);
		float rnd_y = h*ofRandom(1);

		ofRect(x1, y1-rnd_y, rnd_x, rnd_y);
	}
	ofPopStyle();
}

void distoRectsC(int x1, int y1, int x2, int y2, int n, int cMin, int cMax){
	ofPushStyle();
	ofSetRectMode(OF_RECTMODE_CORNER);	

	float w = x2-x1;
	float h = y1-y2;

	for (int i=0; i<n; i++){
		float rnd_x = w*ofRandom(1);
		float rnd_y = h*ofRandom(1);
		ofSetColor(ofRandom(cMin, cMax));
		ofRect(x1, y1-rnd_y, rnd_x, rnd_y);
	}
	ofPopStyle();
}


void distoSquareSwarm(int x, int y, int n, int jitter){
	for (int i=0; i<n; i++){
		int x_fix = (int) x+ofRandom(-jitter, jitter);
		int y_fix = (int) y+ofRandom(-jitter, jitter);
		ofLine(x_fix, y_fix, x_fix+1, y_fix+1);
	}
}

void distoSquareSwarmH(int x, int y, int n, int jitter, int width){
	int jitter_fixed = jitter-width+1;
	for (int i=0; i<n; i++){
		int x_fix = (int) x+ofRandom(-jitter_fixed, jitter_fixed);
		int y_fix = (int) y+ofRandom(-jitter_fixed, jitter_fixed);
		ofLine(x_fix-width, y_fix, x_fix+width, y_fix);
	}
}

void distoSquareSwarmV(int x, int y, int n, int jitter, int width){
	int jitter_fixed = jitter-width+1;
	for (int i=0; i<n; i++){
		int x_fix = (int) x+ofRandom(-jitter_fixed, jitter_fixed);
		int y_fix = (int) y+ofRandom(-jitter_fixed, jitter_fixed);
		ofLine(x_fix, y_fix-width, x_fix, y_fix+width);
	}
}

void distoCircleSwarm(int x, int y, int n, int jitter){
	ofPushMatrix();
	ofTranslate(x,y);
	for (int i=0; i<n; i++){
		float angle = ofRandom(TWO_PI);
		float x_fix = cos(angle)*ofRandom(jitter);
		float y_fix = sin(angle)*ofRandom(jitter);
		ofLine(x_fix, y_fix, x_fix+1, y_fix+1);
	}
	ofPopMatrix();
}

void distoCircleSwarmH(int x, int y, int n, int jitter, int width){
	ofPushMatrix();
	ofTranslate(x,y);
	for (int i=0; i<n; i++){
		float angle = ofRandom(TWO_PI);
		float x_fix = cos(angle)*ofRandom(jitter);
		float y_fix = sin(angle)*ofRandom(jitter);
		ofLine(x_fix-width, y_fix, x_fix+width, y_fix);
	}
	ofPopMatrix();
}

void distoCircleSwarmV(int x, int y, int n, int jitter, int width){
	ofPushMatrix();
	ofTranslate(x,y);
	for (int i=0; i<n; i++){
		float angle = ofRandom(TWO_PI);
		float x_fix = cos(angle)*ofRandom(jitter);
		float y_fix = sin(angle)*ofRandom(jitter);
		ofLine(x_fix, y_fix-width, x_fix, y_fix+width);
	}
	ofPopMatrix();
}

void distoGrid(int x1, int y1, int x2, int y2, int n){
	for(int i=0; i<n; i++){
		if(ofRandom(1)<0.5){
			float x_fix = ofRandom(x1,x2);
			ofLine(x_fix, ofRandom(y1,y2), x_fix, ofRandom(y1,y2));
		}else{
			float y_fix = ofRandom(y1,y2);
			ofLine(ofRandom(x1,x2), y_fix , ofRandom(x1,x2), y_fix);
		}
	}
}

void distoConglomerate(int x, int y, int n, int deviation){
	float x_now=x;
	float y_now=y;
	
	bool horiz;
	if(ofRandom(1)<0.5){horiz=true;}else{horiz=false;}

	for(int i=0; i<n; i++){
	
		float step_x;
		float x_next;
		float step_y;
		float y_next;
		if((x-x_now)>=0){		
			step_x = ofRandom(deviation);
			x_next = x_now+step_x;
			if((y-y_now)>0){	//the center is to the left up
				step_y=ofRandom(deviation);
				y_next = y_now+step_y;
				if(horiz){
					ofLine(x_now, y_now, x_next, y_now);
					ofLine(x_next, y_now, x_next, y_next);
				}else{
					ofLine(x_now, y_now, x_now, y_next);
					ofLine(x_now, y_next, x_next, y_next);				
				}
				x_now=x_next;
				y_now=y_next;
			}else{				//the center is to the left down
				step_y=ofRandom(-deviation);
				y_next = y_now+step_y;
				if(horiz){
					ofLine(x_now, y_now, x_next, y_now);
					ofLine(x_next, y_now, x_next, y_next);
				}else{
					ofLine(x_now, y_now, x_now, y_next);
					ofLine(x_now, y_next, x_next, y_next);				
				}
				x_now=x_next;
				y_now=y_next;
			}
		
		}else{					
			step_x = ofRandom(-deviation);
			x_next = x_now+step_x;
			if((y-y_now)>0){	//the center is to the right up
				step_y=ofRandom(deviation);
				y_next = y_now+step_y;

				if(horiz){
					ofLine(x_now, y_now, x_next, y_now);
					ofLine(x_next, y_now, x_next, y_next);
				}else{
					ofLine(x_now, y_now, x_now, y_next);
					ofLine(x_now, y_next, x_next, y_next);				
				}
				x_now=x_next;
				y_now=y_next;
			}else{				//the center is to the right down
				step_y=ofRandom(-deviation);
				y_next = y_now+step_y;

				if(horiz){
					ofLine(x_now, y_now, x_next, y_now);
					ofLine(x_next, y_now, x_next, y_next);
				}else{
					ofLine(x_now, y_now, x_now, y_next);
					ofLine(x_now, y_next, x_next, y_next);				
				}
				x_now=x_next;
				y_now=y_next;
			}
		}
	}//end for() cycle

	int off; if (horiz) { off = 0;} else { off = 1;}
	if((n+off)%2==0){
		//closing from horizontal
		ofLine(x_now, y_now, x, y_now);
		ofLine(x, y_now, x, y);
	}else{
		//closing from vertical
		ofLine(x_now, y_now, x_now, y);
		ofLine(x_now, y, x, y);
	}

}




void distoPath1(int x1, int y1, int x2, int y2, float check, float jitter){
	float x_now=x1;
	float y_now=y1;
	float x_left=x2-x1;
	float y_left=y2-y1;
	float stepDist = ofDist(x1,y1,x2,y2)/check;

	bool horiz;
	if(ofRandom(1)<0.5){horiz=true;}else{horiz=false;}

	do{
		if(horiz){
			float step_x = x_left*ofRandom(jitter);
			ofLine(x_now, y_now, x_now+step_x, y_now);
			x_now+=step_x;
			x_left-=step_x;
			horiz=false;
		}else{
			float step_y = y_left*ofRandom(jitter);
			ofLine(x_now, y_now, x_now, y_now+step_y);
			y_now+=step_y;
			y_left-=step_y;	
			horiz=true;
		}
	}while(ofDist(x_now, y_now, x2, y2)>stepDist);	
	
	if(horiz){
		ofLine(x_now, y_now, x2, y_now);
		ofLine(x2, y_now, x2, y2);
				
	}else{
		ofLine(x_now, y_now, x_now, y2);
		ofLine(x_now, y2, x2, y2);
	}
}

void distoPath1horiz(int x1, int y1, int x2, int y2, float check, float jitter){
	float x_now=x1;
	float y_now=y1;
	float x_left=x2-x1;
	float y_left=y2-y1;
	float stepDist = ofDist(x1,y1,x2,y2)/check;

	bool horiz;
	if(ofRandom(1)<0.5){horiz=true;}else{horiz=false;}

	do{
		if(horiz){
			float step_x = x_left*ofRandom(jitter);
			ofLine(x_now, y_now, x_now+step_x, y_now);
			x_now+=step_x;
			x_left-=step_x;
			horiz=false;
		}else{
			float step_y = y_left*ofRandom(jitter);
			y_now+=step_y;
			y_left-=step_y;	
			horiz=true;
		}
	}while(ofDist(x_now, y_now, x2, y2)>stepDist);	
	
	if(horiz){
		ofLine(x_now, y_now, x2, y_now);
				
	}else{
		ofLine(x_now, y2, x2, y2);
	}
}

void distoPath1vert(int x1, int y1, int x2, int y2, float check, float jitter){
	float x_now=x1;
	float y_now=y1;
	float x_left=x2-x1;
	float y_left=y2-y1;
	float stepDist = ofDist(x1,y1,x2,y2)/check;

	bool horiz;
	if(ofRandom(1)<0.5){horiz=true;}else{horiz=false;}

	do{
		if(horiz){
			float step_x = x_left*ofRandom(jitter);
			x_now+=step_x;
			x_left-=step_x;
			horiz=false;
		}else{
			float step_y = y_left*ofRandom(jitter);
			ofLine(x_now, y_now, x_now, y_now+step_y);
			y_now+=step_y;
			y_left-=step_y;	
			horiz=true;
		}
	}while(ofDist(x_now, y_now, x2, y2)>stepDist);	
	
	if(horiz){
		ofLine(x2, y_now, x2, y2);
				
	}else{
		ofLine(x_now, y_now, x_now, y2);
	}
}

void distoPath2(int x1, int y1, int x2, int y2, float step){
	float x_now=x1;
	float y_now=y1;
	float x_left=x2-x1;
	float y_left=y2-y1;
	float step_x_rnd = x_left/step;
	float step_y_rnd = y_left/step;
	
	bool horiz;
	if(ofRandom(1)<0.5){horiz=true;}else{horiz=false;}

	while(abs(x2-x_now)>abs(step_x_rnd) && abs(y2-y_now)>abs(step_y_rnd)){
		if(horiz){
			float step_x = ofRandom(step_x_rnd);
			ofLine(x_now, y_now, x_now+step_x, y_now);
			x_now+=step_x;
			x_left-=step_x;
			horiz=false;
		}else{
			float step_y = ofRandom(step_y_rnd);
			ofLine(x_now, y_now, x_now, y_now+step_y);
			y_now+=step_y;
			y_left-=step_y;	
			horiz=true;
		}
	}	
	
	if(horiz){
		ofLine(x_now, y_now, x2, y_now);
		ofLine(x2, y_now, x2, y2);
				
	}else{
		ofLine(x_now, y_now, x_now, y2);
		ofLine(x_now, y2, x2, y2);
	}
}

void distoPath2horiz(int x1, int y1, int x2, int y2, float step){
	float x_now=x1;
	float y_now=y1;
	float x_left=x2-x1;
	float y_left=y2-y1;
	float step_x_rnd = x_left/step;
	float step_y_rnd = y_left/step;
	
	bool horiz;
	if(ofRandom(1)<0.5){horiz=true;}else{horiz=false;}

	while(abs(x2-x_now)>abs(step_x_rnd) && abs(y2-y_now)>abs(step_y_rnd)){
		if(horiz){
			float step_x = ofRandom(step_x_rnd);
			ofLine(x_now, y_now, x_now+step_x, y_now);
			x_now+=step_x;
			x_left-=step_x;
			horiz=false;
		}else{
			float step_y = ofRandom(step_y_rnd);
			y_now+=step_y;
			y_left-=step_y;	
			horiz=true;
		}
	}	
	
	if(horiz){
		ofLine(x_now, y_now, x2, y_now);
	}else{
		ofLine(x_now, y2, x2, y2);
	}
}

void distoPath2vert(int x1, int y1, int x2, int y2, float step){
	float x_now=x1;
	float y_now=y1;
	float x_left=x2-x1;
	float y_left=y2-y1;
	float step_x_rnd = x_left/step;
	float step_y_rnd = y_left/step;
	
	bool horiz;
	if(ofRandom(1)<0.5){horiz=true;}else{horiz=false;}

	while(abs(x2-x_now)>abs(step_x_rnd) && abs(y2-y_now)>abs(step_y_rnd)){
		if(horiz){
			float step_x = ofRandom(step_x_rnd);
			x_now+=step_x;
			x_left-=step_x;
			horiz=false;
		}else{
			float step_y = ofRandom(step_y_rnd);
			ofLine(x_now, y_now, x_now, y_now+step_y);
			y_now+=step_y;
			y_left-=step_y;	
			horiz=true;
		}
	}	
	
	if(horiz){
		ofLine(x2, y_now, x2, y2);	
	}else{
		ofLine(x_now, y_now, x_now, y2);
	}
}


void distoPath3(int x1, int y1, int x2, int y2, int deviation){
	float x_now=x1;
	float y_now=y1;
	bool loopFlag=true;
	
	bool horiz;
	if(ofRandom(1)<0.5){horiz=true;}else{horiz=false;}

	while(loopFlag){
		float step_x;
		float x_next;
		float step_y;
		float y_next;

		if(horiz){
			if((x2-x_now)>0){		
				step_x = ofRandom(deviation);
				x_next = x_now+step_x;
				if((y2-y_now)>0){	//the line goes from left to right, up to down
					step_y=ofRandom(deviation);
					y_next = y_now+step_y;
					
					if (x_next>x2 && y_next>y2){
						ofLine(x_now, y_now, x2, y_now);
						ofLine(x2, y_now, x2, y2);
						loopFlag = false;
					}else{
						ofLine(x_now, y_now, x_next, y_now);
						ofLine(x_next, y_now, x_next, y_next);
						x_now=x_next;
						y_now=y_next;
					}

				}else{				//the line goes from left to right, down to up
					step_y=ofRandom(-deviation);
					y_next = y_now+step_y;

					if (x_next>x2 && y_next<y2){
						ofLine(x_now, y_now, x2, y_now);
						ofLine(x2, y_now, x2, y2);
						loopFlag = false;
					}else{
						ofLine(x_now, y_now, x_next, y_now);
						ofLine(x_next, y_now, x_next, y_next);
						x_now=x_next;
						y_now=y_next;
					}
				}
			
			}else{					
				step_x = ofRandom(-deviation);
				x_next = x_now+step_x;
				if((y2-y_now)>0){	//the line goes right to left, from up to down
					step_y=ofRandom(deviation);
					y_next = y_now+step_y;

					if (x_next<x2 && y_next>y2){
						ofLine(x_now, y_now, x2, y_now);
						ofLine(x2, y_now, x2, y2);
						loopFlag = false;
					}else{
						ofLine(x_now, y_now, x_next, y_now);
						ofLine(x_next, y_now, x_next, y_next);
						x_now=x_next;
						y_now=y_next;
					}
				}else{				//the line goes right to left, from down to up
					step_y=ofRandom(-deviation);
					y_next = y_now+step_y;

					if (x_next<x2 && y_next<y2){
						ofLine(x_now, y_now, x2, y_now);
						ofLine(x2, y_now, x2, y2);
						loopFlag = false;
					}else{
						ofLine(x_now, y_now, x_next, y_now);
						ofLine(x_next, y_now, x_next, y_next);
						x_now=x_next;
						y_now=y_next;
					}
				}
			}
			
						
		}else{	//if not starting horizontal
	
			if((x2-x_now)>0){		
				step_x = ofRandom(deviation);
				x_next = x_now+step_x;
				if((y2-y_now)>0){	//the line goes from left to right, up to down
					step_y=ofRandom(deviation);
					y_next = y_now+step_y;
					
					if (x_next>x2 && y_next>y2){
						ofLine(x_now, y_now, x_now, y2);
						ofLine(x_now, y2, x2, y2);
						loopFlag = false;
					}else{
						ofLine(x_now, y_now, x_now, y_next);
						ofLine(x_now, y_next, x_next, y_next);
						x_now=x_next;
						y_now=y_next;
					}

				}else{				//the line goes from left to right, down to up
					step_y=ofRandom(-deviation);
					y_next = y_now+step_y;

					if (x_next>x2 && y_next<y2){
						ofLine(x_now, y_now, x_now, y2);
						ofLine(x_now, y2, x2, y2);
						loopFlag = false;
					}else{
						ofLine(x_now, y_now, x_now, y_next);
						ofLine(x_now, y_next, x_next, y_next);
						x_now=x_next;
						y_now=y_next;
					}
				}
			
			}else{					
				step_x = ofRandom(-deviation);
				x_next = x_now+step_x;
				if((y2-y_now)>0){	//the line goes right to left, from up to down
					step_y=ofRandom(deviation);
					y_next = y_now+step_y;

					if (x_next<x2 && y_next>y2){
						ofLine(x_now, y_now, x_now, y2);
						ofLine(x_now, y2, x2, y2);
						loopFlag = false;
					}else{
						ofLine(x_now, y_now, x_now, y_next);
						ofLine(x_now, y_next, x_next, y_next);
						x_now=x_next;
						y_now=y_next;
					}
				}else{				//the line goes right to left, from down to up
					step_y=ofRandom(-deviation);
					y_next = y_now+step_y;

					if (x_next<x2 && y_next<y2){
						ofLine(x_now, y_now, x_now, y2);
						ofLine(x_now, y2, x2, y2);
						loopFlag = false;
					}else{
						ofLine(x_now, y_now, x_now, y_next);
						ofLine(x_now, y_next, x_next, y_next);
						x_now=x_next;
						y_now=y_next;
					}
				}
			}
			
						
		
		}//end if(horiz)
	}	
}




void distoLine(int x1, int y1, int x2, int y2, float steps, float jitter){
	
	float distance_x = x2-x1;
	float distance_y = y2-y1;
	float step = 1.0/steps;

	for(float i=0; i<1.0; i+=step){
		float x_jit = x1+distance_x*i+ofRandom(-jitter,jitter);
		float y_jit = y1+distance_y*i+ofRandom(-jitter,jitter);
		ofLine(x_jit, y_jit, x_jit+1, y_jit+1);	
	}

	float x_jit = x2+ofRandom(-jitter,jitter);
	float y_jit = y2+ofRandom(-jitter,jitter);
	ofLine(x_jit, y_jit, x_jit+1, y_jit+1);	

}

void distoLineH(int x1, int y1, int x2, int y2, float steps, float jitter, int width){
	
	float distance_x = x2-x1;
	float distance_y = y2-y1;
	float step = 1.0/steps;

	for(float i=0; i<1.0; i+=step){
		float x_jit = x1+distance_x*i+ofRandom(-jitter,jitter);
		float y_jit = y1+distance_y*i+ofRandom(-jitter,jitter);
		ofLine(x_jit-width, y_jit, x_jit+width, y_jit);	
	}

	float x_jit = x2+ofRandom(-jitter,jitter);
	float y_jit = y2+ofRandom(-jitter,jitter);
	ofLine(x_jit-width, y_jit, x_jit+width, y_jit);

}

void distoLineHC(int x1, int y1, int x2, int y2, float steps, float jitter, int width, int cMin, int cMax){
	ofPushStyle();

	float distance_x = x2-x1;
	float distance_y = y2-y1;
	float step = 1.0/steps;

	for(float i=0; i<1.0; i+=step){
		float x_jit = x1+distance_x*i+ofRandom(-jitter,jitter);
		float y_jit = y1+distance_y*i+ofRandom(-jitter,jitter);
		ofSetColor(ofRandom(cMin, cMax));
		ofLine(x_jit-width, y_jit, x_jit+width, y_jit);	
	}

	float x_jit = x2+ofRandom(-jitter,jitter);
	float y_jit = y2+ofRandom(-jitter,jitter);
	ofLine(x_jit-width, y_jit, x_jit+width, y_jit);

	ofPopStyle();
}

void distoLineV(int x1, int y1, int x2, int y2, float steps, float jitter, int width){
	
	float distance_x = x2-x1;
	float distance_y = y2-y1;
	float step = 1.0/steps;

	for(float i=0; i<1.0; i+=step){
		float x_jit = x1+distance_x*i+ofRandom(-jitter,jitter);
		float y_jit = y1+distance_y*i+ofRandom(-jitter,jitter);
		ofLine(x_jit, y_jit-width, x_jit, y_jit+width);		
	}

	float x_jit = x2+ofRandom(-jitter,jitter);
	float y_jit = y2+ofRandom(-jitter,jitter);
	ofLine(x_jit, y_jit-width, x_jit, y_jit+width);		

}

void distoLineVC(int x1, int y1, int x2, int y2, float steps, float jitter, int width, int cMin, int cMax){
	ofPushStyle();

	float distance_x = x2-x1;
	float distance_y = y2-y1;
	float step = 1.0/steps;

	for(float i=0; i<1.0; i+=step){
		float x_jit = x1+distance_x*i+ofRandom(-jitter,jitter);
		float y_jit = y1+distance_y*i+ofRandom(-jitter,jitter);
		ofSetColor(ofRandom(cMin, cMax));
		ofLine(x_jit, y_jit-width, x_jit, y_jit+width);		
	}

	float x_jit = x2+ofRandom(-jitter,jitter);
	float y_jit = y2+ofRandom(-jitter,jitter);
	ofLine(x_jit, y_jit-width, x_jit, y_jit+width);		

	ofPopStyle();
}

void distoTree1(int x1, int y1, int x2, int y2, bool horizontal, int levels){
	if(levels>1){
		if(horizontal){
			float y_fix = ofRandom(y1, y2);
			ofLine(x1, y_fix, x2, y_fix);
			if(y_fix> (y1+y2)/2){
				distoTree1(x1, y1, x2, y_fix, !horizontal, levels-1);
			}else{
				distoTree1(x1, y_fix, x2, y2, !horizontal, levels-1);
			}
		}else{
			float x_fix = ofRandom(x1, x2);
			ofLine(x_fix, y1, x_fix, y2);
			if(x_fix> (x1+x2)/2){
				distoTree1(x1, y1, x_fix, y2, !horizontal, levels-1);
			}else{
				distoTree1(x_fix, y1, x2, y2, !horizontal, levels-1);
			}
		}
	}
}

void distoTree2(int x1, int y1, int x2, int y2, bool horizontal, int levels){
	
	if(levels>0){
		if(horizontal){
			float y_fix = ofRandom(y1, y2);
			ofLine(x1, y_fix, x2, y_fix);
			distoTree2(x1, y1, x2, y_fix, !horizontal, levels-1);
			distoTree2(x1, y_fix, x2, y2, !horizontal, levels-1);
		}else{
			float x_fix = ofRandom(x1, x2);
			ofLine(x_fix, y1, x_fix, y2);
			distoTree2(x1, y1, x_fix, y2, !horizontal, levels-1);
			distoTree2(x_fix, y1, x2, y2, !horizontal, levels-1);
		}
	}
}


void distoRectLines(int x1, int y1, int x2, int y2, int n){

	for(int i=0; i<n; i++){
		float x_dest = ofRandom(x1, x2);
		float y_dest = ofRandom(y1, y2);
		if(ofRandom(1)<0.5){
			ofLine(x1, y1, x_dest, y1);
			ofLine(x_dest, y1, x_dest, y_dest);
		}else{
			ofLine(x1,y1, x1, y_dest);
			ofLine(x1, y_dest, x_dest, y_dest);
		}
	}
}