#pragma once
#include "Include.h"

Mysql sql;


Mysql::Mysql()
{

}

Mysql::~Mysql()
{
}

void Mysql::Init()
{

}

void Mysql::Update()
{


}

void Mysql::Draw()
{
	// 데이타 베이스 처리 상태 표시/////////////////////////////////////
	if (sql.mysql_Success)


	{
		//dv_font.DrawString("Success", 500, 0);
	}
	else
	{
		dv_font.DrawString("Error", 500, 0);
		dv_font.DrawString(sql.state, 700, 0);
	}
	////////////////////////////////////////////////////////////

}

void Mysql::save()
{
	if (!sql.mysql_Success)return;

	/////// 도스 모드인 경우////////////////////
	// insert Value
	// 이름
	//fgets(name, 12, stdin);
	//CHOP(name);

	// 비밀번호
	//fgets(address, 80, stdin);
	//CHOP(address);
	////////////////////////////////////////////

	////// 우린 에디터 박스가 필요////////////////

	//// 테이블 저장 값 입력
	//sprintf_s(name, "%s", "A2");
	//sprintf_s(address, "%s", "2B");

	/////////////////////////////////////////////

	_itoa_s(inventory.money, money, 10); //1 돈
	_itoa_s(item.item_cruciancarp.howmany, cruciancarp, 10); //2 붕어
	_itoa_s(item.item_jang.howmany, jang, 10); //3 장어
	_itoa_s(item.item_lobster.howmany, lobster, 10); //4 
	_itoa_s(item.item_bing.howmany, bing, 10); //5 
	_itoa_s(item.item_frog.howmany, frog, 10); //6 
	_itoa_s(item.item_ing.howmany, ing, 10); //7 
	_itoa_s(item.item_octopus.howmany, octopus, 10); //8 
	_itoa_s(item.item_shark.howmany, shark, 10); //9 
	_itoa_s(item.item_trash.howmany, trash, 10); //10 
	_itoa_s(item.item_tuna.howmany, tuna, 10); //11
	_itoa_s(item.item_yeon.howmany, yeon, 10); //12 
	_itoa_s(item.item_bait.howmany, bait, 10); //13
	_itoa_s(item.item_ricecake.howmany, ricecake, 10); //14 
	_itoa_s(item.item_shirimp.howmany, shirimp, 10); //15 
	_itoa_s(item.item_fishingrod.howmany, fishingrod, 10); //16 
	_itoa_s(item.item_goodfishingrod.howmany, goodfishingrod, 10); //17 
	_itoa_s(quest.num_mission, num_quest, 10); //18
	_itoa_s(inventory.usingfishrodcode, wear_fishingrod, 10); //19
	_itoa_s(inventory.usingbaitcode, use_item, 10); // 

	//변수명 #define으로 숫자로 셋팅해서 for문으로 돌리는게 깔끔하게 코딩됨
	// 전달 할 쿼리값 셋팅

	sprintf_s(query, "update save set money=%s where saveslot=1", money);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set cruciancarp_num=%s where saveslot=1", cruciancarp);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set jang_num=%s where saveslot=1", jang);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set lobster_num=%s where saveslot=1", lobster);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set bing_num=%s where saveslot=1", bing);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set frog_num=%s where saveslot=1", frog);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set ing_num=%s where saveslot=1", ing);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set octopus_num=%s where saveslot=1", octopus);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set shark_num=%s where saveslot=1", shark);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set trash_num=%s where saveslot=1", trash);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set tuna_num=%s where saveslot=1", tuna);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set yeon_num=%s where saveslot=1", yeon);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set bait_num=%s where saveslot=1", bait);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set ricecake_num=%s where saveslot=1", ricecake);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set shrimp_num=%s where saveslot=1", shirimp);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set fishingrod=%s where saveslot=1", fishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set goodfishingrod=%s where saveslot=1", goodfishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set quest=%s where saveslot=1", num_quest);//수정
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set wearfishingrod=%s where saveslot=1", wear_fishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set usingitem=%s where saveslot=1", use_item);
	query_start = mysql_query(connection, query);


	//sprintf_s(query, "update save set money='%s' where saveslot is '1'", money); 

	//query_start = mysql_query(connection, "update save set money='money' where saveslot='1'");

	//query_start = mysql_query(connection, "insert into save (saveslot) values (2)");
	// 다음 mysql_query() 함수로 MYSQL 구조체를 통한 쿼리문 전송
	query_start = mysql_query(connection, query);
	if (query_start != 0) // 전송 실패시
	{
		sprintf_s(state, "Mysql query error : %s", mysql_error(&conn));
		sql.mysql_Success = false;
	}
	else // 성공시
	{
		mysql_Success = true;
	}
}

void Mysql::save2()
{
	if (!sql.mysql_Success)return;
	/////////////////////////////////////////////

	_itoa_s(inventory.money, money, 10); //1 돈
	_itoa_s(item.item_cruciancarp.howmany, cruciancarp, 10); //2 붕어
	_itoa_s(item.item_jang.howmany, jang, 10); //3 장어
	_itoa_s(item.item_lobster.howmany, lobster, 10); //4 
	_itoa_s(item.item_bing.howmany, bing, 10); //5 
	_itoa_s(item.item_frog.howmany, frog, 10); //6 
	_itoa_s(item.item_ing.howmany, ing, 10); //7 
	_itoa_s(item.item_octopus.howmany, octopus, 10); //8 
	_itoa_s(item.item_shark.howmany, shark, 10); //9 
	_itoa_s(item.item_trash.howmany, trash, 10); //10 
	_itoa_s(item.item_tuna.howmany, tuna, 10); //11
	_itoa_s(item.item_yeon.howmany, yeon, 10); //12 
	_itoa_s(item.item_bait.howmany, bait, 10); //13
	_itoa_s(item.item_ricecake.howmany, ricecake, 10); //14 
	_itoa_s(item.item_shirimp.howmany, shirimp, 10); //15 
	_itoa_s(item.item_fishingrod.howmany, fishingrod, 10); //16 
	_itoa_s(item.item_goodfishingrod.howmany, goodfishingrod, 10); //17 
	_itoa_s(quest.num_mission, num_quest, 10); //18
	_itoa_s(inventory.usingfishrodcode, wear_fishingrod, 10); //19
	_itoa_s(inventory.usingbaitcode, use_item, 10); // 

													 //변수명 #define으로 숫자로 셋팅해서 for문으로 돌리는게 깔끔하게 코딩됨
													 // 전달 할 쿼리값 셋팅

	sprintf_s(query, "update save set money=%s where saveslot=2", money);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set cruciancarp_num=%s where saveslot=2", cruciancarp);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set jang_num=%s where saveslot=2", jang);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set lobster_num=%s where saveslot=2", lobster);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set bing_num=%s where saveslot=2", bing);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set frog_num=%s where saveslot=2", frog);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set ing_num=%s where saveslot=2", ing);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set octopus_num=%s where saveslot=2", octopus);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set shark_num=%s where saveslot=2", shark);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set trash_num=%s where saveslot=2", trash);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set tuna_num=%s where saveslot=2", tuna);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set yeon_num=%s where saveslot=2", yeon);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set bait_num=%s where saveslot=2", bait);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set ricecake_num=%s where saveslot=2", ricecake);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set shrimp_num=%s where saveslot=2", shirimp);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set fishingrod=%s where saveslot=2", fishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set goodfishingrod=%s where saveslot=2", goodfishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set quest=%s where saveslot=2", num_quest);//수정
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set wearfishingrod=%s where saveslot=2", wear_fishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set usingitem=%s where saveslot=2", use_item);
	query_start = mysql_query(connection, query);


	query_start = mysql_query(connection, query);
	if (query_start != 0) // 전송 실패시
	{
		sprintf_s(state, "Mysql query error : %s", mysql_error(&conn));
		sql.mysql_Success = false;
	}
	else // 성공시
	{
		mysql_Success = true;
	}
}
void Mysql::save3()
{
	if (!sql.mysql_Success)return;
	/////////////////////////////////////////////

	_itoa_s(inventory.money, money, 10); //1 돈
	_itoa_s(item.item_cruciancarp.howmany, cruciancarp, 10); //2 붕어
	_itoa_s(item.item_jang.howmany, jang, 10); //3 장어
	_itoa_s(item.item_lobster.howmany, lobster, 10); //4 
	_itoa_s(item.item_bing.howmany, bing, 10); //5 
	_itoa_s(item.item_frog.howmany, frog, 10); //6 
	_itoa_s(item.item_ing.howmany, ing, 10); //7 
	_itoa_s(item.item_octopus.howmany, octopus, 10); //8 
	_itoa_s(item.item_shark.howmany, shark, 10); //9 
	_itoa_s(item.item_trash.howmany, trash, 10); //10 
	_itoa_s(item.item_tuna.howmany, tuna, 10); //11
	_itoa_s(item.item_yeon.howmany, yeon, 10); //12 
	_itoa_s(item.item_bait.howmany, bait, 10); //13
	_itoa_s(item.item_ricecake.howmany, ricecake, 10); //14 
	_itoa_s(item.item_shirimp.howmany, shirimp, 10); //15 
	_itoa_s(item.item_fishingrod.howmany, fishingrod, 10); //16 
	_itoa_s(item.item_goodfishingrod.howmany, goodfishingrod, 10); //17 
	_itoa_s(quest.num_mission, num_quest, 10); //18
	_itoa_s(inventory.usingfishrodcode, wear_fishingrod, 10); //19
	_itoa_s(inventory.usingbaitcode, use_item, 10); // 

													 //변수명 #define으로 숫자로 셋팅해서 for문으로 돌리는게 깔끔하게 코딩됨
													 // 전달 할 쿼리값 셋팅

	sprintf_s(query, "update save set money=%s where saveslot=3", money);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set cruciancarp_num=%s where saveslot=3", cruciancarp);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set jang_num=%s where saveslot=3", jang);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set lobster_num=%s where saveslot=3", lobster);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set bing_num=%s where saveslot=3", bing);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set frog_num=%s where saveslot=3", frog);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set ing_num=%s where saveslot=3", ing);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set octopus_num=%s where saveslot=3", octopus);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set shark_num=%s where saveslot=3", shark);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set trash_num=%s where saveslot=3", trash);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set tuna_num=%s where saveslot=3", tuna);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set yeon_num=%s where saveslot=3", yeon);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set bait_num=%s where saveslot=3", bait);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set ricecake_num=%s where saveslot=3", ricecake);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set shrimp_num=%s where saveslot=3", shirimp);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set fishingrod=%s where saveslot=3", fishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set goodfishingrod=%s where saveslot=3", goodfishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set quest=%s where saveslot=3", num_quest);//수정
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set wearfishingrod=%s where saveslot=3", wear_fishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set usingitem=%s where saveslot=3", use_item);
	query_start = mysql_query(connection, query);


	query_start = mysql_query(connection, query);
	if (query_start != 0) // 전송 실패시
	{
		sprintf_s(state, "Mysql query error : %s", mysql_error(&conn));
		sql.mysql_Success = false;
	}
	else // 성공시
	{
		mysql_Success = true;
	}
}

/*
Mysql 연동하기
* 64 비트인 경우 64 비트 설정 꼭 해주자.
* 포함 디렉터리에 C:\Program Files\MySQL\MySQL Server 5.7\include 를 추가
* 라이브러리 디렉터리에 C:\Program Files\MySQL\MySQL Server 5.7\lib 추가
* 링커 편집 libmysql.lib
* C:\Program Files\MySQL\MySQL Server 5.7\lib 안에 libmysql.dll 복사 후 파일을 프로젝트 폴더에 붙혀넣기

mysql 관련 함수를 사용하면서 에러가 발생?????.
즉 mysql.h를 참조만 했지, 그 함수들이 정의되어 있는 파일(라이브러리에 정의되어 있습니다.)을 찾을 수 없다는 오류이다.
우리 개발 환경은 윈도우7 64Bit 입니다.
윈도우 버전은 상관이 없고 64 비트가 문제입니다.
환경이 64비트이니 분명 mysql 설치할 때도 64비트를 선택하여 설치했습니다.
그러나? 우리가 사용하고 있는 비쥬얼 스튜디오, 이 개발 환경은 32비트입니다.
개발 환경을 64비트로 바꿔주면 오류는 사라집니다.

*/