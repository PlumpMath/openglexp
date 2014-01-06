#ifndef _GAME_H_
#define _GAME_H_

class MyGL;
class Input;
class Graphics;
class World;

class Game
{
  private:
    MyGL* myGL;
    Input* input;
    Graphics* graphics;
    World* world;
  public:
    Game();
    ~Game();
    void run();
};

#endif

