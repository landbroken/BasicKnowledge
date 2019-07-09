// memory.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

const int maxCnt = 4;
#define E_OK 0
#define E_NOT_OK 1

struct Phone
{
	int year;//年份
	int price;//单价
	int sales;//销量
	double profit;//利润
};

#pragma region c

/**
* malloc创建动态数组，分配内存
*/
Phone* createPhoneArrUseMalloc(Phone* pArr) {
	pArr = (Phone*)malloc(sizeof(struct Phone)*maxCnt);
	//初始化
	memset(pArr, 0, sizeof(struct Phone)*maxCnt);

	return pArr;
}

Phone* deletePhoneArrWithDelete(Phone* pArr) {
	if (pArr != NULL) {
		free(pArr);
		pArr = NULL;
	}
	return pArr;
}

#pragma endregion

#pragma region cpp

/**
 * new创建动态数组，分配内存
 */
Phone* createPhoneArrUseNew(Phone* pArr) {
	pArr = new Phone[maxCnt];
	//初始化
	memset(pArr, 0, sizeof(struct Phone)*maxCnt);

	return pArr;
}

Phone* deletePhoneArrWithFree(Phone* pArr) {
	if (pArr != nullptr) {
		delete pArr;
		pArr = nullptr;
	}
	return pArr;
}

#pragma endregion

int setValue(Phone* pArr, size_t size) {
	int begin = 2019;
	for (size_t i = 0;i < size;i++) {
		begin = begin + i;
		pArr[i].year = begin;
		pArr[i].price = 10000 - begin;
		pArr[i].sales = 10 - i;
		pArr[i].profit = ((double)pArr[i].price)*0.3*pArr[i].sales;
	}
	return E_OK;
}

int printAllData(Phone* pArr, size_t size) {
	for (size_t i = 0;i < size;i++) {
		printf_s("year = %d, price = %d, sales=%d, profit=%f\n", 
			pArr[i].year, pArr[i].price, pArr[i].sales, pArr[i].profit);
	}
	return E_OK;
}

int main()
{
	Phone* iphone_xs = nullptr;//cpp的空指针关键字
	Phone* iphone_x = NULL;//c的
	iphone_xs = createPhoneArrUseNew(iphone_xs);
	iphone_x = createPhoneArrUseMalloc(iphone_x);
	setValue(iphone_xs, maxCnt);
	setValue(iphone_x, maxCnt);
	printAllData(iphone_xs, maxCnt);
	printAllData(iphone_x, maxCnt);
	iphone_xs = deletePhoneArrWithDelete(iphone_xs);
	iphone_x = deletePhoneArrWithFree(iphone_x);
    return 0;
}

