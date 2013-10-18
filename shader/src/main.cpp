#include "ofMain.h"
#include "ofGLProgrammableRenderer.h"

class ofApp : public ofBaseApp{
public:
    ofImage testImage;
    ofShader shader;
	bool doShader;
    void setup()
	{
        ofSetLogLevel(OF_LOG_VERBOSE);
		doShader = true;
        testImage.loadImage("of.png");
		shader.load("shader");
        
    }
	
	
	
    void update()
	{
		if (ofGetFrameNum()%300 == 0) 
		{
			doShader = !doShader;
		}
    }

    void draw()
	{
		if(doShader) shader.begin();
			testImage.draw(0, 0);
		if(doShader) shader.end();
		
		stringstream info;
		if (doShader) 
		{
			info << "shader ENABLED" << "\n";
		}else 
		{
			info << "shader DISABLED" << "\n";
		}

		
		info << "This text should be yellow" << "\n";
		//ofPushStyle();
			ofDrawBitmapStringHighlight(info.str(), testImage.getWidth(), 100, ofColor::black, ofColor::yellow);
		//ofPopStyle();
		ofCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
		
    }
};

//========================================================================
int main( ){

    ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE); 
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofRunApp( new ofApp());

}