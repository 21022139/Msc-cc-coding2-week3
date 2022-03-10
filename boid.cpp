/*
 *  boid.cpp
 *  boids
 *
 *  Created by Marco Gillies on 05/10/2010.
 *  Copyright 2010 Goldsmiths, University of London. All rights reserved.
 *
 */

#include "boid.h"
#include "ofMain.h"

Boid::Boid()
{
	separationWeight = 1.0f;
	cohesionWeight = 0.2f;
	alignmentWeight = 0.1f;
	
	separationThreshold = 15;
	neighbourhoodSize = 100;
	
	position = ofVec3f(ofRandom(0, 200), ofRandom(0, 200));
	velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2));
}

Boid::Boid(ofVec3f &pos, ofVec3f &vel)
{
	separationWeight = 1.0f;
	cohesionWeight = 0.2f;
	alignmentWeight = 0.1f;
	
	separationThreshold = 15;
	neighbourhoodSize = 100;
	
	position = pos;
	velocity = vel;
}

Boid::~Boid()
{
	
}

float Boid::getSeparationWeight()
{
	return separationWeight;
}
float Boid::getCohesionWeight()
{
	return cohesionWeight;
}

float Boid::getAlignmentWeight()
{
	return alignmentWeight;
}


float Boid::getSeparationThreshold()
{
	return separationThreshold;
}

float Boid::getNeighbourhoodSize()
{
	return neighbourhoodSize;
}


void Boid::setSeparationWeight(float f)
{
	separationWeight = f;
}
void Boid::setCohesionWeight(float f)
{
	cohesionWeight = f;
}

void Boid::setAlignmentWeight(float f)
{
	alignmentWeight = f;
}


void Boid::setSeparationThreshold(float f)
{
	separationThreshold = f;
}

void Boid::setNeighbourhoodSize(float f)
{
	neighbourhoodSize = f;
}


ofVec3f Boid::getPosition()
{
	return position;
}

ofVec3f Boid::getVelocity()
{
	return velocity;
}

ofVec3f Boid::separation(std::vector<Boid *> &otherBoids)
{
	// finds the first collision and avoids that
	// should probably find the nearest one
	// can you figure out how to do that?
	for (int i = 0; i < otherBoids.size(); i++)
	{	
		if(position.distance(otherBoids[i]->getPosition()) < separationThreshold)
		{
			ofVec3f v = position -  otherBoids[i]->getPosition();
			v.normalize();
			return v;
		}
	}
}

ofVec3f Boid::newseparation(std::vector<Boid *> &otherBoids)
{
    // finds the first collision and avoids that
    // should probably find the nearest one
    // can you figure out how to do that?
    for (int i = 0; i < otherBoids.size(); i++)
    {
        if(position.distance(otherBoids[i]->getPosition()) < (55))
        {
            ofVec3f v = position -  otherBoids[i]->getPosition();
            v.normalize();
            return v;
        }
    }
}

ofVec3f Boid::cohesion(std::vector<Boid *> &otherBoids)
{
	ofVec3f average(0,0,0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getPosition();
			count += 1;
		}
	}
	average /= count;
	ofVec3f v =  average - position;
	v.normalize();
	return v;
}

ofVec3f Boid::newcohesion(std::vector<Boid *> &otherBoids)
{
    ofVec3f average(0,0,0);
    int count = 0;
    for (int i = 0; i < otherBoids.size(); i++)
    {
        if (position.distance(otherBoids[i]->getPosition()) < (150))
        {
            average += otherBoids[i]->getPosition();
            count += 1;
        }
    }
    average /= count;
    ofVec3f v =  average - position;
    v.normalize();
    return v;
}

ofVec3f Boid::alignment(std::vector<Boid *> &otherBoids)
{
	ofVec3f average(0,0,0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getVelocity();
			count += 1;
		}
	}
	average /= count;
	ofVec3f v =  average - velocity;
	v.normalize();
	return v;
}

void Boid::update(std::vector<Boid *> &otherBoids, ofVec3f &min, ofVec3f &max)
{
	velocity += separationWeight*separation(otherBoids);
	velocity += cohesionWeight*cohesion(otherBoids);
	velocity += alignmentWeight*alignment(otherBoids);
	
	walls(min, max);
	position += velocity;
}

void Boid::newupdate(std::vector<Boid *> &otherBoids, std::vector<Boid *> &newOtherBoids, ofVec3f &min, ofVec3f &max)
{
    velocity += (0.8f)*separation(otherBoids) + (0.2f)*newseparation(newOtherBoids);
    velocity += (0.2f)*cohesion(otherBoids) + (0.2f)*newcohesion(newOtherBoids);
    velocity += (0.11f)*alignment(otherBoids);
    
    walls(min, max);
    position += velocity;
}

void Boid::walls(ofVec3f &min, ofVec3f &max)
{
	if (position.x < min.x){
		position.x = min.x;
		velocity.x *= -1;
	} else if (position.x > max.x){
		position.x = max.x;
		velocity.x *= -1;
	}
	
	if (position.y < min.y){
		position.y = min.y;
		velocity.y *= -1;
	} else if (position.y > max.y){
		position.y = max.y;
		velocity.y *= -1;
	}
	
	
}

void Boid::draw()
{
	ofSetColor(255, 255, 255, 100);
    ofDrawRectangle(position.x, position.y, 10, 10);
}


Boid2::Boid2()
{
    separationWeight = 2.0f;
    cohesionWeight = 0.5f;
    alignmentWeight = 0.5f;
    
    separationThreshold = 20;
    neighbourhoodSize = 100;
    
    position = ofVec3f(ofRandom(0, 200), ofRandom(0, 200));
    velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2));
}

Boid2::Boid2(ofVec3f &pos, ofVec3f &vel)
{
    separationWeight = 1.0f;
    cohesionWeight = 0.2f;
    alignmentWeight = 0.1f;
    
    separationThreshold = 15;
    neighbourhoodSize = 100;
    
    position = pos;
    velocity = vel;
}

Boid2::~Boid2()
{
    
}

float Boid2::getSeparationWeight()
{
    return separationWeight;
}
float Boid2::getCohesionWeight()
{
    return cohesionWeight;
}

float Boid2::getAlignmentWeight()
{
    return alignmentWeight;
}


float Boid2::getSeparationThreshold()
{
    return separationThreshold;
}

float Boid2::getNeighbourhoodSize()
{
    return neighbourhoodSize;
}


void Boid2::setSeparationWeight(float f)
{
    separationWeight = f;
}
void Boid2::setCohesionWeight(float f)
{
    cohesionWeight = f;
}

void Boid2::setAlignmentWeight(float f)
{
    alignmentWeight = f;
}


void Boid2::setSeparationThreshold(float f)
{
    separationThreshold = f;
}

void Boid2::setNeighbourhoodSize(float f)
{
    neighbourhoodSize = f;
}


ofVec3f Boid2::getPosition()
{
    return position;
}

ofVec3f Boid2::getVelocity()
{
    return velocity;
}

ofVec3f Boid2::separation(std::vector<Boid2 *> &otherBoids)
{
    // finds the first collision and avoids that
    // should probably find the nearest one
    // can you figure out how to do that?
    for (int i = 0; i < otherBoids.size(); i++)
    {
        if(position.distance(otherBoids[i]->getPosition()) < separationThreshold)
        {
            ofVec3f v = position -  otherBoids[i]->getPosition();
            v.normalize();
            return v;
        }
    }
}

ofVec3f Boid2::cohesion(std::vector<Boid2 *> &otherBoids)
{
    ofVec3f average(0,0,0);
    int count = 0;
    for (int i = 0; i < otherBoids.size(); i++)
    {
        if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
        {
            average += otherBoids[i]->getPosition();
            count += 1;
        }
    }
    average /= count;
    ofVec3f v =  average - position;
    v.normalize();
    return v;
}

ofVec3f Boid2::alignment(std::vector<Boid2 *> &otherBoids)
{
    ofVec3f average(0,0,0);
    int count = 0;
    for (int i = 0; i < otherBoids.size(); i++)
    {
        if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
        {
            average += otherBoids[i]->getVelocity();
            count += 1;
        }
    }
    average /= count;
    ofVec3f v =  average - velocity;
    v.normalize();
    return v;
}

void Boid2::update(std::vector<Boid2 *> &otherBoids, ofVec3f &min, ofVec3f &max)
{
    velocity += separationWeight*separation(otherBoids);
    velocity += cohesionWeight*cohesion(otherBoids);
    velocity += alignmentWeight*alignment(otherBoids);
    
    walls(min, max);
    position += velocity;
}

void Boid2::walls(ofVec3f &min, ofVec3f &max)
{
    if (position.x < min.x){
        position.x = min.x;
        velocity.x *= -1;
    } else if (position.x > max.x){
        position.x = max.x;
        velocity.x *= -1;
    }
    
    if (position.y < min.y){
        position.y = min.y;
        velocity.y *= -1;
    } else if (position.y > max.y){
        position.y = max.y;
        velocity.y *= -1;
    }
    
    
}

void Boid2::draw()
{
    ofSetColor(255, 0, 255, 100);
    ofDrawCircle(position.x, position.y, 10);
}
