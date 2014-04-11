#ifndef _MODELS_H_
#define _MODELS_H_

#define MAX_VERTS 20

#include <glm/glm.hpp>
class Entity;

class Models
{
  private:
  public:
    int numVerts;
    glm::vec3 pos[MAX_VERTS];
    glm::vec3 color[MAX_VERTS];
    glm::vec3 norm[MAX_VERTS];
};

#endif

