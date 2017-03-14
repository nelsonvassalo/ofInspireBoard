#include "ofApp.h"

#define max_items 1



//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableAlphaBlending();
//  ofSetFrameRate(1);
    
    // setup Blur (ofxBlurFilter)
//    blur.setup(ofGetWidth(), ofGetHeight());
//
//    cam.initGrabber(ofGetWidth(), ofGetHeight());
//    maskFbo.allocate(ofGetWidth(), ofGetHeight());
//    maskFbo.begin();
//    ofClear(0, 0, 0);
//    
//    maskFbo.end();
    
    maskFbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    
    bong.load("bong.wav");
    
    

    
    json.open(url);
    json2.open(url2);
    
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
        float randX2 = ofRandom(-300.f, ofGetWindowWidth());
        float randY2 = ofRandom(-300.f, ofGetWindowHeight());
        titles[i]  = json["response"]["posts"][i]["photos"][0]["original_size"]["url"].asString();
        titles2[i] = json2["response"]["posts"][i]["photos"][0]["original_size"]["url"].asString();
        cout << randX << " / " << randY << endl;
        imgs[i].setup(titles[i],randX,randY);
        masks[i].setup(titles2[i], randX2, randY2);
        
        alphaMask[i] = new ofxAlphaMaskTexture(imgs[i].getImage().getTextureReference(),      // top layer texture
                                            maskFbo.getTextureReference(),    // bottom layer texture
                                            masks[i].getImage().getTextureReference());
        
        
    }
    


}


//--------------------------------------------------------------
void ofApp::update(){
//    cam.update();
    ofSetWindowTitle("frame rate = " + ofToString(ofGetFrameRate(), 2) + "fps");
    
    ofSetWindowShape(1680, 945);
    ofSetBackgroundColor(255);
   
   
    for (int i = 0; i<max_items; i++ ) {
        
        float randX = ofRandom(-4.f,4.f);
        float randY = ofRandom(-2.f,2.f);
  
        
        
        ofVec2f _temp = ofVec2f(randX, randY);
        
        imgs[i].update(_temp);
        masks[i].update(_temp);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    // draw mask int FBO
//    maskFbo.clear();
    //    ofSetCircleResolution(128);
//    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight(), ofGetHeight());


    for (int i = 0; i<max_items; i++ ) {

        imgs[i].draw();
        

       
        
    }
    
    
    
    for (int i = 0; i<max_items; i++ ) {
        maskFbo.begin();
        
            ofClear(0);
//            ofPushStyle();
        //    ofEnableBlendMode(OF_BLENDMODE_ADD);
        
//        ofPopStyle();
    maskFbo.end();
     alphaMask[i]->draw(300,300);
    }
    
    
    
    
    
    
    ofSetColor(255);
    title.load("futura.ttf", 60);
    title.drawString("InspireBoard", ofGetWindowWidth()/2-300, ofGetWindowHeight()/2+30);
    
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
