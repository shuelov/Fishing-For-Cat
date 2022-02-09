#pragma once

#include "Include.h"

class Mysql
{

public:
	Mysql();
	~Mysql();

	// MYSQL 구조체 변수 (Logo 챕터에서 1 단계 테스트 접속 확인을 위함...)
	MYSQL mysql;

	// MYSQL 연결 및 구동 변수
	MYSQL		*connection = NULL, conn;
	MYSQL_RES	*sql_result;
	MYSQL_ROW	sql_row;
	int query_start;

	// 데이타 베이스 칼럼 저장 변수
	//char name[12];
	//char address[80];
	//char tel[12];
	char query[1000];

	//db에 저장해야할 총 20개 내용

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

	// MYSQL 상태 변수
	char state[256];
	bool mysql_Success;

	// MYSQL 결과 확인 변수
	char result[256];

	void Init();
	void Update();
	void Draw();
	void save();
	void save2();
	void save3();

};

extern Mysql sql;