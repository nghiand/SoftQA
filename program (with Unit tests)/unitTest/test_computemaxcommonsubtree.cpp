#include "test_computemaxcommonsubtree.h"
#include "functions.h"

/*!
* В массиве list1 нет элементов
*/
void test_computeMaxCommonSubTree::emptyList1(){
	QVector<node*> list1, list2, rootList, res;
	QVector<int> size;
	// второй массив
	node* node2 = new node(2);
	list2.push_back(node2);
	// возвращаемое значение
	int ret = computeMaxCommonSubTree(list1, list2, size, rootList, res);
	QCOMPARE(ret, 0);
	QCOMPARE(res.size(), 0);
	node2->delTree();
}

/*!
* В массиве list2 нет элементов
*/
void test_computeMaxCommonSubTree::emptyList2(){
	QVector<node*> list1, list2, rootList, res;
	QVector<int> size;
	// первый массив
	node* node2 = new node(2);
	list1.push_back(node2);
	// возвращаемое значение
	int ret = computeMaxCommonSubTree(list1, list2, size, rootList, res);
	QCOMPARE(ret, 0);
	QCOMPARE(res.size(), 0);
	node2->delTree();
}

/*!
* Нет пар элементов с одинаковыми цифрами в массивах list1 и list2
*/
void test_computeMaxCommonSubTree::notExistsPairOfMatchedNodes(){
	QVector<node*> list1, list2, rootList, res;
	QVector<int> size(3, 0);
	// первый массив
	node* node1 = new node(1);
	node* node2 = new node(2);
	node1->addChild(node2);
	node* node3 = new node(3);
	node1->addChild(node3);
	node* node4 = new node(4);
	node* node5 = new node(5);
	node* node6 = new node(6);
	node5->addChild(node6);

	list1.push_back(node1);
	list1.push_back(node4);
	list1.push_back(node5);
	// второй массив
	node* node2_ = new node(2);
	node* node1_ = new node(1);
	node2_->addChild(node1_);
	node* node3_ = new node(3);
	node3_->addChild(node3_);
	node* node6_ = new node(6);

	list2.push_back(node2_);
	list2.push_back(node6_);
	// возвращаемое значение
	int ret = computeMaxCommonSubTree(list1, list2, size, rootList, res);
	QCOMPARE(ret, 0);
	QCOMPARE(res.size(), 0);
	for (int i = 0; i < list1.size(); i++)
		list1[i]->delTree();
	for (int i = 0; i < list2.size(); i++)
		list2[i]->delTree();
	for (int i = 0; i < rootList.size(); i++)
		rootList[i]->delTree();
	res.clear();
	rootList.clear();
	list1.clear();
	list2.clear();
	size.clear();
}

/*!
* Элементы в массиве list1 похожи на элементы в массиве list2
*/
void test_computeMaxCommonSubTree::list1EqualsList2(){
	QVector<node*> list1, list2, rootList, res;
	QVector<int> size;
	// первый массив
	node* node1 = new node(1);
	node* node2 = new node(2);
	node1->addChild(node2);
	node* node3 = new node(3);
	node1->addChild(node3);
	node* node4 = new node(4);
	node* node5 = new node(5);
	node* node6 = new node(6);
	node5->addChild(node6);

	list1.push_back(node1);
	list1.push_back(node4);
	list1.push_back(node5);
	// второй массив
	node* node1_ = new node(1);
	node* node2_ = new node(2);
	node1_->addChild(node2_);
	node* node3_ = new node(3);
	node1_->addChild(node3_);
	node* node4_ = new node(4);
	node* node5_ = new node(5);
	node* node6_ = new node(6);
	node5_->addChild(node6_);

	list2.push_back(node1_);
	list2.push_back(node4_);
	list2.push_back(node5_);

	size.push_back(3);
	size.push_back(1);
	size.push_back(2);

	rootList = list2;
	// возвращаемое значение
	int ret = computeMaxCommonSubTree(list1, list2, size, rootList, res);
	QCOMPARE(ret, 6);
	QCOMPARE(res.size(), rootList.size());
	for (int i = 0; i < rootList.size(); i++)
		QVERIFY(node::compareTree(res[i], rootList[i]));
	for (int i = 0; i < list1.size(); i++)
		list1[i]->delTree();
	for (int i = 0; i < list2.size(); i++)
		list2[i]->delTree();
	res.clear();
	rootList.clear();
	list1.clear();
	list2.clear();
	size.clear();
}

/*!
* Cлучайный тест 1
*/
void test_computeMaxCommonSubTree::randomTest1(){
	QVector<node*> list1, list2, rootList, res;
	QVector<int> size;

	// первый массив
	node* node1 = new node(1);
	node* node2 = new node(2);
	node1->addChild(node2);
	node* node3 = new node(3);
	node1->addChild(node3);
	node* node5 = new node(5);
	node* node6 = new node(6);
	node5->addChild(node6);
	node* node7 = new node(7);
	node* node4 = new node(4);
	node7->addChild(node4);
	node* node8 = new node(8);
	node7->addChild(node8);

	list1.push_back(node1);
	list1.push_back(node5);
	list1.push_back(node7);

	// второй массив
	node* node1_ = new node(1);
	node* node3_ = new node(3);
	node1_->addChild(node3_);
	node* node2_ = new node(2);
	node1_->addChild(node2_);
	node* node6_ = new node(6);
	node* node7_ = new node(7);
	node* node8_ = new node(8);
	node7_->addChild(node8_);
	node* node4_ = new node(4);

	list2.push_back(node1_);
	list2.push_back(node6_);
	list2.push_back(node7_);
	list2.push_back(node4_);

	size.push_back(2);
	size.push_back(0);
	size.push_back(2);

	// массив корней максимальных общих поддеревьев, найдены в дочерях вершины с цифрой k в первом дереве
	node* node1__ = new node(1);
	node* node3__ = new node(3);
	node1__->addChild(node3__);
	node* node7__ = new node(7);
	node* node8__ = new node(8);
	node7__->addChild(node8__);
	rootList.push_back(node1__);
	rootList.push_back(NULL);
	rootList.push_back(node7__);
	// возвращаемое значение
	int ret = computeMaxCommonSubTree(list1, list2, size, rootList, res);
	QCOMPARE(ret, 4);
	// Ожидаемые результаты
	QVector<node*> expectedRes;
	node* enode1 = new node(1);
	node* enode3 = new node(3);
	enode1->addChild(enode3);
	node* enode7 = new node(7);
	node* enode8 = new node(8);
	enode7->addChild(enode8);
	expectedRes.push_back(enode1);
	expectedRes.push_back(enode7);

	QCOMPARE(res.size(), expectedRes.size());
	for (int i = 0; i < expectedRes.size(); i++)
		QVERIFY(node::compareTree(res[i], expectedRes[i]));
	for (int i = 0; i < list1.size(); i++)
		list1[i]->delTree();
	for (int i = 0; i < list2.size(); i++)
		list2[i]->delTree();
	for (int i = 0; i < rootList.size(); i++)
		rootList[i]->delTree();
	for (int i = 0; i < expectedRes.size(); i++)
		expectedRes[i]->delTree();
	res.clear();
	rootList.clear();
	list1.clear();
	list2.clear();
	size.clear();
}

/*!
* Cлучайный тест 2
*/
void test_computeMaxCommonSubTree::randomTest2(){
	QVector<node*> list1, list2, rootList, res;
	QVector<int> size;

	// первый массив
	node* node1 = new node(1);
	node* node2 = new node(2);
	node1->addChild(node2);
	node* node3 = new node(3);
	node1->addChild(node3);
	node* node5 = new node(5);
	node* node6 = new node(6);
	node5->addChild(node6);
	node* node7 = new node(7);
	node* node4 = new node(4);
	node7->addChild(node4);
	node* node8 = new node(8);
	node7->addChild(node8);
	node* node11 = new node(11);
	node* node9 = new node(9);
	node11->addChild(node9);
	node* node10 = new node(10);
	node11->addChild(node10);

	list1.push_back(node1);
	list1.push_back(node5);
	list1.push_back(node7);
	list1.push_back(node11);

	// второй массив
	node* node11_ = new node(11);
	node* node9_ = new node(9);
	node11_->addChild(node9_);
	node* node10_ = new node(10);
	node11_->addChild(node10_);
	node* node1_ = new node(1);
	node* node3_ = new node(3);
	node1_->addChild(node3_);
	node* node2_ = new node(2);
	node1_->addChild(node2_);
	node* node6_ = new node(6);
	node* node7_ = new node(7);
	node* node8_ = new node(8);
	node7_->addChild(node8_);
	node* node4_ = new node(4);

	list2.push_back(node11_);
	list2.push_back(node1_);
	list2.push_back(node6_);
	list2.push_back(node7_);
	list2.push_back(node4_);

	size.push_back(2);
	size.push_back(0);
	size.push_back(2);
	size.push_back(3);
	// массив корней максимальных общих поддеревьев, найдены в дочерях вершины с цифрой k в первом дереве
	node* node1__ = new node(1);
	node* node3__ = new node(3);
	node1__->addChild(node3__);
	node* node7__ = new node(7);
	node* node8__ = new node(8);
	node7__->addChild(node8__);
	node* node11__ = new node(11);
	node* node9__ = new node(9);
	node11__->addChild(node9__);
	node* node10__ = new node(10);
	node11__->addChild(node10__);

	rootList.push_back(node1__);
	rootList.push_back(NULL);
	rootList.push_back(node7__);
	rootList.push_back(node11__);
	// возвращаемое значение
	int ret = computeMaxCommonSubTree(list1, list2, size, rootList, res);
	QCOMPARE(ret, 4);
	// Ожидаемые результаты
	QVector<node*> expectedRes;
	node* enode1 = new node(1);
	node* enode3 = new node(3);
	enode1->addChild(enode3);
	node* enode7 = new node(7);
	node* enode8 = new node(8);
	enode7->addChild(enode8);
	expectedRes.push_back(enode1);
	expectedRes.push_back(enode7);

	QCOMPARE(res.size(), expectedRes.size());
	for (int i = 0; i < expectedRes.size(); i++)
		QVERIFY(node::compareTree(res[i], expectedRes[i]));
	for (int i = 0; i < list1.size(); i++)
		list1[i]->delTree();
	for (int i = 0; i < list2.size(); i++)
		list2[i]->delTree();
	for (int i = 0; i < rootList.size(); i++)
		rootList[i]->delTree();
	for (int i = 0; i < expectedRes.size(); i++)
		expectedRes[i]->delTree();
	res.clear();
	rootList.clear();
	list1.clear();
	list2.clear();
	size.clear();
}

/*!
* Cлучайный тест 3
*/
void test_computeMaxCommonSubTree::randomTest3(){
	QVector<node*> list1, list2, rootList, res;
	QVector<int> size;

	// первый массив
	node* node1 = new node(1);
	node* node2 = new node(2);
	node1->addChild(node2);
	node* node3 = new node(3);
	node1->addChild(node3);
	node* node5 = new node(5);
	node* node6 = new node(6);
	node5->addChild(node6);
	node* node7 = new node(7);
	node* node4 = new node(4);
	node7->addChild(node4);
	node* node8 = new node(8);
	node7->addChild(node8);
	node* node11 = new node(11);
	node* node9 = new node(9);
	node11->addChild(node9);
	node* node10 = new node(10);
	node11->addChild(node10);

	list1.push_back(node1);
	list1.push_back(node5);
	list1.push_back(node7);
	list1.push_back(node11);

	// второй массив
	node* node11_ = new node(11);
	node* node9_ = new node(9);
	node11_->addChild(node9_);
	node* node10_ = new node(10);
	node11_->addChild(node10_);
	node* node1_ = new node(1);
	node* node3_ = new node(3);
	node1_->addChild(node3_);
	node* node2_ = new node(2);
	node1_->addChild(node2_);
	node* node6_ = new node(6);
	node* node7_ = new node(7);
	node* node8_ = new node(8);
	node7_->addChild(node8_);
	node* node4_ = new node(4);

	list2.push_back(node6_);
	list2.push_back(node1_);
	list2.push_back(node11_);
	list2.push_back(node7_);
	list2.push_back(node4_);

	size.push_back(2);
	size.push_back(0);
	size.push_back(2);
	size.push_back(3);
	// массив корней максимальных общих поддеревьев, найдены в дочерях вершины с цифрой k в первом дереве
	node* node1__ = new node(1);
	node* node3__ = new node(3);
	node1__->addChild(node3__);
	node* node7__ = new node(7);
	node* node8__ = new node(8);
	node7__->addChild(node8__);
	node* node11__ = new node(11);
	node* node9__ = new node(9);
	node11__->addChild(node9__);
	node* node10__ = new node(10);
	node11__->addChild(node10__);

	rootList.push_back(node1__);
	rootList.push_back(NULL);
	rootList.push_back(node7__);
	rootList.push_back(node11__);
	// возвращаемое значение
	int ret = computeMaxCommonSubTree(list1, list2, size, rootList, res);
	QCOMPARE(ret, 5);
	// Ожидаемые результаты
	QVector<node*> expectedRes;
	node* enode1 = new node(1);
	node* enode3 = new node(3);
	enode1->addChild(enode3);
	node* enode11 = new node(11);
	node* enode9 = new node(9);
	enode11->addChild(enode9);
	node* enode10 = new node(10);
	enode11->addChild(enode10);
	expectedRes.push_back(enode1);
	expectedRes.push_back(enode11);

	QCOMPARE(res.size(), expectedRes.size());

	for (int i = 0; i < expectedRes.size(); i++)
		QVERIFY(node::compareTree(res[i], expectedRes[i]));

	for (int i = 0; i < list1.size(); i++)
		list1[i]->delTree();
	for (int i = 0; i < list2.size(); i++)
		list2[i]->delTree();
	for (int i = 0; i < rootList.size(); i++)
		rootList[i]->delTree();
	for (int i = 0; i < expectedRes.size(); i++)
		expectedRes[i]->delTree();
	res.clear();
	rootList.clear();
	list1.clear();
	list2.clear();
	size.clear();
}
