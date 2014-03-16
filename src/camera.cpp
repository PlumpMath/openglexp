#include "camera.h"

Camera::Camera()
{
  projMat = glm::perspective(45.0f, 2.0f, 0.1f, 100.0f);
  viewMat = glm::lookAt(glm::vec3(-20,0,5),glm::vec3(0,0,-5),glm::vec3(0,1,0));
}

Camera::~Camera()
{

}

