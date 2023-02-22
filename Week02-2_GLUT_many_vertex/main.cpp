#include <GL/glut.h>
void display()
{
    glColor3f(247/255.0, 247/255.0, 247/255.0);
    glBegin(GL_POLYGON); ///背景
        glVertex2f(1,1);
        glVertex2f(-1,1);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
    glEnd();

    glColor3f(244/255.0, 209/255.0, 33/255.0);
    glBegin(GL_POLYGON);
        glVertex2f((45-100)/100.0, -(134-100)/100.0);
        glVertex2f((36-100)/100.0, -(171-100)/100.0);
        glVertex2f((108-100)/100.0, -(179-100)/100.0);
        glVertex2f((104-100)/100.0, -(117-100)/100.0);
        ///口訣:減一半、除一半、y變負號 (抓邊界距離長
    glEnd();

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
