#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity
{
  private:
  public:
    int worldComponentIndex;
    int physicsComponentIndex;
    int HUDComponentIndex;

    Entity();
    ~Entity();
};

#endif

