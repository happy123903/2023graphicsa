#include <GL/glut.h>
#include <math.h>
void myCircle(float r, float x, float y)
{
    glBegin(GL_POLYGON);
        for(float a=0; a<2*3.1415926; a+=0.1){ ///圓形
            glVertex2f(r*cos(a)+x, r*sin(a)+y);
        }
    glEnd();
}
void display()
{
    glColor3f(0,0,1); myCircle(0.6,0,0);
    glColor3f(0,1,0); myCircle(0.3,0.5,0.5);
    glColor3f(1,0,0); myCircle(0.3,-0.5,0.5);
    glColor3f(1,1,0); myCircle(0.3,-0.5,-0.5);
    glColor3f(1,0,1); myCircle(0.3,0.5,-0.5);

    glutSwapBuffers(); ///請GLUT把畫面swap送到顯示的地方
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv); ///open GLUT
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///顯示設定
	glutCreateWindow("GLUT Shapes"); ///開視窗
	glutDisplayFunc(display); ///顯示對應函式display()
	glutMainLoop(); ///main迴圈
}
