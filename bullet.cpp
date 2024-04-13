#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet()
{
    // this draws the bullets (thin bullets cuz u dont want it big lol)
    setRect(0,0, 10, 50);
    QTimer * timerMachineGun = new QTimer(this);
    connect(timerMachineGun, SIGNAL(timeout()), this, SLOT(machineGun()));
    timerMachineGun->start(50);

    // QTimer * timerRocketLauncher = new QTimer(this);

    // connect(timerRocketLauncher, SIGNAL(timeout()), this, SLOT(rocketLauncher()));
    // timerRocketLauncher->start(1000);
    // qDebug() << "Rocket launcher timer started.";
}

void Bullet::machineGun() {
    setPos(x(), y()-10);
    if(pos().y() + rect().height() < 0) {
        scene()->removeItem(this);// scene member function
        delete this;
        qDebug() << "Bullet deleted";
    }
    // qDebug() << "Machine gun bullet moved.";
}

void Bullet::rocketLauncher() {
    setPos(x(), y()-10);
    // qDebug() << "Rocket launcher bullet moved.";
}
