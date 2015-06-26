#ifndef TEST_READTREE_H
#define TEST_READTREE_H

#include <QtTest\qtest.h>
#include <QObject>

/*!
* \class test_readTree
*
* \brief Тестовый класс для функции readTree
*
*/
class test_readTree : public QObject
{
	Q_OBJECT

private slots:
	void wrongID();
	void coincidedNumbers();
	void existsNotNumber();
	void overSize();
	void oneNode();
	void severalNodes();
};

#endif // TEST_READTREE_H

