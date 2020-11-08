#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include <QWidget>
#include "ui_test.h"
#include "ibaseclass.h"
#include <QLibrary>

typedef void *(*createWidget)(QWidget *); //����createInfoWidget����ָ��
typedef IBaseClass *(*getWidget)(void *); //����getInfoWidget����ָ��
typedef void (*destroyWidget)(void *); //����destroyInfoWidget����ָ��

class Test : public QMainWindow
{
	Q_OBJECT

public:
	Test(QWidget *parent = 0);
	~Test();

private:
	Ui::Test ui;

	createWidget m_FunCreateInfoWidget; //����createInfoWidget����ָ��
	getWidget m_FunGetInfoWidget; //����getInfoWidget����ָ��
	destroyWidget m_FunDestroyInfoWidget; //����destroyInfoWidget����ָ��
	void *m_pVoidInfo; //����createInfoWidget�ķ���ֵ
	IBaseClass *m_pIBaseClass; //����getInfoWidget�ķ���ֵ
	QLibrary *m_pLibrary;
};

#endif // TEST_H
