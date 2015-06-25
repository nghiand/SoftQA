#include "test_readtree.h"
#include "functions.h"
#include "qbytearray.h"

/*!
* Неправильный идентификатор дерева
*/
void test_readTree::wrongID(){
	// <tree id="a">
	// <node value="1">
	// </tree>
	QByteArray data = "<tree id=\"a\"><node value=\"1\"/></tree>";
	QXmlStreamReader stream(data);
	stream.readNext();
	node* root;

	try{
		int treeNum = 1;
		// возвращаемое значение
		readTree(stream, root, treeNum);
	} catch (const error& e){
		QCOMPARE(e.type, WRONG_TREE_ID);
		QCOMPARE(e.treeID, 1);
		QCOMPARE(e.errorString, QString("a"));
		return;
	}

	QVERIFY(false);
	root->delTree();
}

/*!
* Существуют несколько вершин с одинаковыми цифрами
*/
void test_readTree::coincidedNumbers(){
	// <tree id="1">
	//   <node value="1">
	//     <node value="2"/>
	//     <node value="2"/>
	//   </node>
	// </tree>
	QByteArray data = "<tree id=\"1\"> ";
	data.append("<node value=\"1\"> ");
	data.append("<node value=\"2\"/>");
	data.append("<node value=\"1\"/>");
	data.append("</node>");
	data.append("</tree>");


	QXmlStreamReader stream(data);
	stream.readNext();
	node* root;

	try{
		int treeNum = 1;
		// возвращаемое значение
		readTree(stream, root, treeNum);
	} catch (const error& e){
		QCOMPARE(e.type, COINCIDED_NUMBERS);
		QCOMPARE(e.treeID, 1);
		QCOMPARE(e.errorString, QString("1"));
		return;
	}

	QVERIFY(false);
	root->delTree();
}

/*!
* Значение в одной вершине не является цифрой
*/
void test_readTree::existsNotNumber(){
	//<tree id="2">
	//	<node value="1">
	//		<node value="2"/>
	//		<node value="n"/>
	//	</node>
	//</tree>
	QByteArray data = "<tree id=\"2\"> ";
	data.append("<node value=\"1\"> ");
	data.append("<node value=\"2\"/>");
	data.append("<node value=\"n\"/>");
	data.append("</node>");
	data.append("</tree>");


	QXmlStreamReader stream(data);
	stream.readNext();
	node* root;

	try{
		int treeNum = 2;
		// возвращаемое значение
		readTree(stream, root, treeNum);
	} catch (const error& e){
		QCOMPARE(e.type, EXISTS_NOT_NUMBER);
		QCOMPARE(e.treeID, 2);
		QCOMPARE(e.errorString, QString("n"));
		return;
	}

	QVERIFY(false);
	root->delTree();
}

/*!
* Количество вершин дерева превышает максимальный размер
*/
void test_readTree::overSize(){
	//<tree id="1">
	//  <node value="1">
	//	<node value="2"/>
	//	<node value="3"/>
	//	<node value="4"/>
	//	<node value="5"/>
	//	<node value="6"/>
	//	<node value="7"/>
	//	<node value="8"/>
	//	<node value="9"/>
	//	<node value="10"/>
	//	<node value="11"/>
	//	<node value="12"/>
	//	<node value="13"/>
	//	<node value="14"/>
	//	<node value="15"/>
	//	<node value="16"/>
	//	<node value="17"/>
	//	<node value="18"/>
	//	<node value="19"/>
	//	<node value="20"/>
	//	<node value="21"/>
	//	<node value="22"/>
	//	<node value="23"/>
	//	<node value="24"/>
	//	<node value="25"/>
	//	<node value="26"/>
	//	<node value="27"/>
	//	<node value="28"/>
	//	<node value="29"/>
	//	<node value="30"/>
	//	<node value="31"/>
	//  </node>
	//</tree>

	QByteArray data = "<tree id=\"1\"> ";
	data.append("<node value=\"1\"> ");
	data.append("<node value=\"2\"/>");
	data.append("<node value=\"3\"/>");
	data.append("<node value=\"4\"/>");
	data.append("<node value=\"5\"/>");
	data.append("<node value=\"6\"/>");
	data.append("<node value=\"7\"/>");
	data.append("<node value=\"8\"/>");
	data.append("<node value=\"9\"/>");
	data.append("<node value=\"10\"/>");
	data.append("<node value=\"11\"/>");
	data.append("<node value=\"12\"/>");
	data.append("<node value=\"13\"/>");
	data.append("<node value=\"14\"/>");
	data.append("<node value=\"15\"/>");
	data.append("<node value=\"16\"/>");
	data.append("<node value=\"17\"/>");
	data.append("<node value=\"18\"/>");
	data.append("<node value=\"19\"/>");
	data.append("<node value=\"20\"/>");
	data.append("<node value=\"21\"/>");
	data.append("<node value=\"22\"/>");
	data.append("<node value=\"23\"/>");
	data.append("<node value=\"24\"/>");
	data.append("<node value=\"25\"/>");
	data.append("<node value=\"26\"/>");
	data.append("<node value=\"27\"/>");
	data.append("<node value=\"28\"/>");
	data.append("<node value=\"29\"/>");
	data.append("<node value=\"30\"/>");
	data.append("<node value=\"31\"/>");
	data.append("</node>");
	data.append("</tree>");


	QXmlStreamReader stream(data);
	stream.readNext();
	node* root;

	try{
		int treeNum = 1;
		// возвращаемое значение
		readTree(stream, root, treeNum);
	} catch (const error& e){
		QCOMPARE(e.type, OVER_SIZE);
		QCOMPARE(e.treeID, 1);
		QCOMPARE(e.errorString, QString("31"));
		return;
	}

	QVERIFY(false);
	root->delTree();
}

/*!
* Дерево содержит одну вершину
*/
void test_readTree::oneNode(){	
	//<tree id="1">
	//	<node value="2"/>
	//</tree>
	QByteArray data = "<tree id=\"1\"> ";
	data.append("<node value=\"2\"/>");
	data.append("</tree>");


	QXmlStreamReader stream(data);
	stream.readNext();
	node* root;

	try{
		int treeNum = 1;
		// возвращаемое значение
		readTree(stream, root, treeNum);
	} catch (const error& e){
		QVERIFY(false);
		return;
	}
	// Ожидаемые результаты
	node* expectedRoot = new node(2);
	QVERIFY(node::compareTree(expectedRoot, root));
	root->delTree();
	expectedRoot->delTree();
}

/*!
* Дерево содержит несколько вершин
*/
void test_readTree::severalNodes(){
	//<tree id="1">
	//  <node value="1">
	//	<node value="2">
	//	  <node value="3"/>
	//	  <node value="4">
	//		<node value="6">
	//		  <node value="8"/>
	//		  <node value="9"/>
	//		</node>
	//		<node value="7"/>
	//	  </node>
	//	  <node value="5"/>
	//	</node>
	//  </node>
	//</tree>

	QByteArray data = "<tree id=\"1\"> ";
	data.append("<node value=\"1\"> ");
	data.append("<node value=\"2\"> ");
	data.append("<node value=\"3\"/>");
	data.append("<node value=\"4\"> ");
	data.append("<node value=\"6\"> ");
	data.append("<node value=\"8\"/>");
	data.append("<node value=\"9\"/>");
	data.append("</node>");
	data.append("<node value=\"7\"/>");
	data.append("</node>");
	data.append("<node value=\"5\"/>");
	data.append("</node>");
	data.append("</node>");
	data.append("</tree>");


	QXmlStreamReader stream(data);
	stream.readNext();
	node* root;

	try{
		int treeNum = 1;
		// возвращаемое значение
		readTree(stream, root, treeNum);
	} catch (const error& e){
		QVERIFY(false);
		return;
	}
	// Ожидаемые результаты
	node* expectedRoot = new node(1);
	node* node2 = new node(2, expectedRoot);
	expectedRoot->addChild(node2);
	node* node3 = new node(3, node2);
	node2->addChild(node3);
	node* node4 = new node(4, node2);
	node2->addChild(node4);
	node* node5 = new node(5, node2);
	node2->addChild(node5);
	node* node6 = new node(6, node4);
	node4->addChild(node6);
	node* node7 = new node(7, node4);
	node4->addChild(node7);
	node* node8 = new node(8, node6);
	node6->addChild(node8);
	node* node9 = new node(9, node6);
	node6->addChild(node9);

	QVERIFY(node::compareTree(expectedRoot, root));
	root->delTree();
	expectedRoot->delTree();
}
