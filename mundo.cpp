#include "mundo.h"

Mundo::Mundo(QWidget *parent) : QOpenGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
}

void Mundo::paintGL()
{
    glClearColor(0.5, 0.5, 0.5, 1);
    int size = 1;
    int n = 10;
    glMatrixMode(GL_PROJECTION);

    float largura = 1.0;
    float altura = largura * height() / width();
    glm::mat4 matrixProjection = glm::frustum(-largura / 2.0f, largura / 2.0f, -altura / 2.0f, altura / 2.0f, 1.0f, 1000.0f);
    //matrixProjection = glm::perspective();
    glLoadMatrixf(glm::value_ptr(matrixProjection));

    glMatrixMode(GL_MODELVIEW);
    pessoa.aplica();
    float s = 0.5;
    glScalef(s,s,s);
    glRotatef(45,0,1,0);
    desenhaEixos();
    //glTranslatef(-size * n / 2, 0.0, -size * n / 2);

    desenha();
}

void Mundo::initializeGL()
{
    glClearColor(0.5, 0.5, 0.5, 1);

    //glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    glEnable(GL_POINT_SMOOTH);
}

void Mundo::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    glClearColor(0.5, 0.5, 0.5, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5, 5, -5, 5, 1, 1000);
    glMatrixMode(GL_MODELVIEW); //Transformações locais e de câmera
    glLoadIdentity();
}

void Mundo::desenha()
{
    int n = 10;
    int size = 1;
    bool aux = true;
    //glColor3f(1,0,0);
    glBegin(GL_QUADS);
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {

            if (aux)
            {
                glColor3f(1.0, 0.0, 0.0);
            }
            else
            {
                glColor3f(0.3, 0.3, 0.3);
            }
            aux = !aux;
            glVertex3f(size * i, 0, size * j);
            glVertex3f(size * (i + 1), 0, size * j);
            glVertex3f(size * (i + 1), 0, size * (j + 1));
            glVertex3f(size * i, 0, size * (j + 1));
        }
        aux = !aux;
    }
    glEnd();
}

void Mundo::desenhaEixos()
{
    glLineWidth(3);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(50, 0, 0);
    glEnd();
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 50, 0);
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 50);
    glEnd();
    glLineWidth(1);

    glColor3f(0.1, 0.1, 0.1);
    buildWall(   0,  0,  0,  100);
    buildWall(0, 100, 55, 100);
    buildWall(60, 100, 100, 100);
    buildWall(100, 100, 100, 0);
    buildWall(100, 0, 0, 0);

    buildWall(  30,  0,  30,  10);
    buildWall(  30,  10, 20,  10);
    buildWall(  20,  10, 20,  30);
    buildWall(  20,  30, 50,  30);

    buildWall(  0, 10, 10, 10);

    buildWall( 10, 20, 10, 40);
    buildWall( 10, 40, 20, 40);
    buildWall( 20, 40, 20, 50);
    buildWall( 20, 50, 40, 50);

    buildWall(0, 50, 10, 50);
    buildWall(10, 50, 10, 60);
    buildWall(10, 60, 20, 60);

    buildWall(0, 80, 10, 80);

    buildWall(10, 90, 20, 90);

    buildWall(20, 100, 20, 70);

    buildWall(30, 50, 30, 70);

    buildWall(10, 70, 80, 70);
    buildWall(80, 70, 80, 90);

    buildWall(50, 70, 50, 80);

    buildWall(60, 70, 60, 60);

    buildWall(80, 80, 60, 80);

    buildWall(40, 100, 40, 80);
    buildWall(40, 80, 30, 80);
    buildWall(30, 80, 30, 90);

    buildWall(40, 90, 70, 90);

    buildWall(90, 100, 90, 70);


    buildWall(100, 60, 70, 60);
    buildWall(70, 60, 70, 50);
    buildWall(70, 50, 50, 50);
    buildWall(50, 50, 50, 60);
    buildWall(50, 60, 40, 60);

    buildWall(60, 50, 60, 30);

    buildWall(30, 40, 50, 40);
    buildWall(50, 40, 50, 20);
    buildWall(50, 20, 80, 20);
    buildWall(80, 20, 80, 10);

    buildWall(70, 0, 70, 10);

    buildWall(60, 20, 60, 10);

    buildWall(50, 0, 50, 10);
    buildWall(50, 10, 40, 10);
    buildWall(40, 10, 40, 20);
    buildWall(40, 20, 30, 20);

    glColor3f(0.4, 0.5, 0.9);
    buildWall(70, 20, 70, 40);
    buildWall(70, 40, 80, 40);
    buildWall(80, 40, 80, 50);

    buildWall(90, 0, 90, 50);

    buildWall(90, 30, 80, 30);

}

void Mundo::buildWall(float x_start, float z_start, float x_end, float z_end, float height)
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(x_start, 0, z_start);
    glVertex3f(x_start, height, z_start);

    glVertex3f(x_end, height, z_end);
    glVertex3f(x_end, 0, z_end);
    glEnd();
    glPopMatrix();
}

void Mundo::mousePressEvent(QMouseEvent *e)
{
}

void Mundo::keyPressEvent(QKeyEvent *e)
{
    char tecla = e->key();
    int girarValor = 4;
    switch (tecla)
    {
    case Qt::Key_A:
        pessoa.gira(girarValor);
        break;
    case Qt::Key_D:
        pessoa.gira(-girarValor);
        break;
    case Qt::Key_W:
        pessoa.anda(-0.2);
        break;
    case Qt::Key_S:
        pessoa.anda(0.2);
        break;
    }
    update();
}
