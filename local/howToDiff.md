
## Use recursive, unified, ignore whitespace ... and filter missing files

```
diff -ruw ../quantlib/ql/ src/ql/  | grep -v "^Only in"
```


## For just the file list use 'q' not 'u':

```
diff -rqw ../quantlib/ql/ src/ql/  | grep -v "^Only in"
```


## Shell script to diff files that can differ (keeping track of blacklist)

```
local/runDiff.sh
```


## Shell script for colordiff on given file (without leading ql/ in path)

```
local/diffFile.sh qldefines.hpp
```
