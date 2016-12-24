#!/bin/sh

EMCC="/Users/edwardkenfox/.emsdk/emscripten/1.35.0/emcc"
DST_DIR="./public"
SRC_DIR="./src/domain"

${EMCC} -O1 --bind -o ${DST_DIR}/todo.js ${SRC_DIR}/todo.cpp
