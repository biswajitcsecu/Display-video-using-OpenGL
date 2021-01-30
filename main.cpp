
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <GL/freeglut.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core/opengl.hpp>



using namespace cv;
using namespace std;




GLfloat angle = 0.0;
GLuint texture;
VideoCapture camera;
Mat frame;

int w = 500;
int h = 500;

void withOpengl(void* param );
int loadFrameTexture(void);


int loadFrameTexture(void){

    if (frame.data ==NULL) return -1;

    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_LIGHT1);
    glColor4f(1.0f, 1.0f, 1.0f, 0.5);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);

    glBindTexture (GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, frame.cols, frame.rows, 0,
                 GL_BGR, GL_UNSIGNED_BYTE, frame.data);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHT1);
    return 0;
}

void withOpengl(void* param ){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable(GL_CULL_FACE);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
    glEnable(GL_TEXTURE_2D);
    glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );

    //adjust screen
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, frame.cols, frame.rows);
    gluOrtho2D(0,frame.cols, frame.rows, 0);
    glLoadIdentity();
    glMatrixMode(GL_TEXTURE_2D);
    glLoadIdentity();
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    }
    glEnd();
    glPopMatrix();

    glFlush();
    glFinish();
    glDisable(GL_CULL_FACE);
    glDisable(GL_COLOR_MATERIAL );
    glDisable(GL_TEXTURE_2D );
}

void initializeOpenGL(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitContextVersion(4,3);
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
    glutInitContextProfile( GLUT_CORE_PROFILE );
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_GLUTMAINLOOP_RETURNS);
}

int main(int argc,  char** argv){

    camera.open("sandbeach.mp4",CAP_ANY);
    if (!camera.isOpened())
    {
        cout << "ERROR : Can't open camera" << endl;
        return -1;
    }

    // windo creation
    std::string winname = "Video on OpenGL"
                          ""
                          "";
    namedWindow(winname, WINDOW_OPENGL);
    cv::moveWindow(winname, 50,50);
    cv::setOpenGlContext(winname);

    //Enable texture
    initializeOpenGL(argc,argv);
    GLint texid =1;
    glInitNames();
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_TEXTURE_2D);
    glGenTextures(texid, &texture);
    setOpenGlDrawCallback(winname, withOpengl);

    //Display
    while(waitKey(500) !='q'){
        camera >> frame;
        cv::rotate(frame, frame, cv::ROTATE_180);
        loadFrameTexture();
        updateWindow(winname);
    }

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_TEXTURE_2D);

    //Destroy windows
    destroyWindow(winname);
    return 0;
}
