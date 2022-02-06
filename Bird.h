#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
class Bird{
    sf::Sprite bird;
    sf::Texture *texture;
    bool Dead,isHit;
    int index,frameL;
    public:
        Bird(string filename,int frameL){
            index=0;
            isHit=false;
            this->frameL=frameL;
            texture=new sf::Texture[frameL];
            for(int i=0;i<this->frameL;i++){
                string name="PNG/"+filename +"/frame ("+to_string(i+1)+").png";
                texture[i].loadFromFile(name.c_str());
            }
            sf::IntRect Rect(0,0,717,610);
            bird.setTexture(texture[index++]);
            // bird.setTextureRect(Rect);
            bird.setScale(sf::Vector2f(0.1,0.1));
            bird.setPosition(sf::Vector2f(50,250));
            Dead=false;
        }
        void fall(float gravity){
            if(Dead && getYPos()>=570)return;
            // bird.rotate(5);
            // bird.setRotation(10);
            bird.move(sf::Vector2f(0,gravity/3));
        }

        void Animate(){
            if(index==frameL)index=0;
            bird.setTexture(texture[index++]);
        }
        
        void fly(float gravity){
            if(Dead)return;
            bird.move(sf::Vector2f(0,-gravity/10-5));
        }

        float getXPos(){
            return bird.getPosition().x;
        }

        float getYPos(){
            return bird.getPosition().y;
        }

        sf::FloatRect getGlobal(){
            return bird.getGlobalBounds();
        }

        void Died(){
            Dead=true;
        }

        void Alive(){
            bird.setPosition(sf::Vector2f(50,250));
            Dead=false;
        }

        bool isDead(){
            if(Dead)return true;
            return false;
            // bird.setPosition(sf::Vector2f(bird.getPosition().x,670));
        }
        void draw(sf::RenderWindow &window){
            if(!isHit)
                window.draw(bird);
        }

        void move(){
            bird.move(-3,0);
        }

        bool isCollided(Bird &b){
            if(bird.getGlobalBounds().intersects(b.getGlobal()))return true;
            return false;
        }
        void setposition(float x, float y){
            bird.setPosition(x,y);
        }

        void Hit(){
            isHit=true;
        }
};