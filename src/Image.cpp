//
//  Image.cpp
//  example-blur
//
//  Created by Nelson on 11/03/17.
//
//

#include "Image.h"


Image::Image() {
    changeDir.set(ofRandom(-100.f, ofGetWindowWidth()),ofRandom(-100.f, ofGetWindowHeight()));
}


void Image::setup(string url, float x, float y) {

      image.load(url);
    float w = image.getWidth()/2;
    float h = image.getHeight()/2;
    if (image.isAllocated()) {
        image.draw(x,y,w,h);
    }
    bang.load("bong.wav");
}

void Image::update(ofVec2f curve) {
    changeDir += curve;
    if (changeDir.x <= 0 || changeDir.x >= ofGetWindowHeight() || changeDir.y <= 0 || changeDir.y >= ofGetWindowHeight() ) {
        changeDir.perpendicular();
        bang.play();
    }
//    if (atBounds()) {
//        move *= (-1, -1);
//    }
    
}

void Image::draw() {
    float w = image.getWidth()/2;
    float h = image.getHeight()/2;

   
    image.draw(changeDir.x, changeDir.y, w, h);
}

//bool Image::atBounds() {
//    if (move.x <= 0 || move.x >= ofGetWindowWidth() || move.y <= 0 || move.y >= ofGetWindowHeight()) {
//        return true;
//    } else return false;
//}




