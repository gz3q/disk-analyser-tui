#ifndef COMMONS_H
#define COMMONS_H

enum scan_status {
  SCAN_OK = 0,                /* success */
  SCAN_OK_WARN = -1,          /* success with warnings */
  SCAN_ERR_INT_EXCP = -2,     /* unexpected failure / unhandled exception */
  SCAN_ERR_MISSING_ARG = -3,  /* missing or invalid arguments - ex: argc = 1 */
  SCAN_ERR_INVALID_PATH = -4, /* chosen path doesnt exist or is a file */
  SCAN_ERR_BLOCKED = -5,      /* chosen root dir has no read access */
  SCAN_ERR_OUTPUT = -6,       /* writing to output was not successful */
  SCAN_INTERRUPT = 130,       /* ctrl-c */
};

static inline const char *c_strerror(int code) {
  switch (code) {
  case SCAN_OK:
    return "success.";
  case SCAN_OK_WARN:
    return "success - with warnings.";
  case SCAN_ERR_INT_EXCP:
    return "unexpected failure / unhandled exception. check over the warnings "
           "and root dir";
  case SCAN_ERR_MISSING_ARG:
    return "missing/invalid argument(s).";
  case SCAN_ERR_INVALID_PATH:
    return "chosen root dir doesn't exist or it is a file.";
  case SCAN_ERR_BLOCKED:
    return "chosen root dir has no read access.";
  case SCAN_ERR_OUTPUT:
    return "writing to output (file,stdout,etc.) was not succesful.";
  default:
    return "unknown status code.";
  }
}
#endif
