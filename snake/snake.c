/**************************************************************************\
* > File Name: snake.c
* > Author   : rack
* > Function :
* > Type     :
* > Github   : https://github.com/rack-leen
* > Date     : 2019年03月10日 星期日 18时00分01秒
\**************************************************************************/

/**************************************************************************\
* > 头文件
\**************************************************************************/
#include "snake.h"


/**************************************************************************\
* > 函数实体
\**************************************************************************/

void printMain()
{
    printf("================================================\n");
    printf("\t\t贪吃蛇v1.0\n");
    printf("================================================\n");
    printf("1.开始游戏\n");
    printf("2.退出游戏\n");
    printf("请输入您的选项：\n");
    int n ;
    scanf("%d",&n);
    switch(n)
    {
        case 1 :
            startGame() ;
            break ;
        case 0 :
            printf("谢谢使用！再见\n");
            exit(0);
    }
}

void startGame()
{
    initscr() ;
    initGame() ;
    //show() ;
    signal(SIGALRM,show) ;
    getOrder();
    endwin();
}

//初始化游戏
void initGame(){
    cbreak() ;//Normally, the tty driver buffers typed characters until a newline or carriage return is typed.
    noecho() ; //不回显
    curs_set(0) ; //把光标位置设置为不可见
    keypad(stdscr , true) ; //使用用户终端的键盘上的小键盘
    srand(time(0));//设置随机种子

    //初始化各项数据
    hour = minute = second = tTime = 0 ;
    snake_length = 1 ; //蛇的初始长度为1
    snake_direct.x = 1 ; //蛇初始是向x轴前进,1表示正x轴方向,-1表示负x轴方向
    snake_direct.y = 0 ; //0表示否

    cmd = 'A' ; //键盘上的A键
    food.x = rand() % COLS ; //食物在x轴上出现的随机位置
    food.y = rand() % (LINES-2) + 2 ; //食物在y轴上出现的随机位置
    createLink() ; //创建链表
    setTicker(20) ; //设置的是通知时在状态栏显示的内容
}

//设置计时器
int setTicker(int n_msecs)
{
    struct itimerval new_timeset ;
    long n_sec , n_usecs ;

    n_sec = n_msecs / 1000 ;
    n_usecs = (n_msecs % 1000) * 1000L ;
    new_timeset.it_interval.tv_sec = n_sec ;
    new_timeset.it_interval.tv_usec = n_usecs ;

    n_msecs = 1 ;

    n_sec = n_msecs / 1000 ;
    n_usecs = (n_msecs % 1000) * 1000L ;
    new_timeset.it_value.tv_sec = n_sec ;
    new_timeset.it_value.tv_usec = n_usecs ;

    return setitimer(ITIMER_REAL,&new_timeset , NULL) ;
}

void showGameInfo()
{
    tTime++ ;
    if(tTime >= 1000000){
        tTime = 0 ;
    }

    if(1 != tTime % 50){
        return ;
    }

    //在第0行显示
    move(0,3) ;

    //显示时间
    printw("time:%d:%d:%d %c", hour , minute , second);
    second++ ;

    if(second > NUM){
        second = 0 ;
        minute++ ;
    }

    if(minute > NUM){
        minute = 0 ;
        hour++ ;
    }

    //显示长度。等级
    move(1,0);
    int i ;
    //COLS表示终端的最大列数
    for(i=0 ; i<COLS ; i++){
        addstr("=");//将第一行用-填满,作为分界线
    }

    //在第0行的中间显示
    move(0,COLS/2-5);
    printw("length:%d",snake_length);

    move(0,COLS-10);
    level = snake_length / 3 + 1 ;

    printw("level:%d",level);
}



void showSnake(){
    if(1 != tTime % (30-level))
    {
        return ;
    }

    //判断蛇的长度有没有变化
    bool snake_length_change = false ;

    //随机位置显示食物
    move(food.y , food.x);
    printw("@");

    //如果蛇碰到墙，则游戏结束
    //COLS-1 == head->next->x && 1 == snake_direct.x 如果蛇朝着正x轴方向并且是蛇头的位置等于墙的位置
    if( (COLS-1 == head->next->x && 1 == snake_direct.x)||
        (0 == head->next->x && -1 == snake_direct.x)||
        (LINES-1 == head->next->y && 1 == snake_direct.y)||
        (2 == head->next->y && -1 == snake_direct.y))
    {
        over(1); //结束游戏
        return ;
    }

    //如果蛇头碰到自身
    if('□' == mvinch(head->next->y + snake_direct.y , head->next->x + snake_direct.x))
    {
        over(2);
        return ;
    }

    //增加x轴方向的节点和增加y轴方向的节点
    insertNode(head->next->x + snake_direct.x , head->next->y + snake_direct.y);

    //蛇吃了一个食物
    if(head->next->x == food.x && head->next->y == food.y)
    {
        snake_length_change = true ; //长度改变
        snake_length++ ;

        //通关
        if(snake_length >= 50)
        {
            over(3);
            return ;
        }

        //重新设置食物位置
        food.x = rand() % COLS ;
        food.y = rand() % (LINES-2)+2 ; //排除最上面的两行
    }

    //如果没有改变长度，则表示没有吃到食物，继续移动
    if(!snake_length_change)
    {
        move(tail->back->y , tail->back->x);//移动尾部
        printw(" ");
        deleteNode() ; //删除原来位置的节点，使得蛇长与原来一致
    }

    move(head->next->y,head->next->x);
    printw("*");
}

void show()
{
    signal(SIGALRM,show) ; //设置中断信号
    showGameInfo() ;
    showSnake() ;
    refresh(); //刷新屏幕
}

void getOrder()
{
    //建立死循环，获取来自键盘的命令
    while(1)
    {
        cmd = getch() ; //获取输入命令

        if(KEY_LEFT == cmd)
        {
            snake_direct.x = -1 ;
            snake_direct.y = 0 ;
        }
        else if(KEY_RIGHT == cmd)
        {
            snake_direct.x = 1 ;
            snake_direct.y = 0 ;
        }

        else if(KEY_DOWN == cmd)
        {
            snake_direct.x = 0 ;
            snake_direct.y = 1 ;
        }

        else if(KEY_UP == cmd)
        {
            snake_direct.x = 0 ;
            snake_direct.y = -1 ;
        }

        setTicker(20);
    }
}


void over(int i)
{
    //显示结束原因
    move(0,0);
    int j ;
    for(j=0 ; j<COLS ; j++)
    {
        addstr(" ");
    }

    move(0,2);
    if(1 == i)
    {
        addstr("!Oop,you crash the wall , game over .");
    }

    else if(2 == i)
    {
        addstr("!Oop,you crash youself , game over .");
    }

    else if(3 == i)
    {
        addstr("Mission complete.");
    }

    setTicker(0);
    deleteLink() ;
}

void createLink()
{
    node *temp = (node *)malloc(sizeof(node)); //动态分配内存空间
    head = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));

    //双向链表初始位置
    temp->x = 5 ;
    temp->y = 10 ;

    head->back = tail->next = NULL ; //头节点的前指针与尾节点的后指针都为空
    head->next = temp ; //头节点指向下一个的指针指向temp,表示为蛇赋值了一个初始位置
    temp->next = tail ;
    tail->back = temp ;
    temp->back = head ;
}

//在链表头部插入节点
void insertNode(int x , int y)
{
    node *temp = (node *)malloc(sizeof(node));

    //将外界传入的xy值赋值给临时变量
    temp->x = x ;
    temp->y = y ;

    temp->next = head->next ;
    head->next = temp ;
    temp->back = head ;
    temp->next->back = temp ;

}


//删除链表的节点
void deleteNode()
{
    node *temp = tail->back ; //定义一个需要删除的节点，也就是尾节点的前一个
    node *bTemp = temp->back ;//定义需要删除节点的前一个
    bTemp->next = tail ; //需要删除的节点的前一个节点指向尾节点
    tail->back = bTemp ; //尾节点的前指针指向需要删除的节点的前一个节点
    temp->next = temp->back = NULL ;//原本temp->next指向tail,但是现在为空；tail->back指向temp;这两个都为空，表示temp为空
    free(temp) ;
    temp = NULL ;
}

//删除整个链表
void deleteLink()
{
    while(head->next != tail)
    {
        deleteNode() ;
    }

    head->next = tail->back = NULL ;
    free(head) ;
    free(tail) ;
}

