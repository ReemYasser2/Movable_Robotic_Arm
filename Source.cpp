#include <stdlib.h>
#include <GL/glut.h>

static int shoulder = 0, elbow = 0, littleFingerBase = 0, littleFingerUp = 0, ringFingerBase = 0, ringFingerUp = 0, middleFingerBase = 0, middleFingerUp = 0, indexFingerBase = 0, indexFingerUp = 0, thumbFingerBase = 0, thumbFingerUp = 0;
int moving, startx, starty;

GLfloat angle = 0.0;   // in degrees 
GLfloat angle2 = 0.0;   // in degrees 

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    //Mouse movements
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(-1.0, 0.0, 0.0);

    //Shoulder
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(1.0, 0.0, 0.0);

    //Elbow
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    //Draw ring finger
    glPushMatrix();
    glTranslatef(1.0, 0.25, 0.15);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)ringFingerBase, 0.0, 0.0, 1.0); //ring finger phalange 1 
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)ringFingerUp, 0.0, 0.0, 1.0); //ring finger phalange 2
    glTranslatef(0.15, 0.0, 0.0);
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    //Draw little finger 
    glPushMatrix();
    glTranslatef(1.0, 0.25, 0.0);
    glTranslatef(0.15, 0.0, 0.45);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)littleFingerBase, 0.0, 0.0, 1.0); //little finger phalange 1 
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)littleFingerUp, 0.0, 0.0, 1.0); //little finger phalange 2 
    glTranslatef(0.15, 0.0, 0.0);
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();


    //Draw middle finger
    glPushMatrix();
    glTranslatef(1.0, 0.25, 0.0);
    glTranslatef(0.15, 0.0, -0.15);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)middleFingerBase, 0.0, 0.0, 1.0); //middle finger  phalange 1
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)middleFingerUp, 0.0, 0.0, 1.0); //middle finger  phalange 2
    glTranslatef(0.15, 0.0, 0.0);
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();


    //Draw index finger
    glPushMatrix();
    glTranslatef(1.0, 0.25, 0.0);
    glTranslatef(0.15, 0.0, -0.45);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)indexFingerBase, 0.0, 0.0, 1.0); // index finger phalange 1
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)indexFingerUp, 0.0, 0.0, 1.0); // index finger phalange 2
    glTranslatef(0.15, 0.0, 0.0);
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();


    // Draw thumb finger
    glPushMatrix();
    glTranslatef(1.0, -0.25, -0.45);
    glRotatef((GLfloat)thumbFingerBase, 0.0, 2.5, -1.0); // thumb finger phalange 1
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.15, 0.0, 0.0);


    glRotatef((GLfloat)thumbFingerUp, 0.0, 2.5, -1.0); // thumb finger phalange 2
    glTranslatef(0.15, 0.0, 0.0);
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    glutPostRedisplay();

}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        if (shoulder < 130)
        {
            shoulder = (shoulder + 5);
            glutPostRedisplay();
        }
        break;
    case 'S':
        if (shoulder > - 150)
        {
            shoulder = (shoulder - 5);
            glutPostRedisplay();
        }
        break;
    case 'e':
        if (elbow < 150)
        {
            elbow = (elbow + 5);
            glutPostRedisplay();
        }
        break;
    case 'E':

        if (elbow > 0)
        {
            elbow = (elbow - 5);
            glutPostRedisplay();
        }
        break;
      
    
       //---------------index---------------
    case 'i':
        if (indexFingerBase > -80)
        {
            indexFingerBase = (indexFingerBase - 5);
            glutPostRedisplay();
        }
        break;
    case 'I':
        if (indexFingerBase < 5)
        {
            indexFingerBase = (indexFingerBase + 5);
            glutPostRedisplay();
        }
        break;
    case 'l':
        if (indexFingerUp > -85)
        {
            indexFingerUp = (indexFingerUp - 5);
            glutPostRedisplay();
        }
        break;
    case 'L':
        if (indexFingerUp < 5)
        {
            indexFingerUp = (indexFingerUp + 5);
            glutPostRedisplay();
        }
        break;


      //---------------middle---------------
    case 'm':
        if (middleFingerBase > -80)
        {
            middleFingerBase = (middleFingerBase - 5);
            glutPostRedisplay();
        }
        break;
    case 'M':
        if (middleFingerBase < 5)
        {
            middleFingerBase = (middleFingerBase + 5);
            glutPostRedisplay();
        }
        break;
    case 'n':
        if (middleFingerUp > -85)
        {
            middleFingerUp = (middleFingerUp - 5);
            glutPostRedisplay();
        }
        break;
    case 'N':
        if (middleFingerUp < 5)
        {
            middleFingerUp = (middleFingerUp + 5);
            glutPostRedisplay();
        }
        break;

      //---------------ring---------------
    case 'r':
        if (ringFingerBase > -80)
        {
            ringFingerBase = (ringFingerBase - 5);
            glutPostRedisplay();
        }
        break;
    case 'R':
        if (ringFingerBase < 5)
        {
            ringFingerBase = (ringFingerBase + 5);
            glutPostRedisplay();
        }
        break;
    case 'o':
        if (ringFingerUp > - 85)
        {
            ringFingerUp = (ringFingerUp - 5);
            glutPostRedisplay();
        }
        break;
    case 'O':
        if (ringFingerUp < 5)
        {
            ringFingerUp = (ringFingerUp + 5);
            glutPostRedisplay();
        }
        break;

      //---------------pinky---------------
    case 'f':
        if (littleFingerBase > - 80)
        {
            littleFingerBase = (littleFingerBase - 5);
            glutPostRedisplay();
        }
        break;
    case 'F':
        if (littleFingerBase < 5)
        {
            littleFingerBase = (littleFingerBase + 5);
            glutPostRedisplay();
        }
        break;
    case 'p':
        if (littleFingerUp > - 85)
        {
            littleFingerUp = (littleFingerUp - 5);
            glutPostRedisplay();
        }
        break;
    case 'P':
        if (littleFingerUp < 5)
        {
            littleFingerUp = (littleFingerUp + 5);
            glutPostRedisplay();
        }
        break;

        //---------------thumb---------------
    case 't':
        if (thumbFingerBase > -70)
        {
            thumbFingerBase = (thumbFingerBase - 5);
            glutPostRedisplay();
        }
        break;
    case 'T':
        if (thumbFingerBase < 5)
        {
            thumbFingerBase = (thumbFingerBase + 5);
            glutPostRedisplay();
        }
        break;
    case 'y':
        if (thumbFingerUp > -50)
        {
            thumbFingerUp = (thumbFingerUp - 5);
            glutPostRedisplay();
        }
        break;
    case 'Y':
        if (thumbFingerUp < 5)
        {
            thumbFingerUp = (thumbFingerUp + 5);
            glutPostRedisplay();
        }
        break;
    case 27: //Esc
        exit(0);
        break;
    default:
        break;
    }
}

static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}


static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

