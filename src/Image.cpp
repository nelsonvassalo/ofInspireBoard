//
//  Image.cpp
//  example-blur
//
//  Created by Nelson on 11/03/17.
//
//

#include "Image.h"


Image::Image() {
    location.set(ofRandom(-500.f, ofGetWindowWidth()),ofRandom(-200.f, ofGetWindowHeight()));
    direction.set(ofRandom(-0.1f, 2.f),ofRandom(-0.1f, 1.f));
}


void Image::setup(string url, string url2, float x, float y, float x2, float y2) {
    
    
    image.load(url);
    mask.load(url2);
    float w = image.getWidth();
    float h = image.getHeight();
    float w2 = mask.getWidth();
    float h2 = image.getHeight();
//    if (image.isAllocated()) {
//        image.draw(x,y,w,h);
//    }
    bang.load("bong.wav");
    
    maskFbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    
    
    alphaMask = new ofxAlphaMaskTexture(image.getTextureReference(),      // top layer texture
                                           maskFbo.getTextureReference(),    // bottom layer texture
                                           mask.getTextureReference());
    
}

void Image::update(ofVec2f speed) {
    direction += speed;
    
    location.x += ofClamp(direction.x, 0, 2);
    location.y += ofClamp(direction.y, 0, 1);
    
//    location.x = ofMap(ofSignedNoise(speed.x, -120), 0, 1, 1,ofGetWindowWidth());
//    location.y = ofMap(ofSignedNoise( speed.y, 120), 0, 1, 1, ofGetWindowHeight());
    location.x += ofMap(ofNoise(direction.x, -1800)* ofGetElapsedTimef()*0.01,0, 1, 0.1, 2.f);
    location.y += ofMap(ofNoise(direction.y, 1800) * ofGetElapsedTimef()*0.01,0, 1, 0.1, 1.f);
    
    if (location.x <= 0 || location.x >= ofGetWindowWidth() || location.y <= 0 || location.y >= ofGetWindowHeight() ) {
        location.set(0,0);
        bang.play();
    }
//    if (atBounds()) {
//        move *= (-1, -1);
//    }
    
}

void Image::draw() {
    float w = image.getWidth();
    float h = image.getHeight();
    float w2 = mask.getWidth();
    float h2 = mask.getHeight();

    maskFbo.begin();
    
    ofClear(0);
    
//    image.draw(location.x, location.y, w, h);

    maskFbo.end();
   
    alphaMask->draw(location.x,location.y);

    ;
}

//bool Image::atBounds() {
//    if (move.x <= 0 || move.x >= ofGetWindowWidth() || move.y <= 0 || move.y >= ofGetWindowHeight()) {
//        return true;
//    } else return false;
//}

ofImage Image::getImage() {
    return image;
}



