#include "testApp.h"

testApp::~testApp()
{
	for (int i = 0; i < boids.size(); i++)
	{
		delete boids[i];
	}
    
    for (int i = 0; i < boids2.size(); i++)
    {
        delete boids2[i];
    }
}

//--------------------------------------------------------------
void testApp::setup(){
	
	
	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();
    

	
	// set up the boids
	for (int i = 0; i < 50; i++)
		boids.push_back(new Boid());
    
    for (int i = 0; i < 50; i++)
        boids2.push_back(new Boid2());

}


//--------------------------------------------------------------
void testApp::update(){
	
    ofVec3f min(0, 0);
	ofVec3f max(ofGetWidth(), ofGetHeight());
	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->update(boids, min, max);
	}
    
    for (int i = 0; i < boids2.size(); i++)
    {
        boids2[i]->update(boids2, min, max);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofColor color1(0, 200, 155);
    ofColor color2(0, 0, 155);

    ofBackgroundGradient(color1, color2, OF_GRADIENT_CIRCULAR);

	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->draw();
	}
    
    for (int i = 0; i < boids2.size(); i++)
    {
        boids2[i]->draw();
    }

}

