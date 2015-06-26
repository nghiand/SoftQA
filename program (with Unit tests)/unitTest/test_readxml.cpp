#include "test_readxml.h"
#include "functions.h"
#include "qbytearray.h"

const QString dir = "unitTestXML\\";

/*!
* Неправильный идентификатор первого дерева
*/
void test_readXML::wrongFirstID(){
	QString filename = dir + "wrongFirstID.xml";
	// результирующие деревья
	node *root1, *root2;

	try{
		readXML(filename, root1, root2);
	} catch (const error& e){
		QCOMPARE(e.type, WRONG_TREE_ID);
		QCOMPARE(e.treeID, 1);
		QCOMPARE(e.errorString, QString("3"));
		return;
	}
	QVERIFY(false);
	root1->delTree();
	root2->delTree();
}

/*!
* Неправильный идентификатор второго дерева
*/
void test_readXML::wrongSecondID(){
	QString filename = dir + "wrongSecondID.xml";
	// результирующие деревья
	node *root1, *root2;

	try{
		readXML(filename, root1, root2);
	} catch (const error& e){
		QCOMPARE(e.type, WRONG_TREE_ID);
		QCOMPARE(e.treeID, 2);
		QCOMPARE(e.errorString, QString("5a"));
		return;
	}
	QVERIFY(false);
	root1->delTree();
	root2->delTree();
}

/*!
* Значение в одной вершине в одном дереве не является цифрой
*/
void test_readXML::existsNotNumber(){
	QString filename = dir + "existsNotNumber.xml";
	// результирующие деревья
	node *root1, *root2;

	try{
		readXML(filename, root1, root2);
	} catch (const error& e){
		QCOMPARE(e.type, EXISTS_NOT_NUMBER);
		QCOMPARE(e.treeID, 2);
		QCOMPARE(e.errorString, QString("wrongvalue"));
		return;
	}
	QVERIFY(false);
	root1->delTree();
	root2->delTree();
}

/*!
* Существуют несколько вершин с одинаковыми цифрами в одном дереве
*/
void test_readXML::coincidedNumbers(){
	QString filename = dir + "coincidedNumbers.xml";
	// результирующие деревья
	node *root1, *root2;

	try{
		readXML(filename, root1, root2);
	} catch (const error& e){
		QCOMPARE(e.type, COINCIDED_NUMBERS);
		QCOMPARE(e.treeID, 2);
		QCOMPARE(e.errorString, QString("1"));
		return;
	}
	QVERIFY(false);
	root1->delTree();
	root2->delTree();
}

/*!
* Одно дерево имеет количество вершин превышает максимальный размер
*/
void test_readXML::overSize(){
	QString filename = dir + "overSize.xml";
	// результирующие деревья
	node *root1, *root2;

	try{
		readXML(filename, root1, root2);
	} catch (const error& e){
		QCOMPARE(e.type, OVER_SIZE);
		QCOMPARE(e.treeID, 1);
		QCOMPARE(e.errorString, QString("31"));
		return;
	}
	QVERIFY(false);
	root1->delTree();
	root2->delTree();
}

/*!
* Одно дерево ничего не содержит
*/
void test_readXML::emptyTree(){
	QString filename = dir + "emptyTree.xml";
	// результирующие деревья
	node *root1, *root2;

	try{
		readXML(filename, root1, root2);
	} catch (const error& e){
		QVERIFY(false);
		return;
	}
	// Ожидаемые результаты
	node* expectedRoot = new node(1);
	node* node2 = new node(2, expectedRoot);
	expectedRoot->addChild(node2);
	node* node3 = new node(3, expectedRoot);
	expectedRoot->addChild(node3);

	QVERIFY(root1 == NULL);
	QVERIFY(node::compareTree(expectedRoot, root2));
	root1->delTree();
	root2->delTree();
	expectedRoot->delTree();
}

/*!
* Оба два деревья содержат несколько вершин
*/
void test_readXML::severalNodesOnBothTree(){
	QString filename = dir + "severalNodesOnBothTree.xml";
	// результирующие деревья
	node *root1, *root2;

	try{
		readXML(filename, root1, root2);
	} catch (const error& e){
		QVERIFY(false);
		return;
	}
	// Ожидаемые результаты
	node* expectedRoot1 = new node(1);
	node* node2 = new node(2);
	expectedRoot1->addChild(node2);
	node* node3 = new node(3);
	node2->addChild(node3);
	node* node4 = new node(4);
	node2->addChild(node4);
	node* node5 = new node(5);
	node2->addChild(node5);
	node* node6 = new node(6);
	node4->addChild(node6);
	node* node7 = new node(7);
	node4->addChild(node7);
	node* node8 = new node(8);
	node6->addChild(node8);
	node* node9 = new node(9);
	node6->addChild(node9);

	node* expectedRoot2 = new node(1);
	node* node11_ = new node(11);
	expectedRoot2->addChild(node11_);
	node* node2_ = new node(2);
	expectedRoot2->addChild(node2_);
	node* node3_ = new node(3);
	node2_->addChild(node3_);
	node* node4_ = new node(4);
	node2_->addChild(node4_);
	node* node5_ = new node(5);
	node2_->addChild(node5_);
	node* node6_ = new node(6);
	node4_->addChild(node6_);
	node* node7_ = new node(7);
	node4_->addChild(node7_);
	node* node8_ = new node(8);
	node6_->addChild(node8_);
	node* node9_ = new node(9);
	node6_->addChild(node9_);


	QVERIFY(node::compareTree(expectedRoot1, root1));
	QVERIFY(node::compareTree(expectedRoot2, root2));
	root1->delTree();
	root2->delTree();
	expectedRoot1->delTree();
	expectedRoot2->delTree();
}

/*!
* Входный файл не существует
*/
void test_readXML::filenotexists(){
	QString filename = dir + "filenotexist.xml";
	// результирующие деревья
	node *root1, *root2;

	try{
		readXML(filename, root1, root2);
	} catch (const error& e){
		QCOMPARE(e.type, COULD_NOT_OPEN_FILE);
		return;
	}
	QVERIFY(false);
}