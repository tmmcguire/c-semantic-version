# c-semantic-version

Semantic Versioning 2.0.0 library for C

This library allows parsing and comparing semantic version strings. See [Semantic Versioning 2.0.0](http://semver.org/spec/v2.0.0.html)
for the format of version strings.

## Example usage

```c
  struct semver ver1, ver2;
  if (semver_parse(&ver1, "1.0.0")) {
    printf("Error!");
  }
  if (semver_parse(&ver2, "1.0.2")) {
    printf("A different error!");
  }
  if (semver_cmp(&ver1, &ver2) == -1) {
    printf("Smaller!");
  }
```
