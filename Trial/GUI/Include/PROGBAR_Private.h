/*********************************************************************
*                SEGGER MICROCONTROLLER SYSTEME GmbH                 *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2005  SEGGER Microcontroller Systeme GmbH        *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V3.96 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : PROGBAR_Private.h
Purpose     : Internal header file
---------------------------END-OF-HEADER------------------------------
*/

#ifndef PROGBAR_PRIVATE_H
#define PROGBAR_PRIVATE_H

#include "WIDGET.h"
#include "PROGBAR.h"

#if GUI_WINSUPPORT

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define PROGBAR_SF_HORIZONTAL PROGBAR_CF_HORIZONTAL
#define PROGBAR_SF_VERTICAL   PROGBAR_CF_VERTICAL

#define PROGBAR_H2P(h) (PROGBAR_Obj*) GUI_ALLOC_h2p(h)

/*********************************************************************
*
*       Types
*
**********************************************************************
*/
typedef struct {
  const GUI_FONT GUI_UNI_PTR * pFont;
  GUI_COLOR aBarColor[2];
  GUI_COLOR aTextColor[2];
} PROGBAR_PROPS;

typedef struct {
  WIDGET Widget;
  int v;
  WM_HMEM hpText;
  I16 XOff, YOff;
  I16 TextAlign;
  int Min, Max;
  #if GUI_DEBUG_LEVEL >= GUI_DEBUG_LEVEL_CHECK_ALL
    int DebugId;
  #endif
  PROGBAR_PROPS Props;
  U8 Flags;
} PROGBAR_Obj;

/*********************************************************************
*
*       Public data (internal defaults)
*
**********************************************************************
*/
extern PROGBAR_PROPS PROGBAR__DefaultProps;

/*********************************************************************
*
*       Public functions (internal)
*
**********************************************************************
*/
void         PROGBAR__FreeText   (PROGBAR_Handle hObj);
const char * PROGBAR__GetText    (const PROGBAR_Obj* pObj, char* pBuffer);
void         PROGBAR__GetTextRect(const PROGBAR_Obj* pObj, GUI_RECT* pRect, const char* pText);

#endif /* GUI_WINSUPPORT */
#endif /* PROGBAR_PRIVATE_H */

/*************************** End of file ****************************/
