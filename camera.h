#ifndef CAMERA_H
#define CAMERA_H
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"
#include <GL/glu.h>

class Camera
{
public:
    Camera();

    glm::vec3 vec_i, vec_j, vec_k, pos, eye, at, up;

    void gira(float distancia);
    void anda(float angulo);

    void aplica();
    //void keyPressEvent(QKeyEvent *e);
};

#endif // CAMERA_H
