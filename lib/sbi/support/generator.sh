#!/bin/sh

C_POST_PROCESS_FILE="/usr/bin/uncrustify --no-backup"
openapi_generator_cli="java -jar ${HOME}/Documents/git/my/openapi-generator/modules/openapi-generator-cli/target/openapi-generator-cli.jar"

$openapi_generator_cli generate -i ./modified/TS29510_Nnrf_NFManagement.yaml -g c -o ..
cp list.c ../src
