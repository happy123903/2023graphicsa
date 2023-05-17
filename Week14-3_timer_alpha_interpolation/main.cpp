#include <GL/glut.h>
float angle=0,oldAngle=0,newAngle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void timer(int t)
{
    if(t<100) glutTimerFunc(50,timer,t+1); ///�b100�H���A�]�w�U�@�Ӿx��
    float alpha=t/100.0; ///alpha����0~1����
    angle=newAngle*alpha+(1-alpha)*oldAngle; ///��������
    glutPostRedisplay(); ///���e�e��
}
void motion(int x,int y)
{
    angle=x; ///�Y�ɧ�s����
    glutPostRedisplay(); ///���e�e��
}
void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN) oldAngle = x; ///���U
    if(state==GLUT_UP) newAngle = x; ///��}
}
void keyboard(unsigned char key,int x,int y) ///���U������}�l����
{
    glutTimerFunc(0,timer,0);
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); ///���U��ܰ_�I
    glutMotionFunc(motion); ///��mouse�bmotion�ɡA�Y�ɧ�s�e��
    glutKeyboardFunc(keyboard);


    glutMainLoop();
}
