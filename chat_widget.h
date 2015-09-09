#ifndef CHAT_WIDGET_H
#define CHAT_WIDGET_H

#include <QWidget>

#include <QMenuBar>
#include <QTextEdit>
#include <QListWidget>
#include "user_info.h"

class ChatWidget : public QWidget
{
	Q_OBJECT
private:
	QTextEdit *recvMsgEdit;
	QTextEdit *sendMsgEdit;
	QTextEdit *userInfoEdit;
	QListWidget *fileTransmitWidget;


signals:

private:
	QMenuBar *createMenuBar();
public:
	explicit ChatWidget(const UserInfo &userInfo, QWidget *parent = 0);
	void addChatDialog(const QString &name);
	virtual QSize minimumSizeHint() const;
	virtual QSize sizeHint() const;
	~ChatWidget();
public slots:

};

#endif // CHAT_WIDGET_H
