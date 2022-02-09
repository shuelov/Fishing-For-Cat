
#pragma once
#include "Include.h"

Item item;

Item::Item(void)
{

	//코드, x좌표,y좌표, 팔때가격, 살때가격, 갖고있는 갯수,나오는스테이지 ,x좌표 배율,y좌표배율 ,이름

	item_cruciancarp = { 1,0,0,4500,50,0,1,1,1,"붕어" };
	item_jang = { 2,0,0,10800,120,0,1,1,1,"장어" };
	item_lobster = { 3,0,0,9000,100,0,1,1,1,"가재" };
	item_bing = { 4,0,0,9900,110,0,2,1,1,"빙어" };
	item_frog = { 5,0,0,5400,60,0,2,1,1,"개구리" };
	item_ing = { 6,0,0,13500,150,0,2,1,1,"잉어" };
	item_octopus = { 7,0,0,16200,180,0,3,1,1,"문어" };
	item_shark = { 8,0,0,18000,200,0,3,1,1,"상어" };
	item_trash = { 9, 0, 0, 500, 10, 0, 4,1,1,"쓰레기" };
	item_tuna = { 10,0,0,19800,220,0,3,1,1,"참치" };
	item_yeon = { 11,0,0,17100,190,0,3,1,1,"연어" };
	item_bait = { 12,0,0,36000,400,0,0,1,1,"지렁이" };
	item_ricecake = { 13,0,0,54000,600,0,0,1,1,"떡밥" };
	item_shirimp = { 14,0,0,72000,800,0,0,1,1,"새우" };
	item_fishingrod = { 15,0,0,144000,1600,0,0,1,1,"낚싯대" };
	item_goodfishingrod = { 16,0,0,180000,2000,0,0,1,1,"좋은 낚싯대" };

}

Item::~Item(void)
{
}

void Item::Init()
{
	bing.Create("./resource/Img/Fish/bing.png", false, D3DCOLOR_XRGB(0, 0, 0));
	frog.Create("./resource/Img/Fish/frog.png", false, D3DCOLOR_XRGB(0, 0, 0));
	cruciancarp.Create("./resource/Img/Fish/cruciancarp.png", false, D3DCOLOR_XRGB(0, 0, 0));
	ing.Create("./resource/Img/Fish/ing.png", false, D3DCOLOR_XRGB(0, 0, 0));
	jang.Create("./resource/Img/Fish/jang.png", false, D3DCOLOR_XRGB(0, 0, 0));
	lobster.Create("./resource/Img/Fish/lobster.png", false, D3DCOLOR_XRGB(0, 0, 0));
	octopus.Create("./resource/Img/Fish/octopus.png", false, D3DCOLOR_XRGB(0, 0, 0));
	sora.Create("./resource/Img/Fish/sora.png", false, D3DCOLOR_XRGB(0, 0, 0));
	trash.Create("./resource/Img/Fish/trash.png", false, D3DCOLOR_XRGB(0, 0, 0));
	tuna.Create("./resource/Img/Fish/tuna.png", false, D3DCOLOR_XRGB(0, 0, 0));
	turtle.Create("./resource/Img/Fish/turtle.png", false, D3DCOLOR_XRGB(0, 0, 0));
	yeon.Create("./resource/Img/Fish/yeon.png", false, D3DCOLOR_XRGB(0, 0, 0));
	shark.Create("./resource/Img/Fish/shark.png", false, D3DCOLOR_XRGB(0, 0, 0));

	bait.Create("./resource/Img/Item/bait.png", false, D3DCOLOR_XRGB(0, 0, 0));
	fishingrod.Create("./resource/Img/Item/fishingrod.png", false, D3DCOLOR_XRGB(0, 0, 0));
	goodfishingrod.Create("./resource/Img/Item/goodfishingrod.png", false, D3DCOLOR_XRGB(0, 0, 0));
	ricecake.Create("./resource/Img/Item/ricecake.png", false, D3DCOLOR_XRGB(0, 0, 0));
	shirimp.Create("./resource/Img/Item/shrimp.png", false, D3DCOLOR_XRGB(0, 0, 0));

}

void Item::Update()
{

}

void Item::Draw()
{

}

void Item::DrawItem(int _itemcode, float _x, float _y, int _u_x, int _u_y) //아이템코드,x,y,ux,uy좌표만 가져오면 드로우해줌
{
	if (_itemcode == 1)
		cruciancarp.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 2)
		jang.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 3)
		lobster.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 4)
		bing.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 5)
		frog.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 6)
		ing.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 7)
		octopus.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 8)
		shark.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 9)
		trash.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 10)
		tuna.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 11)
		yeon.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 12)
		bait.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 13)
		ricecake.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 14)
		shirimp.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 15)
		fishingrod.Render(_x, _y, 0, _u_x, _u_y);
	else if (_itemcode == 16)
		goodfishingrod.Render(_x, _y, 0, _u_x, _u_y);
}
void Item::GetItem(int _itemcode, int _howmany) // 아이템을 얻을때 
{

		if (_itemcode == 1)
			item_cruciancarp.howmany += _howmany;
		else if (_itemcode == 2)
			item_jang.howmany += _howmany;
		else if (_itemcode == 3)
			item_lobster.howmany += _howmany;
		else if (_itemcode == 4)
			item_bing.howmany += _howmany;
		else if (_itemcode == 5)
			item_frog.howmany += _howmany;
		else if (_itemcode == 6)
			item_ing.howmany +=  _howmany;
		else if (_itemcode == 7)
			item_octopus.howmany += _howmany;
		else if (_itemcode == 8)
			item_shark.howmany += _howmany;
		else if (_itemcode == 9)
			item_trash.howmany += _howmany;
		else if (_itemcode == 10)
			item_tuna.howmany += _howmany;
		else if (_itemcode == 11)
			item_yeon.howmany += _howmany;
		else if (_itemcode == 12)
			item_bait.howmany += _howmany; 
		else if (_itemcode == 13)
			item_ricecake.howmany += _howmany;
		else if (_itemcode == 14)
			item_shirimp.howmany += _howmany;
		else if (_itemcode == 15)
			item_fishingrod.howmany += _howmany;
		else if (_itemcode == 16)
			item_goodfishingrod.howmany += _howmany;
	
}

void Item::OutItem(int _itemcode, int _howmany) // 아이템을 잃을때
{

		if (_itemcode == 1)
			item_cruciancarp.howmany -= _howmany;
		else if (_itemcode == 2)
			item_jang.howmany -= _howmany;
		else if (_itemcode == 3)
			item_lobster.howmany -= _howmany;
		else if (_itemcode == 4)
			item_bing.howmany -= _howmany;
		else if (_itemcode == 5)
			item_frog.howmany -= _howmany;
		else if (_itemcode == 6)
			item_ing.howmany -= _howmany;
		else if (_itemcode == 7)
			item_octopus.howmany -= _howmany;
		else if (_itemcode == 8)
			item_shark.howmany -= _howmany;
		else if (_itemcode == 9)
			item_trash.howmany -= _howmany;
		else if (_itemcode == 10)
			item_tuna.howmany -= _howmany;
		else if (_itemcode == 11)
			item_yeon.howmany -= _howmany;
		else if (_itemcode == 12)
			item_bait.howmany -= _howmany;
		else if (_itemcode == 13)
			item_ricecake.howmany -= _howmany;
		else if (_itemcode == 14)
			item_shirimp.howmany -= _howmany;
		else if (_itemcode == 15)
			item_fishingrod.howmany -= _howmany;
		else if (_itemcode == 16)
			item_goodfishingrod.howmany -= _howmany;


}
void Item::Showname(int _itemcode, int _x, int _y)
{
	if (_itemcode == 1)
		dv_font.DrawString(item_cruciancarp.name, _x, _y);
	else if (_itemcode == 2)
         dv_font.DrawString(item_jang.name, _x, _y);
	else if (_itemcode == 3)
		dv_font.DrawString(item_lobster.name, _x, _y);
	else if (_itemcode == 4)
		dv_font.DrawString(item_bing.name, _x, _y);
	else if (_itemcode == 5)
		dv_font.DrawString(item_frog.name, _x, _y);
	else if (_itemcode == 6)
		dv_font.DrawString(item_ing.name, _x, _y);
	else if (_itemcode == 7)
		dv_font.DrawString(item_octopus.name, _x, _y);
	else if (_itemcode == 8)
		dv_font.DrawString(item_shark.name, _x, _y);
	else if (_itemcode == 9)
		dv_font.DrawString(item_trash.name, _x, _y);
	else if (_itemcode == 10)
		dv_font.DrawString(item_tuna.name, _x, _y);
	else if (_itemcode == 11)
		dv_font.DrawString(item_yeon.name, _x, _y);
	else if (_itemcode == 12)
	{
		dv_font.DrawString(item_bait.name, _x, _y);
		if (inventory.usingbaitcode==12)
			dv_font.DrawString("(사용중)", _x + 100, _y);

	}
	else if (_itemcode == 13)
	{
		dv_font.DrawString(item_ricecake.name, _x, _y);
		if (inventory.usingbaitcode == 13)
			dv_font.DrawString("(사용중)", _x + 100, _y);
	}
	else if (_itemcode == 14) //수정
	{
		dv_font.DrawString(item_shirimp.name, _x, _y);
		if (inventory.usingbaitcode == 14)
			dv_font.DrawString("(사용중)", _x + 100, _y);
	}
	else if (_itemcode == 15)
	{
		dv_font.DrawString(item_fishingrod.name, _x, _y);
		if (inventory.usingfishrodcode == 15)
			dv_font.DrawString("(사용중)", _x + 100, _y);
	}
	else if (_itemcode == 16)
	{
		dv_font.DrawString(item_goodfishingrod.name, _x, _y);
		if (inventory.usingfishrodcode == 16)
			dv_font.DrawString("(사용중)", _x + 100, _y);
	}


}

void Item::Showhowmany(int _itemcode, int _x, int _y)
{
	SetRect(&q_rc, _x, _y, 110, 110); 
	ZeroMemory(str, 100);
	if (_itemcode == 1)
		sprintf_s(str, "%d 개", item_cruciancarp.howmany); 
	else if (_itemcode == 2)
		sprintf_s(str, "%d 개", item_jang.howmany);
	else if (_itemcode == 3)
		sprintf_s(str, "%d 개", item_lobster.howmany);
	else if (_itemcode == 4)
		sprintf_s(str, "%d 개", item_bing.howmany);
	else if (_itemcode == 5)
		sprintf_s(str, "%d 개", item_frog.howmany);
	else if (_itemcode == 6)
		sprintf_s(str, "%d 개", item_ing.howmany);
	else if (_itemcode == 7)
		sprintf_s(str, "%d 개", item_octopus.howmany);
	else if (_itemcode == 8)
		sprintf_s(str, "%d 개", item_shark.howmany);
	else if (_itemcode == 9)
		sprintf_s(str, "%d 개", item_trash.howmany);
	else if (_itemcode == 10)
		sprintf_s(str, "%d 개", item_tuna.howmany);
	else if (_itemcode == 11)
		sprintf_s(str, "%d 개", item_yeon.howmany);
	else if (_itemcode == 12)
		sprintf_s(str, "%d 개", item_bait.howmany);
	else if (_itemcode == 13)
		sprintf_s(str, "%d 개", item_ricecake.howmany);
	else if (_itemcode == 14)
		sprintf_s(str, "%d 개", item_shirimp.howmany);
	else if (_itemcode == 15)
		sprintf_s(str, "%d 개", item_fishingrod.howmany);
	else if (_itemcode == 16)
		sprintf_s(str, "%d 개", item_goodfishingrod.howmany);

	dv_font.Fonts->DrawText(NULL, str, 100, &q_rc, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));
}
void Item::SellItem(int _itemcode, int _howmany)
{

	if (_itemcode == 1)
		inventory.money += item_cruciancarp.sell_price;
	else if (_itemcode == 2)
		inventory.money += item_jang.sell_price;
	else if (_itemcode == 3)
		inventory.money += item_lobster.sell_price;
	else if (_itemcode == 4)
		inventory.money += item_bing.sell_price;
	else if (_itemcode == 5)
		inventory.money += item_frog.sell_price;
	else if (_itemcode == 6)
		inventory.money += item_ing.sell_price;
	else if (_itemcode == 7)
		inventory.money += item_octopus.sell_price;
	else if (_itemcode == 8)
		inventory.money += item_shark.sell_price;
	else if (_itemcode == 9)
		inventory.money += item_trash.sell_price;
	else if (_itemcode == 10)
		inventory.money += item_tuna.sell_price;
	else if (_itemcode == 11)
		inventory.money += item_yeon.sell_price;
	else if (_itemcode == 12)
		inventory.money += item_bait.sell_price;
	else if (_itemcode == 13)
		inventory.money += item_ricecake.sell_price;
	else if (_itemcode == 14)
		inventory.money += item_shirimp.sell_price;
	else if (_itemcode == 15)
		inventory.money += item_fishingrod.sell_price;
	else if (_itemcode == 16)
		inventory.money += item_goodfishingrod.sell_price;


}
void Item::ShowSellPrice(int _itemcode, int _x, int _y) // 내가 팔때의 가격을 보여주기
{
	SetRect(&q_rc, _x, _y, 110, 110);
	ZeroMemory(str, 100);
	if (_itemcode == 1)
		sprintf_s(str, "%d Gold", item_cruciancarp.sell_price);
	else if (_itemcode == 2)
		sprintf_s(str, "%d Gold", item_jang.sell_price);
	else if (_itemcode == 3)
		sprintf_s(str, "%d Gold", item_lobster.sell_price);
	else if (_itemcode == 4)
		sprintf_s(str, "%d Gold", item_bing.sell_price);
	else if (_itemcode == 5)
		sprintf_s(str, "%d Gold", item_frog.sell_price);
	else if (_itemcode == 6)
		sprintf_s(str, "%d Gold", item_ing.sell_price);
	else if (_itemcode == 7)
		sprintf_s(str, "%d Gold", item_octopus.sell_price);
	else if (_itemcode == 8)
		sprintf_s(str, "%d Gold", item_shark.sell_price);
	else if (_itemcode == 9)
		sprintf_s(str, "%d Gold", item_trash.sell_price);
	else if (_itemcode == 10)
		sprintf_s(str, "%d Gold", item_tuna.sell_price);
	else if (_itemcode == 11)
		sprintf_s(str, "%d Gold", item_yeon.sell_price);
	else if (_itemcode == 12)
		sprintf_s(str, "%d Gold", item_bait.sell_price);
	else if (_itemcode == 13)
		sprintf_s(str, "%d Gold", item_ricecake.sell_price);
	else if (_itemcode == 14)
		sprintf_s(str, "%d Gold", item_shirimp.sell_price);
	else if (_itemcode == 15)
		sprintf_s(str, "%d Gold", item_fishingrod.sell_price);
	else if (_itemcode == 16)
		sprintf_s(str, "%d Gold", item_goodfishingrod.sell_price);

	dv_font.Fonts->DrawText(NULL, str, 100, &q_rc, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));
}
void Item::ShowBuyPrice(int _itemcode, int _x, int _y) // 내가 살때의 가격을 보여주기(상점에)
{
	SetRect(&q_rc, _x, _y, 110, 110);
	ZeroMemory(str, 100);
	if (_itemcode == 1)
		sprintf_s(str, "%d Gold", item_cruciancarp.buy_price);
	else if (_itemcode == 2)
		sprintf_s(str, "%d Gold", item_jang.buy_price);
	else if (_itemcode == 3)
		sprintf_s(str, "%d Gold", item_lobster.buy_price);
	else if (_itemcode == 4)
		sprintf_s(str, "%d Gold", item_bing.buy_price);
	else if (_itemcode == 5)
		sprintf_s(str, "%d Gold", item_frog.buy_price);
	else if (_itemcode == 6)
		sprintf_s(str, "%d Gold", item_ing.buy_price);
	else if (_itemcode == 7)
		sprintf_s(str, "%d Gold", item_octopus.buy_price);
	else if (_itemcode == 8)
		sprintf_s(str, "%d Gold", item_shark.buy_price);
	else if (_itemcode == 9)
		sprintf_s(str, "%d Gold", item_trash.buy_price);
	else if (_itemcode == 10)
		sprintf_s(str, "%d Gold", item_tuna.buy_price);
	else if (_itemcode == 11)
		sprintf_s(str, "%d Gold", item_yeon.buy_price);
	else if (_itemcode == 12)
		sprintf_s(str, "%d Gold", item_bait.buy_price);
	else if (_itemcode == 13)
		sprintf_s(str, "%d Gold", item_ricecake.buy_price);
	else if (_itemcode == 14)
		sprintf_s(str, "%d Gold", item_shirimp.buy_price);
	else if (_itemcode == 15)
		sprintf_s(str, "%d Gold", item_fishingrod.buy_price);
	else if (_itemcode == 16)
		sprintf_s(str, "%d Gold", item_goodfishingrod.buy_price);

	dv_font.Fonts->DrawText(NULL, str, 100, &q_rc, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));
}