#ifndef TEST_READNODE_H
#define TEST_READNODE_H

#include <QtTest\qtest.h>
#include <QObject>

/*!
* \class test_readNode
*
* \brief Тестовый класс для функции readNode
*
*/
class test_readNode : public QObject
{
	Q_OBJECT

private slots:
	void initTestCase();
	void valueIsNotNumber();
	void openingTag();
	void closingTag();
};

#endif // TEST_READNODE_H
