#!/bin/sh

EMCC="~/.emsdk/emscripten/1.35.0/emcc"
SRC_DIR="./src/models"
DST_DIR="./src/public"

${EMCC} -O1 --bind -o ${DST_DIR}/models.js ${SRC_DIR}/todo.cpp
