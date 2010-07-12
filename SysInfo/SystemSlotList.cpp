//====================================================================================
// Open Computer and Software Inventory Next Generation
// Copyright (C) 2010 OCS Inventory NG Team. All rights reserved.
// Web: http://www.ocsinventory-ng.org

// This code is open source and may be copied and modified as long as the source
// code is always made freely available.
// Please refer to the General Public Licence V2 http://www.gnu.org/ or Licence.txt
//====================================================================================

// SystemSlotList.cpp: implementation of the CSystemSlotList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SystemSlot.h"
#include "SystemSlotList.h"
#include "OcsCrypto.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSystemSlotList::CSystemSlotList()
{
}

CSystemSlotList::~CSystemSlotList()
{
}

LPCTSTR CSystemSlotList::GetHash()
{
	COcsCrypto	myHash;
	CSystemSlot myObject;
	POSITION	pos;
	BOOL		bContinue;
	CString		csToHash;

	if (!myHash.HashInit())
		return NULL;
	pos = GetHeadPosition();
	bContinue = (pos != NULL);
	if (bContinue)
		// There is one record => get the first
		myObject = GetNext( pos);
	while (bContinue)
	{
		csToHash.Format( _T( "%s%s%s%s%s"), myObject.GetName(), myObject.GetDescription(),
						 myObject.GetSlotDesignation(), myObject.GetUsage(), myObject.GetStatus());
		myHash.HashUpdate( LPCTSTR( csToHash), csToHash.GetLength());
		bContinue = (pos != NULL);
		if (bContinue)
			myObject = GetNext( pos);
	}
	return myHash.HashFinal();
}