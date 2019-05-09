/*************************************************************************
* > File Name: media_library.h
* > Author   : rack
* > Function :
* > Type     :
* > Github   : https://github.com/rack-leen
* > Date     : 2018年06月05日 星期二 15时00分08秒
**************************************************************************/

/*************************************************************************
* > 头文件
**************************************************************************/
#include <stdio.h>

#define MAX_LENGTH 40       /* 播放序号最大长度 */
#define MAX_FILE_LENGTH 255 /* 文件名最大长度 */

/* 播放列表初始化 */
void playlist_init()
{
    /* l为当前播放序列长度 */
    unsigned int i , l ;

    /* 用播放序号指针指向文件名 */
    char *p_list ;

    /* 文件名数组 , 第一列存储播放序号，第二列存储文件名 */
    char f_list[MAX_LENGTH][MAX_FILE_LENGTH];

    /*初始化播放列表 */
    for(i=0 ; i<MAX_LENGTH ; i++)
    {
        p_list[i] = NULL ; /* 初始化播放列表指针 */
        f_list[i][0] = 0 ; /* 初始化文件数组的播放序列 */
    }
}


#define GET_NAME "%255S"

/* 打印播放列表 */
void print_playlist()
{

}
