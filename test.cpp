#include "test.h"
#include "common.h"

Test::Test(QWidget *parent)
	: QMainWindow(parent)
	, m_pLibrary(NULL)
{
	ui.setupUi(this);

	bool bflag = false;
	m_pLibrary = new QLibrary("MyDll.dll");
	if (!m_pLibrary->isLoaded())
	{
		bflag = m_pLibrary->load();
		if (bflag)
		{
			m_FunCreateInfoWidget = (createWidget)m_pLibrary->resolve("createInfoWidget"); //ͨ��������createInfoWidget�����Һ���
			m_FunGetInfoWidget = (getWidget)m_pLibrary->resolve("getInfoWidget");
			m_FunDestroyInfoWidget = (destroyWidget)m_pLibrary->resolve("destroyInfoWidget");
		}
	}

	if (m_FunCreateInfoWidget)
	{
		m_pVoidInfo = m_FunCreateInfoWidget(this);
		m_pIBaseClass = m_FunGetInfoWidget(m_pVoidInfo);
		if (m_pIBaseClass)
		{
			QList<Student> qlist;
			Student s;
			s.strClass = "grade 6";
			s.strName = "zhangsan";
			s.strSex = "man";
			s.strNo = "37";
			qlist.push_back(s);
			m_pIBaseClass->LoadStudentInfo(qlist); //���������ӿڣ���ʾѧ����Ϣ
		}
	}
}

Test::~Test()
{

}
