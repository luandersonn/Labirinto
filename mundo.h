#include <QOpenGLWidget>

#ifndef MUNDO_H
#define MUNDO_H


class Mundo : public QOpenGLWidget
{
    Q_OBJECT
public:
    Mundo(QWidget *parent);
    void initializeGL();
    void paintGL();
};

#endif // MUNDO_H
