#include "DragListWidget.h"
#include <QApplication>

DragListWidget::DragListWidget(QWidget *parent):QListWidget(parent)
{
	this->setCurrentRow(10);
	this->setAcceptDrops(true);//设置QListWidget的Item项可以被拖拽

}

void DragListWidget::mousePressEvent( QMouseEvent *event )
{
	if (event->button() == Qt::LeftButton)
		startPos = event->pos();
	QListWidget::mousePressEvent(event);
}

void DragListWidget::mouseMoveEvent(QMouseEvent *event)
{
	QListWidgetItem *item = currentItem();
    mimeData = new QMimeData();
    mimeData->setText(item->text());
	QDrag *drag = new QDrag(this);
	drag->setMimeData(mimeData);
	Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
	if(dropAction == Qt::MoveAction)
	{
		delete item;//删除原有的item,在dropEvent(QDropEvent *event)函数中插入item
	}
}

void DragListWidget::mouseReleaseEvent(QMouseEvent *event)
{
	int distance = (endPos - startPos).manhattanLength();
	if (distance >= QApplication::startDragDistance())
	{
        startDrag(Qt::IgnoreAction);
	}
}

void DragListWidget::dragEnterEvent( QDragEnterEvent *event )
{
	DragListWidget *source = (DragListWidget *)((void*)(event->source()));
	if (source && source == this) {
//        endPos = event->pos();//得到鼠标移动到的坐标
//        QListWidgetItem *itemRow = itemAt(endPos);//通过endPos获取鼠标位置所在的行
//        if(itemRow ==NULL)
//            return;
//        itemRow->setBackgroundColor(QColor(0,0,0));

		event->setDropAction(Qt::MoveAction);
		event->accept();
	}
}

void DragListWidget::dragMoveEvent( QDragMoveEvent *event )
{
	DragListWidget *source = (DragListWidget *)((void*)(event->source()));
	if (source && source == this) {
//        endPos = event->pos();//得到鼠标移动到的坐标
//        QListWidgetItem *itemRow = itemAt(endPos);//通过endPos获取鼠标位置所在的行
//        if(itemRow ==NULL)
//            return;
//        itemRow->setBackgroundColor(QColor(255,0,0));

		event->setDropAction(Qt::MoveAction);
		event->accept();
	}
}

void DragListWidget::dropEvent( QDropEvent *event )
{
	DragListWidget *source = (DragListWidget *)((void*)(event->source()));
	if (source && source == this) 
	{
		endPos = event->pos();//得到鼠标移动到的坐标
        QListWidgetItem *itemRow = itemAt(endPos);//通过endPos获取鼠标位置所在的行
        if(itemRow ==NULL)
            return;
		int rowCount = row(itemRow);
        insertItem(rowCount + 1,mimeData->text());//row+1 为鼠标所指向的行，如果只是向末尾位置插入，把insertItem(rowCount + 1,mimeData->text())改为addItem(mimeData->text())
		event->setDropAction(Qt::MoveAction);
		event->accept();
	}
}
