#define _XOPEN_SOURCE 500
#include "../include/commons.h";
#include <ftw.h>
#include <stdio.h>

// :foo_nft
static int foo_nftw(const char *fpath, const struct stat *sb, int typeflag,
                    struct FTW *ftwbuf) {

  return 0;
}
