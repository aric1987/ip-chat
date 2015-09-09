#include <QMenuBar>
#include "chat_widget.h"



ChatWidget::ChatWidget(QWidget *parent) :
	QWidget(parent)
{
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void ChatWidget::addChatDialog(const QString &name)
{
	setWindowTitle(tr("Chating With ") + name);
}

QSize ChatWidget::minimumSizeHint() const
{
	return QSize(600, 400);
}

QSize ChatWidget::sizeHint() const
{
	return QSize(600, 400);
}

ChatWidget::~ChatWidget()
{

}
