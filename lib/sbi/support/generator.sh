#!/bin/sh

export C_POST_PROCESS_FILE="/usr/bin/uncrustify --no-backup"
export UNCRUSTIFY_CONFIG=/home/acetcom/Documents/git/open5gs/lib/sbi/.openapi-generator/uncrustify/default.cfg
openapi_generator_cli="java -jar ${HOME}/Documents/git/my/openapi-generator/modules/openapi-generator-cli/target/openapi-generator-cli.jar"

$openapi_generator_cli generate -i ./modified/TS29510_Nnrf_NFManagement.yaml -c ../.openapi-generator/config.yaml -g c -o ..
#$openapi_generator_cli generate -i ./modified/TS29510_Nnrf_NFManagement.yaml -g java -o ~/java
#$openapi_generator_cli generate -i ./modified/TS29510_Nnrf_NFManagement.yaml -g cpp-restsdk -o ~/cpp-restsdk
