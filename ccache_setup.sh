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

ls -a
test -d .ccache || mkdir -pv .ccache

cat <<EOF > .ccache/ccache.conf
base_dir = $(pwd)
cache_dir = $(pwd)/.ccache
max_size = 9.87G
# important for R CMD INSTALL *.tar.gz as tarballs are expanded freshly -> fresh ctime
sloppiness = include_file_ctime
# also important as the (temp.) directory name will differ
hash_dir = false
EOF
