/* Copyright (C) 2005-2008 Valeriy Argunov (nporep AT mail DOT ru) */
/*
* This library is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2.1 of the License, or
* (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include "declarations.h"

QSP_CALLBACK qspCallBacks[QSP_CALL_DUMMY];

void qspInitCallBacks()
{
	long i;
	for (i = 0; i < QSP_CALL_DUMMY; ++i)
		qspCallBacks[i] = 0;
}

void qspSetCallBack(long type, QSP_CALLBACK func)
{
	qspCallBacks[type] = func;
}

void qspCallSetTimer(long msecs)
{
	/* ����� ������������� �������� ������� */
	if (qspCallBacks[QSP_CALL_SETTIMER]) qspCallBacks[QSP_CALL_SETTIMER](msecs);
}

void qspCallRefreshInt(QSP_BOOL isRedraw)
{
	/* ����� ��������� ���������� ���������� */
	if (qspCallBacks[QSP_CALL_REFRESHINT]) qspCallBacks[QSP_CALL_REFRESHINT](isRedraw);
}

void qspCallSetInputStrText(QSP_CHAR *text)
{
	/* ����� ������������� ����� ������ ����� */
	if (qspCallBacks[QSP_CALL_SETINPUTSTRTEXT]) qspCallBacks[QSP_CALL_SETINPUTSTRTEXT](text);
}

void qspCallAddMenuItem(QSP_CHAR *name, QSP_CHAR *imgPath)
{
	/* ����� ��������� ����� ���� */
	if (qspCallBacks[QSP_CALL_ADDMENUITEM]) qspCallBacks[QSP_CALL_ADDMENUITEM](name, imgPath);
}

void qspCallSystem(QSP_CHAR *cmd)
{
	/* ����� ��������� ��������� ����� */
	if (qspCallBacks[QSP_CALL_SYSTEM]) qspCallBacks[QSP_CALL_SYSTEM](cmd);
}

void qspCallOpenGame()
{
	/* ����� ��������� ������������ ������� ���� */
	/* ��������� ���� ��� �������� � ��������� ��� */
	if (qspCallBacks[QSP_CALL_OPENGAMESTATUS]) qspCallBacks[QSP_CALL_OPENGAMESTATUS]();
}

void qspCallSaveGame()
{
	/* ����� ��������� ������������ ������� ���� */
	/* ��� ���������� ��������� ���� � ��������� */
	/* � ��� ������� ��������� */
	if (qspCallBacks[QSP_CALL_SAVEGAMESTATUS]) qspCallBacks[QSP_CALL_SAVEGAMESTATUS]();
}

void qspCallShowMessage(QSP_CHAR *text)
{
	/* ����� ���������� ��������� */
	if (qspCallBacks[QSP_CALL_SHOWMSGSTR]) qspCallBacks[QSP_CALL_SHOWMSGSTR](text);
}

void qspCallShowMenu()
{
	/* ����� ���������� ���� */
	if (qspCallBacks[QSP_CALL_SHOWMENU]) qspCallBacks[QSP_CALL_SHOWMENU]();
}

void qspCallShowPicture(QSP_CHAR *file)
{
	/* ����� ���������� ����������� */
	if (qspCallBacks[QSP_CALL_SHOWIMAGE]) qspCallBacks[QSP_CALL_SHOWIMAGE](file);
}

void qspCallShowWindow(long type, QSP_BOOL isShow)
{
	/* ����� ���������� ��� �������� ���� */
	if (qspCallBacks[QSP_CALL_SHOWWINDOW]) qspCallBacks[QSP_CALL_SHOWWINDOW](type, isShow);
}

void qspCallPlayFile(QSP_CHAR *file, long volume)
{
	/* ����� �������� ��������������� ����� � �������� ���������� */
	if (qspCallBacks[QSP_CALL_PLAYFILE]) qspCallBacks[QSP_CALL_PLAYFILE](file, volume);
}

QSP_BOOL qspCallIsPlayingFile(QSP_CHAR *file)
{
	/* ����� ���������, ������������� �� ���� */
	return (qspCallBacks[QSP_CALL_ISPLAYINGFILE] && (QSP_BOOL)qspCallBacks[QSP_CALL_ISPLAYINGFILE](file));
}

void qspCallSleep(long msecs)
{
	/* ����� ������� �������� ���������� ����������� */
	if (qspCallBacks[QSP_CALL_SLEEP]) qspCallBacks[QSP_CALL_SLEEP](msecs);
}

long qspCallGetMSCount()
{
	/* ����� �������� ���������� �����������, ��������� � ������� ���������� ������ ������� */
	return (qspCallBacks[QSP_CALL_GETMSCOUNT] ? qspCallBacks[QSP_CALL_GETMSCOUNT]() : 0);
}

void qspCallCloseFile(QSP_CHAR *file)
{
	/* ����� ��������� �������� ����� */
	if (qspCallBacks[QSP_CALL_CLOSEFILE]) qspCallBacks[QSP_CALL_CLOSEFILE](file);
}

void qspCallDeleteMenu()
{
	/* ����� ������� ������� ���� */
	if (qspCallBacks[QSP_CALL_DELETEMENU]) qspCallBacks[QSP_CALL_DELETEMENU]();
}

QSP_CHAR *qspCallInputBox(QSP_CHAR *text)
{
	/* ����� ������ ����� */
	QSP_CHAR *buffer;
	long maxLen = 511;
	if (qspCallBacks[QSP_CALL_INPUTBOX])
	{
		buffer = (QSP_CHAR *)malloc((maxLen + 1) * sizeof(QSP_CHAR));
		qspCallBacks[QSP_CALL_INPUTBOX](text, buffer, maxLen);
	}
	else
		buffer = qspGetNewText(QSP_FMT(""), 0);
	return buffer;
}
