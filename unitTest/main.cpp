#include "functions.h"
#include "test_readnode.h"
#include "test_readtree.h"
#include "test_readxml.h"
#include "test_findnodewithdata.h"
#include "test_computemaxcommonsubtree.h"
#include "test_computecommontree.h"
#include "test_findrootmaxcommontree.h"

/*!
* ��������� ���������
* \param[in] argc - ���������� ���������� ���������� ��������� ������
* \param[in] argv[1] - ��� ����� ������� ������
* \param[in] argv[2] - ��� ����� �������� ������
* \return 0 - ��� �������� ����������
* \return 1 - � ��������� ������
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
		// 1. ��������� ��������� ��������� ������ �� ������� ������� ������. ���� �� ������� ������ � ���� �����, ������������ ��������� �� ������
		if (argc != 3){
			printf("������ ��� ���������� ���������.\n������������ ���������.\n");
			return 1;
		}
		QString filein = QString(argv[1]);
		QString fileout = QString(argv[2]);

		node *root1, *root2;

		// 2. ������� ������� ������
		try{
			// 2.1. ������� ������� ������ � ������� ������� readXML � ��������� �� �� ������������
			readXML(filein, root1, root2);
		} catch(const error& e){
			// 2.2. ���� �������� ������, �� �������� �� ����� ������ � ������� 1
			e.printMessage();
			return 1;
		}
		node* resRoot = NULL;
		// 3. ����� ���� ������, ������� �������� ���������� ����� � ����� ��������� � ������ � ������� ����� ������������ ������, � ������� ������� findRootMaxCommonTree
		findRootMaxCommonTree(root1, root2, resRoot);

		// 4. ���������� �������������� ������ �� XML-���� � ������� ������� printResult
		printResult(fileout, resRoot);

		delete root1;
		delete root2;
		delete resRoot;
	}
	return 0;
}
