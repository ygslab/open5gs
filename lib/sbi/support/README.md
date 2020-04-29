
* Install JDK, maven, and cmake
$ sudo apt install default-jdk maven cmake

* Setup OpenAPI Generator
$ git clone https://github.com/OpenAPITools/openapi-generator.git
$ cd openapi-generator
$ mvn clean package

* Generate JSON build/parser
$ cd /home/acetcom/Documents/git/open5gs/lib/sbi/support
$ java -jar ${HOME}/Documents/git/my/openapi-generator/modules/openapi-generator-cli/target/openapi-generator-cli.jar validate -i ./openapi/TS29510_Nnrf_NFManagement.yaml
$ java -jar ${HOME}/Documents/git/my/openapi-generator/modules/openapi-generator-cli/target/openapi-generator-cli.jar generate -g c -o out -i ./openapi/TS29510_Nnrf_NFManagement.yaml

* Using NPM
$ C_POST_PROCESS_FILE=/usr/bin/uncrustify --no-backup
$ npm install @openapitools/openapi-generator-cli -g
$ npx openapi-generator generate -i ./openapi/TS29510_Nnrf_NFManagement.yaml -g c -o out
