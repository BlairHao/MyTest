#include "test.h"
#include <QtWidgets/QApplication>
#include <QMainWindow>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Test w;
	w.show();

	return a.exec();
}
