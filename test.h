#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include <QWidget>
#include "ui_test.h"
#include "ibaseclass.h"
#include <QLibrary>

typedef void *(*createWidget)(QWidget *); //声明createInfoWidget函数指针
typedef IBaseClass *(*getWidget)(void *); //声明getInfoWidget函数指针
typedef void (*destroyWidget)(void *); //声明destroyInfoWidget函数指针

class Test : public QMainWindow
{
	Q_OBJECT

public:
	Test(QWidget *parent = 0);
	~Test();

private:
	Ui::Test ui;

	createWidget m_FunCreateInfoWidget; //定义createInfoWidget函数指针
	getWidget m_FunGetInfoWidget; //定义getInfoWidget函数指针
	destroyWidget m_FunDestroyInfoWidget; //定义destroyInfoWidget函数指针
	void *m_pVoidInfo; //接收createInfoWidget的返回值
	IBaseClass *m_pIBaseClass; //接收getInfoWidget的返回值
	QLibrary *m_pLibrary;
};

#endif // TEST_H
