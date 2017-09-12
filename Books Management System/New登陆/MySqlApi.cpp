#include "stdafx.h"
#include <WinSock2.h>
#include "mysql.h"
#include <string>
#include <stdio.h>
#include "MySqlApi.h"
#include <iostream>
#include<vector>
int MySqlApi::getRowCount(std::string UserName,std::string PassWord,std::string Database,std::string Table){

	
	MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);
	
	std::string sql = "select * from ";
	sql += Table;
	
	//char *sql = "select * from student";//unicode下用Cstring会很麻烦，直接用char
	mysql_query(&mysql, sql.c_str());
	result = mysql_store_result(&mysql);
	int rowcount = mysql_num_rows(result);
	mysql_close(&mysql);
	return rowcount;
}
int MySqlApi::getFieldCount(std::string UserName,std::string PassWord,std::string Database,std::string Table){

	
	MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);
	
	std::string sql = "select * from ";
	sql += Table;
	
	//char *sql = "select * from student";//unicode下用Cstring会很麻烦，直接用char
	mysql_query(&mysql, sql.c_str());
	result = mysql_store_result(&mysql);
	int fieldcount = mysql_num_fields(result);
	mysql_close(&mysql);
	return fieldcount;
}

//获取字段名称
void MySqlApi::getFieldName(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string* FieldName){
	MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);
	std::string sql = "select * from ";
	sql += Table;

	mysql_query(&mysql, sql.c_str());
	result = mysql_store_result(&mysql);
	int fieldcount = mysql_num_fields(result);

	for(int x = 0;x<fieldcount;x++){
		MYSQL_FIELD * field = mysql_fetch_field_direct(result,x);//返回字段定义
		
		FieldName[x] = field ->name;
	}
	mysql_close(&mysql);
	
	
}
void  MySqlApi::getTable(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string table[][10]){

	


	MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);
	std::string sql = "select * from  ";
	sql += Table;
	
	mysql_query(&mysql, sql.c_str());
	result = mysql_store_result(&mysql);
	int fieldcount = mysql_num_fields(result);
	int rowcount = mysql_num_rows(result);
	

	row = mysql_fetch_row(result);
	
	for(int r = 0;NULL != row;r++)
	{	
		for(int i=0; i<fieldcount; i++)
		{	
			
			table[r][i] =  row[i] ;
		}
		
		row = mysql_fetch_row(result);
	}
	
	mysql_close(&mysql);
}
int  MySqlApi::selectRowExists(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string* Row,
					 std::string KeyWordField,std::string KeyWord){

	MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);
	std::string sql = "select * from " +Table + " where " + KeyWordField + " = " + "\"" + KeyWord +"\"";
	//std::string sql = "select * from " +Table;
	mysql_query(&mysql, sql.c_str());
	result = mysql_store_result(&mysql);
	int fieldcount = mysql_num_fields(result);
	int rowcount = mysql_num_rows(result);
	if(rowcount==0){

		return 0;

	}
	else{
		row = mysql_fetch_row(result);
		for(int i=0; i<fieldcount; i++)
		{	
			
			Row[i] =  row[i] ;
			
		}

	}
	return 1;	
}

int MySqlApi::selectTable(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string data[][10],
				std::string KeyWordField,std::string KeyWord){
	
	MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);
	std::string sql = "select * from " +Table + " where " + KeyWordField + " = " + "\"" + KeyWord +"\"";
	
	mysql_query(&mysql, sql.c_str());
	result = mysql_store_result(&mysql);
	int fieldcount = mysql_num_fields(result);
	int rowcount = mysql_num_rows(result);
	
	if(rowcount==0){

		return 0;

	}
	else{

		for(int r = 0;r<rowcount;r++){
		row = mysql_fetch_row(result);
		for(int i=0; i<fieldcount; i++)
		{	
			
			data[r][i] =  row[i] ;
		}

		}
	}
	return 1;	


	
}
void MySqlApi::insertRow(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string value){
	MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);
	std::string sql = "insert into " + Table + " value" + value;
	mysql_query(&mysql, sql.c_str());
	
}
void MySqlApi::deletetRow(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string KeyWordField,std::string KeyWord){
	MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);
	std::string sql = "delete from " +Table + " where " + KeyWordField + " = " + "\"" + KeyWord +"\"";
	mysql_query(&mysql, sql.c_str());
}
int MySqlApi::fuzzyQuery(std::string UserName,std::string PassWord,std::string Database,std::string Table,std::string data[][10],
						  std::string KeyWordField,std::string KeyWord){
	MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", UserName.c_str(), PassWord.c_str(), Database.c_str(), 3306, NULL, 0);
	std::string sql = "select * from " +Table + " where " + KeyWordField + " like " + "\"%" + KeyWord +"%\"";

	mysql_query(&mysql, sql.c_str());
	result = mysql_store_result(&mysql);
	int fieldcount = mysql_num_fields(result);
	int rowcount = mysql_num_rows(result);
	
	if(rowcount==0){

		return 0;

	}
	else{

		for(int r = 0;r<rowcount;r++){
		row = mysql_fetch_row(result);
		for(int i=0; i<fieldcount; i++)
		{	
			
			data[r][i] =  row[i] ;
		}

		}
	}
	return 1;	


}