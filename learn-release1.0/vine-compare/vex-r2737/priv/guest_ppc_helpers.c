
/*---------------------------------------------------------------*/
/*--- begin                               guest_ppc_helpers.c ---*/
/*---------------------------------------------------------------*/

/*
   This file is part of Valgrind, a dynamic binary instrumentation
   framework.

   Copyright (C) 2004-2012 OpenWorks LLP
      info@open-works.net

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301, USA.

   The GNU General Public License is contained in the file COPYING.

   Neither the names of the U.S. Department of Energy nor the
   University of California nor the names of its contributors may be
   used to endorse or promote products derived from this software
   without prior written permission.
*/

#include "libvex_basictypes.h"
#include "libvex_emnote.h"
#include "libvex_guest_ppc32.h"
#include "libvex_guest_ppc64.h"
#include "libvex_ir.h"
#include "libvex.h"

#include "main_util.h"
#include "main_globals.h"
#include "guest_generic_bb_to_IR.h"
#include "guest_ppc_defs.h"


/* This file contains helper functions for ppc32 and ppc64 guest code.
   Calls to these functions are generated by the back end.  These
   calls are of course in the host machine code and this file will be
   compiled to host machine code, so that all makes sense.

   Only change the signatures of these helper functions very
   carefully.  If you change the signature here, you'll have to change
   the parameters passed to it in the IR calls constructed by
   guest-ppc/toIR.c.
*/


/*---------------------------------------------------------------*/
/*--- Misc integer helpers.                                   ---*/
/*---------------------------------------------------------------*/

/* CALLED FROM GENERATED CODE */
/* DIRTY HELPER (non-referentially-transparent) */
/* Horrible hack.  On non-ppc platforms, return 1. */
/* Reads a complete, consistent 64-bit TB value. */
ULong ppcg_dirtyhelper_MFTB ( void )
{
#  if defined(__powerpc__) || defined(_AIX)
   ULong res;
   UInt  lo, hi1, hi2;
   while (1) {
      __asm__ __volatile__ ("\n"
         "\tmftbu %0\n"
         "\tmftb %1\n"
         "\tmftbu %2\n"
         : "=r" (hi1), "=r" (lo), "=r" (hi2)
      );
      if (hi1 == hi2) break;
   }
   res = ((ULong)hi1) << 32;
   res |= (ULong)lo;
   return res;
#  else
   return 1ULL;
#  endif
}


/* CALLED FROM GENERATED CODE */
/* DIRTY HELPER (non-referentially transparent) */
UInt ppc32g_dirtyhelper_MFSPR_268_269 ( UInt r269 )
{
#  if defined(__powerpc__) || defined(_AIX)
   UInt spr;
   if (r269) {
      __asm__ __volatile__("mfspr %0,269" : "=b"(spr));
   } else {
      __asm__ __volatile__("mfspr %0,268" : "=b"(spr));
   }
   return spr;
#  else
   return 0;
#  endif
}


/* CALLED FROM GENERATED CODE */
/* DIRTY HELPER (I'm not really sure what the side effects are) */
UInt ppc32g_dirtyhelper_MFSPR_287 ( void )
{
#  if defined(__powerpc__) || defined(_AIX)
   UInt spr;
   __asm__ __volatile__("mfspr %0,287" : "=b"(spr));
   return spr;
#  else
   return 0;
#  endif
}


/* CALLED FROM GENERATED CODE */
/* DIRTY HELPER (reads guest state, writes guest mem) */
void ppc32g_dirtyhelper_LVS ( VexGuestPPC32State* gst,
                              UInt vD_off, UInt sh, UInt shift_right )
{
  static
  UChar ref[32] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
                    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                    0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F };
  U128* pU128_src;
  U128* pU128_dst;

  vassert( vD_off       <= sizeof(VexGuestPPC32State)-8 );
  vassert( sh           <= 15 );
  vassert( shift_right  <=  1 );
  if (shift_right)
     sh = 16-sh;
  /* else shift left  */

  pU128_src = (U128*)&ref[sh];
  pU128_dst = (U128*)( ((UChar*)gst) + vD_off );

  (*pU128_dst)[0] = (*pU128_src)[0];
  (*pU128_dst)[1] = (*pU128_src)[1];
  (*pU128_dst)[2] = (*pU128_src)[2];
  (*pU128_dst)[3] = (*pU128_src)[3];
}

/* CALLED FROM GENERATED CODE */
/* DIRTY HELPER (reads guest state, writes guest mem) */
void ppc64g_dirtyhelper_LVS ( VexGuestPPC64State* gst,
                              UInt vD_off, UInt sh, UInt shift_right )
{
  UChar ref[32];
  ULong i;
  /* ref[] used to be a static const array, but this doesn't work on
     ppc64 because VEX doesn't load the TOC pointer for the call here,
     and so we wind up picking up some totally random other data.
     (It's a wonder we don't segfault.)  So, just to be clear, this
     "fix" (vex r2073) is really a kludgearound for the fact that
     VEX's 64-bit ppc code generation doesn't provide a valid TOC
     pointer for helper function calls.  Ick.  (Bug 250038) */
  for (i = 0; i < 32; i++) ref[i] = i;

  U128* pU128_src;
  U128* pU128_dst;

  vassert( vD_off       <= sizeof(VexGuestPPC64State)-8 );
  vassert( sh           <= 15 );
  vassert( shift_right  <=  1 );
  if (shift_right)
     sh = 16-sh;
  /* else shift left  */

  pU128_src = (U128*)&ref[sh];
  pU128_dst = (U128*)( ((UChar*)gst) + vD_off );

  (*pU128_dst)[0] = (*pU128_src)[0];
  (*pU128_dst)[1] = (*pU128_src)[1];
  (*pU128_dst)[2] = (*pU128_src)[2];
  (*pU128_dst)[3] = (*pU128_src)[3];
}


/* Helper-function specialiser. */

IRExpr* guest_ppc32_spechelper ( const HChar* function_name,
                                 IRExpr** args,
                                 IRStmt** precedingStmts,
                                 Int      n_precedingStmts )
{
   return NULL;
}

IRExpr* guest_ppc64_spechelper ( const HChar* function_name,
                                 IRExpr** args,
                                 IRStmt** precedingStmts,
                                 Int      n_precedingStmts )
{
   return NULL;
}


/*----------------------------------------------*/
/*--- The exported fns ..                    ---*/
/*----------------------------------------------*/

/* VISIBLE TO LIBVEX CLIENT */
UInt LibVEX_GuestPPC32_get_CR ( /*IN*/const VexGuestPPC32State* vex_state )
{
#  define FIELD(_n)                                    \
      ( ( (UInt)                                       \
           ( (vex_state->guest_CR##_n##_321 & (7<<1))  \
             | (vex_state->guest_CR##_n##_0 & 1)       \
           )                                           \
        )                                              \
        << (4 * (7-(_n)))                              \
      )

   return 
      FIELD(0) | FIELD(1) | FIELD(2) | FIELD(3)
      | FIELD(4) | FIELD(5) | FIELD(6) | FIELD(7);

#  undef FIELD
}


/* VISIBLE TO LIBVEX CLIENT */
/* Note: %CR is 32 bits even for ppc64 */
UInt LibVEX_GuestPPC64_get_CR ( /*IN*/const VexGuestPPC64State* vex_state )
{
#  define FIELD(_n)                                    \
      ( ( (UInt)                                       \
           ( (vex_state->guest_CR##_n##_321 & (7<<1))  \
             | (vex_state->guest_CR##_n##_0 & 1)       \
           )                                           \
        )                                              \
        << (4 * (7-(_n)))                              \
      )

   return 
      FIELD(0) | FIELD(1) | FIELD(2) | FIELD(3)
      | FIELD(4) | FIELD(5) | FIELD(6) | FIELD(7);

#  undef FIELD
}


/* VISIBLE TO LIBVEX CLIENT */
void LibVEX_GuestPPC32_put_CR ( UInt cr_native,
                                /*OUT*/VexGuestPPC32State* vex_state )
{
   UInt t;

#  define FIELD(_n)                                           \
      do {                                                    \
         t = cr_native >> (4*(7-(_n)));                       \
         vex_state->guest_CR##_n##_0 = toUChar(t & 1);        \
         vex_state->guest_CR##_n##_321 = toUChar(t & (7<<1)); \
      } while (0)

   FIELD(0);
   FIELD(1);
   FIELD(2);
   FIELD(3);
   FIELD(4);
   FIELD(5);
   FIELD(6);
   FIELD(7);

#  undef FIELD
}


/* VISIBLE TO LIBVEX CLIENT */
/* Note: %CR is 32 bits even for ppc64 */
void LibVEX_GuestPPC64_put_CR ( UInt cr_native,
                                /*OUT*/VexGuestPPC64State* vex_state )
{
   UInt t;

#  define FIELD(_n)                                           \
      do {                                                    \
         t = cr_native >> (4*(7-(_n)));                       \
         vex_state->guest_CR##_n##_0 = toUChar(t & 1);        \
         vex_state->guest_CR##_n##_321 = toUChar(t & (7<<1)); \
      } while (0)

   FIELD(0);
   FIELD(1);
   FIELD(2);
   FIELD(3);
   FIELD(4);
   FIELD(5);
   FIELD(6);
   FIELD(7);

#  undef FIELD
}


/* VISIBLE TO LIBVEX CLIENT */
UInt LibVEX_GuestPPC32_get_XER ( /*IN*/const VexGuestPPC32State* vex_state )
{
   UInt w = 0;
   w |= ( ((UInt)vex_state->guest_XER_BC) & 0xFF );
   w |= ( (((UInt)vex_state->guest_XER_SO) & 0x1) << 31 );
   w |= ( (((UInt)vex_state->guest_XER_OV) & 0x1) << 30 );
   w |= ( (((UInt)vex_state->guest_XER_CA) & 0x1) << 29 );
   return w;
}


/* VISIBLE TO LIBVEX CLIENT */
/* Note: %XER is 32 bits even for ppc64 */
UInt LibVEX_GuestPPC64_get_XER ( /*IN*/const VexGuestPPC64State* vex_state )
{
   UInt w = 0;
   w |= ( ((UInt)vex_state->guest_XER_BC) & 0xFF );
   w |= ( (((UInt)vex_state->guest_XER_SO) & 0x1) << 31 );
   w |= ( (((UInt)vex_state->guest_XER_OV) & 0x1) << 30 );
   w |= ( (((UInt)vex_state->guest_XER_CA) & 0x1) << 29 );
   return w;
}


/* VISIBLE TO LIBVEX CLIENT */
void LibVEX_GuestPPC32_put_XER ( UInt xer_native,
                                 /*OUT*/VexGuestPPC32State* vex_state )
{
   vex_state->guest_XER_BC = toUChar(xer_native & 0xFF);
   vex_state->guest_XER_SO = toUChar((xer_native >> 31) & 0x1);
   vex_state->guest_XER_OV = toUChar((xer_native >> 30) & 0x1);
   vex_state->guest_XER_CA = toUChar((xer_native >> 29) & 0x1);
}

/* VISIBLE TO LIBVEX CLIENT */
/* Note: %XER is 32 bits even for ppc64 */
void LibVEX_GuestPPC64_put_XER ( UInt xer_native,
                                 /*OUT*/VexGuestPPC64State* vex_state )
{
   vex_state->guest_XER_BC = toUChar(xer_native & 0xFF);
   vex_state->guest_XER_SO = toUChar((xer_native >> 31) & 0x1);
   vex_state->guest_XER_OV = toUChar((xer_native >> 30) & 0x1);
   vex_state->guest_XER_CA = toUChar((xer_native >> 29) & 0x1);
}

/* VISIBLE TO LIBVEX CLIENT */
void LibVEX_GuestPPC32_initialise ( /*OUT*/VexGuestPPC32State* vex_state )
{
   Int i;
   vex_state->host_EvC_FAILADDR = 0;
   vex_state->host_EvC_COUNTER  = 0;
   vex_state->pad3 = 0;
   vex_state->pad4 = 0;

   vex_state->guest_GPR0  = 0;
   vex_state->guest_GPR1  = 0;
   vex_state->guest_GPR2  = 0;
   vex_state->guest_GPR3  = 0;
   vex_state->guest_GPR4  = 0;
   vex_state->guest_GPR5  = 0;
   vex_state->guest_GPR6  = 0;
   vex_state->guest_GPR7  = 0;
   vex_state->guest_GPR8  = 0;
   vex_state->guest_GPR9  = 0;
   vex_state->guest_GPR10 = 0;
   vex_state->guest_GPR11 = 0;
   vex_state->guest_GPR12 = 0;
   vex_state->guest_GPR13 = 0;
   vex_state->guest_GPR14 = 0;
   vex_state->guest_GPR15 = 0;
   vex_state->guest_GPR16 = 0;
   vex_state->guest_GPR17 = 0;
   vex_state->guest_GPR18 = 0;
   vex_state->guest_GPR19 = 0;
   vex_state->guest_GPR20 = 0;
   vex_state->guest_GPR21 = 0;
   vex_state->guest_GPR22 = 0;
   vex_state->guest_GPR23 = 0;
   vex_state->guest_GPR24 = 0;
   vex_state->guest_GPR25 = 0;
   vex_state->guest_GPR26 = 0;
   vex_state->guest_GPR27 = 0;
   vex_state->guest_GPR28 = 0;
   vex_state->guest_GPR29 = 0;
   vex_state->guest_GPR30 = 0;
   vex_state->guest_GPR31 = 0;

   /* Initialise the vector state. */
#  define VECZERO(_vr) _vr[0]=_vr[1]=_vr[2]=_vr[3] = 0;

   VECZERO(vex_state->guest_VSR0 );
   VECZERO(vex_state->guest_VSR1 );
   VECZERO(vex_state->guest_VSR2 );
   VECZERO(vex_state->guest_VSR3 );
   VECZERO(vex_state->guest_VSR4 );
   VECZERO(vex_state->guest_VSR5 );
   VECZERO(vex_state->guest_VSR6 );
   VECZERO(vex_state->guest_VSR7 );
   VECZERO(vex_state->guest_VSR8 );
   VECZERO(vex_state->guest_VSR9 );
   VECZERO(vex_state->guest_VSR10);
   VECZERO(vex_state->guest_VSR11);
   VECZERO(vex_state->guest_VSR12);
   VECZERO(vex_state->guest_VSR13);
   VECZERO(vex_state->guest_VSR14);
   VECZERO(vex_state->guest_VSR15);
   VECZERO(vex_state->guest_VSR16);
   VECZERO(vex_state->guest_VSR17);
   VECZERO(vex_state->guest_VSR18);
   VECZERO(vex_state->guest_VSR19);
   VECZERO(vex_state->guest_VSR20);
   VECZERO(vex_state->guest_VSR21);
   VECZERO(vex_state->guest_VSR22);
   VECZERO(vex_state->guest_VSR23);
   VECZERO(vex_state->guest_VSR24);
   VECZERO(vex_state->guest_VSR25);
   VECZERO(vex_state->guest_VSR26);
   VECZERO(vex_state->guest_VSR27);
   VECZERO(vex_state->guest_VSR28);
   VECZERO(vex_state->guest_VSR29);
   VECZERO(vex_state->guest_VSR30);
   VECZERO(vex_state->guest_VSR31);
   VECZERO(vex_state->guest_VSR32);
   VECZERO(vex_state->guest_VSR33);
   VECZERO(vex_state->guest_VSR34);
   VECZERO(vex_state->guest_VSR35);
   VECZERO(vex_state->guest_VSR36);
   VECZERO(vex_state->guest_VSR37);
   VECZERO(vex_state->guest_VSR38);
   VECZERO(vex_state->guest_VSR39);
   VECZERO(vex_state->guest_VSR40);
   VECZERO(vex_state->guest_VSR41);
   VECZERO(vex_state->guest_VSR42);
   VECZERO(vex_state->guest_VSR43);
   VECZERO(vex_state->guest_VSR44);
   VECZERO(vex_state->guest_VSR45);
   VECZERO(vex_state->guest_VSR46);
   VECZERO(vex_state->guest_VSR47);
   VECZERO(vex_state->guest_VSR48);
   VECZERO(vex_state->guest_VSR49);
   VECZERO(vex_state->guest_VSR50);
   VECZERO(vex_state->guest_VSR51);
   VECZERO(vex_state->guest_VSR52);
   VECZERO(vex_state->guest_VSR53);
   VECZERO(vex_state->guest_VSR54);
   VECZERO(vex_state->guest_VSR55);
   VECZERO(vex_state->guest_VSR56);
   VECZERO(vex_state->guest_VSR57);
   VECZERO(vex_state->guest_VSR58);
   VECZERO(vex_state->guest_VSR59);
   VECZERO(vex_state->guest_VSR60);
   VECZERO(vex_state->guest_VSR61);
   VECZERO(vex_state->guest_VSR62);
   VECZERO(vex_state->guest_VSR63);

#  undef VECZERO

   vex_state->guest_CIA  = 0;
   vex_state->guest_LR   = 0;
   vex_state->guest_CTR  = 0;

   vex_state->guest_XER_SO = 0;
   vex_state->guest_XER_OV = 0;
   vex_state->guest_XER_CA = 0;
   vex_state->guest_XER_BC = 0;

   vex_state->guest_CR0_321 = 0;
   vex_state->guest_CR0_0   = 0;
   vex_state->guest_CR1_321 = 0;
   vex_state->guest_CR1_0   = 0;
   vex_state->guest_CR2_321 = 0;
   vex_state->guest_CR2_0   = 0;
   vex_state->guest_CR3_321 = 0;
   vex_state->guest_CR3_0   = 0;
   vex_state->guest_CR4_321 = 0;
   vex_state->guest_CR4_0   = 0;
   vex_state->guest_CR5_321 = 0;
   vex_state->guest_CR5_0   = 0;
   vex_state->guest_CR6_321 = 0;
   vex_state->guest_CR6_0   = 0;
   vex_state->guest_CR7_321 = 0;
   vex_state->guest_CR7_0   = 0;

   vex_state->guest_FPROUND  = PPCrm_NEAREST;
   vex_state->guest_DFPROUND = PPCrm_NEAREST;
   vex_state->pad1 = 0;
   vex_state->pad2 = 0;

   vex_state->guest_VRSAVE = 0;

   vex_state->guest_VSCR = 0x0;  // Non-Java mode = 0

   vex_state->guest_EMNOTE = EmNote_NONE;

   vex_state->guest_TISTART = 0;
   vex_state->guest_TILEN   = 0;

   vex_state->guest_NRADDR = 0;
   vex_state->guest_NRADDR_GPR2 = 0;

   vex_state->guest_REDIR_SP = -1;
   for (i = 0; i < VEX_GUEST_PPC32_REDIR_STACK_SIZE; i++)
      vex_state->guest_REDIR_STACK[i] = 0;

   vex_state->guest_IP_AT_SYSCALL = 0;
   vex_state->guest_SPRG3_RO = 0;

   vex_state->padding = 0;
}


/* VISIBLE TO LIBVEX CLIENT */
void LibVEX_GuestPPC64_initialise ( /*OUT*/VexGuestPPC64State* vex_state )
{
   Int i;
   vex_state->host_EvC_FAILADDR = 0;
   vex_state->host_EvC_COUNTER = 0;
   vex_state->pad0 = 0;
   vex_state->guest_GPR0  = 0;
   vex_state->guest_GPR1  = 0;
   vex_state->guest_GPR2  = 0;
   vex_state->guest_GPR3  = 0;
   vex_state->guest_GPR4  = 0;
   vex_state->guest_GPR5  = 0;
   vex_state->guest_GPR6  = 0;
   vex_state->guest_GPR7  = 0;
   vex_state->guest_GPR8  = 0;
   vex_state->guest_GPR9  = 0;
   vex_state->guest_GPR10 = 0;
   vex_state->guest_GPR11 = 0;
   vex_state->guest_GPR12 = 0;
   vex_state->guest_GPR13 = 0;
   vex_state->guest_GPR14 = 0;
   vex_state->guest_GPR15 = 0;
   vex_state->guest_GPR16 = 0;
   vex_state->guest_GPR17 = 0;
   vex_state->guest_GPR18 = 0;
   vex_state->guest_GPR19 = 0;
   vex_state->guest_GPR20 = 0;
   vex_state->guest_GPR21 = 0;
   vex_state->guest_GPR22 = 0;
   vex_state->guest_GPR23 = 0;
   vex_state->guest_GPR24 = 0;
   vex_state->guest_GPR25 = 0;
   vex_state->guest_GPR26 = 0;
   vex_state->guest_GPR27 = 0;
   vex_state->guest_GPR28 = 0;
   vex_state->guest_GPR29 = 0;
   vex_state->guest_GPR30 = 0;
   vex_state->guest_GPR31 = 0;

   /* Initialise the vector state. */
#  define VECZERO(_vr) _vr[0]=_vr[1]=_vr[2]=_vr[3] = 0;

   VECZERO(vex_state->guest_VSR0 );
   VECZERO(vex_state->guest_VSR1 );
   VECZERO(vex_state->guest_VSR2 );
   VECZERO(vex_state->guest_VSR3 );
   VECZERO(vex_state->guest_VSR4 );
   VECZERO(vex_state->guest_VSR5 );
   VECZERO(vex_state->guest_VSR6 );
   VECZERO(vex_state->guest_VSR7 );
   VECZERO(vex_state->guest_VSR8 );
   VECZERO(vex_state->guest_VSR9 );
   VECZERO(vex_state->guest_VSR10);
   VECZERO(vex_state->guest_VSR11);
   VECZERO(vex_state->guest_VSR12);
   VECZERO(vex_state->guest_VSR13);
   VECZERO(vex_state->guest_VSR14);
   VECZERO(vex_state->guest_VSR15);
   VECZERO(vex_state->guest_VSR16);
   VECZERO(vex_state->guest_VSR17);
   VECZERO(vex_state->guest_VSR18);
   VECZERO(vex_state->guest_VSR19);
   VECZERO(vex_state->guest_VSR20);
   VECZERO(vex_state->guest_VSR21);
   VECZERO(vex_state->guest_VSR22);
   VECZERO(vex_state->guest_VSR23);
   VECZERO(vex_state->guest_VSR24);
   VECZERO(vex_state->guest_VSR25);
   VECZERO(vex_state->guest_VSR26);
   VECZERO(vex_state->guest_VSR27);
   VECZERO(vex_state->guest_VSR28);
   VECZERO(vex_state->guest_VSR29);
   VECZERO(vex_state->guest_VSR30);
   VECZERO(vex_state->guest_VSR31);
   VECZERO(vex_state->guest_VSR32);
   VECZERO(vex_state->guest_VSR33);
   VECZERO(vex_state->guest_VSR34);
   VECZERO(vex_state->guest_VSR35);
   VECZERO(vex_state->guest_VSR36);
   VECZERO(vex_state->guest_VSR37);
   VECZERO(vex_state->guest_VSR38);
   VECZERO(vex_state->guest_VSR39);
   VECZERO(vex_state->guest_VSR40);
   VECZERO(vex_state->guest_VSR41);
   VECZERO(vex_state->guest_VSR42);
   VECZERO(vex_state->guest_VSR43);
   VECZERO(vex_state->guest_VSR44);
   VECZERO(vex_state->guest_VSR45);
   VECZERO(vex_state->guest_VSR46);
   VECZERO(vex_state->guest_VSR47);
   VECZERO(vex_state->guest_VSR48);
   VECZERO(vex_state->guest_VSR49);
   VECZERO(vex_state->guest_VSR50);
   VECZERO(vex_state->guest_VSR51);
   VECZERO(vex_state->guest_VSR52);
   VECZERO(vex_state->guest_VSR53);
   VECZERO(vex_state->guest_VSR54);
   VECZERO(vex_state->guest_VSR55);
   VECZERO(vex_state->guest_VSR56);
   VECZERO(vex_state->guest_VSR57);
   VECZERO(vex_state->guest_VSR58);
   VECZERO(vex_state->guest_VSR59);
   VECZERO(vex_state->guest_VSR60);
   VECZERO(vex_state->guest_VSR61);
   VECZERO(vex_state->guest_VSR62);
   VECZERO(vex_state->guest_VSR63);

#  undef VECZERO

   vex_state->guest_CIA  = 0;
   vex_state->guest_LR   = 0;
   vex_state->guest_CTR  = 0;

   vex_state->guest_XER_SO = 0;
   vex_state->guest_XER_OV = 0;
   vex_state->guest_XER_CA = 0;
   vex_state->guest_XER_BC = 0;

   vex_state->guest_CR0_321 = 0;
   vex_state->guest_CR0_0   = 0;
   vex_state->guest_CR1_321 = 0;
   vex_state->guest_CR1_0   = 0;
   vex_state->guest_CR2_321 = 0;
   vex_state->guest_CR2_0   = 0;
   vex_state->guest_CR3_321 = 0;
   vex_state->guest_CR3_0   = 0;
   vex_state->guest_CR4_321 = 0;
   vex_state->guest_CR4_0   = 0;
   vex_state->guest_CR5_321 = 0;
   vex_state->guest_CR5_0   = 0;
   vex_state->guest_CR6_321 = 0;
   vex_state->guest_CR6_0   = 0;
   vex_state->guest_CR7_321 = 0;
   vex_state->guest_CR7_0   = 0;

   vex_state->guest_FPROUND  = PPCrm_NEAREST;
   vex_state->guest_DFPROUND = PPCrm_NEAREST;
   vex_state->pad1 = 0;
   vex_state->pad2 = 0;

   vex_state->guest_VRSAVE = 0;

   vex_state->guest_VSCR = 0x0;  // Non-Java mode = 0

   vex_state->guest_EMNOTE = EmNote_NONE;

   vex_state->padding = 0;

   vex_state->guest_TISTART = 0;
   vex_state->guest_TILEN   = 0;

   vex_state->guest_NRADDR = 0;
   vex_state->guest_NRADDR_GPR2 = 0;

   vex_state->guest_REDIR_SP = -1;
   for (i = 0; i < VEX_GUEST_PPC64_REDIR_STACK_SIZE; i++)
      vex_state->guest_REDIR_STACK[i] = 0;

   vex_state->guest_IP_AT_SYSCALL = 0;
   vex_state->guest_SPRG3_RO = 0;

   vex_state->padding2 = 0;
   vex_state->padding3 = 0;
   vex_state->padding4 = 0;
}


/*-----------------------------------------------------------*/
/*--- Describing the ppc guest state, for the benefit     ---*/
/*--- of iropt and instrumenters.                         ---*/
/*-----------------------------------------------------------*/

/* Figure out if any part of the guest state contained in minoff
   .. maxoff requires precise memory exceptions.  If in doubt return
   True (but this is generates significantly slower code).  

   By default we enforce precise exns for guest R1 (stack pointer),
   CIA (current insn address) and LR (link register).  These are the
   minimum needed to extract correct stack backtraces from ppc
   code. [[NB: not sure if keeping LR up to date is actually
   necessary.]]

   Only R1 is needed in mode VexRegUpdSpAtMemAccess.   
*/
Bool guest_ppc32_state_requires_precise_mem_exns ( Int minoff, 
                                                   Int maxoff )
{
   Int lr_min  = offsetof(VexGuestPPC32State, guest_LR);
   Int lr_max  = lr_min + 4 - 1;
   Int r1_min  = offsetof(VexGuestPPC32State, guest_GPR1);
   Int r1_max  = r1_min + 4 - 1;
   Int cia_min = offsetof(VexGuestPPC32State, guest_CIA);
   Int cia_max = cia_min + 4 - 1;

   if (maxoff < r1_min || minoff > r1_max) {
      /* no overlap with R1 */
      if (vex_control.iropt_register_updates == VexRegUpdSpAtMemAccess)
         return False; // We only need to check stack pointer.
   } else {
      return True;
   }

   if (maxoff < lr_min || minoff > lr_max) {
      /* no overlap with LR */
   } else {
      return True;
   }

   if (maxoff < cia_min || minoff > cia_max) {
      /* no overlap with CIA */
   } else {
      return True;
   }

   return False;
}

Bool guest_ppc64_state_requires_precise_mem_exns ( Int minoff, 
                                                   Int maxoff )
{
   /* Given that R2 is a Big Deal in the ELF ppc64 ABI, it seems
      prudent to be conservative with it, even though thus far there
      is no evidence to suggest that it actually needs to be kept up
      to date wrt possible exceptions. */
   Int lr_min  = offsetof(VexGuestPPC64State, guest_LR);
   Int lr_max  = lr_min + 8 - 1;
   Int r1_min  = offsetof(VexGuestPPC64State, guest_GPR1);
   Int r1_max  = r1_min + 8 - 1;
   Int r2_min  = offsetof(VexGuestPPC64State, guest_GPR2);
   Int r2_max  = r2_min + 8 - 1;
   Int cia_min = offsetof(VexGuestPPC64State, guest_CIA);
   Int cia_max = cia_min + 8 - 1;

   if (maxoff < r1_min || minoff > r1_max) {
      /* no overlap with R1 */
      if (vex_control.iropt_register_updates == VexRegUpdSpAtMemAccess)
         return False; // We only need to check stack pointer.
   } else {
      return True;
   }

   if (maxoff < lr_min || minoff > lr_max) {
      /* no overlap with LR */
   } else {
      return True;
   }

   if (maxoff < r2_min || minoff > r2_max) {
      /* no overlap with R2 */
   } else {
      return True;
   }

   if (maxoff < cia_min || minoff > cia_max) {
      /* no overlap with CIA */
   } else {
      return True;
   }

   return False;
}


#define ALWAYSDEFD32(field)                           \
    { offsetof(VexGuestPPC32State, field),            \
      (sizeof ((VexGuestPPC32State*)0)->field) }

VexGuestLayout
   ppc32Guest_layout 
      = { 
          /* Total size of the guest state, in bytes. */
          .total_sizeB = sizeof(VexGuestPPC32State),

          /* Describe the stack pointer. */
          .offset_SP = offsetof(VexGuestPPC32State,guest_GPR1),
          .sizeof_SP = 4,

          /* Describe the frame pointer. */
          .offset_FP = offsetof(VexGuestPPC32State,guest_GPR1),
          .sizeof_FP = 4,

          /* Describe the instruction pointer. */
          .offset_IP = offsetof(VexGuestPPC32State,guest_CIA),
          .sizeof_IP = 4,

          /* Describe any sections to be regarded by Memcheck as
             'always-defined'. */
          .n_alwaysDefd = 11,

          .alwaysDefd 
	  = { /*  0 */ ALWAYSDEFD32(guest_CIA),
	      /*  1 */ ALWAYSDEFD32(guest_EMNOTE),
	      /*  2 */ ALWAYSDEFD32(guest_TISTART),
	      /*  3 */ ALWAYSDEFD32(guest_TILEN),
	      /*  4 */ ALWAYSDEFD32(guest_VSCR),
	      /*  5 */ ALWAYSDEFD32(guest_FPROUND),
              /*  6 */ ALWAYSDEFD32(guest_NRADDR),
	      /*  7 */ ALWAYSDEFD32(guest_NRADDR_GPR2),
	      /*  8 */ ALWAYSDEFD32(guest_REDIR_SP),
	      /*  9 */ ALWAYSDEFD32(guest_REDIR_STACK),
	      /* 10 */ ALWAYSDEFD32(guest_IP_AT_SYSCALL)
            }
        };

#define ALWAYSDEFD64(field)                           \
    { offsetof(VexGuestPPC64State, field),            \
      (sizeof ((VexGuestPPC64State*)0)->field) }

VexGuestLayout
   ppc64Guest_layout 
      = { 
          /* Total size of the guest state, in bytes. */
          .total_sizeB = sizeof(VexGuestPPC64State),

          /* Describe the stack pointer. */
          .offset_SP = offsetof(VexGuestPPC64State,guest_GPR1),
          .sizeof_SP = 8,

          /* Describe the frame pointer. */
          .offset_FP = offsetof(VexGuestPPC64State,guest_GPR1),
          .sizeof_FP = 8,

          /* Describe the instruction pointer. */
          .offset_IP = offsetof(VexGuestPPC64State,guest_CIA),
          .sizeof_IP = 8,

          /* Describe any sections to be regarded by Memcheck as
             'always-defined'. */
          .n_alwaysDefd = 11,

          .alwaysDefd 
	  = { /*  0 */ ALWAYSDEFD64(guest_CIA),
	      /*  1 */ ALWAYSDEFD64(guest_EMNOTE),
	      /*  2 */ ALWAYSDEFD64(guest_TISTART),
	      /*  3 */ ALWAYSDEFD64(guest_TILEN),
	      /*  4 */ ALWAYSDEFD64(guest_VSCR),
	      /*  5 */ ALWAYSDEFD64(guest_FPROUND),
	      /*  6 */ ALWAYSDEFD64(guest_NRADDR),
	      /*  7 */ ALWAYSDEFD64(guest_NRADDR_GPR2),
	      /*  8 */ ALWAYSDEFD64(guest_REDIR_SP),
	      /*  9 */ ALWAYSDEFD64(guest_REDIR_STACK),
	      /* 10 */ ALWAYSDEFD64(guest_IP_AT_SYSCALL)
            }
        };

/*---------------------------------------------------------------*/
/*--- end                                 guest_ppc_helpers.c ---*/
/*---------------------------------------------------------------*/
