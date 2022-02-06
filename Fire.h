#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pipe.h"
using namespace std;
class Fires{
        sf::RectangleShape fire,score;
        sf::Texture *text;
        int index,frameL;
    public:
        Fires(){
        //     index=0;
        //     frameL=11;
        //     text=new sf::Texture[frameL];
        //     for(int i=0;i<frameL;i++){
        //         string name="PNG/Fire/frame ("+to_string(i+1)+").png";
        //         text[i].loadFromFile(name.c_str());
        //     }
        //     fire.setTexture(text[index++]);
        fire.setSize(sf::Vector2f(15,10));
        fire.setFillColor(sf::Color::Red); 
        score.setSize(sf::Vector2f(15,10));
        score.setFillColor(sf::Color::Red); 
        score.setPosition(sf::Vector2f(20,30));
        }

        void setposition(float x,float y){
            fire.setPosition(x,y);
        }

        

        // void Animate(){
        //     fire.setTexture(text[index++]);
        //     if(index==frameL)index=0;
        // }
        void move(){
            fire.move(7,0);
            
        }

        bool hit(Bird &b){
            if(b.getGlobal().intersects(fire.getGlobalBounds()))return true;
            return false;
        }

        void draw(sf::RenderWindow &window){
            window.draw(fire);
        }
};