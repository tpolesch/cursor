#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
protected:
     void paintEvent(QPaintEvent *event);
     void mousePressEvent(QMouseEvent *event);
     void keyPressEvent(QKeyEvent *event);
private:
     void movePoint(int step);
     void nextPoint();
     int pointIndex;
     QPoint leftPoint;
     QPoint rightPoint;
};

#endif
