
#include <QMenuBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "main_window.h"

void MainWindow::createMenuBar()
{
	QMenu *menu;
	QMenuBar *menuBar = this->menuBar();
	menu = menuBar->addMenu(tr("&File"));
	menu->addAction(QIcon(":/pixmaps/menu/pixmaps/menu/menu-detect.png"), tr("&Detect"));
	menu->addAction(QIcon(":/pixmaps/menu/pixmaps/menu/menu-find.png"), tr("&Find"), this, SLOT(findActionSlotFunc()));
	menu->addAction(QIcon(":/pixmaps/menu/pixmaps/menu/menu-exit.png"), tr("&Exit"), this, SLOT(close()));
}

void MainWindow::findActionSlotFunc()
{

}

void MainWindow::createChatWidgetSlocFunc()
{


}

void MainWindow::userListWidgetClickedSlocFunc(const QModelIndex &index)
{

	chatWidget->addChatDialog(userListWidget->getUserName(index));
	QRect rect = geometry();
	chatWidget->setHidden(!chatWidget->isHidden());
	if(chatWidget->isHidden())
	{
		setGeometry(rect);
	}
	else
	{
		QWidget *widget = userListWidget->itemWidget(userListWidget->item(index.row()));
		userListWidget->item(index.row())->setBackgroundColor(QColor("red"));
	}
}


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	chatWidget = NULL;

	QWidget *centralWidget = new QWidget();
	this->setCentralWidget(centralWidget);

	QHBoxLayout *mainLayout = new QHBoxLayout();
	centralWidget->setLayout(mainLayout);

	userListWidget = new UserListWidget();
	connect(userListWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(userListWidgetClickedSlocFunc(QModelIndex)));
	mainLayout->addWidget(userListWidget);
	chatWidget = new ChatWidget(this);
	chatWidget->setHidden(true);
	mainLayout->addWidget(chatWidget);
}

MainWindow::~MainWindow()
{

}
