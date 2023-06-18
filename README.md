# wildcard (bash)
This project aim to recreate the comportement of wildcard \* and exclamation mark ?<br>
In bash, wildcard replace from 0 to an infinite of typeface and the exclamation mark substitute only one typeface<br>
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
~> echo /*
bin   etc      lib    libx32      mnt  proc  sbin      srv       tmp
boot  goinfre  lib32  lost+found  nfs  root  sgoinfre  usr       dev   
home  lib64    media  opt         run  snap  sys       var
```
note: when first typeface is . it return hidden files and when it's / it return files from root<br>
The result is sort alphabeticly
```
~> echo *
Da/ Dtest/  test.c
~> echo D*/*
Da/alpha  Da/beta Da/gamma  Dtest/ba  Dtest/bb  Dtest/bc
~>echo D*/??
Dtest/ba  Dtest/bb  Dtest/bc
```
Prototype of wildcard
```
char	**wildcard(char *str);
```
It takes a string with wildcard or exclamation mark (ex:&nbsp;&nbsp;te\*st&nbsp;&nbsp;&nbsp;&nbsp;\*&nbsp;&nbsp;&nbsp;&nbsp;file.?&nbsp;&nbsp;&nbsp;&nbsp;??\*?&nbsp;&nbsp;&nbsp;&nbsp;/\*)<br>
And return an array of string (NULL terminated) of the name of all files witch match with *str*<br>
#### Man
* `make` &nbsp;&nbsp; --> &nbsp;&nbsp;compile a library "*libwildcard.a*"
* `make test` &nbsp;&nbsp; --> &nbsp;&nbsp;compile the C file test.c to test the function into "*test*"
* `make clean` &nbsp;&nbsp; --> &nbsp;&nbsp;delete .o files
* `make fclean` &nbsp;&nbsp; --> &nbsp;&nbsp;delete .o files, the library and test
<br><br>Date: 18 Jun 2023
