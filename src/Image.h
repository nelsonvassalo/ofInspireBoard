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
#include "ofxAlphaMaskTexture.h"
#include "ofxBlurShader.h"


#endif /* Image_hpp */

class Image {
public:
    
    ofSoundPlayer bang;
    
    Image();
    
    void setup(string url, string url2, float x = ofRandom(1.f, ofGetWidth()), float y = ofRandom(1.f,ofGetHeight()), float x2 = ofRandom(1.f, ofGetWidth()), float y2 = ofRandom(1.f,ofGetHeight()) );
  
    void draw();
    
    ofxBlurShader blur;
    ofFbo maskFbo;
    ofImage image;
    ofImage mask;
    ofxAlphaMaskTexture *alphaMask;
    void update(ofVec2f speed);
    
    ofVec2f direction;
    
    ofVec2f location;
    
    

    
    string url;
    
    bool atBounds();
    
    ofImage getImage();
#include "ofxAlphaMaskTexture.h"
#include "ofxBlurShader.h"
    
    
    
private:
    ofPoint init;
};



