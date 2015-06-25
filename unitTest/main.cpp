#include "functions.h"
#include "test_readnode.h"
#include "test_readtree.h"
#include "test_readxml.h"
#include "test_findnodewithdata.h"
#include "test_computemaxcommonsubtree.h"
#include "test_computecommontree.h"
#include "test_findrootmaxcommontree.h"

/*!
* Выполняет программу
* \param[in] argc - количество переданных аргументов командной строки
* \param[in] argv[1] - имя файла вводных данных
* \param[in] argv[2] - имя файла выводных данных
* \return 0 - при успешном выполнении
* \return 1 - в противном случае
*/
int main(int argc, char *argv[]){
	setlocale(LC_ALL, "rus");
	if (argc == 1){
		test_readNode tReadNode;
		QTest::qExec(&tReadNode);

		test_readTree tReadTree;
		QTest::qExec(&tReadTree);

		test_readXML tReadXML;
		QTest::qExec(&tReadXML);

		test_findNodeWithData tFindNodeWithData;
		QTest::qExec(&tFindNodeWithData);

		test_computeMaxCommonSubTree tComputeMaxCommonSubTree;
		QTest::qExec(&tComputeMaxCommonSubTree);

		test_computeCommonTree tComputeCommonTree;
		QTest::qExec(&tComputeCommonTree);

		test_findRootMaxCommonTree tFindRootMaxCommonTree;
		QTest::qExec(&tFindRootMaxCommonTree);
	} else{
		// 1. Проверить аргументы командной строки на наличие входных данных. Если не достает какого – либо файла, сформировать сообщение об ошибке
		if (argc != 3){
			printf("Ошибка при выполнении программы.\nНеправильные аргументы.\n");
			return 1;
		}
		QString filein = QString(argv[1]);
		QString fileout = QString(argv[2]);

		node *root1, *root2;

		// 2. Считать входные данные
		try{
			// 2.1. Считать входные данные с помощью функции readXML и проверить их на корректность
			readXML(filein, root1, root2);
		} catch(const error& e){
			// 2.2. Если возникла ошибка, то сообщать на экран ошибок и вернуть 1
			e.printMessage();
			return 1;
		}
		node* resRoot = NULL;
		// 3. Найти пару вершин, которые содержат одинаковые цифры и общее поддерево с корнем в которой имеет максимальный размер, с помощью функции findRootMaxCommonTree
		findRootMaxCommonTree(root1, root2, resRoot);

		// 4. Напечатать результирующее дерево на XML-файл с помощью функции printResult
		printResult(fileout, resRoot);

		delete root1;
		delete root2;
		delete resRoot;
	}
	return 0;
}
