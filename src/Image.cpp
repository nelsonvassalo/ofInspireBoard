//
//  Image.cpp
//  example-blur
//
//  Created by Nelson on 11/03/17.
//
//

#include "Image.h"


Image::Image() {
    changeDir.set(ofRandom(-5.f, 5.f),ofRandom(-5.f, 5.f));
}


void Image::setup(string url, float x, float y) {

      image.load(url);
    if (image.isAllocated()) {
        image.draw(x,y);
    }
}

void Image::update(ofVec2f curve) {
//    moveDir += curve;
//    if (atBounds()) {
//        move *= (-1, -1);
//    }
    
}

void Image::draw() {
   
    image.draw(move.x,move.y);
}

//bool Image::atBounds() {
//    if (move.x <= 0 || move.x >= ofGetWindowWidth() || move.y <= 0 || move.y >= ofGetWindowHeight()) {
//        return true;
//    } else return false;
//}




