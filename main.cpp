#include <QApplication>
#include "main_window.h"
#include <QTranslator>

int main(int argc, char *argv[])
{
	QTranslator translator;
	QApplication app(argc, argv);
	translator.load(":/langurage/qscom_zh.qm");
	app.installTranslator(&translator);
	MainWindow mainWindow;
	mainWindow.setWindowIcon(QIcon(":/pixmaps/app/pixmaps/app/ip-tux.png"));
	mainWindow.show();

	return app.exec();
}
