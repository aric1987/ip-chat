#include "user_list_widget.h"

UserListWidget::UserListWidget(QWidget *parent) :
	QListWidget(parent)
{
	setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
	new QListWidgetItem(QIcon(":/pixmaps/icon/pixmaps/icon/icon-tux.png"), "Aric\n192.168.10.11", this);
	new QListWidgetItem(QIcon(":/pixmaps/icon/pixmaps/icon/icon-tux.png"), "Aric\n192.168.10.11", this);

}

const QString UserListWidget::getUserName(const QModelIndex &index)
{
	return "Aric";
}

QSize UserListWidget::minimumSizeHint() const
{
	return QSize(200, 400);
}

QSize UserListWidget::sizeHint() const
{
	return QSize(200, 500);
}
