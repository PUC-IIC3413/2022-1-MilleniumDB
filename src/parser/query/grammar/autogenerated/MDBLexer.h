
// Generated from MDBLexer.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  MDBLexer : public antlr4::Lexer {
public:
  enum {
    K_ANY = 1, K_AND = 2, K_AVG = 3, K_ALL = 4, K_ASC = 5, K_BY = 6, K_BOOL = 7, 
    K_COUNT = 8, K_DESCRIBE = 9, K_DESC = 10, K_DISTINCT = 11, K_IS = 12, 
    K_INTEGER = 13, K_FALSE = 14, K_FLOAT = 15, K_GROUP = 16, K_LIMIT = 17, 
    K_MAX = 18, K_MATCH = 19, K_MIN = 20, K_OPTIONAL = 21, K_ORDER = 22, 
    K_OR = 23, K_NOT = 24, K_NULL = 25, K_SUM = 26, K_STRING = 27, K_RETURN = 28, 
    K_TRUE = 29, K_WHERE = 30, TRUE_PROP = 31, FALSE_PROP = 32, TRUE_PARENTHESIS = 33, 
    FALSE_PARENTHESIS = 34, ANON_NODE = 35, EDGE_NODE = 36, EDGE_ID = 37, 
    KEY = 38, TYPE = 39, TYPE_VAR = 40, VARIABLE = 41, STRING = 42, UNSIGNED_INTEGER = 43, 
    UNSIGNED_FLOAT = 44, NAME = 45, LEQ = 46, GEQ = 47, EQ = 48, NEQ = 49, 
    LT = 50, GT = 51, SINGLE_EQ = 52, PATH_SEQUENCE = 53, PATH_ALTERNATIVE = 54, 
    PATH_NEGATION = 55, STAR = 56, PERCENT = 57, QUESTION_MARK = 58, PLUS = 59, 
    MINUS = 60, L_PAR = 61, R_PAR = 62, LCURLY_BRACKET = 63, RCURLY_BRACKET = 64, 
    LSQUARE_BRACKET = 65, RSQUARE_BRACKET = 66, COMMA = 67, COLON = 68, 
    WHITE_SPACE = 69, SINGLE_LINE_COMMENT = 70, UNRECOGNIZED = 71
  };

  enum {
    WS_CHANNEL = 2
  };

  explicit MDBLexer(antlr4::CharStream *input);
  ~MDBLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

