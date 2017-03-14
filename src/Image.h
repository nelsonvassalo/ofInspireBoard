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
    
    ofSoundPlayer bang;
    
    Image();
    
    void setup(string url, float x = ofRandom(1.f, ofGetWidth()), float y = ofRandom(1.f,ofGetHeight()));
  
    void draw();
    
    void update(ofVec2f speed);
    
    ofImage image;
    
    ofVec2f direction;
    
    ofVec2f location;
    

    
    string url;
    
    bool atBounds();
    
    ofImage getImage();
    
    
    
private:
    ofPoint init;
};



