#include "camera.h"
#include <iostream>
using namespace std;

Camera::Camera()
{
    eye = glm::vec3(0,0,0); // Olhando pra onde?
    at = glm::vec3(1,0,1);
    up = glm::vec3(0,2,0); // Altura

    pos = glm::vec3(0,0.5,0);
    vec_i = glm::vec3(1,0,0);
    vec_j = glm::vec3(0,1,0);
    vec_k = glm::vec3(0,0,1);

    vec_k = eye - at;
    vec_k = glm::normalize(vec_k);
    vec_i = glm::cross(up,vec_k);
    vec_i = glm::normalize(vec_i);
    vec_j = glm::cross(vec_k, vec_i);
    vec_j = glm::normalize(vec_j);    
}


void Camera::anda(float distancia)
{
    pos = pos + distancia * vec_k;
}

void Camera::gira(float angulo)
{
    glm::mat4 mat_rotacao = glm::rotate(glm::mat4(1.0), glm::radians(angulo), glm::vec3(0,1,0));
    vec_i = glm::vec3(mat_rotacao * glm::vec4(vec_i,0));
    vec_k = glm::vec3(mat_rotacao * glm::vec4(vec_k,0));
}

void Camera::aplica()
{
    glm::mat4x4 matriz = glm::mat4(1.0);
    matriz[0] = glm::vec4(vec_i,0);
    matriz[1] = glm::vec4(vec_j,0);
    matriz[2] = glm::vec4(vec_k,0);
    matriz[3] = glm::vec4(pos,  1);
    matriz = glm::inverse(matriz);
    //glPushMatrix();
    glLoadMatrixf(glm::value_ptr(matriz));
    //glPopMatrix();    
}
