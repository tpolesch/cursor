
#include <QApplication>
#include <QPainter>
#include <QMouseEvent>
#include "main.h"
     
void MainWindow::paintEvent(QPaintEvent *event)
{
     QPainter painter(this);
     painter.setPen(Qt::blue);
     painter.setFont(QFont("Arial", 30));
     painter.drawText(rect(), Qt::AlignCenter, "Qt");;
     
     painter.setPen(Qt::gray);
     painter.drawLine(0, leftPoint.y(), width(), leftPoint.y());
     painter.drawLine(0, rightPoint.y(), width(), rightPoint.y());

     painter.drawLine(leftPoint.x(), 0, leftPoint.x(), height());
     painter.drawLine(rightPoint.x(), 0, rightPoint.x(), height());
}

void MainWindow::movePoint(int step)
{
	QPoint & point = ((pointIndex % 2) == 0) ? leftPoint : rightPoint;
	point.rx() += step;
	update();
}

void MainWindow::nextPoint()
{
	++pointIndex;
}
     
void MainWindow::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
		case Qt::Key_Left:
			movePoint(-1);
			break;
		case Qt::Key_Right:
			movePoint(1);
			break;
		case Qt::Key_Down:
		case Qt::Key_Up:
			nextPoint();
			break;
		default:
			QMainWindow::keyPressEvent(event);
	}
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
         leftPoint = event->pos();
         update();
         return;
    }

    if (event->button() == Qt::RightButton)
    {
         rightPoint = event->pos();
         update();
         return;
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}

