//====================================================================================
// Open Computer and Software Inventory Next Generation
// Copyright (C) 2010 OCS Inventory NG Team. All rights reserved.
// Web: http://www.ocsinventory-ng.org

// This code is open source and may be copied and modified as long as the source
// code is always made freely available.
// Please refer to the General Public Licence V2 http://www.gnu.org/ or Licence.txt
//====================================================================================

#if !defined( _PLUGIN_API_H_INCLUDED_)
#define _PLUGIN_API_H_INCLUDED_

#pragma once

#include "markup.h"
#include "PrologResponse.h"
#include "InventoryResponse.h"
#include "PrologRequest.h"
#include "InventoryRequest.h"

#ifdef _OCS_AGENT
// We are in agent code, we import plugins functions
#define OCSINVENTORY_API_EXPORTED _declspec(dllimport)
#else
// We are in plugin, we export functions
#define OCSINVENTORY_API_EXPORTED _declspec(dllexport)
#endif

#define PLUGIN_OK 0

typedef int (*HOOK_START)(void);
typedef int (*HOOK_END)(void);
typedef int (*HOOK_CLEAN)(void);
typedef int (*HOOK_PROLOG_WRITE)(CPrologRequest*);
typedef int (*HOOK_PROLOG_RESP)(CPrologResponse*);
typedef int (*HOOK_INVENTORY)(CInventoryRequest*);

OCSINVENTORY_API_EXPORTED int OCS_CALL_INVENTORY_EXPORTED(CInventoryRequest*);
OCSINVENTORY_API_EXPORTED int OCS_CALL_PROLOGWRITE_EXPORTED(CPrologRequest*);
OCSINVENTORY_API_EXPORTED int OCS_CALL_PROLOGRESP_EXPORTED(CPrologResponse*);
OCSINVENTORY_API_EXPORTED int OCS_CALL_END_EXPORTED();
OCSINVENTORY_API_EXPORTED int OCS_CALL_START_EXPORTED();

#endif // _PLUGIN_API_H_INCLUDED_