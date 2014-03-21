#include "ofMain.h"
#include "ofGLProgrammableRenderer.h"

class ofApp : public ofBaseApp{
public:
    ofFbo fbo;
    ofImage testImage;
	bool updateFBOInUpdate;
    void setup()
	{
		updateFBOInUpdate = false;
        ofSetLogLevel(OF_LOG_VERBOSE);
		check_gl_error();
        testImage.loadImage("of.png");
		check_gl_error();
        fbo.allocate(ofGetWidth(), ofGetHeight());
		check_gl_error();
		fbo.begin();
			check_gl_error();
			ofClear(0, 0, 0, 0);
			check_gl_error();
		fbo.end();
		check_gl_error();
    }
	
    void update()
	{
		if (ofGetFrameNum() % 400 == 0) 
		{
			updateFBOInUpdate = !updateFBOInUpdate;
		}
		if (updateFBOInUpdate) 
		{
			updateFBO("update");
		}
    }
	
	void updateFBO(string programState)
	{
		//ofViewport(0, 0, ofGetWidth(), ofGetHeight());
		ofLogVerbose() << "programState: " << programState;
		check_gl_error();
		fbo.begin();check_gl_error();
		ofClear(0, 0, 0, 0);check_gl_error();
		testImage.draw(0, 0);check_gl_error();
        fbo.end();check_gl_error();
	}
    void draw()
	{
		if (!updateFBOInUpdate) 
		{
			updateFBO("draw");
		}
		
		check_gl_error();
        fbo.draw(0, 0);
		check_gl_error();
		stringstream info;
		if (updateFBOInUpdate) 
		{
			info << "UPDATING FBO IN update()" << "\n";
		}else 
		{
			info << "UPDATING FBO IN draw()" << "\n";
		}

		
		info << "This text should be yellow, circle should be white" << "\n";
		info << ofGetFrameRate() << "\n";
		ofDrawBitmapStringHighlight(info.str(), testImage.getWidth(), 100, ofColor::black, ofColor::yellow);
		check_gl_error();
		ofCircle(100, 400, 100);
		check_gl_error();
    }
};

//========================================================================
int main( ){
	
    ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE); 
	check_gl_error();
    ofSetupOpenGL(1280, 720, OF_WINDOW);
	check_gl_error();
    ofRunApp( new ofApp());
	
}