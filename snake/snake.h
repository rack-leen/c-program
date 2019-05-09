/**************************************************************************\
* > File Name: snake.h
* > Author   : rack
* > Function :
* > Type     :
* > Github   : https://github.com/rack-leen
* > Date     : 2019年03月10日 星期日 17时43分14秒
\**************************************************************************/

#ifndef _SNAKE_H
#define _SNAKE_H

/**************************************************************************\
* > 头文件
\**************************************************************************/
#include <stdio.h>              //stdio.h头文件定义了三个变量类型，一些宏和各种函数来执行输入输出
#include <stdlib.h>             //stdlib.h头文件定义了四个变量类型，一些宏和各种通用工具函数
#include <curses.h>             //linux下广泛应用的图形函数库，作用是在终端内绘制简单的图形用户界面
#include <signal.h>             //信号处理，定义程序执行时如何处理不同的信号
#include <sys/time.h>           //linux系统的日期时间文件
#define NUM 60

/**************************************************************************\
* > 贪吃蛇结构体
\**************************************************************************/

//方向结构体
struct direct
{
    int x ;                     //x轴
    int y ;                     //y轴
};

//链表结构
typedef struct node
{
    int x ;
    int y ;
    struct node *back ;
    struct node *next ;
}node ;

/**************************************************************************\
* > 函数原型
\**************************************************************************/
void printMain(); //打印主界面
void startGame() ;
void initGame() ; //初始化游戏
int setTicker(int) ; //设置计时器
void show();       //显示整个画面
void showGameInfo(); //显示游戏信息
void showSnake() ; //显示蛇的身体
void getOrder() ; //从键盘获取命令
void over(int i) ;  //完成游戏结束后的提示信息

void createLink() ; //创建双向链表以及它的操作  该链表用来表示蛇
void insertNode(int x , int y); //增加节点 增加蛇的长度
void deleteNode() ; //删除节点 游戏完成或者结束，删除创建的节点
void deleteLink() ; //删除链表 游戏完成或者结束，删除创建的链表


/**************************************************************************\
* > 全局变量
\**************************************************************************/
int cmd ;                       //输入的命令
int hour , minute , second ;    //时分秒
int snake_length ;              //蛇的长度
int tTime ;                     //计时器,游戏时长
int level ;                     //游戏等级
struct direct snake_direct ;    //蛇前进的方向
struct direct food ;            //食物所在位置
node *head=NULL , *tail=NULL ;            //链表的头结点和尾节点

#endif

