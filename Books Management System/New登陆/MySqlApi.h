#ifndef CIRCLE_H
#define CIRCLE_H
#include "stdafx.h"
#include <WinSock2.h>
#include "mysql.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include<vector>
class MySqlApi
{
public:
	//输入MySql的用户名 密码 数据库名 表格名 获得表格行数
	int getRowCount(std::string UserName,std::string PassWord,std::string Database,std::string Table);//得到表的行数
	//输入MySql的用户名 密码 数据库名 表格名 获得表格列数
	int getFieldCount(std::string UserName,std::string PassWord,std::string Database,std::string Table);//得到表的列数
	//在主程序内 建立一个string数组 例如 std::string FieldName[10];    并连同MySql的用户名 密码 数据库名 表格名 传入函数 函数将表头数据存入 string数组内
	void getFieldName(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string* FieldName);//得到表头数据

	//在主程序内 建立一个string二维数组 例如 std::string FieldName[10][10];    并连同MySql的用户名 密码 数据库名 表格名 传入函数 函数将表头数据存入 string二维数组内
	void getTable(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string table[][10]);//得到表格数据

	//在主程序内 建立一个string数组 例如 std::string FieldName[10];    并连同MySql的用户名 密码 数据库名 表格名 关键词 传入函数 
	//若数据存在 函数将存入string数组内 返回值为1 否则 返回值 为0  该函数只可查找一行 并且keyword 为主键  用于查找用户
	int selectRowExists(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string* Row,
		std::string KeyWordField,std::string KeyWord);


	//在主程序内 建立一个string二维数组 例如 std::string FieldName[10][10];    并连同MySql的用户名 密码 数据库名 表格名 关键词 传入函数 
	//若数据存在 函数将存入string二维数组内 返回值为1 否则 返回值 为0      
	int selectTable(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string data[][10],
		std::string KeyWordField,std::string KeyWord);
	//在主程序里创建一个string  例如 std::string value = (1,\"chenyi\",\"man\",2015.2014)   value内格式必须为 (1,\"chenyi\",\"man\",2015.2014)  括号内为要添加的数据
	//字符串内 引号为 \"
	void insertRow(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string value );
	//在主程序内  将KeyWordField（字段名） 与 要删除的KeyWord  同MySql的用户名 密码 数据库名 表格名 传入函数 
	void deletetRow(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string KeyWordField,std::string KeyWord);
	//在主程序内 建立一个string二维数组 例如 std::string FieldName[10][10];    并连同MySql的用户名 密码 数据库名 表格名 关键词 传入函数 
	//若数据存在 函数将存入string二维数组内 返回值为1 否则 返回值 为0   模糊查询
	int fuzzyQuery(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string data[][10],
		std::string KeyWordField,std::string KeyWord);
};


#endif