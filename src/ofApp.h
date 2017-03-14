#pragma once

#include "ofMain.h"
#include "ofxAlphaMaskTexture.h"
#include "ofxBlurShader.h"
#include "ofxJSON.h"
#include "Image.h"

using namespace std;

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxAlphaMaskTexture *alphaMask;

    ofFbo maskFbo;
    ofVideoGrabber cam;
    ofxBlurShader blur;
    
    string url = "http://api.tumblr.com/v2/blog/visual-storage.tumblr.com/posts?api_key=049tE8j8UbMVLqvmkx36KIxfGM0fgp4hCnltTHUOYcizX7K2fo";
    
    ofxJSONElement json;
    
    
    Image imgs[10];
    string titles[10];
    
    
};
