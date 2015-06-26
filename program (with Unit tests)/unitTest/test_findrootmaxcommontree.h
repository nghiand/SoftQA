#ifndef TEST_FINDROOTMAXCOMMONTREE_H
#define TEST_FINDROOTMAXCOMMONTREE_H

#include <QtTest\qtest.h>
#include <QObject>

/*!
* \class test_findRootMaxCommonTree
*
* \brief Тестовый класс для функции findRootMaxCommonTree
*
*/
class test_findRootMaxCommonTree : public QObject
{
	Q_OBJECT
private slots:
	void notExistsPairOfMatchedNodes();
	void dataInRootsEqual();
	void dataInRootsAreDifferent();
};

#endif // TEST_FINDROOTMAXCOMMONTREE_H
