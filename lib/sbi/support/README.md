
* Install JDK, maven, and cmake
$ sudo apt install default-jdk maven cmake

* Setup OpenAPI Generator
$ git clone https://github.com/OpenAPITools/openapi-generator.git
$ cd openapi-generator
$ mvn clean package

* Generate JSON build/parser
$ cd /home/acetcom/Documents/git/open5gs/lib/sbi/support/openapi
$ java -jar ${HOME}/Documents/git/my/openapi-generator/modules/openapi-generator-cli/target/openapi-generator-cli.jar validate -i ./TS29510_Nnrf_NFManagement.yaml
$ java -jar ${HOME}/Documents/git/my/openapi-generator/modules/openapi-generator-cli/target/openapi-generator-cli.jar generate -g c -o out -i ./TS29510_Nnrf_NFManagement.yaml
