#include "ofMain.h"
#include "ofGLProgrammableRenderer.h"

class ofApp : public ofBaseApp{
public:
    ofImage testImage;
    ofShader shader;
    void setup()
	{
        
		//ofEnableNormalizedTexCoords();
        testImage.loadImage("of.png");
		shader.load("shader");
    }
	
	
	
    void update()
	{
		//ofSetupScreen(); 
    }

    void draw()
	{
		ofSetupScreen(); 
		shader.begin();
			check_gl_error();
			shader.setUniformTexture("myTexture", testImage.getTextureReference(), testImage.getTextureReference().texData.textureID);
			testImage.draw(0, 0);
		shader.end();
		check_gl_error();
		stringstream info;
		info << "This text should be yellow" << "\n";
		ofPushStyle();
			ofDrawBitmapStringHighlight(info.str(), testImage.getWidth(), 100, ofColor::black, ofColor::yellow);
			check_gl_error();
		ofPopStyle();
		ofSetColor(ofColor::blue);
		check_gl_error();
		ofCircle(100, 400, 100);
		check_gl_error();
		ofSetupScreen(); 
    }
};

//========================================================================
int main( ){

	ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE); 
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofRunApp( new ofApp());

}