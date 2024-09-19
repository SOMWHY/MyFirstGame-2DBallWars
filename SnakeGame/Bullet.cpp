#include "Bullet.h"

void Bullet::InitBullet()
{
    direction = Vector2f(0, 0);
    bulletSpeed = 15.f;
    bulletTimer = 0.f;
    bulletTime = 0.25f;

    bullet.setFillColor(Color::White);
    bullet.setSize(Vector2f(50.f,5.f));
    

}

void Bullet::ClearBullet(CircleShape playerShape,float vectorLength)
{
   
  
    for (size_t i = 0; i < bullets.size(); i++) {
        everyBulletDir = bullets[i].getPosition() - playerShape.getPosition();

        bulletDistance = sqrt(pow(everyBulletDir.x, 2) + pow(everyBulletDir.y, 2));
    
       if(bulletDistance >vectorLength)
        bullets.erase(bullets.begin() + i);
    }

      
    
}



void Bullet::Move(RenderWindow* window, CircleShape playerShape,View& view)
{

    bulletTimer++;
 
    
    if (Mouse::isButtonPressed(Mouse::Left)&& bulletTimer > bulletTime) {
    bullet.setPosition(playerShape.getPosition());
    bullets.push_back(bullet);
    mousePos = Mouse::getPosition(*window);
   mousePosF = window->mapPixelToCoords(mousePos, view);
    direction = mousePosF - playerShape.getPosition();

    vectorLength =sqrt(direction.x * direction.x + direction.y * direction.y);
        direction /= vectorLength; // πÈ“ªªØ


    bulletTimer = 0;
        //cout <<"mouse: " << mousePosF.x << " " << mousePosF.y << endl;
        //cout << playerShape.getPosition().x<<" " << playerShape.getPosition().y << endl;
    }
  
    ClearBullet(playerShape,vectorLength);
   

}

Bullet::Bullet()
{
    InitBullet();
}

Bullet::~Bullet()
{
}


void Bullet::Update(RenderWindow* window,CircleShape playerShape, View& view)
{
    
    Move(window,playerShape,view);
}

void Bullet::Render(RenderWindow* window)
{
    for (size_t i = 0; i < bullets.size(); i++) {

        bullets[i].move(direction.x * bulletSpeed, direction.y * bulletSpeed);

        window->draw(bullets[i]);
    }

    
}
