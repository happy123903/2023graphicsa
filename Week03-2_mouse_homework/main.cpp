#include <GL/glut.h>
#include <stdio.h>

float X=0, Y=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///清背景
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.224,0.140);
        glVertex2f(-0.240,0.088);
        glVertex2f(-0.240,0.068);
        glVertex2f(-0.312,-0.068);
        glVertex2f(-0.296,-0.100);
        glVertex2f(-0.212,-0.224);
        glVertex2f(0.184,-0.240);
        glVertex2f(0.284,-0.140);
        glVertex2f(0.292,-0.008);
        glVertex2f(0.224,0.120);
        glVertex2f(0.036,0.192);
        glVertex2f(-0.056,0.164);
        glVertex2f(-0.216,0.136);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.288,0.640);
        glVertex2f(0.608,0.604);
        glVertex2f(0.600,0.424);
        glVertex2f(-0.276,0.436);
        glVertex2f(0.136,0.304);
        glVertex2f(0.168,0.872);
    glEnd();

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
    X=(x-250)/250.0;
    Y=-(y-250)/250.0; ///by口訣
    if(state==GLUT_DOWN){ ///判斷是否為滑鼠放開
        printf("glVertex2f(%.3f,%.3f);\n",X,Y); ///輸出滑鼠所點的座標
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("week03");
	glutDisplayFunc(display);
	glutMouseFunc(mouse); ///用mouse函式
	glutMainLoop();
}
