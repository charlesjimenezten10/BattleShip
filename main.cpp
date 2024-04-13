#include <QApplication>
#include <QGraphicsScene>
#include "player.h" // replaced from <QGraphicsItem> -> myRect is derived from it
#include <QGraphicsView>
#include <QTimer>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    Player * player = new Player();
    player->setRect(0, 0,100,100);
    player->setFlag(QGraphicsItem::ItemIsFocusable); // allows to focus on item as only one item at a scene can respond to q events
    player->setFocus();


    scene->addItem(player);
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // disables horizontal scrollbar
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // disables vertical scrollbar
    view->show();
    view->setFixedSize(800, 800);
    // view->setSceneRect(scene->sceneRect());
    scene->setSceneRect(0,0, 800, 800);
    player->setPos(view-> width() / 2, view -> height() - (player -> rect().height()) - 10);

    // Enemy * enemy = new Enemy();
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(50);
    // scene->addItem(enemy);
    return a.exec();
}
