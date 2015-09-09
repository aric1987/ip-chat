#include <QLabel>
#include <QSplitter>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "chat_widget.h"



QMenuBar *ChatWidget::createMenuBar()
{
	QMenu *menu;
	QMenuBar *menuBar = new QMenuBar(this);
	menu = menuBar->addMenu(tr("&File"));
	menu->addAction(QIcon(":/pixmaps/menu/pixmaps/menu/menu-detect.png"), tr("&Detect"));
	menu->addAction(QIcon(":/pixmaps/menu/pixmaps/menu/menu-find.png"), tr("&Find"), this, SLOT(findActionSlotFunc()));
	menu->addAction(QIcon(":/pixmaps/menu/pixmaps/menu/menu-exit.png"), tr("&Exit"), this, SLOT(close()));

	return menuBar;
}

ChatWidget::ChatWidget(const UserInfo &userInfo, QWidget *parent) :
	QWidget(parent)
{
	QVBoxLayout *mainLayout;
	QWidget *widget;
	QPushButton *pushButton;
	QHBoxLayout *hBoxLayout;
	QVBoxLayout *vBoxLayout;

	setWindowIcon(QIcon(":/pixmaps/app/pixmaps/app/ip-tux.png"));
	setWindowTitle(tr("Chat with "));

	mainLayout = new QVBoxLayout();
	mainLayout->setMargin(7);
	setLayout(mainLayout);

	mainLayout->addWidget(createMenuBar());

	QSplitter *mainSplitter;
	mainSplitter = new QSplitter(Qt::Horizontal);
	mainLayout->addWidget(mainSplitter);

	QSplitter *leftSplitter;
	leftSplitter = new QSplitter(Qt::Vertical);
	leftSplitter->setChildrenCollapsible(false);
	mainSplitter->addWidget(leftSplitter);
	mainSplitter->setStretchFactor(0, 7);
	mainSplitter->setCollapsible(0, false);

	widget = new QWidget();
	vBoxLayout = new QVBoxLayout();
	vBoxLayout->setMargin(0);
	widget->setLayout(vBoxLayout);
	leftSplitter->addWidget(widget);
	leftSplitter->setStretchFactor(0, 7);
	vBoxLayout->addWidget(new QLabel(tr("Chat History")));
	recvMsgEdit = new QTextEdit();
	recvMsgEdit->setReadOnly(true);
	vBoxLayout->addWidget(recvMsgEdit);


	widget = new QWidget();
	vBoxLayout = new QVBoxLayout();
	vBoxLayout->setMargin(0);
	widget->setLayout(vBoxLayout);
	leftSplitter->addWidget(widget);
	leftSplitter->setStretchFactor(1, 3);
	sendMsgEdit = new QTextEdit();
	vBoxLayout->addWidget(sendMsgEdit);


	QSplitter *rightSplitter;
	rightSplitter = new QSplitter(Qt::Vertical);
	rightSplitter->setChildrenCollapsible(false);
	mainSplitter->addWidget(rightSplitter);
	mainSplitter->setStretchFactor(1, 3);

	widget = new QWidget();
	rightSplitter->addWidget(widget);
	rightSplitter->setStretchFactor(0, 4);
	vBoxLayout = new QVBoxLayout();
	vBoxLayout->setMargin(0);
	widget->setLayout(vBoxLayout);
	vBoxLayout->addWidget(new QLabel(tr("File Transmit")));
	hBoxLayout = new QHBoxLayout();
	hBoxLayout->setMargin(0);
	vBoxLayout->addLayout(hBoxLayout);
	pushButton = new QPushButton(tr("File"));
	hBoxLayout->addWidget(pushButton);
	pushButton = new QPushButton(tr("Dir"));
	hBoxLayout->addWidget(pushButton);
	fileTransmitWidget = new QListWidget();
	vBoxLayout->addWidget(fileTransmitWidget);

	widget = new QWidget();
	rightSplitter->addWidget(widget);
	rightSplitter->setStretchFactor(1, 6);
	vBoxLayout = new QVBoxLayout();
	vBoxLayout->setMargin(0);
	widget->setLayout(vBoxLayout);
	userInfoEdit = new QTextEdit();
	userInfoEdit->setReadOnly(true);
	vBoxLayout->addWidget(userInfoEdit);
	//vBoxLayout->addWidget(new QLabel(tr("User Info")));

	hBoxLayout = new QHBoxLayout();
	hBoxLayout->setMargin(0);
	vBoxLayout->addLayout(hBoxLayout);
//	hBoxLayout->addStretch();
	pushButton = new QPushButton(tr("Send"));
	hBoxLayout->addWidget(pushButton);
	pushButton = new QPushButton(tr("Close"));
	hBoxLayout->addWidget(pushButton);

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
