#!/bin/zsh
# alias antlr4='java -Xmx500M -cp "/usr/local/lib/antlr-4.9.3-complete.jar:$CLASSPATH" org.antlr.v4.Tool'
# antlr4 -Dlanguage=Cpp Mdb.g4 -o autogenerated -no-listener -visitor
# rm -r autogenerated/*.cc
# java -Xmx500M -cp "/usr/local/lib/antlr-4.9.3-complete.jar:$CLASSPATH" org.antlr.v4.Tool -Dlanguage=Cpp Mdb.g4 -o autogenerated -no-listener -visitor
# autoload zmv
# zmv 'autogenerated/(*).cpp' autogenerated/'$1.cc'

rm -r autogenerated/*.cc
java -Xmx500M -cp "/usr/local/lib/antlr-4.9.3-complete.jar:$CLASSPATH" org.antlr.v4.Tool -Dlanguage=Cpp MDBLexer.g4 -o autogenerated -no-listener -visitor
java -Xmx500M -cp "/usr/local/lib/antlr-4.9.3-complete.jar:$CLASSPATH" org.antlr.v4.Tool -Dlanguage=Cpp MDBParser.g4 -o autogenerated -no-listener -visitor
autoload zmv
zmv 'autogenerated/(*).cpp' autogenerated/'$1.cc'