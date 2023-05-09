#ifndef CANEVAS_H
#define CANEVAS_H

#include <QGridLayout>
#include <QLabel>
#include <QWidget>

class Canevas : public QWidget
{
    Q_OBJECT
private:
    QGridLayout *grid_layout = new QGridLayout();
    QLabel message = QLabel("Je ne suis pas un hero, je veux pas croire \nce que disent les journaux");
    QLabel cases[2][2] = {
        {
            QLabel("first case"),
            QLabel("second case")
        },
        {
            QLabel("third case"),
            QLabel("fourth case")
        }
    };
    int selected_case_indexes[2] = {0, 0};
    QLabel *selected_case = &cases[selected_case_indexes[0]][selected_case_indexes[1]];

    void updateSelectedCase();

public:
    explicit Canevas(QWidget *parent = nullptr);


    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // CANEVAS_H
