/*
 * semantic-version.c - Simple semantic version support for C.
 * Copyright (C) 2017 Tommy M. McGuire
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "semantic-version.h"

static const char identifier[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" \
                                 "abcdefghijklmnopqrstuvwxyz" \
                                 "0123456789-";

#define MIN(x,y) ((x) < (y) ? (x) : (y))

static int
read_identifiers(const char *string, char **end, char *dest)
{
  const char *s = string;
  while (s == string || *s == '.') {
    if (*s == '.') {
      s++;
    }
    size_t count = strspn(s, identifier);
    if (count < 1) {
      return SEMVER_INVALID;
    }
    s += count;
  }
  *end = (char *) s;
  size_t count = MIN(*end - string, SEMVER_BUFFER_SZ - 1);
  memcpy(dest, string, count);
  dest[count] = '\0';
  return 0;
}

int
semver_parse(struct semver *s, const char *string)
{
  char *next;
  s->major = strtoul(string, &next, 10);
  if (*next != '.') {
    return SEMVER_INVALID;
  }
  s->minor = strtoul(next + 1, &next, 10);
  if (*next != '.') {
    return SEMVER_INVALID;
  }
  s->patch = strtoul(next + 1, &next, 10);
  /* pre-release version */
  if (*next == '-') {
    if (read_identifiers(next + 1, &next, s->prerelease)) {
      return SEMVER_INVALID;
    }
  } else {
    s->prerelease[0] = '\0';
  }
  /* build metadata */
  if (*next == '+') {
    if (read_identifiers(next + 1, &next, s->metadata)) {
      return SEMVER_INVALID;
    }
  } else {
    s->metadata[0] = '\0';
  }
  if (*next != '\0') {
    return SEMVER_INVALID;
  } else {
    return 0;
  }
}

int
semver_cmp(const struct semver *s1, const struct semver *s2)
{
  if (s1->major < s2->major) {
    return -1;
  } else if (s1->major > s2->major) {
    return 1;
  }
  /* major numbers are equal */
  if (s1->minor < s2->minor) {
    return -1;
  } else if (s1->minor > s2->minor) {
    return 1;
  }
  /* minor numbers are equal */
  if (s1->patch < s2->patch) {
    return -1;
  } else if (s1->patch > s2->patch) {
    return 1;
  }
  /* patch numbers are equal */
  return strcmp(s1->prerelease, s2->prerelease);
}
