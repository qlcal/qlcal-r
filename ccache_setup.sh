#!/bin/bash

test -d ${HOME}/.R || mkdir ${HOME}/.R

cat <<EOF > ${HOME}/.R/Makevars
CC=ccache gcc -std=gnu2x
CC17=ccache gcc -std=gnu17
CC23=ccache gcc -std=gnu2x
CC90=ccache gcc -std=gnu90
CC99=ccache gcc -std=gnu99
CXX=ccache g++
CXX11=ccache g++ #-std=c++11
CXX14=ccache g++ #-std=c++14
CXX17=ccache g++ #-std=c++17
CXX20=ccache g++ #-std=c++20
CXX23=ccache g++ #-std=c++23
EOF

test -d ${HOME}/.config/ccache || mkdir -pv ${HOME}/.config/ccache

cfgfile=${HOME}/.config/ccache/ccache.conf
## test -f ${cfgfile} && echo "** Have ccache.conf" && cat ${cfgfile}

cat <<EOF > ${cfgfile}
# set base directory
base_dir = $(pwd)
# set cache location directory
cache_dir = $(pwd)/.ccache
# set max size, this is also the default value at GH
max_size = 10G
# important for R CMD INSTALL *.tar.gz as tarballs are expanded freshly -> fresh ctime
sloppiness = include_file_ctime
# also important as the (temporary) directory name will differ
hash_dir = false
EOF

## test -f ${cfgfile} && echo "** Now have ccache.conf" && cat ${cfgfile}
