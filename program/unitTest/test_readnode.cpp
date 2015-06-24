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
	int treeNum = 1;
	// <node value="a">
	// </node>
	QByteArray data = "<node value=\"a\"></node>";
	QXmlStreamReader stream(data);
	stream.readNext();
	node* newNode;
	int ret;
	try{
		// возвращаемое значение
		ret = readNode(stream, treeNum, newNode);
	} catch (error e){
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
	int treeNum = 1;
	// <node value="1">
	// </node>
	QByteArray data = "<node value=\"1\"></node>";
	QXmlStreamReader stream(data);
	stream.readNext();
	node* newNode;
	int ret;

	try{
		// возвращаемое значение
		ret = readNode(stream, treeNum, newNode);
	} catch (error e){
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
	int treeNum = 1;
	// <node>
	// </node>
	QByteArray data = "<node></node>";
	QXmlStreamReader stream(data);
	stream.readNext();
	stream.readNext();

	node* newNode;
	int ret;

	try{
		// возвращаемое значение
		ret = readNode(stream, treeNum, newNode);
	} catch (error e){
		QVERIFY(false);
	}

	QCOMPARE(ret, -1);
	QVERIFY(newNode == NULL);
	if (newNode) newNode->delTree();
}