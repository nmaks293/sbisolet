#include "precomp.h"
#include "Balloon.h"
#include "Plane.h"
#include "Scene.h"
Balloon::Balloon(float xPos, float yPos) : isAlive(true) {
    sprite.setTexture(Scene::instance->getEffectsTexture());
    sprite.setTextureRect(IntRect(0,0,256,256));
    sprite.setOrigin(128, 128);

    sprite.setScale(ENEMIES_BALLOON_H_SIZE / 256, -ENEMIES_BALLOON_V_SIZE / 256);
    velocity = Vector2f(-ENEMIES_BALLOON_H_SPEED, ENEMIES_BALLOON_V_SPEED);
    sprite.setPosition(xPos, yPos);
}

void Balloon::initScene() {
    isAlive = true;
}

void Balloon::update(float deltaTime) {
    sprite.setPosition(sprite.getPosition() + velocity * deltaTime);
    FloatRect rect = sprite.getGlobalBounds();
    float p = 0.2;
    float width = rect.width;
    float height = rect.height;
    rect.left += width * p;
    rect.top -= height * p;
    rect.width = width * (1-p);
    rect.height = height * (1-p);
    if (sprite.getGlobalBounds().intersects(Plane::instance->getGlobalBounds())) {
        Plane::instance->addHP(-ENEMIES_BALLOON_DAMAGE);
        isAlive = false;
    }
    if (sprite.getPosition().x < Camera::instance->getRect().left-50) {
        isAlive = false;
    }
}

void Balloon::render(RenderWindow &window) {
    window.draw(sprite);
}

bool Balloon::isToBeRemoved() {
    return !isAlive;
}


