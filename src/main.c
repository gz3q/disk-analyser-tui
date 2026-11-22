#define _XOPEN_SOURCE 500
#include "../include/commons.h"
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>

static int cback(const char *fpath, const struct stat *sb, int typeflag,
                 struct FTW *ftwbuf) {
  printf("%-3s %2d ",
         (typeflag == FTW_D)     ? "d"
         : (typeflag == FTW_DNR) ? "dnr"
         : (typeflag == FTW_DP)  ? "dp"
         : (typeflag == FTW_F)   ? "f"
         : (typeflag == FTW_NS)  ? "ns"
         : (typeflag == FTW_SL)  ? "sl"
         : (typeflag == FTW_SLN) ? "sln"
                                 : "???",
         ftwbuf->level);

  if (typeflag == FTW_NS)
    printf("-------");
  else
    printf("%7jd", (__intmax_t)sb->st_size);

  printf("   %-40s %d %s\n", fpath, ftwbuf->base, fpath + ftwbuf->base);

  return 0;
}

int main(int argc, char *argv[]) {
  int flags = 0;
  flags |= FTW_PHYS;

  const char *root = (argc > 1) ? "." : argv[1];

  if (nftw(root, cback, 20, flags) == -1) {
    perror("nftw");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
