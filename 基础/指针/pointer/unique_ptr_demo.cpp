#include "stdafx.h"
#include <memory>
#include <string>
#include <list>

#include "ptr.h"

using namespace std;

typedef unsigned char cv_pixel_format;

/// 图像格式定义
typedef struct cv_image_t {
	unsigned char *data;            ///< 图像数据指针
	cv_pixel_format pixel_format;   ///< 像素格式
	int width;                      ///< 宽度(以像素为单位)
	int height;                     ///< 高度(以像素为单位)
	int stride;                     ///< 跨度, 即每行所占的字节数
} cv_image_t;

void cv_image_release(cv_image_t* image) {
	if (image == nullptr) {
		return;
	}
	delete[] image->data;
	delete image;
	return;
}

int unique_demo() {
	/*智能指针的创建*/  
	unique_ptr<int> u_i; //创建空智能指针
	u_i.reset(new int(3)); //"绑定”动态对象  
	unique_ptr<int> u_i2(new int(4));//创建时指定动态对象
	//unique_ptr<T, D> u(d);	//创建空unique_ptr,执行类型为T的对象，用类型为D的对象d来替代默认的删除器delete

	/*所有权的变化*/
	//std::unique_ptr<int>p2 = u_i2;// 编译会出错
	int *p_i = u_i2.release(); //释放所有权  
	unique_ptr<string> u_s(new string("abc"));
	unique_ptr<string> u_s2 = std::move(u_s); //所有权转移(通过移动语义)，u_s所有权转移后，变成无效的指针
	unique_ptr<string> u_s3(new string("def"));
	unique_ptr<string> u_s4;
	u_s4.reset(u_s3.release());//所有权转移
	u_s4.reset(new string("ghi"));//释放原来管理的对象，分配一个新的指针

	/*交换*/
	u_s2.swap(u_s4);//交换内容

	/*释放内存*/
	u_i.reset();// empty
	u_i2.reset();// empty
	u_s.reset();//已转移所有权，无效的释放
	u_s2 = nullptr;//显式销毁所指对象，同时智能指针变为空指针。相当于u_i.reset();
	//u_s3已经转移所有权，不用再释放了
	u_s4 = nullptr;

	/**自定义删除器
	 * why:当你的对象不能仅仅只是依靠 delete 删除时，那么你就需要依靠自定义的删除器了。例如对象中还有其它对象的数组等
	 * how:编写一个删除器，指定输入的参数，然后实现相应的释放操作，并将这个删除器传入 unique_ptr 中
	 */

	return E_OK;
}