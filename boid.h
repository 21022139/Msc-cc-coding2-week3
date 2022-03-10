/*

 *
 */

#ifndef _BOID
#define _BOID
#include <vector>
#include "ofMain.h"

class Boid
{
// all the methods and variables after the
// private keyword can only be used inside
// the class
private:	
	ofVec3f position;
	ofVec3f velocity;
	
	float separationWeight;
	float cohesionWeight;
	float alignmentWeight;
	
	float separationThreshold;
	float neighbourhoodSize;
	
	ofVec3f separation(std::vector<Boid *> &otherBoids);
    ofVec3f newseparation(std::vector<Boid *> &otherBoids);
    ofVec3f cohesion(std::vector<Boid *> &otherBoids);
	ofVec3f alignment(std::vector<Boid *> &otherBoids);
    ofVec3f newcohesion(std::vector<Boid *> &otherBoids);
    
    
	
// all the methods and variables after the
// public keyword can only be used by anyone
public:	
	Boid();
	Boid(ofVec3f &pos, ofVec3f &vel);
	
	~Boid();
	
	ofVec3f getPosition();
	ofVec3f getVelocity();
	
	
	float getSeparationWeight();
	float getCohesionWeight();
	float getAlignmentWeight();
	
	float getSeparationThreshold();
	float getNeighbourhoodSize();
	
	void setSeparationWeight(float f);
	void setCohesionWeight(float f);
	void setAlignmentWeight(float f);
	
	void setSeparationThreshold(float f);
	void setNeighbourhoodSize(float f);
	
	void update(std::vector<Boid *> &otherBoids, ofVec3f &min, ofVec3f &max);
    void newupdate(std::vector<Boid *> &otherBoids, std::vector<Boid *> &newOtherBoids, ofVec3f &min, ofVec3f &max);
	
	void walls(ofVec3f &min, ofVec3f &max);
	
	void draw();
};

class Boid2: public Boid
{
// all the methods and variables after the
// private keyword can only be used inside
// the class
private:
    ofVec3f position;
    ofVec3f velocity;
    
    float separationWeight;
    float cohesionWeight;
    float alignmentWeight;
    
    float separationThreshold;
    float neighbourhoodSize;
    
    ofVec3f separation(std::vector<Boid2 *> &otherBoids);
    ofVec3f cohesion(std::vector<Boid2 *> &otherBoids);
    ofVec3f alignment(std::vector<Boid2 *> &otherBoids);
    
// all the methods and variables after the
// public keyword can only be used by anyone
public:
    Boid2();
    Boid2(ofVec3f &pos, ofVec3f &vel);
    
    ~Boid2();
    
    ofVec3f getPosition();
    class ofVec3f getVelocity();
    
    
    float getSeparationWeight();
    float getCohesionWeight();
    float getAlignmentWeight();
    
    float getSeparationThreshold();
    float getNeighbourhoodSize();
    
    void setSeparationWeight(float f);
    void setCohesionWeight(float f);
    void setAlignmentWeight(float f);
    
    void setSeparationThreshold(float f);
    void setNeighbourhoodSize(float f);
    
    void update(std::vector<Boid2 *> &otherBoids, ofVec3f &min, ofVec3f &max);
    
    void walls(ofVec3f &min, ofVec3f &max);
    
    void draw();
};

#endif
