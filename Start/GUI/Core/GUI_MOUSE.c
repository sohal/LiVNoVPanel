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
File        : GUI_MOUSE.C
Purpose     : Generic mouse routines
----------------------------------------------------------------------
*/

#include <string.h>           /* memcmp */
#include "LCD_Private.h"      /* private modul definitions & config */
#include "GUI_Protected.h"

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

static GUI_PID_STATE _State;

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       GUI_MOUSE_GetState
*/
int GUI_MOUSE_GetState(GUI_PID_STATE *pState) {
  *pState = _State;
  return (_State.Pressed != 0) ? 1 : 0;
}

/*********************************************************************
*
*       GUI_MOUSE_StoreState
*/
void GUI_MOUSE_StoreState(const GUI_PID_STATE *pState) {
  if (memcmp(pState, &_State, sizeof(_State))) {
    _State = *pState;
    GUI_PID_StoreState(pState);
  }
}

/*************************** End of file ****************************/

