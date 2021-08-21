#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include "camera.h"

#ifndef MUNDO_H
#define MUNDO_H


class Mundo : public QOpenGLWidget
{
    Q_OBJECT
public:
    Mundo(QWidget *parent);
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);

    void desenha();
    void desenhaEixos();


     Camera pessoa;
};

#endif // MUNDO_H
