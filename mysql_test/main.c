#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "/usr/include/mysql/mysql.h"

static MYSQL mysql , *sock ;
char sql[1024] ;
MYSQL_RES *es = NULL ;
MYSQL_ROW row ;
int num_fileds ;
int num_rows = 0 ;

int main()
{
	memset(sql , 0x00 , sizeof(sql)) ;
	mysql_init(&mysql) ;

	if(!(sock = mysql_real_connect(&mysql , (char *)"localhost" , (char *)"root" , (char *)"19970110AA" , (char *)"herodb" , 0 , NULL , 0)))
	{
		printf("不能链接数据库！\n\n%s\n",mysql_error(&mysql)) ;
		return 0 ;
	}

	if(sock)
	{
		printf("SUCCESS!\n") ;
	}
	else
	{
		printf("FAIL!\n");
		return 0 ;
	}

	//将输入的数据库语句存入sql中
	sprintf(sql , "create table my_account(userId int(3) , userName varchar(10) , userPasswd varchar(10)); ") ;

	//mysql_query执行数据库语句,通过sock发送给数据库
	if(mysql_query(sock, sql)) {
         printf("mysql_query[%d] [%s]!\n", mysql_errno(sock), mysql_error(sock));
         return -1;
     }
     //mysql_affected_rows() 函数返回前一次 MySQL 操作所影响的记录行数。
     //如果上一次查询失败的话，函数返回 -1。
     //执行成功则返回受影响的行的数。
    if( !(mysql_affected_rows( sock )) ){
        printf("create OK\n");
    }else{
        printf("create Fail\n");
    }
    if(mysql_errno(sock)){
        printf("mysql_affected_rows[%d] [%s]!\n", mysql_errno(sock), mysql_error(sock));
    }
    return 0;
}
