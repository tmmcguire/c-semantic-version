#include <stdio.h>
#include <string.h>

#include "semantic-version.h"

const char *
test_correct()
{
  struct semver ver;
  int res = semver_parse(&ver, "1.0.0");
  if (res != 0 ||
      ver.major != 1 || ver.minor != 0 || ver.patch != 0 ||
      *ver.prerelease != '\0' || *ver.metadata != '\0') {
    return "unable to parse 1.0.0";
  }
  res = semver_parse(&ver, "1.0.0-test");
  if (res != 0 ||
      ver.major != 1 || ver.minor != 0 || ver.patch != 0 ||
      strncmp(ver.prerelease, "test", SEMVER_BUFFER_SZ) != 0 ||
      *ver.metadata != '\0') {
    return "unable to parse 1.0.0-test";
  }
  res = semver_parse(&ver, "1.0.0+test");
  if (res != 0 ||
      ver.major != 1 || ver.minor != 0 || ver.patch != 0 ||
      strncmp(ver.metadata, "test", SEMVER_BUFFER_SZ) != 0 ||
      *ver.prerelease != '\0') {
    return "unable to parse 1.0.0+test";
  }
  res = semver_parse(&ver, "1.0.0-test1+test");
  if (res != 0 ||
      ver.major != 1 || ver.minor != 0 || ver.patch != 0 ||
      strncmp(ver.prerelease, "test1", SEMVER_BUFFER_SZ) != 0 ||
      strncmp(ver.metadata, "test", SEMVER_BUFFER_SZ) != 0) {
    return "unable to parse 1.0.0-test1+test";
  }
  return 0;
}

int
main(int argc, char *argv[])
{
  const char * msg = test_correct();
  if (msg) {
    printf("%s\n", msg);
  }
  return 0;
}
