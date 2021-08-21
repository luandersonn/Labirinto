#include "mundo.h"

Mundo::Mundo(QWidget *parent) : QOpenGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
}

void Mundo::paintGL()
{
    glClearColor(1, 1, 1, 1);
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

    desenhaEixos();
    glTranslatef(-size * n / 2, 0.0, -size * n / 2);
    desenha();
}

void Mundo::initializeGL()
{
    glClearColor(1, 1, 1, 1);

    //glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    glEnable(GL_POINT_SMOOTH);
}

void Mundo::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    glClearColor(0, 0, 0, 1);
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
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
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
