#include "test_readnode.h"
#include "functions.h"
#include "qbytearray.h"

void test_readNode::initTestCase(){
	//QTest::addColumn<node*>("");
}

/*!
* Атрибут значение не является цифрой
*/
void test_readNode::valueIsNotNumber(){
	QByteArray data = "<node value=\"a\"></node>";
	QXmlStreamReader stream(data);
	stream.readNext();
	node* newNode;
	try{
		int treeNum = 1;
		// возвращаемое значение
		readNode(stream, treeNum, newNode);
	} catch (const error& e){
		QCOMPARE(e.type, EXISTS_NOT_NUMBER);
		QCOMPARE(e.treeID, 1);
		QCOMPARE(e.errorString, QString("a"));
		return;
	}
	QVERIFY(false);
	newNode->delTree();
}

/*!
* Открывающий тег <node> и атрибут значение является цифрой
*/
void test_readNode::openingTag(){
	QByteArray data = "<node value=\"1\"></node>";
	QXmlStreamReader stream(data);
	stream.readNext();
	node* newNode;
	int ret;

	try{
		int treeNum = 1;
		// возвращаемое значение
		ret = readNode(stream, treeNum, newNode);
	} catch (const error& e){
		QVERIFY(false);
	}

	QCOMPARE(ret, 1);

	node* expectedNode = new node(1);
	QVERIFY(node::compareTree(expectedNode, newNode));
	newNode->delTree();
	expectedNode->delTree();
}

/*!
* Закрывающий тег </node>
*/
void test_readNode::closingTag(){
	QByteArray data = "<node></node>";
	QXmlStreamReader stream(data);
	stream.readNext();
	stream.readNext();

	node* newNode;
	int ret;

	try{
		int treeNum = 1;
		// возвращаемое значение
		ret = readNode(stream, treeNum, newNode);
	} catch (const error& e){
		QVERIFY(false);
	}

	QCOMPARE(ret, -1);
	QVERIFY(newNode == NULL);
	if (newNode) newNode->delTree();
}