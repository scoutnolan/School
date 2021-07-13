#ifndef BALLOON_H
#define BALLOON_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Balloon : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Balloon(int color);
    QString myColor = "Null";

signals:

public slots:
};

#endif // BALLOON_H
