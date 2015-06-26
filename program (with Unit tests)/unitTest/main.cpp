#include "functions.h"
#include "test_readnode.h"
#include "test_readtree.h"
#include "test_readxml.h"
#include "test_findnodewithdata.h"
#include "test_computemaxcommonsubtree.h"
#include "test_computecommontree.h"
#include "test_findrootmaxcommontree.h"

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
		printf("Ошибка при выполнении программы.\nНеправильные аргументы.\n");
		return 1;
	}
	return 0;
}
