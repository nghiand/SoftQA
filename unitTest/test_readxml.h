#ifndef TEST_READXML_H
#define TEST_READXML_H

#include <QtTest\qtest.h>
#include <QObject>

/*!
* \class test_readXML
*
* \brief Тестовый класс для функции readXML
*
*/
class test_readXML : public QObject
{
	Q_OBJECT

private slots:
	void wrongFirstID();
	void wrongSecondID();
	void existsNotNumber();
	void coincidedNumbers();
	void overSize();
	void emptyTree();
	void severalNodesOnBothTree();
};

#endif // TEST_READXML_H
