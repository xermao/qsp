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
#include "variant.h"

#ifndef QSP_MATHDEFINES
	#define QSP_MATHDEFINES

	#define QSP_MAXOPSNAMES 100
	#define QSP_OPMAXARGS 10
	#define QSP_STACKSIZE 30
	#define QSP_MAXITEMS 100

	typedef void (*QSP_FUNCTION)(QSPVariant *, long, QSPVariant *);

	typedef struct
	{
		long Code;
		QSP_CHAR *Name;
		long NameLen;
	} QSPMathOpName;

	typedef struct
	{
		char Priority;
		char ResType;
		long MinArgsCount;
		long MaxArgsCount;
		char ArgsTypes[QSP_OPMAXARGS];
		QSP_FUNCTION Func;
	} QSPMathOperation;

	enum
	{
		qspOpUnknown,
		qspOpStart,
		qspOpEnd,
		qspOpValue,
		qspOpOpenBracket,
		qspOpMinus,
		qspOpComma,
		qspOpCloseBracket,
		qspOpMul,
		qspOpDiv,
		qspOpAdd,
		qspOpSub,
		qspOpNe,
		qspOpLeq,
		qspOpGeq,
		qspOpEq,
		qspOpLt,
		qspOpGt,
		qspOpAnd,
		qspOpOr,
		qspOpAppend,

		qspOpFirst_Function,
		qspOpNot = qspOpFirst_Function,
		qspOpObj,
		qspOpMin,
		qspOpMax,
		qspOpRand,
		qspOpIIf,
		qspOpRGB,
		qspOpLen,
		qspOpIsNum,
		qspOpLCase,
		qspOpUCase,
		qspOpInput,
		qspOpStr,
		qspOpVal,
		qspOpArrSize,
		qspOpIsPlay,
		qspOpDesc,
		qspOpTrim,
		qspOpGetObj,
		qspOpStrComp,
		qspOpStrFind,
		qspOpStrPos,
		qspOpMid,
		qspOpArrPos,
		qspOpArrComp,
		qspOpInstr,
		qspOpReplace,
		qspOpFunc,
		qspOpDynEval,
		qspOpRnd,
		qspOpCountObj,
		qspOpMsecsCount,
		qspOpQSPVer,
		qspOpUserText,
		qspOpCurLoc,
		qspOpSelObj,
		qspOpSelAct,
		qspOpMainText,
		qspOpStatText,
		qspOpCurActs,

		qspOpLast_Operation
	};

	/* External functions */
	void qspInitMath();
	QSPVariant qspExprValue(QSP_CHAR *);

#endif
