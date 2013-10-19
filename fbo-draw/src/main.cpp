#include "ofMain.h"
#include "ofGLProgrammableRenderer.h"

class ofApp : public ofBaseApp{
public:
    ofFbo fbo;
    ofImage testImage;
	
    void setup()
	{
        ofSetLogLevel(OF_LOG_VERBOSE);
		
        testImage.loadImage("of.png");
        fbo.allocate(ofGetWidth(), ofGetHeight());
		fbo.begin();
			ofClear(0, 0, 0, 0);
		fbo.end();
    }
	
    void update()
	{
		
    }

    void draw()
	{
		fbo.begin();
			ofClear(0, 0, 0, 0);
			testImage.draw(0, 0);
        fbo.end();
		
        fbo.draw(0, 0);
		
		stringstream info;
		info << "UPDATING FBO IN draw()" << "\n";
		info << "This text should be yellow" << "\n";
		info << ofGetFrameRate() << "\n";
		ofDrawBitmapStringHighlight(info.str(), testImage.getWidth(), 100, ofColor::black, ofColor::yellow);
		
		ofCircle(100, 400, 100);
		
    }
};

//========================================================================
int main( ){

    ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE); 
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofRunApp( new ofApp());

}