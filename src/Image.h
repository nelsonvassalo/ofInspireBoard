//
//  Image.hpp
//  example-blur
//
//  Created by Nelson on 11/03/17.
//
//

#ifndef Image_h
#define Image_h

#include "ofMain.h"


#endif /* Image_hpp */

class Image {
public:
    
    Image();
    
    void setup(string url, float x = ofRandom(1.f, ofGetWidth()), float y = ofRandom(1.f,ofGetHeight()));
  
    void draw();
    
    void update(ofVec2f curve);
    
    ofImage image;
    
    ofVec2f move;
    
    string url;
    
    bool atBounds();
    
    
    
private:
    ofPoint init;
};



