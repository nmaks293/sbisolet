#include "precomp.h"
#include "Scene.h"
#include "UI.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Bonuses.h>

int main()
{
    RenderWindow window(VideoMode::getDesktopMode(), "SBISolet");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    Scene scene{window};
    scene.initScene();

    Clock clock;
    Time deltaTime;

    while (window.isOpen())
    {
        Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::B){
                    //Bonuses::instance->createBonus();
                }

                if(event.key.code == Keyboard::S) {
                    scene.start();
                }
                if(event.key.code==Keyboard::H){
                    Plane::instance->addHP(1);
                }
                if(event.key.code == Keyboard::P){
                    Scene::instance->addBirds(1);
                }
                if(event.key.code==Keyboard::K){
                    Scene::instance->addRocketKit(1);
                }
                if(event.key.code==Keyboard::F){
                   // Sounds::instance->play_big_boom();
                }
                if(event.key.code==Keyboard::I){
                    Plane::instance->addGodModeTime(1);
                }

            }   

        }
        deltaTime = clock.restart();
        scene.update(deltaTime.asSeconds());
        scene.render(window);

        window.display();
    }
    return EXIT_SUCCESS;
}