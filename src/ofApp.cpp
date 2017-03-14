#include "ofApp.h"

#define max_items 4

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
//    ofSetFrameRate(12);
    
    // setup Blur (ofxBlurFilter)
//    blur.setup(ofGetWidth(), ofGetHeight());
//    
//    cam.initGrabber(ofGetWidth(), ofGetHeight());
//    maskFbo.allocate(ofGetWidth(), ofGetHeight());
//    maskFbo.begin();
//    ofClear(0, 0, 0);
//    
//    maskFbo.end();
    
    json.open(url);
    
     // mask layer texture
    
    bool parsingSuccessful = json.open(url);
    
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    for (int i = 0; i < max_items; i++) {
        titles[i]  = json["response"]["posts"][i]["photos"][0]["original_size"]["url"].asString();
        imgs[i].setup(titles[i],0,0);
    

    }
//    alphaMask = new ofxAlphaMaskTexture(cam.getTexture(),        // top layer texture
//                                        images[2].getTexture(),  // bottom layer texture
//                                        maskFbo.getTexture());
//
}


//--------------------------------------------------------------
void ofApp::update(){
//    cam.update();
    ofSetWindowTitle("frame rate = " + ofToString(ofGetFrameRate(), 2) + "fps");
    ofVec2f one = ofVec2f(1.f,-1.f);
    
    for (int i = 0; i<max_items; i++ ) {
        imgs[i].update(one);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float blurAmount = ofMap(mouseX, 0, ofGetWidth(), 0, 10.0);

    // draw mask int FBO
//    maskFbo.begin();
//    blur.begin(blurAmount, 30); // blur begin
//    ofSetCircleResolution(128);
//    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight(), ofGetHeight());
//    blur.end(); // blur end
//    maskFbo.end();
//    
//    alphaMask->draw();
    for (int i = 0; i<max_items; i++ ) {
        imgs[i].draw();
    }
    
//
//    for(int i = 0; i<50; i++) {
//        
//        if(images[i].isAllocated()) {
//          images[i].draw(ofRandom(1, ofGetWindowWidth()),ofRandom(1, ofGetWindowHeight()));
//        }
//    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
