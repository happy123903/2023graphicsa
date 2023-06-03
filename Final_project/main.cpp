#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"

GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * righthand = NULL, * lefthand = NULL;


int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

FILE * fin = NULL;
FILE * fout = NULL;
float teapotX=0, teapotY=0, oldX=0, oldY=0;  ///有不同
float angle[20]={}, angle2[20]={};
float OldAngle[20]={}, NewAngle[20]={};
float OldAngle2[20]={}, NewAngle2[20]={};
int ID=0; ///0:head, 1,2:left, 3,4:right hand, 5,6,7:left leg, 8,9,10:right leg
void timer(int t)
{
    printf("t:%d\n",t);
    glutTimerFunc(20,timer,t+1);
    if(t%50==0)
    {
        if(fin==NULL) fin = fopen("motion.txt","r");
        for(int i=0;i<20;i++)
        {
            OldAngle[i] = NewAngle[i];
            OldAngle2[i] = NewAngle2[i];
            fscanf(fin, "%f", &NewAngle[i]);
            fscanf(fin, "%f", &NewAngle2[i]);
        }
    }
    float alpha = (t%50) / 50.0;
    for(int i=0;i<20;i++)
    {
        angle[i] = alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
        angle2[i]= alpha * NewAngle2[i] + (1-alpha) * OldAngle2[i];
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if(key=='0') ID=0;
    if(key=='1') ID=1;
    if(key=='2') ID=2;
    if(key=='3') ID=3;
    if(key=='s'){ ///save 三選一: save, read, play (重開)
        if(fout==NULL) fout = fopen("motion.txt", "w");
        for(int i=0; i<20; i++){
            fprintf(fout, "%.2f ", angle[i] );
            fprintf(fout, "%.2f ", angle2[i] );
        }
        fprintf(fout, "\n");
        printf("你寫了1行\n");
    }

    if(key=='r'){ ///read 三選一: save, read, play (重開)
        if(fin==NULL) fin = fopen("motion.txt", "r");
        for(int i=0; i<20; i++){
            fscanf(fin, "%f", &angle[i] );
            fscanf(fin, "%f", &angle2[i] );
        }
        glutPostRedisplay();
    }

    if(key=='p'){ ///play 三選一: save, read, play (重開)
        glutTimerFunc(0, timer, 0);
    }
}

void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///有不同
    teapotY += (oldY - y)/10.0; ///有不同
    angle[ID] += x - oldX;
    angle2[ID] += y - oldY; ///有不同
    oldX = x;
    oldY = y; ///有不同
    ///printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0.95f, 0.95f, 0.95f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        glScalef(2,2,2);
        glTranslatef(0, -0.3, 0);
        glPushMatrix();
            glColor3f(1,1,1);///glColor3f(1,0,0);
            glScalef(0.15, 0.15, 0.15);
            glPushMatrix();
                glTranslatef(0 , 0 , 0 );
                glRotatef(angle[3], 0, 1, 0);
                glRotatef(angle2[3], 1, 0, 0);
                glTranslatef(0 , 0 , 0 );
                glmDraw(body, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.000 , 2.200 , 0 );
                glRotatef(angle[0], 0, 1, 0);
                glRotatef(angle2[0], 1, 0, 0);
                glTranslatef(0.000 , -2.200 , 0 );
                glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.600 , 1.900 , 0 );
                glRotatef(angle[1], 0, 1, 0);
                glRotatef(angle2[1], 1, 0, 0);
                glTranslatef(-0.600 , -1.900 , 0 );

                glmDraw(righthand, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.600 , 1.900 , 0 );
                glRotatef(angle[2], 0, 1, 0);
                glRotatef(angle2[2], 1, 0, 0);
                glTranslatef(0.600 , -1.900 , 0 );
                glmDraw(lefthand, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();
        glPopMatrix();

        glColor3f(0,1,0);///中心點的位置
        glutSolidTeapot( 0.01 );///中心點的位置
    glPopMatrix();



    glutSwapBuffers();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("10160172");
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    head = glmReadOBJ("model/head.obj");

    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/gundam.obj");
    righthand = glmReadOBJ("model/righthand.obj");
    lefthand = glmReadOBJ("model/lefthand.obj");
    myTexture("model/snowman.jpg");
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}

