/*
 * Yuri Dario <mc6530@mclink.it>
 *
 * setproc.c code taken from Toolkit samples.
 *
 * Used to take offline the second cpu on shutdown.
 * Create a program object with '2 off' as parameters and place
 * in your XShutDown folder (requires XWP, eWP)
 *
*/
#define INCL_DOS
#define INCL_DOSSPINLOCK
#include <os2.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
   APIRET rc;
   ULONG procid;
   ULONG status;
   int i;

   if (argc < 3) {
      printf("Syntax: SETPROC p1 [p2] [p3...] ON|OFF\n");
      return 0;
   } /* endif */

   if (stricmp(argv[argc-1],"OFF")==0) status = 0;
   else if (stricmp(argv[argc-1],"ON")==0) status = 1;
   else {
      printf("Syntax: SETPROC p1 [p2] [p3...] ON|OFF\n");
      return 0;
   } /* endif */

   for (i=1; i<argc-1; ++i ) {
      procid = atol(argv[i]);
      rc = DosSetProcessorStatus(procid, status);
      if (rc) 
         printf("DosSetProcesorStatus failed: rc=%u\n",rc);
   } /* endfor */

   return rc;
}
