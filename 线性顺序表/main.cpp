#include "SqList.h"
#include <iostream>

using namespace std;

int main()
{
	SqList l1;
	int s1[] = { 1, 5, 3, 4, 5, 1, 7, 6, 9};
	l1.Init_SqList(s1, 9);
	l1.PrintList();

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
	l1.Del_Seq_NoSort(l1, 2, 6);
	l1.PrintList();
}