#include "Game.h"

    //Constructors and destructors
Game::Game(){
    initVariables();
    initEnemies();
    initWindow();
    
}

Game::~Game(){
    delete this->window;
}

    //Private functions
void Game::initVariables()
{
    this->window = nullptr;
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10;
    this->points = 0;
};

void Game::initEnemies()
{
    //this->enemy.setPosition(100.f, 100.f);
    this->enemy.setSize(sf::Vector2f(50.0f, 50.0f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
}

void Game::initWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Astroids", sf::Style::Close | sf::Style::Titlebar);
    this->window->setPosition(sf::Vector2i(200,200));
    this->window->setFramerateLimit(60);
};

    //Accesors
bool Game::running(){
    return this->window->isOpen();
}

    //Functions
void Game::spawnEnemy()
{

    int ranNum = rand() % 5;

        this->enemy.setPosition(
        static_cast<float>( rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f);

    switch(ranNum)
    {
        case 0:
        this->enemy.setFillColor(sf::Color::Red);
        this->enemy.setSize(sf::Vector2f(20.0f, 20.0f));
        break;

        case 1:
        this->enemy.setFillColor(sf::Color::Blue);
        this->enemy.setSize(sf::Vector2f(40.0f, 40.0f));
        break;

          case 2:
        this->enemy.setFillColor(sf::Color::Magenta);
        this->enemy.setSize(sf::Vector2f(60.0f, 60.0f));
        break;

          case 3:
        this->enemy.setFillColor(sf::Color::Cyan);
        this->enemy.setSize(sf::Vector2f(80.0f, 80.0f));

        break;

          case 4:
        this->enemy.setFillColor(sf::Color::Green);
        this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
        break;
    }
        this->enemies.push_back(this->enemy);
};

void Game::updateEnemies()
{

    bool deleted = false;
    //Update timer and spawn when timer runs out
    if(this->enemies.size() < this->maxEnemies)
    {
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            this->spawnEnemy();
            this->enemySpawnTimer = 0;
        }
        else
        this->enemySpawnTimer += 1.f;
    }
    //Move enemy
    for (int i = 0 ; i < this->enemies.size() ; i++)
    {
        enemies[i].move(0.f, 5.f);

        //Chack if clicked upon
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if(this->enemies[i].getGlobalBounds().contains(this->mousePosView))
            {
                deleted = true;
                if(this->enemies[i].getFillColor() == sf::Color::Green){this->points += 1;}
                else if(this->enemies[i].getFillColor() == sf::Color::Cyan){this->points += 3;}
                else if(this->enemies[i].getFillColor() == sf::Color::Magenta){this->points += 5;}
                else if(this->enemies[i].getFillColor() == sf::Color::Blue){this->points += 7;}
                else if(this->enemies[i].getFillColor() == sf::Color::Red){this->points += 10;}
            }
       
        }
        //Delete enemy if out of screen
        if(this->enemies[i].getPosition().y > this->window->getSize().y)
        {
            deleted = true;
        }
        if(deleted)
        {
            this->enemies.erase(this->enemies.begin() + i);
            deleted = false;
        };

    }
};

void Game::renderEnemies()
{
   for (int i = 0 ; i < this->enemies.size() ; i++)
    {
        this->window->draw(this->enemies[i]);
    }
};


void Game::getMousePos()
{
    this->mousePos = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePos);
}

void Game::update()
{
    this->pollEvents();
    this->getMousePos();
    this->updateEnemies();
}


void Game::render()
{

    /*
    Renders the game objects
        @ Return void
        - Clear old frame
        - Render objects
        - Display old frame
    */

    this->window->clear();
    //this->window->draw(this->enemy);
    this->renderEnemies();
    this->window->display();
}

void Game::pollEvents(){

    while(this->window->pollEvent(this->evnt))
    {
        switch (this->evnt.type)
        {
        case sf::Event::Closed :
            this->window->close();
            break;
        
        case sf::Event::KeyPressed :
            if(this->evnt.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;

        default:
            break;
        }
    }
}


