#ifndef CHAT_WIDGET_H
#define CHAT_WIDGET_H

#include <QWidget>

class ChatWidget : public QWidget
{
	Q_OBJECT
public:


signals:

private:
	void createMenuBar();
public:
	explicit ChatWidget(QWidget *parent = 0);
	void addChatDialog(const QString &name);
	virtual QSize minimumSizeHint() const;
	virtual QSize sizeHint() const;
	~ChatWidget();
public slots:

};

#endif // CHAT_WIDGET_H
