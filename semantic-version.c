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

#include "semantic-version.h"

int
semver_parse(struct semver *s, const char *string)
{
  return 0;
}

int
semver_cmp(const struct semver *s1, const struct semver *s2)
{
  return 0;
}

static uint32_t
numeric_element(const char *string)
{
  const char *c = string;
  while (isdigit(*c)) {
    c++;
  }
  return 0;
}
