#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
// #include <cstdlib>
#include <QGraphicsScene>
#include <QDebug>

Enemy::Enemy() {
    int sceneWidth = scene() -> width() - 100;
    qDebug() << sceneWidth;
    setPos(300, 0);
    setRect(0,0, 100, 100);
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer ->start(50);
}

void Enemy::move()
{
    setPos(x(), y()+10);
    if(pos().y() + rect().height() < 0) {
        scene()->removeItem(this);// scene member function
        delete this;
        qDebug() << "Bullet deleted";
    }
}
