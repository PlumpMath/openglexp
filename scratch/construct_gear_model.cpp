#include <stdio.h>
#include <math.h>

struct pt
{
  float x;
  float y;
};

int main(int argc, char **argv)
{
  int numGears = 10;
  float radius = 3.0f;
  float gearlen = 0.6f;
  float gearwid = 1.0f;
  float thickness = 1.0f;

  float radiansPerGear = 2*M_PI/numGears;
  float lenToSubtractFromJutt = radius-sqrt((radius*radius)-((gearwid/2.0f)*(gearwid/2.0f)));

  float curRadian;
  pt offsetFromTangent;
  pt innerCenterOfTooth;
  pt innerCCWTooth;
  pt innerCWTooth;
  pt outerCenterOfTooth;
  pt outerCCWTooth;
  pt outerCWTooth;

  int currentVert = 0;

  for(int i = 0; i < numGears; i++)
  {
    curRadian = radiansPerGear*(float)i;

    offsetFromTangent.x = sin(curRadian)*gearwid/2.0f;
    offsetFromTangent.y = cos(curRadian)*gearwid/2.0f;

    innerCenterOfTooth.x = cos(curRadian)*(radius-lenToSubtractFromJutt);
    innerCenterOfTooth.y = sin(curRadian)*(radius-lenToSubtractFromJutt);

    innerCCWTooth.x = innerCenterOfTooth.x-offsetFromTangent.x;
    innerCCWTooth.y = innerCenterOfTooth.y+offsetFromTangent.y;
    innerCWTooth.x = innerCenterOfTooth.x+offsetFromTangent.x;
    innerCWTooth.y = innerCenterOfTooth.y-offsetFromTangent.y;

    outerCenterOfTooth.x = cos(curRadian)*(radius+gearlen);
    outerCenterOfTooth.y = sin(curRadian)*(radius+gearlen);

    outerCCWTooth.x = outerCenterOfTooth.x-offsetFromTangent.x;
    outerCCWTooth.y = outerCenterOfTooth.y+offsetFromTangent.y;
    outerCWTooth.x = outerCenterOfTooth.x+offsetFromTangent.x;
    outerCWTooth.y = outerCenterOfTooth.y-offsetFromTangent.y;

    //tooth - front
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,innerCWTooth.x,innerCWTooth.y,thickness/2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,outerCWTooth.x,outerCWTooth.y,thickness/2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,outerCCWTooth.x,outerCCWTooth.y,thickness/2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,innerCWTooth.x,innerCWTooth.y,thickness/2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,outerCCWTooth.x,outerCCWTooth.y,thickness/2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,innerCCWTooth.x,innerCCWTooth.y,thickness/2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;

    //tooth - back
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,innerCWTooth.x,innerCWTooth.y,thickness/-2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,-1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,outerCCWTooth.x,outerCCWTooth.y,thickness/-2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,-1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,outerCWTooth.x,outerCWTooth.y,thickness/-2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,-1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,innerCWTooth.x,innerCWTooth.y,thickness/-2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,-1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,innerCCWTooth.x,innerCCWTooth.y,thickness/-2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,-1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,outerCCWTooth.x,outerCCWTooth.y,thickness/-2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,-1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;


    //tooth wedge - front
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(0.0f,0.0f,%f);\n",currentVert,thickness/2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,innerCWTooth.x,innerCWTooth.y,thickness/2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,innerCCWTooth.x,innerCCWTooth.y,thickness/2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;

    //tooth wedge - back
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(0.0f,0.0f,%f);\n",currentVert,thickness/-2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,-1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,innerCCWTooth.x,innerCCWTooth.y,thickness/-2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,-1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,innerCWTooth.x,innerCWTooth.y,thickness/-2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,-1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;

    //neighbor wedge - front
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(0.0f,0.0f,%f);\n",currentVert,thickness/2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,innerCCWTooth.x,innerCCWTooth.y,thickness/2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    //literally do entire calculation in one line
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,(cos(radiansPerGear*(i+1.0f))*(radius-lenToSubtractFromJutt))+(sin(radiansPerGear*(i+1.0f))*gearwid/2.0f),(sin(radiansPerGear*(i+1.0f))*(radius-lenToSubtractFromJutt))-(cos(radiansPerGear*(i+1.0f))*gearwid/2.0f),thickness/2.0f);
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;

    //neighbor wedge - back
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(0.0f,0.0f,%f);\n",currentVert,thickness/-2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,-1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    //literally do entire calculation in one line
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,(cos(radiansPerGear*(i+1.0f))*(radius-lenToSubtractFromJutt))+(sin(radiansPerGear*(i+1.0f))*gearwid/2.0f),(sin(radiansPerGear*(i+1.0f))*(radius-lenToSubtractFromJutt))-(cos(radiansPerGear*(i+1.0f))*gearwid/2.0f),thickness/-2.0f);
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,-1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;
    printf("Models::models[GEAR_MODEL].pos[%d] = glm::vec3(%f,%f,%f);\n",currentVert,innerCCWTooth.x,innerCCWTooth.y,thickness/-2.0f); 
    printf("Models::models[GEAR_MODEL].norm[%d] = glm::vec3(0.0f,0.0f,-1.0f);\n",currentVert);
    printf("Models::models[GEAR_MODEL].color[%d] = glm::vec3(1.0f,0.0,0.0);\n",currentVert); currentVert++;

  }
  printf("Models::models[GEAR_MODEL].numVerts = %d;\n",currentVert);
  printf("Models::models[GEAR_MODEL].wiggle = 0.0f;\n");
  return 0;
}

