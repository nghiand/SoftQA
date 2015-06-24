#ifndef TEST_FINDNODEWITHDATA_H
#define TEST_FINDNODEWITHDATA_H

#include <QtTest\qtest.h>
#include <QObject>

/*!
* \class test_findNodeWithData
*
* \brief Тестовый класс для функции findNodeWithData
*
*/
class test_findNodeWithData : public QObject
{
	Q_OBJECT

private slots:
	void nodeWithDataDoesNotExist();
	void dataInCurrentNode();
	void dataOnSubTree();
};

#endif // TEST_FINDNODEWITHDATA_H
