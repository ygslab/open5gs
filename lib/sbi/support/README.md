
* Install JDK, maven, and cmake
$ sudo apt install default-jdk maven cmake

* Setup OpenAPI Generator
$ git clone https://github.com/OpenAPITools/openapi-generator.git
$ cd openapi-generator
$ mvn clean package

* Using NPM
$ export C_POST_PROCESS_FILE="/usr/bin/uncrustify --no-backup"
$ npm install @openapitools/openapi-generator-cli -g
$ npx openapi-generator generate -i ./modified/TS29510_Nnrf_NFManagement.yaml -g c -o ..

* Generate JSON build/parser Using JAVA
$ cd /home/acetcom/Documents/git/open5gs/lib/sbi/support
$ java -jar ${HOME}/Documents/git/my/openapi-generator/modules/openapi-generator-cli/target/openapi-generator-cli.jar validate -i ./3gpp-spec/TS29510_Nnrf_NFManagement.yaml
$ java -jar ${HOME}/Documents/git/my/openapi-generator/modules/openapi-generator-cli/target/openapi-generator-cli.jar generate -i ./modified/TS29510_Nnrf_NFManagement.yaml -g c -o ..

