#include "ofApp.h"

#define max_items 10



//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableAlphaBlending();
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
    
    bong.load("bong.wav");
    

    
    json.open(url);
    json.open(url2);
    
     // mask layer texture
    
    bool parsingSuccessful = json.open(url);
    
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    for (int i = 0; i < max_items; i++) {
        float randX = ofRandom(-300.f, ofGetWindowWidth());
        float randY = ofRandom(-300.f, ofGetWindowHeight());
        titles[i]  = json["response"]["posts"][i]["photos"][0]["original_size"]["url"].asString();
        cout << randX << " / " << randY << endl;
        imgs[i].setup(titles[i],randX,randY);
        
        
        
        
        

    }

}


//--------------------------------------------------------------
void ofApp::update(){
//    cam.update();
    ofSetWindowTitle("frame rate = " + ofToString(ofGetFrameRate(), 2) + "fps");
    
    for (int i = 0; i<max_items; i++ ) {
        
        float rand = ofRandom(-10.f,10.f);
        float x = ofMap( ofNoise( ofGetElapsedTimef()/rand, -1200), 0, 1, 0, ofGetWidth()) / 200;
        float y = ofMap( ofNoise( ofGetElapsedTimef()/rand, 1200), 0, 1, 0, ofGetHeight()) / 200;
        ofVec2f one = ofVec2f(x, y);
        
        imgs[i].update(one);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    // draw mask int FBO
    maskFbo.begin();
//    ofSetCircleResolution(128);
//    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight(), ofGetHeight());
    
    
    maskFbo.end();
    
//    alphaMask->draw();
    for (int i = 0; i<max_items; i++ ) {
        imgs[i].draw();
    }
    ofSetColor(220);
    title.load("futura.ttf", 60);
    title.drawString("Not Supreme", ofGetWindowWidth()/2-300, ofGetWindowHeight()/2+30);


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
    bong.play();
    
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
