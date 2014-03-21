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
		check_gl_error();
		shader.load("shader");
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
        
    }

    void draw()
	{
		check_gl_error();
		fbo.begin();
			check_gl_error();
			ofClear(0, 0, 0, 0);
			check_gl_error();
			shader.begin();
				check_gl_error();
				shader.setUniformTexture("myTexture", testImage.getTextureReference(), testImage.getTextureReference().texData.textureID);
				check_gl_error();
				testImage.draw(0, 0);
				check_gl_error();
			shader.end();
			check_gl_error();
		fbo.end();
		check_gl_error();
        fbo.draw(0, 0);
		check_gl_error();
		stringstream info;
		info << "UPDATING FBO/SHADER IN draw()" << "\n";
		info << "This text should be yellow" << "\n";
		ofDrawBitmapStringHighlight(info.str(), testImage.getWidth(), 100, ofColor::black, ofColor::yellow);
		check_gl_error();
		ofCircle(100, 400, 100);
		check_gl_error();
    }
};

//========================================================================
int main( ){

    ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE); 
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofRunApp( new ofApp());

}