#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>

namespace ConsoleUtilities
{

	enum Color
	{
		Black,
		Blue,
		Green,
		Cyan,
		Red,
		Purple,
		Brown,
		LightGray,
		DarkGray,
		LightBlue,
		LightGreen,
		LightCyan,
		LightRed,
		LightPurple,
		Yellow,
		White

	};

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	void SetColour(int colour)
	{
		SetConsoleTextAttribute(hOut, colour);
	}

	void ClearScreen()
	{
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(hOut, &info);
		DWORD d = info.srWindow.Bottom * info.srWindow.Right;
		COORD coord = { 0,0 };
		FillConsoleOutputCharacter(hOut, ' ', d, coord, &d);
	}

	void SetCursor(short x, short y)
	{
		COORD coord = { x , y };
		SetConsoleCursorPosition(hOut, coord);
	}
	
	//Write a function that outputs text with a color
	void LogText(std::string text, int colour)
	{
		SetColour(colour);
		std::cout << text;
		SetColour(White);
	}

};