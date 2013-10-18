#include "ofMain.h"
#include "ofGLProgrammableRenderer.h"

class ofApp : public ofBaseApp{
public:
    ofFbo fbo;
    ofImage testImage;
	bool doUpdateFboInUpdate;
	
    void setup()
	{
        ofSetLogLevel(OF_LOG_VERBOSE);
		doUpdateFboInUpdate = false;
		
        testImage.loadImage("of.png");
        fbo.allocate(testImage.getWidth(), testImage.getHeight());
		fbo.begin();
			ofClear(0, 0, 0, 0);
		fbo.end();
    }
	
	void updateFbo()
	{
		fbo.begin();
			ofClear(0, 0, 0, 0);
			testImage.draw(0, 0);
        fbo.end();
	}
	
    void update()
	{
        if (ofGetFrameNum()%500 == 0) 
		{
			doUpdateFboInUpdate = !doUpdateFboInUpdate;
		}
    }

    void draw()
	{
		if(!doUpdateFboInUpdate) updateFbo();
        fbo.draw(0, 0);
		stringstream info;
		if (doUpdateFboInUpdate) 
		{
			info << "UPDATING FBO IN update()" << "\n";
		}else 
		{
			info << "UPDATING FBO IN draw()" << "\n";
		}
		info << ofGetFrameRate() << "\n";
		
		ofDrawBitmapStringHighlight(info.str(), testImage.getWidth(), 100, ofColor::black, ofColor::yellow);
		ofCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
		
    }
};

//========================================================================
int main( ){

    ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE); 
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofRunApp( new ofApp());

}