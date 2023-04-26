#include "SqList.h"
#include <iostream>

using namespace std;

int main()
{
	SqList l1, l2;
	int s1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int s2[] = { 2, 2, 4, 5, 6, 7 };
	l1.Init_SqList(s1, 9);
	l2.Init_SqList(s2, 6);
	l1.PrintList();
	l2.PrintList();

	// P18_01
	/*int min;
	l1.Del_Min(l1, min);
	cout << min << endl;
	l1.PrintList();*/
	
	// P18_02
	/*l1.Reverse(l1);
	l1.PrintList();*/

	// P18_03
	/*l1.Del_Value(l1, 2);
	l1.PrintList();*/

	// P18_04
	/*l1.Del_Seq(l1, -2, 0);
	l1.PrintList();*/
	
	// P18_05
	/*l1.Del_Seq_NoSort(l1, 2, 6);
	l1.PrintList();*/

	// P18_06
	/*l1.Del_Same(l1);
	l1.PrintList();*/

	// P18_07
	/*SqList l3;
	l1.Merge(l1, l2, l3);
	l3.PrintList();*/

	// P18_08
	/*l1.Exchange(l1, 3, 6);
	l1.PrintList();*/

	// P18_09
	/*l1.Find_x(l1, 3);
	l1.PrintList();*/

	// P18_10
	l1.LMove(s1, 9, 4);

}