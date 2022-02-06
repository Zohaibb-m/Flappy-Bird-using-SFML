#include <SFML/Graphics.hpp>
#include "Bird.h"

class Pipe{
        sf::RectangleShape pipe_u,pipe_l;
        sf::Texture *p;
    public:
        Pipe(sf::Vector2f size){
            p=new sf::Texture[2];
            
            if(!p[0].loadFromFile("PNG/Game/pL.png"))cout << "Error\n";
            p[1].loadFromFile("PNG/Game/pU.png");
            pipe_u.setSize(size);
            pipe_l.setSize(sf::Vector2f(size.x,700-(size.y+170)));
            sf::IntRect rectU(0,160-(pipe_u.getSize().y*280)/700,26,(pipe_u.getSize().y*280)/700+1);
            sf::IntRect rectL(0,0,26,(pipe_l.getSize().y*280)/700);
            pipe_u.setTextureRect(rectU);
            pipe_l.setTextureRect(rectL);
            pipe_u.setTexture(&p[1]);
            pipe_l.setTexture(&p[0]);
            pipe_u.setPosition(sf::Vector2f(600,0));
            pipe_l.setPosition(sf::Vector2f(600,700-pipe_l.getSize().y));
        }

        void draw(sf::RenderWindow &window){
            window.draw(pipe_u);
            window.draw(pipe_l);
        }
        void move(){
            pipe_u.move(sf::Vector2f(-1,0));
            pipe_l.move(sf::Vector2f(-1,0));
        }

        bool isColliding(Bird &b){
            // cout << pipe_u.getGlobalBounds().height << " " << b.getGlobal().height << "\n";
            return pipe_u.getGlobalBounds().intersects(b.getGlobal()) || pipe_l.getGlobalBounds().intersects(b.getGlobal());

        }

        bool isPassed(Bird &b){
            if(b.getXPos()>pipe_u.getPosition().x+170)return true;
            return false;
        }

};  