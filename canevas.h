#ifndef CANEVAS_H
#define CANEVAS_H

#include <QWidget>

class Canevas : public QWidget
{
    Q_OBJECT
public:
    explicit Canevas(QWidget *parent = nullptr);


    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // CANEVAS_H
