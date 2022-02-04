#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <vector>
#include <ctime>

/*
    Class that represent the game engine
*/

class Game
{
private:

    //Variables
    sf::Vector2i mousePos;
    sf::Vector2f mousePosView;

    //Window
    sf::RenderWindow * window;
    sf::Event evnt;

    //Private functions
    void initVariables();
    void initWindow();
    void initEnemies();

public:
    //Constructors and destructors
    Game();
    virtual ~Game();

    //Game logic
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    int points;

    //Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    //Accessors
    bool running();

    //Functions
    void spawnEnemy();
    void updateEnemies();
    void renderEnemies();
    void update();
    void render();
    void pollEvents();
    void getMousePos();

    void test1();
    sf::Vector2f test2(float a, float b);


};

#endif