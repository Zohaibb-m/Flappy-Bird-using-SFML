#include "SFML/Graphics.hpp"
#include <iostream>
#include <windows.h>
#include "Fire.h"
#include "Main.h"
#include "Score.h"
using namespace std;

sf::RenderWindow window(sf::VideoMode(600,700),"Test Window");


int main(){
    sf::Sprite bg,land[2];
    sf::Texture bgTexture,land_t;
    bgTexture.loadFromFile("PNG/Game/BG.png");
    bg.setTexture(bgTexture);
    int time=0;
    Game g;
    sf::Event evnt;
    Bird bird("Grumpy",4);
    vector <Bird> Enemies;
    vector <Pipe> pipes;
    vector <Fires> fires;
    int gravity=10;
    int bullets=1;
    bool isDead=false,play=false,playAgain=true,drawMain=true;
    window.setFramerateLimit(70);
    window.setKeyRepeatEnabled(false);
    land_t.loadFromFile("PNG/Game/land.png");
    land[0].setTexture(land_t);
    land[1].setTexture(land_t);
    land[0].setScale(4,3);
    land[1].setScale(4.3,3);
    land[0].setPosition(sf::Vector2f(0,600));
    land[1].setPosition(sf::Vector2f(500,600));
    int land_index=1;
    bool isFired=false;
    string enemyB[]={"BlueBat","Dragon","Green_Horn","HatBird","Side_Scroller"};
    int enemyF[]={11,4,17,2,2},score=0;
    Score scr;
    while(window.isOpen()){
        while(window.pollEvent(evnt)){
            if(evnt.type==sf::Event::Closed){
                window.close();
            }
        }
        if(!play || playAgain){
            if(playAgain){bird.Alive();play=false;}
            // cout << play << " " << playAgain << "\n";
            time++;
            if(time%10==0)bird.Animate();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){play=true;playAgain=false;}
            window.clear();
            window.draw(bg);
            for(int i=0;i<2;i++){
            if(-530>=land[i].getPosition().x)land[i].setPosition(400,600);
            }
            if(drawMain){
            g.drawMain(window);
            g.drawPlayButton(window);
            g.drawTap(window);
            }
            window.draw(land[0]);
            window.draw(land[1]);
            land[0].move(-1,0);
            land[1].move(-1,0);
            bird.draw(window);
            window.display();
            pipes.clear();
            Enemies.clear();
        }
        else if(!bird.isDead()){
            if(playAgain){playAgain=false;}
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                bird.fly(20);
            }
            else bird.fall(gravity);
            time++;
            if(time%500==0){
                Pipe newPipe(sf::Vector2f(120,rand()%400));
                pipes.push_back(newPipe);
                time=0;
            }
            if(time%350==0){
                int ind=rand()%5;
                Bird newB(enemyB[ind],enemyF[ind]);
                newB.setposition(600,rand()%600);
                Enemies.push_back(newB);
            }
            if(time%10==0){
                bird.Animate();
                for(int i=0;i<Enemies.size();i++){
                    Enemies[i].Animate();
                }
                // for(int i=0;i<fires.size();i++){
                //     fires[i].Animate();
                // }
            }
            Fires newFire;
            if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && bullets>0){
                newFire.setposition(bird.getXPos(),bird.getYPos()+5);
                bullets--;
                isFired=true;
            }
            window.clear();
            window.draw(bg);
            for(int i=0;i<2;i++){
                if(-530>=land[i].getPosition().x)land[i].setPosition(400,600);
            }
            for(int i=0;i<pipes.size();i++){
                pipes[i].draw(window);
                pipes[i].move();
            }
            for(int i=0;i<Enemies.size();i++){
                Enemies[i].move();
                Enemies[i].draw(window);
            }
            for(int i=0;i<fires.size();i++){
                fires[i].move();
                fires[i].draw(window);
                for(int j=0;j<Enemies.size();j++){
                    if(fires[i].hit(Enemies[j])){Enemies[j].Hit();Enemies.pop_back();}
                }
            }
            window.draw(land[0]);
            window.draw(land[1]);
            land[0].move(-1,0);
            land[1].move(-1,0);
            if(bird.getYPos() > 530 )bird.Died();
            for(int i=0;i<pipes.size();i++){
                if(pipes[i].isColliding(bird))bird.Died();            
                if(pipes[i].isPassed(bird)){score++;if(score%2==0)bullets++;pipes.erase(begin(pipes));}
            }
            if(isFired){
                fires.push_back(newFire); 
                isFired=false;
            }
            scr.drawScore(score,window);
            for(int i=0;i<Enemies.size();i++){
                if(bird.isCollided(Enemies[i]))bird.Died();      
            }
            bird.draw(window);
            window.display();
        }
        else if(!playAgain){
            drawMain=false;
            window.clear();
            window.draw(bg);
            for(int i=0;i<pipes.size();i++){
            pipes[i].draw(window);
            }
            if(g.getPlayGlobalBounds().contains((float)sf::Mouse::getPosition(window).x,(float)sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){playAgain=true;bullets=1;score=0;}
            g.drawgameOver(window);
            g.drawPlayButton(window);
            window.draw(land[0]);
            window.draw(land[1]);
            bird.fall(gravity);
            bird.draw(window);
            window.display();
        }
    }
}
