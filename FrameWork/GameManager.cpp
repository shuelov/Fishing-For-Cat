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
	// ������ ���̽� ����
//	sql.mysql_Success = false;

	//// ������ ���̽� �׽�Ʈ ����
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
	
	if ((err = fopen_s(&fp,"./Save/save.fss","rb"))== NULL) //���� ���� rb:�������Ʈ (���������)
	{
		return ;
	}
	
	fread(&m_SysTem,sizeof(SysTem),1,fp);

	fclose(fp);

	//// ����Ÿ ���̽�//////////////////////////////////////////////////////////////////////////////////////////////////////

	// 1 �ܰ� �׽�Ʈ ���� Ȯ��////////////////////////////////////////////////////////////////////

	// MYSQL ����ü ���� ���� (��ü���� ����Ÿ ���̽��� ��Ʈ�� ���ش�)
	////MYSQL mysql;
	//// mysql ����ü ���� �ʱ�ȭ
	//mysql_init(&sql.mysql);
	//// mysql ����Ÿ ���̽��� ���� (���⼱ �׳� ���Ӹ� Ȯ��)
	//if(!mysql_real_connect(&sql.mysql, NULL/*host�ּ�(ip)*/, "root", "Glfhglfh00!", NULL/*DB�̸�*/, 3306, NULL, 0) )
	//	sql.mysql_Success = false;
	//else sql.mysql_Success = true;
	//// mysql  ���� ����
	//mysql_close(&sql.mysql);

	//////////////////////////////////////////////////////////////////////////////////////////////

	// 2 �ܰ� ���� Ȯ��


	// ����ü ����

	/*
	MYSQL *mysql_real_connect(

	MYSQL *mysql,				// MYSQL ������ ��巹��

	const char *host,			// ȣ��Ʈ �̸� �Ǵ� IP ��巹�� (default = localhost)

	const char *user,			// MySQL Login ID (default = ���� �α��� �̸�)

	const char *passwd,			// �н����� (default = none)

	const char *db,				// �����ͺ��̽� �̸� (default = none)

	unsigned int port,			// TCP/IP ���� ��Ʈ (use default)

	const char *unix_socket,    // ���� (use default)

	unsigned long client_flag)  // flag (none)

	*/

	// mysql ����ü ���� �ʱ�ȭ
//	mysql_init(&sql.conn);
//
//	// ip, ���� id , pass, ����Ÿ ���̽���, ��Ʈ��ȣ ������ ����
////	sql.connection = mysql_real_connect(&sql.conn, DB_HOST,
//		DB_USER, DB_PASS,
//		DB_NAME, 3306,
//		(char *)NULL, 0);
//
//	// ���� ���ӿ� �����ϸ� ���� ����
//	if (sql.connection == NULL)
//	{
//		sprintf_s(sql.state, "Mysql connection error : %s", mysql_error(&sql.conn));
//		sql.mysql_Success = false;
//	}
//	else // �ƴϸ�...
//	{
//		sql.mysql_Success = true;
//	}
//
//	// ���� mysql_query() �Լ��� MYSQL ����ü�� ���� ������ ����
//	sql.query_start = mysql_query(sql.connection, "select * from save");
//	if (sql.query_start != 0) // ���� ���н�
//	{
//		sprintf_s(sql.state, "Mysql query error : %s", mysql_error(&sql.conn));
//	}
//	else // ������
//	{
//		sql.mysql_Success = true;
//	}
//
//	// mysql_store_result �Լ��� �Ѿ�� ����Ÿ ���̽� �� ����
//	sql.sql_result = mysql_store_result(sql.connection);
//
//	// ID, ��й�ȣ �������� 
//	// select * from login where ?? ��� ��������... �� ���ڵ� �� ��ŭ �Ѿ��(�� ��ŭ ������ ����)
//	while ((sql.sql_row = mysql_fetch_row(sql.sql_result)) != NULL)
//	{
//		// ���� ����� ������ ���ڵ� ���� ����������... where id = ? ? ������ Ư�� ����� ���� ����������...
//		// ��ü ����Ÿ�� �ʿ��� ���� �迭�� ������ ó������....
//		// sql.sql_row[0] �ε����� �ش� Į��(��,�ʵ�)�� ������
//		sprintf_s(sql.result, "%s %s\n", sql.sql_row[1], sql.sql_row[2], sql.sql_row[3], sql.sql_row[4], sql.sql_row[5],
//			sql.sql_row[6], sql.sql_row[7], sql.sql_row[8], sql.sql_row[9], sql.sql_row[10],
//			sql.sql_row[11], sql.sql_row[12], sql.sql_row[13], sql.sql_row[14], sql.sql_row[15],
//			sql.sql_row[16], sql.sql_row[17], sql.sql_row[18], sql.sql_row[19], sql.sql_row[20]);
//
//		// �̷������� ���ڿ��� ������ ��ȯ
//		int a = atoi(sql.sql_row[1]);
//		// �������� ���ڿ��� ��ȯ �Լ� ����� #define _CRT_NONSTDC_NO_DEPRECATE ���ϸ� ���� �߻�
//		//itoa(a, pw, 10);	// 10 ������ ������
//
//		// ���ڵ� ����ŭ ����... 
//		//count += 1;
//	}
//
//	// �������� ���ڿ��� ��ȯ �Լ� ����� #define _CRT_NONSTDC_NO_DEPRECATE ���ϸ� ���� �߻�
//	//itoa(count, cnt, 10);	// 10 ������ ������
//
//	// sql.sql_result �� ����
//	mysql_free_result(sql.sql_result);
//	///////////////////////////////////////////////////////////////////////////////////////////////
	
}

void GameManager::Update()
{
	//if(���� �����) g_Mng.n_Chap = OVER; 
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
 



void GameManager::GameReset(void)  // ����� ���ӻ� ÷�� �ѹ���  �ʱ�ȭ�Ǵ� �κи� �־���.
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
	//// ����Ÿ ���̽� ��� �� ó�� ���� ǥ��/////////////////////////////////////

	//if (sql.mysql_Success)
	//{
	//	dv_font.DrawString("Success", 500, 0);   
	//}
	//else
	//{
	//	dv_font.DrawString("Error", 500, 0);   
	//	dv_font.DrawString(sql.state, 700, 0);
	//}


	//// ����Ÿ ���̽� ��� �� ó�� ���� ǥ��/////////////////////////////////////
	//if (sql.mysql_Success)
	//{
	//	dv_font.DrawString("Success", 500, 0);
	//}
	//else
	//{
	//	dv_font.DrawString("Error", 500, 0);
	//	dv_font.DrawString(sql.state, 700, 0);
	//}

	//// ���
	//dv_font.DrawString(sql.result, 500, 30);

	//// �� ���ڵ� ��
	//dv_font.DrawString(cnt, 500, 60);

	//// ���
	//dv_font.DrawString(pw, 500, 100);
	//////////////////////////////////////////////////////////////
	
}
