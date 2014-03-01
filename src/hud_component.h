#ifndef _HUD_COMPONENT_H_
#define _HUD_COMPONENT_H_

#define MAX_VERTS 100

#include "gl_include.h"

class HUDComponent
{
  private:
  public:
    HUDComponent();
    ~HUDComponent();

    int entityIndex;

    int numVerts;
    glm::vec3 posData[MAX_VERTS];
    glm::vec3 colorData[MAX_VERTS];
    glm::mat4 modelMat;
};

#endif

