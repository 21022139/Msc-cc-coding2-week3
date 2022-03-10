#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include <vector>
#include "boid.h"

class testApp : public ofBaseApp{
	
public:
    ~testApp(); // a destructor
	
    void setup();
    void update();
    void draw();
    


    std::vector<Boid *> boids;
    std::vector<Boid2 *> boids2;
	
};



#endif	
