#include <GL/glut.h>
void display()
{
    glBegin(GL_POLYGON);
        glColor3f(1,0,0); glVertex2f(0,1); ///紅色的頂點
        glColor3f(0,1,0); glVertex2f(-1,-1); ///綠色的頂點
        glColor3f(0,0,1); glVertex2f(+1,-1); ///藍色的頂點
    glEnd();

    glColor3f(1,1,0); ///黃色
    glutSolidTeapot(0.3); ///畫實心茶壺,大小0.3
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
