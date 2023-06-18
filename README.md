# wildcard (bash)
#### goal:
This project aim to recreate the comportement of wildcard \* and exclamation mark ?<br>
In bash wildcard replace from 0 to an infinite of typeface and the exclamation mark substitute only one typeface<br>
```
~> ls
test.c  test.h  MAKEFILE  test_ext.c
~> echo *
test.c  test.h  MAKEFILE  test_ext.c
~> echo *.c
test.c  test_ext.c
~> echo *.?
test.c  test.h  test_ext.c
~> echo .*
. ..
```
