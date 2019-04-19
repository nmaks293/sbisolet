#pragma once

class Plane {
    Sprite sprite;
    Vector2f velocity;
public:
    static Plane* instance;

    Plane();

    const Vector2f& getPosition();

    void initScene();
    void update(float deltaTime);
    void render(RenderWindow& window);

private:
    void setPosition(Vector2f position);
};