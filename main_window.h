#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "user_info.h"
#include "chat_widget.h"
#include "user_list_widget.h"
class MainWindow : public QMainWindow
{
	Q_OBJECT
private:
	ChatWidget *chatWidget;
	UserListWidget *userListWidget;

private:
	void createMenuBar();
private slots:
	void findActionSlotFunc();
	void createChatWidgetSlocFunc();
	void userListWidgetClickedSlocFunc(const QModelIndex &index);
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
};

#endif // MAIN_WINDOW_H
