#include <SFML/Graphics.hpp>

class Game{
    sf::Sprite main,game_o,play_b,tap;
    sf::Texture *text;
    bool animate;
    public:
    Game(){
        animate=0;
        text=new sf::Texture[4];
        text[0].loadFromFile("PNG/Game/main.png");
        text[1].loadFromFile("PNG/Game/Game_over.png");
        text[2].loadFromFile("PNG/Game/Play_B.png");
        text[3].loadFromFile("PNG/Game/tap.png");
        main.setTexture(text[0]);
        game_o.setTexture(text[1]);
        play_b.setTexture(text[2]);
        tap.setTexture(text[3]);
        main.setPosition(80,80);
        game_o.setPosition(70,80);
        play_b.setPosition(180,350);
        tap.setPosition(190,450);
        main.setScale(5,5);
        play_b.setScale(3,3);
        game_o.setScale(5,5);
        tap.setScale(3,3);
    }

    void drawMain(sf::RenderWindow &window){
        window.draw(main);
    }
    void drawgameOver(sf::RenderWindow &window){
        window.draw(game_o);
    }
    void drawPlayButton(sf::RenderWindow &window){
        window.draw(play_b);
    }
    void drawTap(sf::RenderWindow &window){
        window.draw(tap);
    }
    sf::FloatRect getPlayGlobalBounds(){
        return play_b.getGlobalBounds();
    }


};