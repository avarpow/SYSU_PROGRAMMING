// subwaygui.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <graphics.h>		// Reference graphics library header file
#include <conio.h>
#include<iostream>
#include<string>
#include "gui.h"
using namespace std;
IMAGE cover;
void load_image() {
	loadimage(&cover, "2.jpg");
}
int main()
{
	initgraph(1050,700);	// Create a graphics window with a size of 640x480 pixels
	//circle(200, 200, 100);	// Draw a circle with center (200, 200) and radius 100
	load_image();
	// RECT r = { 0, 0, 639, 479 };
	// putimage(0, 0, &cover);
	// string  msg= "---------------------------广州地铁查询------------------------\n"
	// 	"                          1.地铁线路查询                       \n"
	// 	"                          2.站点-站点查询                      \n"
	// 	"                          3.退出                              \n"
	// 	"--------------------------------------------------------------\n";
	// LPCTSTR tempmsg = msg.c_str();
	// drawtext(tempmsg, &r, DT_CENTER | DT_VCENTER  );
	// char s[10];
	// InputBox(s, 10, "Please enter the chose");

	// // Convert user input to numbers
	// int te = atoi(s);

	GUI g;
    g.GUIinit();
    g.GUImain();
	_getch();
	closegraph();			
	return 0;
}

