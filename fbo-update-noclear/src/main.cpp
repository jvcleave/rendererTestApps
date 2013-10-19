#include "ofMain.h"
#include "ofGLProgrammableRenderer.h"

class ofApp : public ofBaseApp{
public:
    ofFbo fbo;
    ofImage testImage;
	
    void setup(){
        ofSetLogLevel(OF_LOG_VERBOSE);
        testImage.loadImage("of.png");
        fbo.allocate(ofGetWidth(), ofGetHeight());
    }
	
    //--------------------------------------------------------------
    void update(){
        fbo.begin();
			testImage.draw(0, 0);
        fbo.end();
    }
	
    //--------------------------------------------------------------
    void draw(){
        fbo.draw(0, 0);
    }
};

//========================================================================
int main( ){
	
    //commenting this line will allow to work
    ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE); 
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofRunApp( new ofApp());
	
}