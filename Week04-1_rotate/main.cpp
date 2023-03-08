#include <GL/glut.h>

float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///清背景
    glPushMatrix(); ///備份矩陣
        glRotatef(angle,0,1,0); ///旋轉angle角度 (X,Y,Z)
        glutSolidTeapot(0.3);
    glPopMatrix(); ///還原矩陣

    glutSwapBuffers();
    angle++;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04");
	glutDisplayFunc(display);
	glutIdleFunc(display); ///有空idle時,就重畫畫面
	glutMainLoop();
}
