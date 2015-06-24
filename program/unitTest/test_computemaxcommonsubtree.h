#ifndef TEST_COMPUTEMAXCOMMONSUBTREE_H
#define TEST_COMPUTEMAXCOMMONSUBTREE_H

#include <QtTest\qtest.h>
#include <QObject>

/*!
* \class test_computeMaxCommonSubTree
*
* \brief Тестовый класс для функции computeMaxCommonSubTree
*
*/
class test_computeMaxCommonSubTree : public QObject
{
	Q_OBJECT

private slots:
	void emptyList1();
	void emptyList2();
	void notExistsPairOfMatchedNodes();
	void list1EqualsList2();
	void randomTest1();
	void randomTest2();
	void randomTest3();
};

#endif // TEST_COMPUTEMAXCOMMONSUBTREE_H
