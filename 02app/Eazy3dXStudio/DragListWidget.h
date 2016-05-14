#ifndef DRAG_TABLE_H
#define DRAG_TABLE_H

#include <QTableWidget>
#include <QListWidget>
#include <QtGui>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QListView>


class DragListWidget : public QListWidget
{
public:
	DragListWidget(QWidget *parent = 0);
protected:
	void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dropEvent(QDropEvent *event);
public:
	QPoint startPos;
	QPoint endPos;
    QMimeData* mimeData;
};

#endif
