#pragma once

#include "Include.h"

class Mysql
{

public:
	Mysql();
	~Mysql();

	// MYSQL ����ü ���� (Logo é�Ϳ��� 1 �ܰ� �׽�Ʈ ���� Ȯ���� ����...)
	MYSQL mysql;

	// MYSQL ���� �� ���� ����
	MYSQL		*connection = NULL, conn;
	MYSQL_RES	*sql_result;
	MYSQL_ROW	sql_row;
	int query_start;

	// ����Ÿ ���̽� Į�� ���� ����
	//char name[12];
	//char address[80];
	//char tel[12];
	char query[1000];

	//db�� �����ؾ��� �� 20�� ����

	char money[10];
	char cruciancarp[10];
	char jang[10];
	char lobster[10];
	char bing[10];
	char frog[10];
	char ing[10];
	char octopus[10];
	char shark[10];
	char trash[10];
	char tuna[10];
	char yeon[10];
	char bait[10];
	char ricecake[10];
	char shirimp[10];
	char fishingrod[10];
	char goodfishingrod[10];
	char num_quest[10];
	char wear_fishingrod[10];
	char use_item[10];

	// MYSQL ���� ����
	char state[256];
	bool mysql_Success;

	// MYSQL ��� Ȯ�� ����
	char result[256];

	void Init();
	void Update();
	void Draw();
	void save();
	void save2();
	void save3();

};

extern Mysql sql;