#include "ofMain.h"
#include "ofGLProgrammableRenderer.h"

class ofApp : public ofBaseApp{
public:
    ofFbo fbo;
    ofImage testImage;
    ofShader shader;
	
    void setup()
	{
        ofSetLogLevel(OF_LOG_VERBOSE);
		
        testImage.loadImage("of.png");
		shader.load("shader");
		
        fbo.allocate(ofGetWidth(), ofGetHeight());
		fbo.begin();
			ofClear(0, 0, 0, 0);
		fbo.end();
        
    }
	
    void update()
	{
        fbo.begin();
			ofClear(0, 0, 0, 0);
			shader.begin();
				testImage.draw(0, 0);
			shader.end();
        fbo.end();
    }
	
    void draw()
	{
        fbo.draw(0, 0);
		
		stringstream info;
		info << "UPDATING FBO IN update()" << "\n";
		info << "This text should be yellow" << "\n";
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