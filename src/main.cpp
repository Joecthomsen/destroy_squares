#include "Game.h"

int main(){

    //VideoMode mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings()
/*     sf::RenderWindow window(sf::VideoMode(800, 800), "Astroids", sf::Style::Close | sf::Style::Titlebar);
    window.setPosition(sf::Vector2i(200,200)); */

    //init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    //Init game engine
    Game game;

    sf::Event evnt;
    
    //Game loop
    while(game.running())
    {
        //Update
        game.update();

        //Render
        game.render();
    }
    return 0;
}