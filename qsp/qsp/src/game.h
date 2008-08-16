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
#include "variant.h"

#ifndef QSP_GAMEDEFINES
	#define QSP_GAMEDEFINES

	#define QSP_GAMEID QSP_FMT("QSPGAME")
	#define QSP_SAVEDGAMEID QSP_FMT("QSPSAVEDGAME")
	#define QSP_GAMEMINVER QSP_FMT("5.4.0")
	#define QSP_MAXINCFILES 100
	#define QSP_DEFTIMERINTERVAL 500

	extern QSP_CHAR *qspQstPath;
	extern long qspQstPathLen;
	extern QSP_CHAR *qspQstFullPath;
	extern long qspQstCRC;

	void qspClearIncludes(QSP_BOOL);
	void qspNewGame(QSP_BOOL);
	void qspOpenQuest(QSP_CHAR *, QSP_BOOL);
	void qspSaveGameStatus(QSP_CHAR *);
	void qspOpenGameStatus(QSP_CHAR *);
	/* -- */
	QSP_BOOL qspStatementOpenQst(QSPVariant *, long, QSP_CHAR **, char);
	QSP_BOOL qspStatementOpenGame(QSPVariant *, long, QSP_CHAR **, char);
	QSP_BOOL qspStatementSaveGame(QSPVariant *, long, QSP_CHAR **, char);

#endif
