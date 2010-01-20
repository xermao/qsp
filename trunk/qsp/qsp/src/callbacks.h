/* Copyright (C) 2005-2009 Valeriy Argunov (nporep AT mail DOT ru) */
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

#ifndef QSP_CALLSDEFINES
	#define QSP_CALLSDEFINES

	typedef struct
	{
		QSP_BOOL IsInCallBack;
		QSP_BOOL IsMustWait;
		QSP_BOOL IsMainDescChanged;
		QSP_BOOL IsVarsDescChanged;
		QSP_BOOL IsObjectsChanged;
		QSP_BOOL IsActionsChanged;
	} QSPCallState;

	extern volatile QSP_BOOL qspIsInCallBack;

	/* External functions */
	void qspInitCallBacks();
	void qspSetCallBack(int, QSP_CALLBACK);
	void qspCallDebug(QSP_CHAR *);
	void qspCallSetTimer(int);
	void qspCallRefreshInt(QSP_BOOL);
	void qspCallSetInputStrText(QSP_CHAR *);
	void qspCallAddMenuItem(QSP_CHAR *, QSP_CHAR *);
	void qspCallSystem(QSP_CHAR *);
	void qspCallOpenGame();
	void qspCallSaveGame();
	void qspCallShowMessage(QSP_CHAR *);
	void qspCallShowMenu();
	void qspCallShowPicture(QSP_CHAR *);
	void qspCallShowWindow(int, QSP_BOOL);
	void qspCallPlayFile(QSP_CHAR *, int);
	QSP_BOOL qspCallIsPlayingFile(QSP_CHAR *);
	void qspCallSleep(int);
	int qspCallGetMSCount();
	void qspCallCloseFile(QSP_CHAR *);
	void qspCallDeleteMenu();
	QSP_CHAR *qspCallInputBox(QSP_CHAR *);

	#ifdef _FLASH
		void qspSetReturnValue(AS3_Val res);
	#endif

#endif
