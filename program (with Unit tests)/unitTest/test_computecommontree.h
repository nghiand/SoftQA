#ifndef TEST_COMPUTECOMMONTREE_H
#define TEST_COMPUTECOMMONTREE_H

#include <QtTest\qtest.h>
#include <QObject>

/*!
* \class test_computeCommonTree
*
* \brief Тестовый класс для функции computeCommonTree
*
*/
class test_computeCommonTree : public QObject
{
	Q_OBJECT

private slots:
	void differentNumbersInRoots();
	void nonSubTreeOnFirstRoot();
	void nonSubTreeOnSecondRoot();
	void notExistsPairOfMatchedChild();
	void twoTreesEqual();
	void randomTest1();
	void randomTest2();
	void randomTest3();
	void randomTest4();
};

#endif // TEST_COMPUTECOMMONTREE_H
