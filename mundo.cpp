#include "mundo.h"

Mundo::Mundo(QWidget *parent) : QOpenGLWidget(parent)
{

}

void Mundo::initializeGL()
{
    glClearColor(1,1,1,1);
}

void Mundo::paintGL(){

}
