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
File        : LCDP555.C
Purpose     : Color conversion routines
---------------------------END-OF-HEADER------------------------------
*/

#include "LCD_Protected.h"    /* inter modul definitions */

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

#define B_BITS 5
#define G_BITS 5
#define R_BITS 5

#define R_MASK ((1 << R_BITS) -1)
#define G_MASK ((1 << G_BITS) -1)
#define B_MASK ((1 << B_BITS) -1)

/*********************************************************************
*
*       Public code,
*
*       LCD_FIXEDPALETTE == 555, 32768 colors, 0BBBBBGGGGGRRRRR
*
**********************************************************************
*/
/*********************************************************************
*
*       LCD_Color2Index_555
*/
unsigned LCD_Color2Index_555(LCD_COLOR Color) {
  int r,g,b;
  r = (Color>> (8  - R_BITS)) & R_MASK;
  g = (Color>> (16 - G_BITS)) & G_MASK;
  b = (Color>> (24 - B_BITS)) & B_MASK;
  return r + (g << R_BITS) + (b << (G_BITS + R_BITS));
}

/*********************************************************************
*
*       LCD_Index2Color_555
*/
LCD_COLOR LCD_Index2Color_555(int Index) {
  unsigned int r,g,b;
  /* Seperate the color masks */
  r = Index                                  & R_MASK;
  g = (Index >> R_BITS)                      & G_MASK;
  b = ((unsigned)Index >> (R_BITS + G_BITS)) & B_MASK;
  /* Convert the color masks */
  r = r * 255 / R_MASK;
  g = g * 255 / G_MASK;
  b = b * 255 / B_MASK;
  return r + (g<<8) + (((U32)b)<<16);
}

/*********************************************************************
*
*       LCD_GetIndexMask_555
*/
unsigned LCD_GetIndexMask_555(void) {
  return 0x7fff;
}

/*************************** End of file ****************************/