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
File        : GUI_SetDrawMode.C
Purpose     : Implementation of optional routines
---------------------------END-OF-HEADER------------------------------
*/

#include <stddef.h>           /* needed for definition of NULL */

#include "GUI_Protected.h"
#include "GUIDebug.h"

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       GUI_SetDrawMode
*/
GUI_DRAWMODE GUI_SetDrawMode(GUI_DRAWMODE dm) {
  GUI_DRAWMODE OldMode;
  GUI_LOCK(); {
  OldMode = LCD_SetDrawMode(dm);
  } GUI_UNLOCK();
  return OldMode;
}

/*************************** End of file ****************************/
