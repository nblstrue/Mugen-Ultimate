/*
 *** Fighting Game Project - Started the 18th of September
 *
 *** Mugen Ultimate v0.1
 *
 *** By sally_stan (discord)
 */

#include <iostream>
#include <fstream>
#include <raylib.h>

/*************************************************************************************/

#define widthscreen 1000
#define heightscreen 700
#define small_fontsize 20
#define big_fontsize 35
#define middle_x 450
#define middle_y 450

bool Exiting();
void TakeScreenShot();
void ScreenManage();
void Ending();
void FPS();
void name_recup();

char player_name[51];

/*************************************************************************************/

int main()
{
	name_recup();
	InitWindow(widthscreen, heightscreen, "Mugen Ultimate v0.1");
	HideCursor();

	while (!Exiting())
	{
		ScreenManage();
		ClearBackground(BLACK);
		BeginDrawing();
		FPS();
		DrawText("Test Text", middle_x, middle_y, small_fontsize, RED);
		EndDrawing();
	}

	Ending();
	CloseWindow();

	return 0;
}

/*************************************************************************************/

void name_recup()
{
	std::cout << "Veuillez ecrire votre nom de joueur (50 caracteres maximum)\n=> ";
	std::fgets(player_name, sizeof(player_name), stdin);
	std::cout << TextFormat("%s, are you sure this is the name you want ? (y/n) ", player_name);
	char res; std::cin >> res;

	if (res == 'n')
	{
		while (res == 'n')
		{
			std::cout << "/n/nVeuillez ecrire votre nom de joueur (50 caracteres maximum)\n=> ";
			std::fgets(player_name, sizeof(player_name), stdin);
			std::cout << TextFormat("%s, are you sure this is the name you want ? (y/n) ", player_name);
			std::cin >> res;
		}
	}
}

bool Exiting()
{
	if (IsKeyPressed(KEY_ESCAPE))
		return true;
	else
		return false;
}

void Ending()
{
	int a = 0;
	while (a < 1500)
	{
		a++;
		ClearBackground(BLACK);
		BeginDrawing();
		DrawFPS(10, 10);
		DrawText("Thanks for testing my game ! :)", middle_x, middle_y, small_fontsize, YELLOW);
		DrawText("Closing game...", middle_x + 40, middle_y + 40, small_fontsize, RED);
		EndDrawing();
	}
}

void TakeScreenShot()
{
	static int PhotosNumbers = 0;
	if ((IsKeyPressed(KEY_LEFT_CONTROL) || IsKeyPressed(KEY_RIGHT_CONTROL) && IsKeyPressed(KEY_S)))
	{
		TakeScreenshot(TextFormat("Screenshot_%d.png", PhotosNumbers));
		PhotosNumbers++;
	}
}

void ScreenManage()
{

}

void FPS()
{
	int f = GetFPS();

	if (f < 30)
		DrawText(TextFormat("%d FPS", f), 10, 0, 10, RED);

	if (f < 30 && f > 50)
		DrawText(TextFormat("%d FPS", f), 10, 0, 10, YELLOW);

	if (f >= 50)
		DrawText(TextFormat("%d FPS", f), 10, 0, 10, GREEN);
}
