#include <GL/glut.h>
void display()
{
    glBegin(GL_POLYGON);
        glColor3f(1,0,0); glVertex2f(0,1); ///���⪺���I
        glColor3f(0,1,0); glVertex2f(-1,-1); ///��⪺���I
        glColor3f(0,0,1); glVertex2f(+1,-1); ///�Ŧ⪺���I
    glEnd();

    glColor3f(1,1,0); ///����
    glutSolidTeapot(0.3); ///�e��߯���,�j�p0.3
    glutSwapBuffers(); ///��GLUT��e��swap�e����ܪ��a��
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv); ///open GLUT
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///��ܳ]�w
	glutCreateWindow("GLUT Shapes"); ///�}����
	glutDisplayFunc(display); ///��ܹ����禡display()
	glutMainLoop(); ///main�j��
}
