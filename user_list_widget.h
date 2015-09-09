#ifndef USER_LIST_WIDGET_H
#define USER_LIST_WIDGET_H

#include <QListWidget>

class UserListWidget : public QListWidget
{
	Q_OBJECT
public:
	explicit UserListWidget(QWidget *parent = 0);

signals:

private:

protected:

public slots:

public:
	const QString getUserName(const QModelIndex &index);
	virtual QSize minimumSizeHint() const;
	virtual QSize sizeHint() const;
};

#endif // USER_LIST_WIDGET_H
