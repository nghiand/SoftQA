#ifndef _FUNCTIONS_
#define _FUNCTIONS_
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <qdebug.h>
#include <qset.h>
#include <qset.h>
#include <qtextcodec.h>
#include <locale>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include "node.h"
#include "error.h"

const int MAX_TREE_SIZE = 30;

/**
 * \defgroup Функции Функции программы
 * @{
 */

/*!
* Считать открывающий тег вершины, создав её или, считать закрывающий тег вершины, в зависимости от положения в потоке
* \param[in] xmlStream - покок чтения на вводный XML-файл
* \param[in] treeNum - номер дерева, которое считываются
* \param[out] newNode - указатель на новую вершину
* \return 1 - при считывал открывающий тег и новая вершина создалась
* \return -1 - при считывал закрывающий тег
* \return 0 - при других случах.
*/
int readNode(QXmlStreamReader& xmlStream, int treeNum, node*& newNode);

/*!
* Считать и построить дерево
* \param[in] xmlStream - покок чтения на вводный XML-файл
* \param[in] treeNum - номер дерева, которое считываются
* \param[out] root - указатель на корень входного дерева
*/
void readTree(QXmlStreamReader& xmlStream, node*& root, int treeNum);

/*!
* Считать данные из XML-файла и построить деревья
* \param[in] filename - имя входного файла
* \param[out] root1 - указатель на корень первого дерева
* \param[out] root2 - указатель на корень второго дерева
*/
void readXML(QString file, node*& root1, node*& root2);

/*!
* Добавить вершину в таблицу
* \param[in] currentNode - указатель на коренную вершину поддерева
* \param[out] nodeTable - таблица вершин дерева
*/
void addNodeToTable(node* currentNode, QHash<int, node*>& nodeTable);

/*!
* Рассчитать максимальный размер общего поддерева с корнем в вершине с цифрой k, когда размеры общих поддеревьев с корнями в дочернях известны
* \param[in] list1 - массив дочерей вершины с цифрой k в первом дереве
* \param[in] list2 - массив дочерей вершины с цифрой k во втором дереве
* \param[in] size - массив размеров общих поддеревьев с корнями в дочерях вершины с цифрой k в первом дереве
* \param[in] rootList - массив корней максимальных общих поддеревьев, найдены в дочерях вершины с цифрой k в первом дереве
* \param[out] res - список дочерей, которые в общем дереве
* \return - максимальный размер общего дерева
*/
int computeMaxCommonSubTree(const QVector<node*>& list1, const QVector<node*>& list2, const QVector<int>& size, const QVector<node*>& rootList, QVector<node*>& res);

/*!
* Рассчитать размер максимального общего поддерева 2 деревьев, у которой корень в вершине root1 в первом дереве и в вершине root2 во втором дереве. Цифры в 2 вершинах root1 и root2 одинаковые
* \param[in] root1 - указатель на вершину в первом дереве
* \param[in] root2 - указатель на вершину во втором дереве
* \param[out] commonRoot - указатель на корень максимального общего поддерева
* return - максимальный размер общего поддерева
*/
int computeCommonTree(node* root1, node* root2, node*& commonRoot);

/*!
* Найти вершину, цифра, присвоенная которой присутствует в обоих деревьях, и размер общего поддерева в которой максимальный
* \param[in] root1 - указатель на корень первого дерева
* \param[in] root2 - указатель на корень второго дерева
* \param[out] retRoot - указатель на корень найденного максимального общего поддерева
* \param[in] nodeTableTree2 - таблица вершин второго дерева
* \return - максимальный размер общего поддерева двух деревьев
*/
int findRootMaxCommonTree(node* root1, node* root2, node*& retRoot, const QHash<int, node*>& nodeTableTree2);

/*!
* Напечатать цифру вершины результирующего дерева на XML-файл
* \param[in] stream - покок записи на выводный XML-файл
* \param[in] currentNode - указатель на вершину результающего дерева, которую надо напечать
*/
void printNode(QXmlStreamWriter& stream, node* currentNode);

/*!
* Напечатать результируюющее дерево на XML-файл
* \param[in] filename - название выходного файла
* \param[in] root - указатель на корень результирующего дерева
*/
void printResult(QString filename, node* root);
/**@}*/
#endif