#include "Include.h"

GameManager Gmanager;
static DWORD ALPHATime = GetTickCount();

errno_t err;
FILE *fp;

GameManager::GameManager(void)
{
	GameTime = GetTickCount();
	m_GameSpeed = 1;
	m_Pause = false;

	//m_SysTem.m_Save1 = 100;
	//m_SysTem.m_Save2 = 200;
	//Save();

	
	m_GameStart = true;

	//m_GameStart = false;
	// 데이터 베이스 관련
//	sql.mysql_Success = false;

	//// 데이터 베이스 테스트 관련
	//count = 0;

}

GameManager::~GameManager(void)
{
}

void GameManager::Init()
{
	//Menuimg[0].Create("./resource/Effect/menu/1.png",false,D3DCOLOR_XRGB(0,0,0));
	//Menuimg[1].Create("./resource/Effect/menu/2.png",false,D3DCOLOR_XRGB(0,0,0));


	char seps[] = ",\n";
	char *token;

	

	if ((err = fopen_s(&fp,"C:\\SYSTEM.txt","r"))== NULL)
	{
		return ;
	}
	
	if ((err = fopen_s(&fp,"./Save/save.fss","rb"))== NULL) //파일 열기 rb:리드바이트 (기계어로읽음)
	{
		return ;
	}
	
	fread(&m_SysTem,sizeof(SysTem),1,fp);

	fclose(fp);

	//// 데이타 베이스//////////////////////////////////////////////////////////////////////////////////////////////////////

	// 1 단계 테스트 접속 확인////////////////////////////////////////////////////////////////////

	// MYSQL 구조체 변수 선언 (전체적인 데이타 베이스를 컨트럴 해준다)
	////MYSQL mysql;
	//// mysql 구조체 변수 초기화
	//mysql_init(&sql.mysql);
	//// mysql 데이타 베이스에 접속 (여기선 그냥 접속만 확인)
	//if(!mysql_real_connect(&sql.mysql, NULL/*host주소(ip)*/, "root", "Glfhglfh00!", NULL/*DB이름*/, 3306, NULL, 0) )
	//	sql.mysql_Success = false;
	//else sql.mysql_Success = true;
	//// mysql  접속 종료
	//mysql_close(&sql.mysql);

	//////////////////////////////////////////////////////////////////////////////////////////////

	// 2 단계 접속 확인


	// 구조체 설명

	/*
	MYSQL *mysql_real_connect(

	MYSQL *mysql,				// MYSQL 구조의 어드레스

	const char *host,			// 호스트 이름 또는 IP 어드레스 (default = localhost)

	const char *user,			// MySQL Login ID (default = 현재 로그인 이름)

	const char *passwd,			// 패스워드 (default = none)

	const char *db,				// 데이터베이스 이름 (default = none)

	unsigned int port,			// TCP/IP 연결 포트 (use default)

	const char *unix_socket,    // 소켓 (use default)

	unsigned long client_flag)  // flag (none)

	*/

	// mysql 구조체 변수 초기화
//	mysql_init(&sql.conn);
//
//	// ip, 접속 id , pass, 데이타 베이스명, 포트번호 등으로 접속
////	sql.connection = mysql_real_connect(&sql.conn, DB_HOST,
//		DB_USER, DB_PASS,
//		DB_NAME, 3306,
//		(char *)NULL, 0);
//
//	// 만약 접속에 실패하면 다음 실행
//	if (sql.connection == NULL)
//	{
//		sprintf_s(sql.state, "Mysql connection error : %s", mysql_error(&sql.conn));
//		sql.mysql_Success = false;
//	}
//	else // 아니면...
//	{
//		sql.mysql_Success = true;
//	}
//
//	// 다음 mysql_query() 함수로 MYSQL 구조체를 통한 쿼리문 전송
//	sql.query_start = mysql_query(sql.connection, "select * from save");
//	if (sql.query_start != 0) // 전송 실패시
//	{
//		sprintf_s(sql.state, "Mysql query error : %s", mysql_error(&sql.conn));
//	}
//	else // 성공시
//	{
//		sql.mysql_Success = true;
//	}
//
//	// mysql_store_result 함수로 넘어온 데이타 베이스 값 저장
//	sql.sql_result = mysql_store_result(sql.connection);
//
//	// ID, 비밀번호 가져오기 
//	// select * from login where ?? 사용 안했으니... 총 레코드 수 만큼 넘어옴(그 만큼 루프를 돈다)
//	while ((sql.sql_row = mysql_fetch_row(sql.sql_result)) != NULL)
//	{
//		// 지금 현재는 마지막 레코드 값만 가져오지만... where id = ? ? 등으로 특정 대상의 값을 가져오던지...
//		// 전체 데이타가 필요할 경우는 배열로 적절히 처리하자....
//		// sql.sql_row[0] 인덱스로 해당 칼럼(열,필드)값 가져옴
//		sprintf_s(sql.result, "%s %s\n", sql.sql_row[1], sql.sql_row[2], sql.sql_row[3], sql.sql_row[4], sql.sql_row[5],
//			sql.sql_row[6], sql.sql_row[7], sql.sql_row[8], sql.sql_row[9], sql.sql_row[10],
//			sql.sql_row[11], sql.sql_row[12], sql.sql_row[13], sql.sql_row[14], sql.sql_row[15],
//			sql.sql_row[16], sql.sql_row[17], sql.sql_row[18], sql.sql_row[19], sql.sql_row[20]);
//
//		// 이런식으로 문자열을 정수로 변환
//		int a = atoi(sql.sql_row[1]);
//		// 정수형을 문자열로 변환 함수 참고로 #define _CRT_NONSTDC_NO_DEPRECATE 안하면 에러 발생
//		//itoa(a, pw, 10);	// 10 진수로 가져옴
//
//		// 레코드 수만큼 증가... 
//		//count += 1;
//	}
//
//	// 정수형을 문자열로 변환 함수 참고로 #define _CRT_NONSTDC_NO_DEPRECATE 안하면 에러 발생
//	//itoa(count, cnt, 10);	// 10 진수로 가져옴
//
//	// sql.sql_result 값 해제
//	mysql_free_result(sql.sql_result);
//	///////////////////////////////////////////////////////////////////////////////////////////////
	
}

void GameManager::Update()
{
	//if(게임 종료시) g_Mng.n_Chap = OVER; 
}
void GameManager::Save()
{
	if ((err = fopen_s(&fp,"./Save/save.fss", "wb")) == NULL)
	{
		return;
	}
	fwrite(&m_SysTem, sizeof(SysTem), 1, fp);
	fclose(fp);

}

void GameManager::Delete()
{
//	sound.g_pSoundManager->drr  

}
 



void GameManager::GameReset(void)  // 여기는 게임상 첨에 한번만  초기화되는 부분만 넣어줌.
{

}


void GameManager::Draw()
{

	//if(m_Alpha == 0) { Menuimg[0].SetColor(255,255, 255, 255);  Menuimg[1].SetColor(255,255, 255, 255);}
	//if(m_Alpha == 1) { Menuimg[0].SetColor(255,255,255,0); Menuimg[1].SetColor(255,255,255,0); }
	

	//map.numimg[5].Draw(50, 53);
	//map.numimg[0].Draw(65, 53);
	//map.numimg[0].Draw(80, 53);
	//map.numimg[0].Draw(95, 53);
	//// 데이타 베이스 결과 및 처리 상태 표시/////////////////////////////////////

	//if (sql.mysql_Success)
	//{
	//	dv_font.DrawString("Success", 500, 0);   
	//}
	//else
	//{
	//	dv_font.DrawString("Error", 500, 0);   
	//	dv_font.DrawString(sql.state, 700, 0);
	//}


	//// 데이타 베이스 결과 및 처리 상태 표시/////////////////////////////////////
	//if (sql.mysql_Success)
	//{
	//	dv_font.DrawString("Success", 500, 0);
	//}
	//else
	//{
	//	dv_font.DrawString("Error", 500, 0);
	//	dv_font.DrawString(sql.state, 700, 0);
	//}

	//// 결과
	//dv_font.DrawString(sql.result, 500, 30);

	//// 총 레코드 수
	//dv_font.DrawString(cnt, 500, 60);

	//// 비번
	//dv_font.DrawString(pw, 500, 100);
	//////////////////////////////////////////////////////////////
	
}
