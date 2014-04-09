#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "CinderOpenNI.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class DepthRecorderApp : public AppNative {
public:
    void prepareSettings(Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );
	void update();
	void draw();
    void shutdown();
private:
    ci::openni::Camera camera;
};

void DepthRecorderApp::prepareSettings(Settings *settings)
{
    settings->setWindowSize( 1280, 480 );
    settings->setFrameRate( 30 );
}

void DepthRecorderApp::setup()
{
    camera.setup( ci::openni::Camera::SENSOR_DEPTH | ci::openni::Camera::SENSOR_COLOR );
}

void DepthRecorderApp::mouseDown( MouseEvent event )
{
}

void DepthRecorderApp::update()
{
    camera.update();
}

void DepthRecorderApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    
    gl::draw( camera.getDepthTex(), Rectf( 0, 0, 640, 480 ) );
    //    gl::draw( camera.getRawDepthTex(), Rectf( 0, 0, 640, 480 ) );
    //    gl::draw( camera.getColorTex(), Rectf( 640, 0, 1280, 480 ) );
    
}

void DepthRecorderApp::shutdown()
{
    console() << "Shutting down" << endl;
    camera.close();
    camera.shutdown();
}

CINDER_APP_NATIVE( DepthRecorderApp, RendererGl )
