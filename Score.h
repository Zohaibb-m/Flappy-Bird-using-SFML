#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Score{
    sf::Sprite score1,score2;
    sf::Texture *text;
    public:
        Score(){
            text=new sf::Texture[10];
            for(int i=0;i<10;i++){
                string name="PNG/Game/"+to_string(i)+".png";
                text[i].loadFromFile(name.c_str());
            }
            score1.setPosition(250,160);
            score2.setPosition(280,160);
            score1.setScale(3,3);
            score2.setScale(3,3);
        }

        void drawScore(int score,sf::RenderWindow &window){
            if(score<10){
                score1.setTexture(text[score]);
                window.draw(score1);
            }
            else {
                score2.setTexture(text[score%10]);
                score1.setTexture(text[score/10]);
                window.draw(score1);
                window.draw(score2);
            }
        }
};