
// Generated from MDBParser.g4 by ANTLR 4.9.3


#include "MDBParserVisitor.h"

#include "MDBParser.h"


using namespace antlrcpp;
using namespace antlr4;

MDBParser::MDBParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MDBParser::~MDBParser() {
  delete _interpreter;
}

std::string MDBParser::getGrammarFileName() const {
  return "MDBParser.g4";
}

const std::vector<std::string>& MDBParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MDBParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- RootContext ------------------------------------------------------------------

MDBParser::RootContext::RootContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MDBParser::MatchStatementContext* MDBParser::RootContext::matchStatement() {
  return getRuleContext<MDBParser::MatchStatementContext>(0);
}

MDBParser::ReturnStatementContext* MDBParser::RootContext::returnStatement() {
  return getRuleContext<MDBParser::ReturnStatementContext>(0);
}

tree::TerminalNode* MDBParser::RootContext::EOF() {
  return getToken(MDBParser::EOF, 0);
}

MDBParser::WhereStatementContext* MDBParser::RootContext::whereStatement() {
  return getRuleContext<MDBParser::WhereStatementContext>(0);
}

MDBParser::GroupByStatementContext* MDBParser::RootContext::groupByStatement() {
  return getRuleContext<MDBParser::GroupByStatementContext>(0);
}

MDBParser::OrderByStatementContext* MDBParser::RootContext::orderByStatement() {
  return getRuleContext<MDBParser::OrderByStatementContext>(0);
}

MDBParser::DescribeStatementContext* MDBParser::RootContext::describeStatement() {
  return getRuleContext<MDBParser::DescribeStatementContext>(0);
}


size_t MDBParser::RootContext::getRuleIndex() const {
  return MDBParser::RuleRoot;
}


antlrcpp::Any MDBParser::RootContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitRoot(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::RootContext* MDBParser::root() {
  RootContext *_localctx = _tracker.createInstance<RootContext>(_ctx, getState());
  enterRule(_localctx, 0, MDBParser::RuleRoot);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(104);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MDBParser::K_MATCH: {
        enterOuterAlt(_localctx, 1);
        setState(88);
        matchStatement();
        setState(90);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::K_WHERE) {
          setState(89);
          whereStatement();
        }
        setState(93);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::K_GROUP) {
          setState(92);
          groupByStatement();
        }
        setState(96);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::K_ORDER) {
          setState(95);
          orderByStatement();
        }
        setState(98);
        returnStatement();
        setState(99);
        match(MDBParser::EOF);
        break;
      }

      case MDBParser::K_DESCRIBE: {
        enterOuterAlt(_localctx, 2);
        setState(101);
        describeStatement();
        setState(102);
        match(MDBParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DescribeStatementContext ------------------------------------------------------------------

MDBParser::DescribeStatementContext::DescribeStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::DescribeStatementContext::K_DESCRIBE() {
  return getToken(MDBParser::K_DESCRIBE, 0);
}

MDBParser::FixedNodeContext* MDBParser::DescribeStatementContext::fixedNode() {
  return getRuleContext<MDBParser::FixedNodeContext>(0);
}


size_t MDBParser::DescribeStatementContext::getRuleIndex() const {
  return MDBParser::RuleDescribeStatement;
}


antlrcpp::Any MDBParser::DescribeStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitDescribeStatement(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::DescribeStatementContext* MDBParser::describeStatement() {
  DescribeStatementContext *_localctx = _tracker.createInstance<DescribeStatementContext>(_ctx, getState());
  enterRule(_localctx, 2, MDBParser::RuleDescribeStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    match(MDBParser::K_DESCRIBE);
    setState(107);
    fixedNode();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatchStatementContext ------------------------------------------------------------------

MDBParser::MatchStatementContext::MatchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::MatchStatementContext::K_MATCH() {
  return getToken(MDBParser::K_MATCH, 0);
}

MDBParser::GraphPatternContext* MDBParser::MatchStatementContext::graphPattern() {
  return getRuleContext<MDBParser::GraphPatternContext>(0);
}


size_t MDBParser::MatchStatementContext::getRuleIndex() const {
  return MDBParser::RuleMatchStatement;
}


antlrcpp::Any MDBParser::MatchStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitMatchStatement(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::MatchStatementContext* MDBParser::matchStatement() {
  MatchStatementContext *_localctx = _tracker.createInstance<MatchStatementContext>(_ctx, getState());
  enterRule(_localctx, 4, MDBParser::RuleMatchStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    match(MDBParser::K_MATCH);
    setState(110);
    graphPattern();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhereStatementContext ------------------------------------------------------------------

MDBParser::WhereStatementContext::WhereStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::WhereStatementContext::K_WHERE() {
  return getToken(MDBParser::K_WHERE, 0);
}

MDBParser::ExprContext* MDBParser::WhereStatementContext::expr() {
  return getRuleContext<MDBParser::ExprContext>(0);
}


size_t MDBParser::WhereStatementContext::getRuleIndex() const {
  return MDBParser::RuleWhereStatement;
}


antlrcpp::Any MDBParser::WhereStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitWhereStatement(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::WhereStatementContext* MDBParser::whereStatement() {
  WhereStatementContext *_localctx = _tracker.createInstance<WhereStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, MDBParser::RuleWhereStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    match(MDBParser::K_WHERE);
    setState(113);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GroupByStatementContext ------------------------------------------------------------------

MDBParser::GroupByStatementContext::GroupByStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::GroupByStatementContext::K_GROUP() {
  return getToken(MDBParser::K_GROUP, 0);
}

tree::TerminalNode* MDBParser::GroupByStatementContext::K_BY() {
  return getToken(MDBParser::K_BY, 0);
}

std::vector<MDBParser::GroupByItemContext *> MDBParser::GroupByStatementContext::groupByItem() {
  return getRuleContexts<MDBParser::GroupByItemContext>();
}

MDBParser::GroupByItemContext* MDBParser::GroupByStatementContext::groupByItem(size_t i) {
  return getRuleContext<MDBParser::GroupByItemContext>(i);
}

std::vector<tree::TerminalNode *> MDBParser::GroupByStatementContext::COMMA() {
  return getTokens(MDBParser::COMMA);
}

tree::TerminalNode* MDBParser::GroupByStatementContext::COMMA(size_t i) {
  return getToken(MDBParser::COMMA, i);
}


size_t MDBParser::GroupByStatementContext::getRuleIndex() const {
  return MDBParser::RuleGroupByStatement;
}


antlrcpp::Any MDBParser::GroupByStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitGroupByStatement(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::GroupByStatementContext* MDBParser::groupByStatement() {
  GroupByStatementContext *_localctx = _tracker.createInstance<GroupByStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, MDBParser::RuleGroupByStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(MDBParser::K_GROUP);
    setState(116);
    match(MDBParser::K_BY);
    setState(117);
    groupByItem();
    setState(122);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MDBParser::COMMA) {
      setState(118);
      match(MDBParser::COMMA);
      setState(119);
      groupByItem();
      setState(124);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrderByStatementContext ------------------------------------------------------------------

MDBParser::OrderByStatementContext::OrderByStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::OrderByStatementContext::K_ORDER() {
  return getToken(MDBParser::K_ORDER, 0);
}

tree::TerminalNode* MDBParser::OrderByStatementContext::K_BY() {
  return getToken(MDBParser::K_BY, 0);
}

std::vector<MDBParser::OrderByItemContext *> MDBParser::OrderByStatementContext::orderByItem() {
  return getRuleContexts<MDBParser::OrderByItemContext>();
}

MDBParser::OrderByItemContext* MDBParser::OrderByStatementContext::orderByItem(size_t i) {
  return getRuleContext<MDBParser::OrderByItemContext>(i);
}

std::vector<tree::TerminalNode *> MDBParser::OrderByStatementContext::COMMA() {
  return getTokens(MDBParser::COMMA);
}

tree::TerminalNode* MDBParser::OrderByStatementContext::COMMA(size_t i) {
  return getToken(MDBParser::COMMA, i);
}


size_t MDBParser::OrderByStatementContext::getRuleIndex() const {
  return MDBParser::RuleOrderByStatement;
}


antlrcpp::Any MDBParser::OrderByStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitOrderByStatement(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::OrderByStatementContext* MDBParser::orderByStatement() {
  OrderByStatementContext *_localctx = _tracker.createInstance<OrderByStatementContext>(_ctx, getState());
  enterRule(_localctx, 10, MDBParser::RuleOrderByStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    match(MDBParser::K_ORDER);
    setState(126);
    match(MDBParser::K_BY);
    setState(127);
    orderByItem();
    setState(132);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MDBParser::COMMA) {
      setState(128);
      match(MDBParser::COMMA);
      setState(129);
      orderByItem();
      setState(134);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

MDBParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MDBParser::ReturnStatementContext::getRuleIndex() const {
  return MDBParser::RuleReturnStatement;
}

void MDBParser::ReturnStatementContext::copyFrom(ReturnStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ReturnAllContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::ReturnAllContext::K_RETURN() {
  return getToken(MDBParser::K_RETURN, 0);
}

tree::TerminalNode* MDBParser::ReturnAllContext::STAR() {
  return getToken(MDBParser::STAR, 0);
}

tree::TerminalNode* MDBParser::ReturnAllContext::K_DISTINCT() {
  return getToken(MDBParser::K_DISTINCT, 0);
}

tree::TerminalNode* MDBParser::ReturnAllContext::K_LIMIT() {
  return getToken(MDBParser::K_LIMIT, 0);
}

tree::TerminalNode* MDBParser::ReturnAllContext::UNSIGNED_INTEGER() {
  return getToken(MDBParser::UNSIGNED_INTEGER, 0);
}

MDBParser::ReturnAllContext::ReturnAllContext(ReturnStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::ReturnAllContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitReturnAll(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnListContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::ReturnListContext::K_RETURN() {
  return getToken(MDBParser::K_RETURN, 0);
}

std::vector<MDBParser::ReturnItemContext *> MDBParser::ReturnListContext::returnItem() {
  return getRuleContexts<MDBParser::ReturnItemContext>();
}

MDBParser::ReturnItemContext* MDBParser::ReturnListContext::returnItem(size_t i) {
  return getRuleContext<MDBParser::ReturnItemContext>(i);
}

tree::TerminalNode* MDBParser::ReturnListContext::K_DISTINCT() {
  return getToken(MDBParser::K_DISTINCT, 0);
}

std::vector<tree::TerminalNode *> MDBParser::ReturnListContext::COMMA() {
  return getTokens(MDBParser::COMMA);
}

tree::TerminalNode* MDBParser::ReturnListContext::COMMA(size_t i) {
  return getToken(MDBParser::COMMA, i);
}

tree::TerminalNode* MDBParser::ReturnListContext::K_LIMIT() {
  return getToken(MDBParser::K_LIMIT, 0);
}

tree::TerminalNode* MDBParser::ReturnListContext::UNSIGNED_INTEGER() {
  return getToken(MDBParser::UNSIGNED_INTEGER, 0);
}

MDBParser::ReturnListContext::ReturnListContext(ReturnStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::ReturnListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitReturnList(this);
  else
    return visitor->visitChildren(this);
}
MDBParser::ReturnStatementContext* MDBParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, MDBParser::RuleReturnStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(160);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MDBParser::ReturnListContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(135);
      match(MDBParser::K_RETURN);
      setState(137);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MDBParser::K_DISTINCT) {
        setState(136);
        match(MDBParser::K_DISTINCT);
      }
      setState(139);
      returnItem();
      setState(144);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MDBParser::COMMA) {
        setState(140);
        match(MDBParser::COMMA);
        setState(141);
        returnItem();
        setState(146);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(149);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MDBParser::K_LIMIT) {
        setState(147);
        match(MDBParser::K_LIMIT);
        setState(148);
        match(MDBParser::UNSIGNED_INTEGER);
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MDBParser::ReturnAllContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(151);
      match(MDBParser::K_RETURN);
      setState(153);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MDBParser::K_DISTINCT) {
        setState(152);
        match(MDBParser::K_DISTINCT);
      }
      setState(155);
      match(MDBParser::STAR);
      setState(158);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MDBParser::K_LIMIT) {
        setState(156);
        match(MDBParser::K_LIMIT);
        setState(157);
        match(MDBParser::UNSIGNED_INTEGER);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnItemContext ------------------------------------------------------------------

MDBParser::ReturnItemContext::ReturnItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MDBParser::ReturnItemContext::getRuleIndex() const {
  return MDBParser::RuleReturnItem;
}

void MDBParser::ReturnItemContext::copyFrom(ReturnItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ReturnItemVarContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::ReturnItemVarContext::VARIABLE() {
  return getToken(MDBParser::VARIABLE, 0);
}

tree::TerminalNode* MDBParser::ReturnItemVarContext::KEY() {
  return getToken(MDBParser::KEY, 0);
}

MDBParser::ReturnItemVarContext::ReturnItemVarContext(ReturnItemContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::ReturnItemVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitReturnItemVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnItemAggContext ------------------------------------------------------------------

MDBParser::AggregateFuncContext* MDBParser::ReturnItemAggContext::aggregateFunc() {
  return getRuleContext<MDBParser::AggregateFuncContext>(0);
}

tree::TerminalNode* MDBParser::ReturnItemAggContext::L_PAR() {
  return getToken(MDBParser::L_PAR, 0);
}

tree::TerminalNode* MDBParser::ReturnItemAggContext::VARIABLE() {
  return getToken(MDBParser::VARIABLE, 0);
}

tree::TerminalNode* MDBParser::ReturnItemAggContext::R_PAR() {
  return getToken(MDBParser::R_PAR, 0);
}

tree::TerminalNode* MDBParser::ReturnItemAggContext::KEY() {
  return getToken(MDBParser::KEY, 0);
}

MDBParser::ReturnItemAggContext::ReturnItemAggContext(ReturnItemContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::ReturnItemAggContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitReturnItemAgg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnItemCountContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::ReturnItemCountContext::K_COUNT() {
  return getToken(MDBParser::K_COUNT, 0);
}

tree::TerminalNode* MDBParser::ReturnItemCountContext::L_PAR() {
  return getToken(MDBParser::L_PAR, 0);
}

tree::TerminalNode* MDBParser::ReturnItemCountContext::R_PAR() {
  return getToken(MDBParser::R_PAR, 0);
}

tree::TerminalNode* MDBParser::ReturnItemCountContext::VARIABLE() {
  return getToken(MDBParser::VARIABLE, 0);
}

tree::TerminalNode* MDBParser::ReturnItemCountContext::STAR() {
  return getToken(MDBParser::STAR, 0);
}

tree::TerminalNode* MDBParser::ReturnItemCountContext::K_DISTINCT() {
  return getToken(MDBParser::K_DISTINCT, 0);
}

tree::TerminalNode* MDBParser::ReturnItemCountContext::KEY() {
  return getToken(MDBParser::KEY, 0);
}

MDBParser::ReturnItemCountContext::ReturnItemCountContext(ReturnItemContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::ReturnItemCountContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitReturnItemCount(this);
  else
    return visitor->visitChildren(this);
}
MDBParser::ReturnItemContext* MDBParser::returnItem() {
  ReturnItemContext *_localctx = _tracker.createInstance<ReturnItemContext>(_ctx, getState());
  enterRule(_localctx, 14, MDBParser::RuleReturnItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(187);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MDBParser::VARIABLE: {
        _localctx = _tracker.createInstance<MDBParser::ReturnItemVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(162);
        match(MDBParser::VARIABLE);
        setState(164);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::KEY) {
          setState(163);
          match(MDBParser::KEY);
        }
        break;
      }

      case MDBParser::K_AVG:
      case MDBParser::K_MAX:
      case MDBParser::K_MIN:
      case MDBParser::K_SUM: {
        _localctx = _tracker.createInstance<MDBParser::ReturnItemAggContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(166);
        aggregateFunc();
        setState(167);
        match(MDBParser::L_PAR);
        setState(168);
        match(MDBParser::VARIABLE);
        setState(170);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::KEY) {
          setState(169);
          match(MDBParser::KEY);
        }
        setState(172);
        match(MDBParser::R_PAR);
        break;
      }

      case MDBParser::K_COUNT: {
        _localctx = _tracker.createInstance<MDBParser::ReturnItemCountContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(174);
        match(MDBParser::K_COUNT);
        setState(175);
        match(MDBParser::L_PAR);
        setState(177);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::K_DISTINCT) {
          setState(176);
          match(MDBParser::K_DISTINCT);
        }
        setState(184);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case MDBParser::VARIABLE: {
            setState(179);
            match(MDBParser::VARIABLE);
            setState(181);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == MDBParser::KEY) {
              setState(180);
              match(MDBParser::KEY);
            }
            break;
          }

          case MDBParser::STAR: {
            setState(183);
            match(MDBParser::STAR);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(186);
        match(MDBParser::R_PAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AggregateFuncContext ------------------------------------------------------------------

MDBParser::AggregateFuncContext::AggregateFuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::AggregateFuncContext::K_SUM() {
  return getToken(MDBParser::K_SUM, 0);
}

tree::TerminalNode* MDBParser::AggregateFuncContext::K_MAX() {
  return getToken(MDBParser::K_MAX, 0);
}

tree::TerminalNode* MDBParser::AggregateFuncContext::K_MIN() {
  return getToken(MDBParser::K_MIN, 0);
}

tree::TerminalNode* MDBParser::AggregateFuncContext::K_AVG() {
  return getToken(MDBParser::K_AVG, 0);
}


size_t MDBParser::AggregateFuncContext::getRuleIndex() const {
  return MDBParser::RuleAggregateFunc;
}


antlrcpp::Any MDBParser::AggregateFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitAggregateFunc(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::AggregateFuncContext* MDBParser::aggregateFunc() {
  AggregateFuncContext *_localctx = _tracker.createInstance<AggregateFuncContext>(_ctx, getState());
  enterRule(_localctx, 16, MDBParser::RuleAggregateFunc);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MDBParser::K_AVG)
      | (1ULL << MDBParser::K_MAX)
      | (1ULL << MDBParser::K_MIN)
      | (1ULL << MDBParser::K_SUM))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrderByItemContext ------------------------------------------------------------------

MDBParser::OrderByItemContext::OrderByItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MDBParser::OrderByItemContext::getRuleIndex() const {
  return MDBParser::RuleOrderByItem;
}

void MDBParser::OrderByItemContext::copyFrom(OrderByItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- OrderByItemCountContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::OrderByItemCountContext::K_COUNT() {
  return getToken(MDBParser::K_COUNT, 0);
}

tree::TerminalNode* MDBParser::OrderByItemCountContext::L_PAR() {
  return getToken(MDBParser::L_PAR, 0);
}

tree::TerminalNode* MDBParser::OrderByItemCountContext::VARIABLE() {
  return getToken(MDBParser::VARIABLE, 0);
}

tree::TerminalNode* MDBParser::OrderByItemCountContext::R_PAR() {
  return getToken(MDBParser::R_PAR, 0);
}

tree::TerminalNode* MDBParser::OrderByItemCountContext::K_DISTINCT() {
  return getToken(MDBParser::K_DISTINCT, 0);
}

tree::TerminalNode* MDBParser::OrderByItemCountContext::KEY() {
  return getToken(MDBParser::KEY, 0);
}

tree::TerminalNode* MDBParser::OrderByItemCountContext::K_ASC() {
  return getToken(MDBParser::K_ASC, 0);
}

tree::TerminalNode* MDBParser::OrderByItemCountContext::K_DESC() {
  return getToken(MDBParser::K_DESC, 0);
}

MDBParser::OrderByItemCountContext::OrderByItemCountContext(OrderByItemContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::OrderByItemCountContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitOrderByItemCount(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrderByItemVarContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::OrderByItemVarContext::VARIABLE() {
  return getToken(MDBParser::VARIABLE, 0);
}

tree::TerminalNode* MDBParser::OrderByItemVarContext::KEY() {
  return getToken(MDBParser::KEY, 0);
}

tree::TerminalNode* MDBParser::OrderByItemVarContext::K_ASC() {
  return getToken(MDBParser::K_ASC, 0);
}

tree::TerminalNode* MDBParser::OrderByItemVarContext::K_DESC() {
  return getToken(MDBParser::K_DESC, 0);
}

MDBParser::OrderByItemVarContext::OrderByItemVarContext(OrderByItemContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::OrderByItemVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitOrderByItemVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrderByItemAggContext ------------------------------------------------------------------

MDBParser::AggregateFuncContext* MDBParser::OrderByItemAggContext::aggregateFunc() {
  return getRuleContext<MDBParser::AggregateFuncContext>(0);
}

tree::TerminalNode* MDBParser::OrderByItemAggContext::L_PAR() {
  return getToken(MDBParser::L_PAR, 0);
}

tree::TerminalNode* MDBParser::OrderByItemAggContext::VARIABLE() {
  return getToken(MDBParser::VARIABLE, 0);
}

tree::TerminalNode* MDBParser::OrderByItemAggContext::R_PAR() {
  return getToken(MDBParser::R_PAR, 0);
}

tree::TerminalNode* MDBParser::OrderByItemAggContext::KEY() {
  return getToken(MDBParser::KEY, 0);
}

tree::TerminalNode* MDBParser::OrderByItemAggContext::K_ASC() {
  return getToken(MDBParser::K_ASC, 0);
}

tree::TerminalNode* MDBParser::OrderByItemAggContext::K_DESC() {
  return getToken(MDBParser::K_DESC, 0);
}

MDBParser::OrderByItemAggContext::OrderByItemAggContext(OrderByItemContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::OrderByItemAggContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitOrderByItemAgg(this);
  else
    return visitor->visitChildren(this);
}
MDBParser::OrderByItemContext* MDBParser::orderByItem() {
  OrderByItemContext *_localctx = _tracker.createInstance<OrderByItemContext>(_ctx, getState());
  enterRule(_localctx, 18, MDBParser::RuleOrderByItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(221);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MDBParser::VARIABLE: {
        _localctx = _tracker.createInstance<MDBParser::OrderByItemVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(191);
        match(MDBParser::VARIABLE);
        setState(193);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::KEY) {
          setState(192);
          match(MDBParser::KEY);
        }
        setState(196);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::K_ASC

        || _la == MDBParser::K_DESC) {
          setState(195);
          _la = _input->LA(1);
          if (!(_la == MDBParser::K_ASC

          || _la == MDBParser::K_DESC)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        break;
      }

      case MDBParser::K_AVG:
      case MDBParser::K_MAX:
      case MDBParser::K_MIN:
      case MDBParser::K_SUM: {
        _localctx = _tracker.createInstance<MDBParser::OrderByItemAggContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(198);
        aggregateFunc();
        setState(199);
        match(MDBParser::L_PAR);
        setState(200);
        match(MDBParser::VARIABLE);
        setState(202);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::KEY) {
          setState(201);
          match(MDBParser::KEY);
        }
        setState(204);
        match(MDBParser::R_PAR);
        setState(206);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::K_ASC

        || _la == MDBParser::K_DESC) {
          setState(205);
          _la = _input->LA(1);
          if (!(_la == MDBParser::K_ASC

          || _la == MDBParser::K_DESC)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        break;
      }

      case MDBParser::K_COUNT: {
        _localctx = _tracker.createInstance<MDBParser::OrderByItemCountContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(208);
        match(MDBParser::K_COUNT);
        setState(209);
        match(MDBParser::L_PAR);
        setState(211);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::K_DISTINCT) {
          setState(210);
          match(MDBParser::K_DISTINCT);
        }
        setState(213);
        match(MDBParser::VARIABLE);
        setState(215);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::KEY) {
          setState(214);
          match(MDBParser::KEY);
        }
        setState(217);
        match(MDBParser::R_PAR);
        setState(219);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::K_ASC

        || _la == MDBParser::K_DESC) {
          setState(218);
          _la = _input->LA(1);
          if (!(_la == MDBParser::K_ASC

          || _la == MDBParser::K_DESC)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GroupByItemContext ------------------------------------------------------------------

MDBParser::GroupByItemContext::GroupByItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::GroupByItemContext::VARIABLE() {
  return getToken(MDBParser::VARIABLE, 0);
}

tree::TerminalNode* MDBParser::GroupByItemContext::KEY() {
  return getToken(MDBParser::KEY, 0);
}


size_t MDBParser::GroupByItemContext::getRuleIndex() const {
  return MDBParser::RuleGroupByItem;
}


antlrcpp::Any MDBParser::GroupByItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitGroupByItem(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::GroupByItemContext* MDBParser::groupByItem() {
  GroupByItemContext *_localctx = _tracker.createInstance<GroupByItemContext>(_ctx, getState());
  enterRule(_localctx, 20, MDBParser::RuleGroupByItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    match(MDBParser::VARIABLE);
    setState(225);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MDBParser::KEY) {
      setState(224);
      match(MDBParser::KEY);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GraphPatternContext ------------------------------------------------------------------

MDBParser::GraphPatternContext::GraphPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MDBParser::BasicPatternContext* MDBParser::GraphPatternContext::basicPattern() {
  return getRuleContext<MDBParser::BasicPatternContext>(0);
}

std::vector<MDBParser::OptionalPatternContext *> MDBParser::GraphPatternContext::optionalPattern() {
  return getRuleContexts<MDBParser::OptionalPatternContext>();
}

MDBParser::OptionalPatternContext* MDBParser::GraphPatternContext::optionalPattern(size_t i) {
  return getRuleContext<MDBParser::OptionalPatternContext>(i);
}


size_t MDBParser::GraphPatternContext::getRuleIndex() const {
  return MDBParser::RuleGraphPattern;
}


antlrcpp::Any MDBParser::GraphPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitGraphPattern(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::GraphPatternContext* MDBParser::graphPattern() {
  GraphPatternContext *_localctx = _tracker.createInstance<GraphPatternContext>(_ctx, getState());
  enterRule(_localctx, 22, MDBParser::RuleGraphPattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    basicPattern();
    setState(231);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MDBParser::K_OPTIONAL) {
      setState(228);
      optionalPattern();
      setState(233);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OptionalPatternContext ------------------------------------------------------------------

MDBParser::OptionalPatternContext::OptionalPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::OptionalPatternContext::K_OPTIONAL() {
  return getToken(MDBParser::K_OPTIONAL, 0);
}

tree::TerminalNode* MDBParser::OptionalPatternContext::LCURLY_BRACKET() {
  return getToken(MDBParser::LCURLY_BRACKET, 0);
}

MDBParser::GraphPatternContext* MDBParser::OptionalPatternContext::graphPattern() {
  return getRuleContext<MDBParser::GraphPatternContext>(0);
}

tree::TerminalNode* MDBParser::OptionalPatternContext::RCURLY_BRACKET() {
  return getToken(MDBParser::RCURLY_BRACKET, 0);
}


size_t MDBParser::OptionalPatternContext::getRuleIndex() const {
  return MDBParser::RuleOptionalPattern;
}


antlrcpp::Any MDBParser::OptionalPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitOptionalPattern(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::OptionalPatternContext* MDBParser::optionalPattern() {
  OptionalPatternContext *_localctx = _tracker.createInstance<OptionalPatternContext>(_ctx, getState());
  enterRule(_localctx, 24, MDBParser::RuleOptionalPattern);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    match(MDBParser::K_OPTIONAL);
    setState(235);
    match(MDBParser::LCURLY_BRACKET);
    setState(236);
    graphPattern();
    setState(237);
    match(MDBParser::RCURLY_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicPatternContext ------------------------------------------------------------------

MDBParser::BasicPatternContext::BasicPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MDBParser::LinearPatternContext *> MDBParser::BasicPatternContext::linearPattern() {
  return getRuleContexts<MDBParser::LinearPatternContext>();
}

MDBParser::LinearPatternContext* MDBParser::BasicPatternContext::linearPattern(size_t i) {
  return getRuleContext<MDBParser::LinearPatternContext>(i);
}

std::vector<tree::TerminalNode *> MDBParser::BasicPatternContext::COMMA() {
  return getTokens(MDBParser::COMMA);
}

tree::TerminalNode* MDBParser::BasicPatternContext::COMMA(size_t i) {
  return getToken(MDBParser::COMMA, i);
}


size_t MDBParser::BasicPatternContext::getRuleIndex() const {
  return MDBParser::RuleBasicPattern;
}


antlrcpp::Any MDBParser::BasicPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitBasicPattern(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::BasicPatternContext* MDBParser::basicPattern() {
  BasicPatternContext *_localctx = _tracker.createInstance<BasicPatternContext>(_ctx, getState());
  enterRule(_localctx, 26, MDBParser::RuleBasicPattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    linearPattern();
    setState(244);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MDBParser::COMMA) {
      setState(240);
      match(MDBParser::COMMA);
      setState(241);
      linearPattern();
      setState(246);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LinearPatternContext ------------------------------------------------------------------

MDBParser::LinearPatternContext::LinearPatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MDBParser::NodeContext *> MDBParser::LinearPatternContext::node() {
  return getRuleContexts<MDBParser::NodeContext>();
}

MDBParser::NodeContext* MDBParser::LinearPatternContext::node(size_t i) {
  return getRuleContext<MDBParser::NodeContext>(i);
}

std::vector<MDBParser::EdgeContext *> MDBParser::LinearPatternContext::edge() {
  return getRuleContexts<MDBParser::EdgeContext>();
}

MDBParser::EdgeContext* MDBParser::LinearPatternContext::edge(size_t i) {
  return getRuleContext<MDBParser::EdgeContext>(i);
}

std::vector<MDBParser::PathContext *> MDBParser::LinearPatternContext::path() {
  return getRuleContexts<MDBParser::PathContext>();
}

MDBParser::PathContext* MDBParser::LinearPatternContext::path(size_t i) {
  return getRuleContext<MDBParser::PathContext>(i);
}


size_t MDBParser::LinearPatternContext::getRuleIndex() const {
  return MDBParser::RuleLinearPattern;
}


antlrcpp::Any MDBParser::LinearPatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitLinearPattern(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::LinearPatternContext* MDBParser::linearPattern() {
  LinearPatternContext *_localctx = _tracker.createInstance<LinearPatternContext>(_ctx, getState());
  enterRule(_localctx, 28, MDBParser::RuleLinearPattern);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    node();
    setState(256);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MDBParser::LEQ)
      | (1ULL << MDBParser::LT)
      | (1ULL << MDBParser::SINGLE_EQ)
      | (1ULL << MDBParser::MINUS))) != 0)) {
      setState(250);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case MDBParser::LT:
        case MDBParser::MINUS: {
          setState(248);
          edge();
          break;
        }

        case MDBParser::LEQ:
        case MDBParser::SINGLE_EQ: {
          setState(249);
          path();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(252);
      node();
      setState(258);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathContext ------------------------------------------------------------------

MDBParser::PathContext::PathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MDBParser::PathContext::getRuleIndex() const {
  return MDBParser::RulePath;
}

void MDBParser::PathContext::copyFrom(PathContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RightPathContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> MDBParser::RightPathContext::SINGLE_EQ() {
  return getTokens(MDBParser::SINGLE_EQ);
}

tree::TerminalNode* MDBParser::RightPathContext::SINGLE_EQ(size_t i) {
  return getToken(MDBParser::SINGLE_EQ, i);
}

tree::TerminalNode* MDBParser::RightPathContext::LSQUARE_BRACKET() {
  return getToken(MDBParser::LSQUARE_BRACKET, 0);
}

MDBParser::PathAlternativesContext* MDBParser::RightPathContext::pathAlternatives() {
  return getRuleContext<MDBParser::PathAlternativesContext>(0);
}

tree::TerminalNode* MDBParser::RightPathContext::RSQUARE_BRACKET() {
  return getToken(MDBParser::RSQUARE_BRACKET, 0);
}

tree::TerminalNode* MDBParser::RightPathContext::GT() {
  return getToken(MDBParser::GT, 0);
}

MDBParser::PathTypeContext* MDBParser::RightPathContext::pathType() {
  return getRuleContext<MDBParser::PathTypeContext>(0);
}

tree::TerminalNode* MDBParser::RightPathContext::VARIABLE() {
  return getToken(MDBParser::VARIABLE, 0);
}

MDBParser::RightPathContext::RightPathContext(PathContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::RightPathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitRightPath(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LeftPathContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::LeftPathContext::LEQ() {
  return getToken(MDBParser::LEQ, 0);
}

tree::TerminalNode* MDBParser::LeftPathContext::LSQUARE_BRACKET() {
  return getToken(MDBParser::LSQUARE_BRACKET, 0);
}

MDBParser::PathAlternativesContext* MDBParser::LeftPathContext::pathAlternatives() {
  return getRuleContext<MDBParser::PathAlternativesContext>(0);
}

tree::TerminalNode* MDBParser::LeftPathContext::RSQUARE_BRACKET() {
  return getToken(MDBParser::RSQUARE_BRACKET, 0);
}

tree::TerminalNode* MDBParser::LeftPathContext::SINGLE_EQ() {
  return getToken(MDBParser::SINGLE_EQ, 0);
}

MDBParser::PathTypeContext* MDBParser::LeftPathContext::pathType() {
  return getRuleContext<MDBParser::PathTypeContext>(0);
}

tree::TerminalNode* MDBParser::LeftPathContext::VARIABLE() {
  return getToken(MDBParser::VARIABLE, 0);
}

MDBParser::LeftPathContext::LeftPathContext(PathContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::LeftPathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitLeftPath(this);
  else
    return visitor->visitChildren(this);
}
MDBParser::PathContext* MDBParser::path() {
  PathContext *_localctx = _tracker.createInstance<PathContext>(_ctx, getState());
  enterRule(_localctx, 30, MDBParser::RulePath);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(284);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MDBParser::LEQ: {
        _localctx = _tracker.createInstance<MDBParser::LeftPathContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(259);
        match(MDBParser::LEQ);
        setState(260);
        match(MDBParser::LSQUARE_BRACKET);
        setState(262);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::K_ANY

        || _la == MDBParser::K_ALL) {
          setState(261);
          pathType();
        }
        setState(265);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::VARIABLE) {
          setState(264);
          match(MDBParser::VARIABLE);
        }
        setState(267);
        pathAlternatives();
        setState(268);
        match(MDBParser::RSQUARE_BRACKET);
        setState(269);
        match(MDBParser::SINGLE_EQ);
        break;
      }

      case MDBParser::SINGLE_EQ: {
        _localctx = _tracker.createInstance<MDBParser::RightPathContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(271);
        match(MDBParser::SINGLE_EQ);
        setState(272);
        match(MDBParser::LSQUARE_BRACKET);
        setState(274);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::K_ANY

        || _la == MDBParser::K_ALL) {
          setState(273);
          pathType();
        }
        setState(277);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::VARIABLE) {
          setState(276);
          match(MDBParser::VARIABLE);
        }
        setState(279);
        pathAlternatives();
        setState(280);
        match(MDBParser::RSQUARE_BRACKET);
        setState(281);
        match(MDBParser::SINGLE_EQ);
        setState(282);
        match(MDBParser::GT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathAlternativesContext ------------------------------------------------------------------

MDBParser::PathAlternativesContext::PathAlternativesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MDBParser::PathSequenceContext *> MDBParser::PathAlternativesContext::pathSequence() {
  return getRuleContexts<MDBParser::PathSequenceContext>();
}

MDBParser::PathSequenceContext* MDBParser::PathAlternativesContext::pathSequence(size_t i) {
  return getRuleContext<MDBParser::PathSequenceContext>(i);
}

std::vector<tree::TerminalNode *> MDBParser::PathAlternativesContext::PATH_ALTERNATIVE() {
  return getTokens(MDBParser::PATH_ALTERNATIVE);
}

tree::TerminalNode* MDBParser::PathAlternativesContext::PATH_ALTERNATIVE(size_t i) {
  return getToken(MDBParser::PATH_ALTERNATIVE, i);
}


size_t MDBParser::PathAlternativesContext::getRuleIndex() const {
  return MDBParser::RulePathAlternatives;
}


antlrcpp::Any MDBParser::PathAlternativesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitPathAlternatives(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::PathAlternativesContext* MDBParser::pathAlternatives() {
  PathAlternativesContext *_localctx = _tracker.createInstance<PathAlternativesContext>(_ctx, getState());
  enterRule(_localctx, 32, MDBParser::RulePathAlternatives);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    pathSequence();
    setState(291);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MDBParser::PATH_ALTERNATIVE) {
      setState(287);
      match(MDBParser::PATH_ALTERNATIVE);
      setState(288);
      pathSequence();
      setState(293);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathSequenceContext ------------------------------------------------------------------

MDBParser::PathSequenceContext::PathSequenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MDBParser::PathAtomContext *> MDBParser::PathSequenceContext::pathAtom() {
  return getRuleContexts<MDBParser::PathAtomContext>();
}

MDBParser::PathAtomContext* MDBParser::PathSequenceContext::pathAtom(size_t i) {
  return getRuleContext<MDBParser::PathAtomContext>(i);
}

std::vector<tree::TerminalNode *> MDBParser::PathSequenceContext::PATH_SEQUENCE() {
  return getTokens(MDBParser::PATH_SEQUENCE);
}

tree::TerminalNode* MDBParser::PathSequenceContext::PATH_SEQUENCE(size_t i) {
  return getToken(MDBParser::PATH_SEQUENCE, i);
}


size_t MDBParser::PathSequenceContext::getRuleIndex() const {
  return MDBParser::RulePathSequence;
}


antlrcpp::Any MDBParser::PathSequenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitPathSequence(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::PathSequenceContext* MDBParser::pathSequence() {
  PathSequenceContext *_localctx = _tracker.createInstance<PathSequenceContext>(_ctx, getState());
  enterRule(_localctx, 34, MDBParser::RulePathSequence);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    pathAtom();
    setState(299);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MDBParser::PATH_SEQUENCE) {
      setState(295);
      match(MDBParser::PATH_SEQUENCE);
      setState(296);
      pathAtom();
      setState(301);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathAtomContext ------------------------------------------------------------------

MDBParser::PathAtomContext::PathAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MDBParser::PathAtomContext::getRuleIndex() const {
  return MDBParser::RulePathAtom;
}

void MDBParser::PathAtomContext::copyFrom(PathAtomContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PathAtomAlternativesContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::PathAtomAlternativesContext::L_PAR() {
  return getToken(MDBParser::L_PAR, 0);
}

MDBParser::PathAlternativesContext* MDBParser::PathAtomAlternativesContext::pathAlternatives() {
  return getRuleContext<MDBParser::PathAlternativesContext>(0);
}

tree::TerminalNode* MDBParser::PathAtomAlternativesContext::R_PAR() {
  return getToken(MDBParser::R_PAR, 0);
}

tree::TerminalNode* MDBParser::PathAtomAlternativesContext::PATH_NEGATION() {
  return getToken(MDBParser::PATH_NEGATION, 0);
}

MDBParser::PathSuffixContext* MDBParser::PathAtomAlternativesContext::pathSuffix() {
  return getRuleContext<MDBParser::PathSuffixContext>(0);
}

MDBParser::PathAtomAlternativesContext::PathAtomAlternativesContext(PathAtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::PathAtomAlternativesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitPathAtomAlternatives(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PathAtomSimpleContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::PathAtomSimpleContext::TYPE() {
  return getToken(MDBParser::TYPE, 0);
}

tree::TerminalNode* MDBParser::PathAtomSimpleContext::PATH_NEGATION() {
  return getToken(MDBParser::PATH_NEGATION, 0);
}

MDBParser::PathSuffixContext* MDBParser::PathAtomSimpleContext::pathSuffix() {
  return getRuleContext<MDBParser::PathSuffixContext>(0);
}

MDBParser::PathAtomSimpleContext::PathAtomSimpleContext(PathAtomContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::PathAtomSimpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitPathAtomSimple(this);
  else
    return visitor->visitChildren(this);
}
MDBParser::PathAtomContext* MDBParser::pathAtom() {
  PathAtomContext *_localctx = _tracker.createInstance<PathAtomContext>(_ctx, getState());
  enterRule(_localctx, 36, MDBParser::RulePathAtom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(318);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MDBParser::PathAtomSimpleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(303);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MDBParser::PATH_NEGATION) {
        setState(302);
        match(MDBParser::PATH_NEGATION);
      }
      setState(305);
      match(MDBParser::TYPE);
      setState(307);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MDBParser::STAR)
        | (1ULL << MDBParser::QUESTION_MARK)
        | (1ULL << MDBParser::PLUS)
        | (1ULL << MDBParser::LCURLY_BRACKET))) != 0)) {
        setState(306);
        pathSuffix();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MDBParser::PathAtomAlternativesContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(310);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MDBParser::PATH_NEGATION) {
        setState(309);
        match(MDBParser::PATH_NEGATION);
      }
      setState(312);
      match(MDBParser::L_PAR);
      setState(313);
      pathAlternatives();
      setState(314);
      match(MDBParser::R_PAR);
      setState(316);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MDBParser::STAR)
        | (1ULL << MDBParser::QUESTION_MARK)
        | (1ULL << MDBParser::PLUS)
        | (1ULL << MDBParser::LCURLY_BRACKET))) != 0)) {
        setState(315);
        pathSuffix();
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathSuffixContext ------------------------------------------------------------------

MDBParser::PathSuffixContext::PathSuffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::PathSuffixContext::STAR() {
  return getToken(MDBParser::STAR, 0);
}

tree::TerminalNode* MDBParser::PathSuffixContext::PLUS() {
  return getToken(MDBParser::PLUS, 0);
}

tree::TerminalNode* MDBParser::PathSuffixContext::QUESTION_MARK() {
  return getToken(MDBParser::QUESTION_MARK, 0);
}

tree::TerminalNode* MDBParser::PathSuffixContext::LCURLY_BRACKET() {
  return getToken(MDBParser::LCURLY_BRACKET, 0);
}

tree::TerminalNode* MDBParser::PathSuffixContext::COMMA() {
  return getToken(MDBParser::COMMA, 0);
}

tree::TerminalNode* MDBParser::PathSuffixContext::RCURLY_BRACKET() {
  return getToken(MDBParser::RCURLY_BRACKET, 0);
}

std::vector<tree::TerminalNode *> MDBParser::PathSuffixContext::UNSIGNED_INTEGER() {
  return getTokens(MDBParser::UNSIGNED_INTEGER);
}

tree::TerminalNode* MDBParser::PathSuffixContext::UNSIGNED_INTEGER(size_t i) {
  return getToken(MDBParser::UNSIGNED_INTEGER, i);
}


size_t MDBParser::PathSuffixContext::getRuleIndex() const {
  return MDBParser::RulePathSuffix;
}


antlrcpp::Any MDBParser::PathSuffixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitPathSuffix(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::PathSuffixContext* MDBParser::pathSuffix() {
  PathSuffixContext *_localctx = _tracker.createInstance<PathSuffixContext>(_ctx, getState());
  enterRule(_localctx, 38, MDBParser::RulePathSuffix);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(328);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MDBParser::STAR: {
        enterOuterAlt(_localctx, 1);
        setState(320);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->op = match(MDBParser::STAR);
        break;
      }

      case MDBParser::PLUS: {
        enterOuterAlt(_localctx, 2);
        setState(321);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->op = match(MDBParser::PLUS);
        break;
      }

      case MDBParser::QUESTION_MARK: {
        enterOuterAlt(_localctx, 3);
        setState(322);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->op = match(MDBParser::QUESTION_MARK);
        break;
      }

      case MDBParser::LCURLY_BRACKET: {
        enterOuterAlt(_localctx, 4);
        setState(323);
        match(MDBParser::LCURLY_BRACKET);
        setState(324);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->min = match(MDBParser::UNSIGNED_INTEGER);
        setState(325);
        match(MDBParser::COMMA);
        setState(326);
        antlrcpp::downCast<PathSuffixContext *>(_localctx)->max = match(MDBParser::UNSIGNED_INTEGER);
        setState(327);
        match(MDBParser::RCURLY_BRACKET);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathTypeContext ------------------------------------------------------------------

MDBParser::PathTypeContext::PathTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::PathTypeContext::K_ANY() {
  return getToken(MDBParser::K_ANY, 0);
}

tree::TerminalNode* MDBParser::PathTypeContext::K_ALL() {
  return getToken(MDBParser::K_ALL, 0);
}


size_t MDBParser::PathTypeContext::getRuleIndex() const {
  return MDBParser::RulePathType;
}


antlrcpp::Any MDBParser::PathTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitPathType(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::PathTypeContext* MDBParser::pathType() {
  PathTypeContext *_localctx = _tracker.createInstance<PathTypeContext>(_ctx, getState());
  enterRule(_localctx, 40, MDBParser::RulePathType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    _la = _input->LA(1);
    if (!(_la == MDBParser::K_ANY

    || _la == MDBParser::K_ALL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodeContext ------------------------------------------------------------------

MDBParser::NodeContext::NodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MDBParser::FixedNodeContext* MDBParser::NodeContext::fixedNode() {
  return getRuleContext<MDBParser::FixedNodeContext>(0);
}

MDBParser::VarNodeContext* MDBParser::NodeContext::varNode() {
  return getRuleContext<MDBParser::VarNodeContext>(0);
}


size_t MDBParser::NodeContext::getRuleIndex() const {
  return MDBParser::RuleNode;
}


antlrcpp::Any MDBParser::NodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitNode(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::NodeContext* MDBParser::node() {
  NodeContext *_localctx = _tracker.createInstance<NodeContext>(_ctx, getState());
  enterRule(_localctx, 42, MDBParser::RuleNode);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(334);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(332);
      fixedNode();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(333);
      varNode();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FixedNodeContext ------------------------------------------------------------------

MDBParser::FixedNodeContext::FixedNodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MDBParser::FixedNodeContext::getRuleIndex() const {
  return MDBParser::RuleFixedNode;
}

void MDBParser::FixedNodeContext::copyFrom(FixedNodeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NodeValueContext ------------------------------------------------------------------

MDBParser::ValueContext* MDBParser::NodeValueContext::value() {
  return getRuleContext<MDBParser::ValueContext>(0);
}

MDBParser::NodeValueContext::NodeValueContext(FixedNodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::NodeValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitNodeValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NodeAnonNodeContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::NodeAnonNodeContext::ANON_NODE() {
  return getToken(MDBParser::ANON_NODE, 0);
}

MDBParser::NodeAnonNodeContext::NodeAnonNodeContext(FixedNodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::NodeAnonNodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitNodeAnonNode(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NodeEdgeNodeContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::NodeEdgeNodeContext::EDGE_NODE() {
  return getToken(MDBParser::EDGE_NODE, 0);
}

MDBParser::NodeEdgeNodeContext::NodeEdgeNodeContext(FixedNodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::NodeEdgeNodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitNodeEdgeNode(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NodeNamedNodeContext ------------------------------------------------------------------

MDBParser::Named_nodeContext* MDBParser::NodeNamedNodeContext::named_node() {
  return getRuleContext<MDBParser::Named_nodeContext>(0);
}

MDBParser::NodeNamedNodeContext::NodeNamedNodeContext(FixedNodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::NodeNamedNodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitNodeNamedNode(this);
  else
    return visitor->visitChildren(this);
}
MDBParser::FixedNodeContext* MDBParser::fixedNode() {
  FixedNodeContext *_localctx = _tracker.createInstance<FixedNodeContext>(_ctx, getState());
  enterRule(_localctx, 44, MDBParser::RuleFixedNode);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(340);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MDBParser::L_PAR: {
        _localctx = _tracker.createInstance<MDBParser::NodeNamedNodeContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(336);
        named_node();
        break;
      }

      case MDBParser::ANON_NODE: {
        _localctx = _tracker.createInstance<MDBParser::NodeAnonNodeContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(337);
        match(MDBParser::ANON_NODE);
        break;
      }

      case MDBParser::EDGE_NODE: {
        _localctx = _tracker.createInstance<MDBParser::NodeEdgeNodeContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(338);
        match(MDBParser::EDGE_NODE);
        break;
      }

      case MDBParser::K_FALSE:
      case MDBParser::K_TRUE:
      case MDBParser::STRING:
      case MDBParser::UNSIGNED_INTEGER:
      case MDBParser::UNSIGNED_FLOAT:
      case MDBParser::PLUS:
      case MDBParser::MINUS: {
        _localctx = _tracker.createInstance<MDBParser::NodeValueContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(339);
        value();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EdgeContext ------------------------------------------------------------------

MDBParser::EdgeContext::EdgeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MDBParser::EdgeContext::getRuleIndex() const {
  return MDBParser::RuleEdge;
}

void MDBParser::EdgeContext::copyFrom(EdgeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LeftEdgeContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::LeftEdgeContext::LT() {
  return getToken(MDBParser::LT, 0);
}

std::vector<tree::TerminalNode *> MDBParser::LeftEdgeContext::MINUS() {
  return getTokens(MDBParser::MINUS);
}

tree::TerminalNode* MDBParser::LeftEdgeContext::MINUS(size_t i) {
  return getToken(MDBParser::MINUS, i);
}

MDBParser::EdgeInsideContext* MDBParser::LeftEdgeContext::edgeInside() {
  return getRuleContext<MDBParser::EdgeInsideContext>(0);
}

MDBParser::LeftEdgeContext::LeftEdgeContext(EdgeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::LeftEdgeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitLeftEdge(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RightEdgeContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> MDBParser::RightEdgeContext::MINUS() {
  return getTokens(MDBParser::MINUS);
}

tree::TerminalNode* MDBParser::RightEdgeContext::MINUS(size_t i) {
  return getToken(MDBParser::MINUS, i);
}

tree::TerminalNode* MDBParser::RightEdgeContext::GT() {
  return getToken(MDBParser::GT, 0);
}

MDBParser::EdgeInsideContext* MDBParser::RightEdgeContext::edgeInside() {
  return getRuleContext<MDBParser::EdgeInsideContext>(0);
}

MDBParser::RightEdgeContext::RightEdgeContext(EdgeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::RightEdgeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitRightEdge(this);
  else
    return visitor->visitChildren(this);
}
MDBParser::EdgeContext* MDBParser::edge() {
  EdgeContext *_localctx = _tracker.createInstance<EdgeContext>(_ctx, getState());
  enterRule(_localctx, 46, MDBParser::RuleEdge);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(355);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MDBParser::LT: {
        _localctx = _tracker.createInstance<MDBParser::LeftEdgeContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(342);
        match(MDBParser::LT);
        setState(345);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
        case 1: {
          setState(343);
          match(MDBParser::MINUS);
          setState(344);
          edgeInside();
          break;
        }

        default:
          break;
        }
        setState(347);
        match(MDBParser::MINUS);
        break;
      }

      case MDBParser::MINUS: {
        _localctx = _tracker.createInstance<MDBParser::RightEdgeContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(348);
        match(MDBParser::MINUS);
        setState(352);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::LSQUARE_BRACKET) {
          setState(349);
          edgeInside();
          setState(350);
          match(MDBParser::MINUS);
        }
        setState(354);
        match(MDBParser::GT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EdgeInsideContext ------------------------------------------------------------------

MDBParser::EdgeInsideContext::EdgeInsideContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::EdgeInsideContext::LSQUARE_BRACKET() {
  return getToken(MDBParser::LSQUARE_BRACKET, 0);
}

tree::TerminalNode* MDBParser::EdgeInsideContext::RSQUARE_BRACKET() {
  return getToken(MDBParser::RSQUARE_BRACKET, 0);
}

MDBParser::PropertiesContext* MDBParser::EdgeInsideContext::properties() {
  return getRuleContext<MDBParser::PropertiesContext>(0);
}

tree::TerminalNode* MDBParser::EdgeInsideContext::VARIABLE() {
  return getToken(MDBParser::VARIABLE, 0);
}

tree::TerminalNode* MDBParser::EdgeInsideContext::EDGE_ID() {
  return getToken(MDBParser::EDGE_ID, 0);
}

tree::TerminalNode* MDBParser::EdgeInsideContext::TYPE() {
  return getToken(MDBParser::TYPE, 0);
}

tree::TerminalNode* MDBParser::EdgeInsideContext::TYPE_VAR() {
  return getToken(MDBParser::TYPE_VAR, 0);
}


size_t MDBParser::EdgeInsideContext::getRuleIndex() const {
  return MDBParser::RuleEdgeInside;
}


antlrcpp::Any MDBParser::EdgeInsideContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitEdgeInside(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::EdgeInsideContext* MDBParser::edgeInside() {
  EdgeInsideContext *_localctx = _tracker.createInstance<EdgeInsideContext>(_ctx, getState());
  enterRule(_localctx, 48, MDBParser::RuleEdgeInside);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(MDBParser::LSQUARE_BRACKET);
    setState(359);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MDBParser::EDGE_ID

    || _la == MDBParser::VARIABLE) {
      setState(358);
      _la = _input->LA(1);
      if (!(_la == MDBParser::EDGE_ID

      || _la == MDBParser::VARIABLE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(362);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MDBParser::TYPE

    || _la == MDBParser::TYPE_VAR) {
      setState(361);
      _la = _input->LA(1);
      if (!(_la == MDBParser::TYPE

      || _la == MDBParser::TYPE_VAR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(365);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MDBParser::LCURLY_BRACKET) {
      setState(364);
      properties();
    }
    setState(367);
    match(MDBParser::RSQUARE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarNodeContext ------------------------------------------------------------------

MDBParser::VarNodeContext::VarNodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::VarNodeContext::L_PAR() {
  return getToken(MDBParser::L_PAR, 0);
}

tree::TerminalNode* MDBParser::VarNodeContext::R_PAR() {
  return getToken(MDBParser::R_PAR, 0);
}

tree::TerminalNode* MDBParser::VarNodeContext::VARIABLE() {
  return getToken(MDBParser::VARIABLE, 0);
}

std::vector<tree::TerminalNode *> MDBParser::VarNodeContext::TYPE() {
  return getTokens(MDBParser::TYPE);
}

tree::TerminalNode* MDBParser::VarNodeContext::TYPE(size_t i) {
  return getToken(MDBParser::TYPE, i);
}

MDBParser::PropertiesContext* MDBParser::VarNodeContext::properties() {
  return getRuleContext<MDBParser::PropertiesContext>(0);
}


size_t MDBParser::VarNodeContext::getRuleIndex() const {
  return MDBParser::RuleVarNode;
}


antlrcpp::Any MDBParser::VarNodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitVarNode(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::VarNodeContext* MDBParser::varNode() {
  VarNodeContext *_localctx = _tracker.createInstance<VarNodeContext>(_ctx, getState());
  enterRule(_localctx, 50, MDBParser::RuleVarNode);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    match(MDBParser::L_PAR);
    setState(371);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MDBParser::VARIABLE) {
      setState(370);
      match(MDBParser::VARIABLE);
    }
    setState(376);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MDBParser::TYPE) {
      setState(373);
      match(MDBParser::TYPE);
      setState(378);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(380);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MDBParser::LCURLY_BRACKET) {
      setState(379);
      properties();
    }
    setState(382);
    match(MDBParser::R_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertiesContext ------------------------------------------------------------------

MDBParser::PropertiesContext::PropertiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::PropertiesContext::LCURLY_BRACKET() {
  return getToken(MDBParser::LCURLY_BRACKET, 0);
}

std::vector<MDBParser::PropertyContext *> MDBParser::PropertiesContext::property() {
  return getRuleContexts<MDBParser::PropertyContext>();
}

MDBParser::PropertyContext* MDBParser::PropertiesContext::property(size_t i) {
  return getRuleContext<MDBParser::PropertyContext>(i);
}

tree::TerminalNode* MDBParser::PropertiesContext::RCURLY_BRACKET() {
  return getToken(MDBParser::RCURLY_BRACKET, 0);
}

std::vector<tree::TerminalNode *> MDBParser::PropertiesContext::COMMA() {
  return getTokens(MDBParser::COMMA);
}

tree::TerminalNode* MDBParser::PropertiesContext::COMMA(size_t i) {
  return getToken(MDBParser::COMMA, i);
}


size_t MDBParser::PropertiesContext::getRuleIndex() const {
  return MDBParser::RuleProperties;
}


antlrcpp::Any MDBParser::PropertiesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitProperties(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::PropertiesContext* MDBParser::properties() {
  PropertiesContext *_localctx = _tracker.createInstance<PropertiesContext>(_ctx, getState());
  enterRule(_localctx, 52, MDBParser::RuleProperties);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(384);
    match(MDBParser::LCURLY_BRACKET);
    setState(385);
    property();
    setState(390);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MDBParser::COMMA) {
      setState(386);
      match(MDBParser::COMMA);
      setState(387);
      property();
      setState(392);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(393);
    match(MDBParser::RCURLY_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyContext ------------------------------------------------------------------

MDBParser::PropertyContext::PropertyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MDBParser::IdentifierContext* MDBParser::PropertyContext::identifier() {
  return getRuleContext<MDBParser::IdentifierContext>(0);
}

tree::TerminalNode* MDBParser::PropertyContext::COLON() {
  return getToken(MDBParser::COLON, 0);
}

MDBParser::ValueContext* MDBParser::PropertyContext::value() {
  return getRuleContext<MDBParser::ValueContext>(0);
}

tree::TerminalNode* MDBParser::PropertyContext::TRUE_PROP() {
  return getToken(MDBParser::TRUE_PROP, 0);
}

tree::TerminalNode* MDBParser::PropertyContext::FALSE_PROP() {
  return getToken(MDBParser::FALSE_PROP, 0);
}


size_t MDBParser::PropertyContext::getRuleIndex() const {
  return MDBParser::RuleProperty;
}


antlrcpp::Any MDBParser::PropertyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitProperty(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::PropertyContext* MDBParser::property() {
  PropertyContext *_localctx = _tracker.createInstance<PropertyContext>(_ctx, getState());
  enterRule(_localctx, 54, MDBParser::RuleProperty);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    identifier();
    setState(400);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MDBParser::COLON: {
        setState(396);
        match(MDBParser::COLON);
        setState(397);
        value();
        break;
      }

      case MDBParser::TRUE_PROP: {
        setState(398);
        match(MDBParser::TRUE_PROP);
        break;
      }

      case MDBParser::FALSE_PROP: {
        setState(399);
        match(MDBParser::FALSE_PROP);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Named_nodeContext ------------------------------------------------------------------

MDBParser::Named_nodeContext::Named_nodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::Named_nodeContext::L_PAR() {
  return getToken(MDBParser::L_PAR, 0);
}

MDBParser::IdentifierContext* MDBParser::Named_nodeContext::identifier() {
  return getRuleContext<MDBParser::IdentifierContext>(0);
}

tree::TerminalNode* MDBParser::Named_nodeContext::R_PAR() {
  return getToken(MDBParser::R_PAR, 0);
}


size_t MDBParser::Named_nodeContext::getRuleIndex() const {
  return MDBParser::RuleNamed_node;
}


antlrcpp::Any MDBParser::Named_nodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitNamed_node(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::Named_nodeContext* MDBParser::named_node() {
  Named_nodeContext *_localctx = _tracker.createInstance<Named_nodeContext>(_ctx, getState());
  enterRule(_localctx, 56, MDBParser::RuleNamed_node);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(402);
    match(MDBParser::L_PAR);
    setState(403);
    identifier();
    setState(404);
    match(MDBParser::R_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

MDBParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::IdentifierContext::NAME() {
  return getToken(MDBParser::NAME, 0);
}

MDBParser::KeywordContext* MDBParser::IdentifierContext::keyword() {
  return getRuleContext<MDBParser::KeywordContext>(0);
}


size_t MDBParser::IdentifierContext::getRuleIndex() const {
  return MDBParser::RuleIdentifier;
}


antlrcpp::Any MDBParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::IdentifierContext* MDBParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 58, MDBParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(408);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MDBParser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(406);
        match(MDBParser::NAME);
        break;
      }

      case MDBParser::K_AND:
      case MDBParser::K_AVG:
      case MDBParser::K_ALL:
      case MDBParser::K_ASC:
      case MDBParser::K_BY:
      case MDBParser::K_BOOL:
      case MDBParser::K_COUNT:
      case MDBParser::K_DESCRIBE:
      case MDBParser::K_DESC:
      case MDBParser::K_DISTINCT:
      case MDBParser::K_IS:
      case MDBParser::K_INTEGER:
      case MDBParser::K_FLOAT:
      case MDBParser::K_GROUP:
      case MDBParser::K_LIMIT:
      case MDBParser::K_MAX:
      case MDBParser::K_MATCH:
      case MDBParser::K_MIN:
      case MDBParser::K_OPTIONAL:
      case MDBParser::K_ORDER:
      case MDBParser::K_OR:
      case MDBParser::K_NOT:
      case MDBParser::K_NULL:
      case MDBParser::K_SUM:
      case MDBParser::K_STRING:
      case MDBParser::K_RETURN:
      case MDBParser::K_WHERE: {
        enterOuterAlt(_localctx, 2);
        setState(407);
        keyword();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolValueContext ------------------------------------------------------------------

MDBParser::BoolValueContext::BoolValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::BoolValueContext::K_TRUE() {
  return getToken(MDBParser::K_TRUE, 0);
}

tree::TerminalNode* MDBParser::BoolValueContext::K_FALSE() {
  return getToken(MDBParser::K_FALSE, 0);
}


size_t MDBParser::BoolValueContext::getRuleIndex() const {
  return MDBParser::RuleBoolValue;
}


antlrcpp::Any MDBParser::BoolValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitBoolValue(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::BoolValueContext* MDBParser::boolValue() {
  BoolValueContext *_localctx = _tracker.createInstance<BoolValueContext>(_ctx, getState());
  enterRule(_localctx, 60, MDBParser::RuleBoolValue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(410);
    _la = _input->LA(1);
    if (!(_la == MDBParser::K_FALSE

    || _la == MDBParser::K_TRUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericValueContext ------------------------------------------------------------------

MDBParser::NumericValueContext::NumericValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::NumericValueContext::UNSIGNED_INTEGER() {
  return getToken(MDBParser::UNSIGNED_INTEGER, 0);
}

tree::TerminalNode* MDBParser::NumericValueContext::UNSIGNED_FLOAT() {
  return getToken(MDBParser::UNSIGNED_FLOAT, 0);
}

tree::TerminalNode* MDBParser::NumericValueContext::PLUS() {
  return getToken(MDBParser::PLUS, 0);
}

tree::TerminalNode* MDBParser::NumericValueContext::MINUS() {
  return getToken(MDBParser::MINUS, 0);
}


size_t MDBParser::NumericValueContext::getRuleIndex() const {
  return MDBParser::RuleNumericValue;
}


antlrcpp::Any MDBParser::NumericValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitNumericValue(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::NumericValueContext* MDBParser::numericValue() {
  NumericValueContext *_localctx = _tracker.createInstance<NumericValueContext>(_ctx, getState());
  enterRule(_localctx, 62, MDBParser::RuleNumericValue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(413);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MDBParser::PLUS

    || _la == MDBParser::MINUS) {
      setState(412);
      _la = _input->LA(1);
      if (!(_la == MDBParser::PLUS

      || _la == MDBParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(415);
    _la = _input->LA(1);
    if (!(_la == MDBParser::UNSIGNED_INTEGER

    || _la == MDBParser::UNSIGNED_FLOAT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

MDBParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MDBParser::NumericValueContext* MDBParser::ValueContext::numericValue() {
  return getRuleContext<MDBParser::NumericValueContext>(0);
}

tree::TerminalNode* MDBParser::ValueContext::STRING() {
  return getToken(MDBParser::STRING, 0);
}

MDBParser::BoolValueContext* MDBParser::ValueContext::boolValue() {
  return getRuleContext<MDBParser::BoolValueContext>(0);
}


size_t MDBParser::ValueContext::getRuleIndex() const {
  return MDBParser::RuleValue;
}


antlrcpp::Any MDBParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::ValueContext* MDBParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 64, MDBParser::RuleValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(420);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MDBParser::UNSIGNED_INTEGER:
      case MDBParser::UNSIGNED_FLOAT:
      case MDBParser::PLUS:
      case MDBParser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(417);
        numericValue();
        break;
      }

      case MDBParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(418);
        match(MDBParser::STRING);
        break;
      }

      case MDBParser::K_FALSE:
      case MDBParser::K_TRUE: {
        enterOuterAlt(_localctx, 3);
        setState(419);
        boolValue();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MDBParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MDBParser::ConditionalOrExprContext* MDBParser::ExprContext::conditionalOrExpr() {
  return getRuleContext<MDBParser::ConditionalOrExprContext>(0);
}


size_t MDBParser::ExprContext::getRuleIndex() const {
  return MDBParser::RuleExpr;
}


antlrcpp::Any MDBParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::ExprContext* MDBParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 66, MDBParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(422);
    conditionalOrExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalOrExprContext ------------------------------------------------------------------

MDBParser::ConditionalOrExprContext::ConditionalOrExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MDBParser::ConditionalAndExprContext *> MDBParser::ConditionalOrExprContext::conditionalAndExpr() {
  return getRuleContexts<MDBParser::ConditionalAndExprContext>();
}

MDBParser::ConditionalAndExprContext* MDBParser::ConditionalOrExprContext::conditionalAndExpr(size_t i) {
  return getRuleContext<MDBParser::ConditionalAndExprContext>(i);
}

std::vector<tree::TerminalNode *> MDBParser::ConditionalOrExprContext::K_OR() {
  return getTokens(MDBParser::K_OR);
}

tree::TerminalNode* MDBParser::ConditionalOrExprContext::K_OR(size_t i) {
  return getToken(MDBParser::K_OR, i);
}


size_t MDBParser::ConditionalOrExprContext::getRuleIndex() const {
  return MDBParser::RuleConditionalOrExpr;
}


antlrcpp::Any MDBParser::ConditionalOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitConditionalOrExpr(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::ConditionalOrExprContext* MDBParser::conditionalOrExpr() {
  ConditionalOrExprContext *_localctx = _tracker.createInstance<ConditionalOrExprContext>(_ctx, getState());
  enterRule(_localctx, 68, MDBParser::RuleConditionalOrExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
    conditionalAndExpr();
    setState(429);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MDBParser::K_OR) {
      setState(425);
      match(MDBParser::K_OR);
      setState(426);
      conditionalAndExpr();
      setState(431);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalAndExprContext ------------------------------------------------------------------

MDBParser::ConditionalAndExprContext::ConditionalAndExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MDBParser::ComparisonExprContext *> MDBParser::ConditionalAndExprContext::comparisonExpr() {
  return getRuleContexts<MDBParser::ComparisonExprContext>();
}

MDBParser::ComparisonExprContext* MDBParser::ConditionalAndExprContext::comparisonExpr(size_t i) {
  return getRuleContext<MDBParser::ComparisonExprContext>(i);
}

std::vector<tree::TerminalNode *> MDBParser::ConditionalAndExprContext::K_AND() {
  return getTokens(MDBParser::K_AND);
}

tree::TerminalNode* MDBParser::ConditionalAndExprContext::K_AND(size_t i) {
  return getToken(MDBParser::K_AND, i);
}


size_t MDBParser::ConditionalAndExprContext::getRuleIndex() const {
  return MDBParser::RuleConditionalAndExpr;
}


antlrcpp::Any MDBParser::ConditionalAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitConditionalAndExpr(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::ConditionalAndExprContext* MDBParser::conditionalAndExpr() {
  ConditionalAndExprContext *_localctx = _tracker.createInstance<ConditionalAndExprContext>(_ctx, getState());
  enterRule(_localctx, 70, MDBParser::RuleConditionalAndExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    comparisonExpr();
    setState(437);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MDBParser::K_AND) {
      setState(433);
      match(MDBParser::K_AND);
      setState(434);
      comparisonExpr();
      setState(439);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonExprContext ------------------------------------------------------------------

MDBParser::ComparisonExprContext::ComparisonExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MDBParser::ComparisonExprContext::getRuleIndex() const {
  return MDBParser::RuleComparisonExpr;
}

void MDBParser::ComparisonExprContext::copyFrom(ComparisonExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ComparisonExprIsContext ------------------------------------------------------------------

MDBParser::AditiveExprContext* MDBParser::ComparisonExprIsContext::aditiveExpr() {
  return getRuleContext<MDBParser::AditiveExprContext>(0);
}

tree::TerminalNode* MDBParser::ComparisonExprIsContext::K_IS() {
  return getToken(MDBParser::K_IS, 0);
}

MDBParser::ExprTypenameContext* MDBParser::ComparisonExprIsContext::exprTypename() {
  return getRuleContext<MDBParser::ExprTypenameContext>(0);
}

tree::TerminalNode* MDBParser::ComparisonExprIsContext::K_NOT() {
  return getToken(MDBParser::K_NOT, 0);
}

MDBParser::ComparisonExprIsContext::ComparisonExprIsContext(ComparisonExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::ComparisonExprIsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitComparisonExprIs(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComparisonExprOpContext ------------------------------------------------------------------

std::vector<MDBParser::AditiveExprContext *> MDBParser::ComparisonExprOpContext::aditiveExpr() {
  return getRuleContexts<MDBParser::AditiveExprContext>();
}

MDBParser::AditiveExprContext* MDBParser::ComparisonExprOpContext::aditiveExpr(size_t i) {
  return getRuleContext<MDBParser::AditiveExprContext>(i);
}

tree::TerminalNode* MDBParser::ComparisonExprOpContext::EQ() {
  return getToken(MDBParser::EQ, 0);
}

tree::TerminalNode* MDBParser::ComparisonExprOpContext::NEQ() {
  return getToken(MDBParser::NEQ, 0);
}

tree::TerminalNode* MDBParser::ComparisonExprOpContext::LT() {
  return getToken(MDBParser::LT, 0);
}

tree::TerminalNode* MDBParser::ComparisonExprOpContext::GT() {
  return getToken(MDBParser::GT, 0);
}

tree::TerminalNode* MDBParser::ComparisonExprOpContext::LEQ() {
  return getToken(MDBParser::LEQ, 0);
}

tree::TerminalNode* MDBParser::ComparisonExprOpContext::GEQ() {
  return getToken(MDBParser::GEQ, 0);
}

MDBParser::ComparisonExprOpContext::ComparisonExprOpContext(ComparisonExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::ComparisonExprOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitComparisonExprOp(this);
  else
    return visitor->visitChildren(this);
}
MDBParser::ComparisonExprContext* MDBParser::comparisonExpr() {
  ComparisonExprContext *_localctx = _tracker.createInstance<ComparisonExprContext>(_ctx, getState());
  enterRule(_localctx, 72, MDBParser::RuleComparisonExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(452);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MDBParser::ComparisonExprOpContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(440);
      aditiveExpr();
      setState(443);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MDBParser::LEQ)
        | (1ULL << MDBParser::GEQ)
        | (1ULL << MDBParser::EQ)
        | (1ULL << MDBParser::NEQ)
        | (1ULL << MDBParser::LT)
        | (1ULL << MDBParser::GT))) != 0)) {
        setState(441);
        antlrcpp::downCast<ComparisonExprOpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MDBParser::LEQ)
          | (1ULL << MDBParser::GEQ)
          | (1ULL << MDBParser::EQ)
          | (1ULL << MDBParser::NEQ)
          | (1ULL << MDBParser::LT)
          | (1ULL << MDBParser::GT))) != 0))) {
          antlrcpp::downCast<ComparisonExprOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(442);
        aditiveExpr();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MDBParser::ComparisonExprIsContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(445);
      aditiveExpr();
      setState(446);
      match(MDBParser::K_IS);
      setState(448);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MDBParser::K_NOT) {
        setState(447);
        match(MDBParser::K_NOT);
      }
      setState(450);
      exprTypename();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AditiveExprContext ------------------------------------------------------------------

MDBParser::AditiveExprContext::AditiveExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MDBParser::MultiplicativeExprContext *> MDBParser::AditiveExprContext::multiplicativeExpr() {
  return getRuleContexts<MDBParser::MultiplicativeExprContext>();
}

MDBParser::MultiplicativeExprContext* MDBParser::AditiveExprContext::multiplicativeExpr(size_t i) {
  return getRuleContext<MDBParser::MultiplicativeExprContext>(i);
}

std::vector<tree::TerminalNode *> MDBParser::AditiveExprContext::PLUS() {
  return getTokens(MDBParser::PLUS);
}

tree::TerminalNode* MDBParser::AditiveExprContext::PLUS(size_t i) {
  return getToken(MDBParser::PLUS, i);
}

std::vector<tree::TerminalNode *> MDBParser::AditiveExprContext::MINUS() {
  return getTokens(MDBParser::MINUS);
}

tree::TerminalNode* MDBParser::AditiveExprContext::MINUS(size_t i) {
  return getToken(MDBParser::MINUS, i);
}


size_t MDBParser::AditiveExprContext::getRuleIndex() const {
  return MDBParser::RuleAditiveExpr;
}


antlrcpp::Any MDBParser::AditiveExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitAditiveExpr(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::AditiveExprContext* MDBParser::aditiveExpr() {
  AditiveExprContext *_localctx = _tracker.createInstance<AditiveExprContext>(_ctx, getState());
  enterRule(_localctx, 74, MDBParser::RuleAditiveExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(454);
    multiplicativeExpr();
    setState(459);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MDBParser::PLUS

    || _la == MDBParser::MINUS) {
      setState(455);
      antlrcpp::downCast<AditiveExprContext *>(_localctx)->_tset843 = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == MDBParser::PLUS

      || _la == MDBParser::MINUS)) {
        antlrcpp::downCast<AditiveExprContext *>(_localctx)->_tset843 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      antlrcpp::downCast<AditiveExprContext *>(_localctx)->op.push_back(antlrcpp::downCast<AditiveExprContext *>(_localctx)->_tset843);
      setState(456);
      multiplicativeExpr();
      setState(461);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeExprContext ------------------------------------------------------------------

MDBParser::MultiplicativeExprContext::MultiplicativeExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MDBParser::UnaryExprContext *> MDBParser::MultiplicativeExprContext::unaryExpr() {
  return getRuleContexts<MDBParser::UnaryExprContext>();
}

MDBParser::UnaryExprContext* MDBParser::MultiplicativeExprContext::unaryExpr(size_t i) {
  return getRuleContext<MDBParser::UnaryExprContext>(i);
}

std::vector<tree::TerminalNode *> MDBParser::MultiplicativeExprContext::STAR() {
  return getTokens(MDBParser::STAR);
}

tree::TerminalNode* MDBParser::MultiplicativeExprContext::STAR(size_t i) {
  return getToken(MDBParser::STAR, i);
}

std::vector<tree::TerminalNode *> MDBParser::MultiplicativeExprContext::PATH_SEQUENCE() {
  return getTokens(MDBParser::PATH_SEQUENCE);
}

tree::TerminalNode* MDBParser::MultiplicativeExprContext::PATH_SEQUENCE(size_t i) {
  return getToken(MDBParser::PATH_SEQUENCE, i);
}

std::vector<tree::TerminalNode *> MDBParser::MultiplicativeExprContext::PERCENT() {
  return getTokens(MDBParser::PERCENT);
}

tree::TerminalNode* MDBParser::MultiplicativeExprContext::PERCENT(size_t i) {
  return getToken(MDBParser::PERCENT, i);
}


size_t MDBParser::MultiplicativeExprContext::getRuleIndex() const {
  return MDBParser::RuleMultiplicativeExpr;
}


antlrcpp::Any MDBParser::MultiplicativeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpr(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::MultiplicativeExprContext* MDBParser::multiplicativeExpr() {
  MultiplicativeExprContext *_localctx = _tracker.createInstance<MultiplicativeExprContext>(_ctx, getState());
  enterRule(_localctx, 76, MDBParser::RuleMultiplicativeExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    unaryExpr();
    setState(467);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MDBParser::PATH_SEQUENCE)
      | (1ULL << MDBParser::STAR)
      | (1ULL << MDBParser::PERCENT))) != 0)) {
      setState(463);
      antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->_tset863 = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MDBParser::PATH_SEQUENCE)
        | (1ULL << MDBParser::STAR)
        | (1ULL << MDBParser::PERCENT))) != 0))) {
        antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->_tset863 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->op.push_back(antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->_tset863);
      setState(464);
      unaryExpr();
      setState(469);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExprContext ------------------------------------------------------------------

MDBParser::UnaryExprContext::UnaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::UnaryExprContext::K_NOT() {
  return getToken(MDBParser::K_NOT, 0);
}

MDBParser::UnaryExprContext* MDBParser::UnaryExprContext::unaryExpr() {
  return getRuleContext<MDBParser::UnaryExprContext>(0);
}

tree::TerminalNode* MDBParser::UnaryExprContext::PLUS() {
  return getToken(MDBParser::PLUS, 0);
}

tree::TerminalNode* MDBParser::UnaryExprContext::MINUS() {
  return getToken(MDBParser::MINUS, 0);
}

MDBParser::AtomicExprContext* MDBParser::UnaryExprContext::atomicExpr() {
  return getRuleContext<MDBParser::AtomicExprContext>(0);
}


size_t MDBParser::UnaryExprContext::getRuleIndex() const {
  return MDBParser::RuleUnaryExpr;
}


antlrcpp::Any MDBParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::UnaryExprContext* MDBParser::unaryExpr() {
  UnaryExprContext *_localctx = _tracker.createInstance<UnaryExprContext>(_ctx, getState());
  enterRule(_localctx, 78, MDBParser::RuleUnaryExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(477);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MDBParser::K_NOT: {
        enterOuterAlt(_localctx, 1);
        setState(470);
        match(MDBParser::K_NOT);
        setState(471);
        unaryExpr();
        break;
      }

      case MDBParser::PLUS: {
        enterOuterAlt(_localctx, 2);
        setState(472);
        match(MDBParser::PLUS);
        setState(473);
        unaryExpr();
        break;
      }

      case MDBParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(474);
        match(MDBParser::MINUS);
        setState(475);
        unaryExpr();
        break;
      }

      case MDBParser::K_FALSE:
      case MDBParser::K_TRUE:
      case MDBParser::TRUE_PARENTHESIS:
      case MDBParser::FALSE_PARENTHESIS:
      case MDBParser::VARIABLE:
      case MDBParser::STRING:
      case MDBParser::UNSIGNED_INTEGER:
      case MDBParser::UNSIGNED_FLOAT:
      case MDBParser::L_PAR: {
        enterOuterAlt(_localctx, 4);
        setState(476);
        atomicExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomicExprContext ------------------------------------------------------------------

MDBParser::AtomicExprContext::AtomicExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MDBParser::AtomicExprContext::getRuleIndex() const {
  return MDBParser::RuleAtomicExpr;
}

void MDBParser::AtomicExprContext::copyFrom(AtomicExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprValueExprContext ------------------------------------------------------------------

MDBParser::ValueExprContext* MDBParser::ExprValueExprContext::valueExpr() {
  return getRuleContext<MDBParser::ValueExprContext>(0);
}

MDBParser::ExprValueExprContext::ExprValueExprContext(AtomicExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::ExprValueExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitExprValueExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprTrueParenthesisContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::ExprTrueParenthesisContext::TRUE_PARENTHESIS() {
  return getToken(MDBParser::TRUE_PARENTHESIS, 0);
}

MDBParser::ExprTrueParenthesisContext::ExprTrueParenthesisContext(AtomicExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::ExprTrueParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitExprTrueParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprFalseParenthesisContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::ExprFalseParenthesisContext::FALSE_PARENTHESIS() {
  return getToken(MDBParser::FALSE_PARENTHESIS, 0);
}

MDBParser::ExprFalseParenthesisContext::ExprFalseParenthesisContext(AtomicExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::ExprFalseParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitExprFalseParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprVarContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::ExprVarContext::VARIABLE() {
  return getToken(MDBParser::VARIABLE, 0);
}

tree::TerminalNode* MDBParser::ExprVarContext::KEY() {
  return getToken(MDBParser::KEY, 0);
}

MDBParser::ExprVarContext::ExprVarContext(AtomicExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::ExprVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitExprVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParenthesisContext ------------------------------------------------------------------

tree::TerminalNode* MDBParser::ExprParenthesisContext::L_PAR() {
  return getToken(MDBParser::L_PAR, 0);
}

MDBParser::ExprContext* MDBParser::ExprParenthesisContext::expr() {
  return getRuleContext<MDBParser::ExprContext>(0);
}

tree::TerminalNode* MDBParser::ExprParenthesisContext::R_PAR() {
  return getToken(MDBParser::R_PAR, 0);
}

MDBParser::ExprParenthesisContext::ExprParenthesisContext(AtomicExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MDBParser::ExprParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitExprParenthesis(this);
  else
    return visitor->visitChildren(this);
}
MDBParser::AtomicExprContext* MDBParser::atomicExpr() {
  AtomicExprContext *_localctx = _tracker.createInstance<AtomicExprContext>(_ctx, getState());
  enterRule(_localctx, 80, MDBParser::RuleAtomicExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(490);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MDBParser::VARIABLE: {
        _localctx = _tracker.createInstance<MDBParser::ExprVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(479);
        match(MDBParser::VARIABLE);
        setState(481);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MDBParser::KEY) {
          setState(480);
          match(MDBParser::KEY);
        }
        break;
      }

      case MDBParser::K_FALSE:
      case MDBParser::K_TRUE:
      case MDBParser::STRING:
      case MDBParser::UNSIGNED_INTEGER:
      case MDBParser::UNSIGNED_FLOAT: {
        _localctx = _tracker.createInstance<MDBParser::ExprValueExprContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(483);
        valueExpr();
        break;
      }

      case MDBParser::L_PAR: {
        _localctx = _tracker.createInstance<MDBParser::ExprParenthesisContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(484);
        match(MDBParser::L_PAR);
        setState(485);
        expr();
        setState(486);
        match(MDBParser::R_PAR);
        break;
      }

      case MDBParser::TRUE_PARENTHESIS: {
        _localctx = _tracker.createInstance<MDBParser::ExprTrueParenthesisContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(488);
        match(MDBParser::TRUE_PARENTHESIS);
        break;
      }

      case MDBParser::FALSE_PARENTHESIS: {
        _localctx = _tracker.createInstance<MDBParser::ExprFalseParenthesisContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(489);
        match(MDBParser::FALSE_PARENTHESIS);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueExprContext ------------------------------------------------------------------

MDBParser::ValueExprContext::ValueExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::ValueExprContext::UNSIGNED_INTEGER() {
  return getToken(MDBParser::UNSIGNED_INTEGER, 0);
}

tree::TerminalNode* MDBParser::ValueExprContext::UNSIGNED_FLOAT() {
  return getToken(MDBParser::UNSIGNED_FLOAT, 0);
}

tree::TerminalNode* MDBParser::ValueExprContext::STRING() {
  return getToken(MDBParser::STRING, 0);
}

MDBParser::BoolValueContext* MDBParser::ValueExprContext::boolValue() {
  return getRuleContext<MDBParser::BoolValueContext>(0);
}


size_t MDBParser::ValueExprContext::getRuleIndex() const {
  return MDBParser::RuleValueExpr;
}


antlrcpp::Any MDBParser::ValueExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitValueExpr(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::ValueExprContext* MDBParser::valueExpr() {
  ValueExprContext *_localctx = _tracker.createInstance<ValueExprContext>(_ctx, getState());
  enterRule(_localctx, 82, MDBParser::RuleValueExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(496);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MDBParser::UNSIGNED_INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(492);
        match(MDBParser::UNSIGNED_INTEGER);
        break;
      }

      case MDBParser::UNSIGNED_FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(493);
        match(MDBParser::UNSIGNED_FLOAT);
        break;
      }

      case MDBParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(494);
        match(MDBParser::STRING);
        break;
      }

      case MDBParser::K_FALSE:
      case MDBParser::K_TRUE: {
        enterOuterAlt(_localctx, 4);
        setState(495);
        boolValue();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprTypenameContext ------------------------------------------------------------------

MDBParser::ExprTypenameContext::ExprTypenameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::ExprTypenameContext::K_NULL() {
  return getToken(MDBParser::K_NULL, 0);
}

tree::TerminalNode* MDBParser::ExprTypenameContext::K_STRING() {
  return getToken(MDBParser::K_STRING, 0);
}

tree::TerminalNode* MDBParser::ExprTypenameContext::K_BOOL() {
  return getToken(MDBParser::K_BOOL, 0);
}

tree::TerminalNode* MDBParser::ExprTypenameContext::K_INTEGER() {
  return getToken(MDBParser::K_INTEGER, 0);
}

tree::TerminalNode* MDBParser::ExprTypenameContext::K_FLOAT() {
  return getToken(MDBParser::K_FLOAT, 0);
}


size_t MDBParser::ExprTypenameContext::getRuleIndex() const {
  return MDBParser::RuleExprTypename;
}


antlrcpp::Any MDBParser::ExprTypenameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitExprTypename(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::ExprTypenameContext* MDBParser::exprTypename() {
  ExprTypenameContext *_localctx = _tracker.createInstance<ExprTypenameContext>(_ctx, getState());
  enterRule(_localctx, 84, MDBParser::RuleExprTypename);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(498);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MDBParser::K_BOOL)
      | (1ULL << MDBParser::K_INTEGER)
      | (1ULL << MDBParser::K_FLOAT)
      | (1ULL << MDBParser::K_NULL)
      | (1ULL << MDBParser::K_STRING))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeywordContext ------------------------------------------------------------------

MDBParser::KeywordContext::KeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MDBParser::KeywordContext::K_ALL() {
  return getToken(MDBParser::K_ALL, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_AND() {
  return getToken(MDBParser::K_AND, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_AVG() {
  return getToken(MDBParser::K_AVG, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_ASC() {
  return getToken(MDBParser::K_ASC, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_BY() {
  return getToken(MDBParser::K_BY, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_BOOL() {
  return getToken(MDBParser::K_BOOL, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_COUNT() {
  return getToken(MDBParser::K_COUNT, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_DESCRIBE() {
  return getToken(MDBParser::K_DESCRIBE, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_DESC() {
  return getToken(MDBParser::K_DESC, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_DISTINCT() {
  return getToken(MDBParser::K_DISTINCT, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_IS() {
  return getToken(MDBParser::K_IS, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_INTEGER() {
  return getToken(MDBParser::K_INTEGER, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_FLOAT() {
  return getToken(MDBParser::K_FLOAT, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_GROUP() {
  return getToken(MDBParser::K_GROUP, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_LIMIT() {
  return getToken(MDBParser::K_LIMIT, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_MAX() {
  return getToken(MDBParser::K_MAX, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_MATCH() {
  return getToken(MDBParser::K_MATCH, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_MIN() {
  return getToken(MDBParser::K_MIN, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_OPTIONAL() {
  return getToken(MDBParser::K_OPTIONAL, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_ORDER() {
  return getToken(MDBParser::K_ORDER, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_OR() {
  return getToken(MDBParser::K_OR, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_NOT() {
  return getToken(MDBParser::K_NOT, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_NULL() {
  return getToken(MDBParser::K_NULL, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_SUM() {
  return getToken(MDBParser::K_SUM, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_STRING() {
  return getToken(MDBParser::K_STRING, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_RETURN() {
  return getToken(MDBParser::K_RETURN, 0);
}

tree::TerminalNode* MDBParser::KeywordContext::K_WHERE() {
  return getToken(MDBParser::K_WHERE, 0);
}


size_t MDBParser::KeywordContext::getRuleIndex() const {
  return MDBParser::RuleKeyword;
}


antlrcpp::Any MDBParser::KeywordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MDBParserVisitor*>(visitor))
    return parserVisitor->visitKeyword(this);
  else
    return visitor->visitChildren(this);
}

MDBParser::KeywordContext* MDBParser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 86, MDBParser::RuleKeyword);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(500);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MDBParser::K_AND)
      | (1ULL << MDBParser::K_AVG)
      | (1ULL << MDBParser::K_ALL)
      | (1ULL << MDBParser::K_ASC)
      | (1ULL << MDBParser::K_BY)
      | (1ULL << MDBParser::K_BOOL)
      | (1ULL << MDBParser::K_COUNT)
      | (1ULL << MDBParser::K_DESCRIBE)
      | (1ULL << MDBParser::K_DESC)
      | (1ULL << MDBParser::K_DISTINCT)
      | (1ULL << MDBParser::K_IS)
      | (1ULL << MDBParser::K_INTEGER)
      | (1ULL << MDBParser::K_FLOAT)
      | (1ULL << MDBParser::K_GROUP)
      | (1ULL << MDBParser::K_LIMIT)
      | (1ULL << MDBParser::K_MAX)
      | (1ULL << MDBParser::K_MATCH)
      | (1ULL << MDBParser::K_MIN)
      | (1ULL << MDBParser::K_OPTIONAL)
      | (1ULL << MDBParser::K_ORDER)
      | (1ULL << MDBParser::K_OR)
      | (1ULL << MDBParser::K_NOT)
      | (1ULL << MDBParser::K_NULL)
      | (1ULL << MDBParser::K_SUM)
      | (1ULL << MDBParser::K_STRING)
      | (1ULL << MDBParser::K_RETURN)
      | (1ULL << MDBParser::K_WHERE))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> MDBParser::_decisionToDFA;
atn::PredictionContextCache MDBParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MDBParser::_atn;
std::vector<uint16_t> MDBParser::_serializedATN;

std::vector<std::string> MDBParser::_ruleNames = {
  "root", "describeStatement", "matchStatement", "whereStatement", "groupByStatement", 
  "orderByStatement", "returnStatement", "returnItem", "aggregateFunc", 
  "orderByItem", "groupByItem", "graphPattern", "optionalPattern", "basicPattern", 
  "linearPattern", "path", "pathAlternatives", "pathSequence", "pathAtom", 
  "pathSuffix", "pathType", "node", "fixedNode", "edge", "edgeInside", "varNode", 
  "properties", "property", "named_node", "identifier", "boolValue", "numericValue", 
  "value", "expr", "conditionalOrExpr", "conditionalAndExpr", "comparisonExpr", 
  "aditiveExpr", "multiplicativeExpr", "unaryExpr", "atomicExpr", "valueExpr", 
  "exprTypename", "keyword"
};

std::vector<std::string> MDBParser::_literalNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "'false'", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "'true'", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "'<='", "'>='", 
  "'=='", "'!='", "'<'", "'>'", "'='", "'/'", "'|'", "'^'", "'*'", "'%'", 
  "'\u003F'", "'+'", "'-'", "'('", "')'", "'{'", "'}'", "'['", "']'", "','", 
  "':'"
};

std::vector<std::string> MDBParser::_symbolicNames = {
  "", "K_ANY", "K_AND", "K_AVG", "K_ALL", "K_ASC", "K_BY", "K_BOOL", "K_COUNT", 
  "K_DESCRIBE", "K_DESC", "K_DISTINCT", "K_IS", "K_INTEGER", "K_FALSE", 
  "K_FLOAT", "K_GROUP", "K_LIMIT", "K_MAX", "K_MATCH", "K_MIN", "K_OPTIONAL", 
  "K_ORDER", "K_OR", "K_NOT", "K_NULL", "K_SUM", "K_STRING", "K_RETURN", 
  "K_TRUE", "K_WHERE", "TRUE_PROP", "FALSE_PROP", "TRUE_PARENTHESIS", "FALSE_PARENTHESIS", 
  "ANON_NODE", "EDGE_NODE", "EDGE_ID", "KEY", "TYPE", "TYPE_VAR", "VARIABLE", 
  "STRING", "UNSIGNED_INTEGER", "UNSIGNED_FLOAT", "NAME", "LEQ", "GEQ", 
  "EQ", "NEQ", "LT", "GT", "SINGLE_EQ", "PATH_SEQUENCE", "PATH_ALTERNATIVE", 
  "PATH_NEGATION", "STAR", "PERCENT", "QUESTION_MARK", "PLUS", "MINUS", 
  "L_PAR", "R_PAR", "LCURLY_BRACKET", "RCURLY_BRACKET", "LSQUARE_BRACKET", 
  "RSQUARE_BRACKET", "COMMA", "COLON", "WHITE_SPACE", "SINGLE_LINE_COMMENT", 
  "UNRECOGNIZED"
};

dfa::Vocabulary MDBParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MDBParser::_tokenNames;

MDBParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x49, 0x1f9, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x5d, 
       0xa, 0x2, 0x3, 0x2, 0x5, 0x2, 0x60, 0xa, 0x2, 0x3, 0x2, 0x5, 0x2, 
       0x63, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x2, 0x5, 0x2, 0x6b, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x7b, 0xa, 
       0x6, 0xc, 0x6, 0xe, 0x6, 0x7e, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x85, 0xa, 0x7, 0xc, 0x7, 0xe, 
       0x7, 0x88, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x8c, 0xa, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x91, 0xa, 0x8, 0xc, 0x8, 
       0xe, 0x8, 0x94, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x98, 0xa, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x9c, 0xa, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x5, 0x8, 0xa1, 0xa, 0x8, 0x5, 0x8, 0xa3, 0xa, 0x8, 
       0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xa7, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xad, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xb4, 0xa, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x5, 0x9, 0xb8, 0xa, 0x9, 0x3, 0x9, 0x5, 0x9, 0xbb, 0xa, 
       0x9, 0x3, 0x9, 0x5, 0x9, 0xbe, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
       0xb, 0x3, 0xb, 0x5, 0xb, 0xc4, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0xc7, 
       0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xcd, 
       0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xd1, 0xa, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xd6, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x5, 0xb, 0xda, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xde, 0xa, 
       0xb, 0x5, 0xb, 0xe0, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xe4, 
       0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xe8, 0xa, 0xd, 0xc, 0xd, 
       0xe, 0xd, 0xeb, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
       0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xf5, 0xa, 0xf, 
       0xc, 0xf, 0xe, 0xf, 0xf8, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x5, 0x10, 0xfd, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x101, 
       0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x104, 0xb, 0x10, 0x3, 0x11, 0x3, 
       0x11, 0x3, 0x11, 0x5, 0x11, 0x109, 0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 
       0x10c, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
       0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x115, 0xa, 0x11, 0x3, 0x11, 
       0x5, 0x11, 0x118, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
       0x11, 0x3, 0x11, 0x5, 0x11, 0x11f, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x7, 0x12, 0x124, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x127, 
       0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x12c, 0xa, 
       0x13, 0xc, 0x13, 0xe, 0x13, 0x12f, 0xb, 0x13, 0x3, 0x14, 0x5, 0x14, 
       0x132, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x136, 0xa, 0x14, 
       0x3, 0x14, 0x5, 0x14, 0x139, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x5, 0x14, 0x13f, 0xa, 0x14, 0x5, 0x14, 0x141, 0xa, 
       0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x14b, 0xa, 0x15, 0x3, 0x16, 
       0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x151, 0xa, 0x17, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x157, 0xa, 0x18, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x15c, 0xa, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x163, 
       0xa, 0x19, 0x3, 0x19, 0x5, 0x19, 0x166, 0xa, 0x19, 0x3, 0x1a, 0x3, 
       0x1a, 0x5, 0x1a, 0x16a, 0xa, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x16d, 0xa, 
       0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x170, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
       0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x176, 0xa, 0x1b, 0x3, 0x1b, 0x7, 
       0x1b, 0x179, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x17c, 0xb, 0x1b, 0x3, 
       0x1b, 0x5, 0x1b, 0x17f, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x187, 0xa, 0x1c, 0xc, 
       0x1c, 0xe, 0x1c, 0x18a, 0xb, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 
       0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x193, 0xa, 
       0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 
       0x1f, 0x5, 0x1f, 0x19b, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 
       0x5, 0x21, 0x1a0, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 
       0x22, 0x3, 0x22, 0x5, 0x22, 0x1a7, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 
       0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x1ae, 0xa, 0x24, 0xc, 
       0x24, 0xe, 0x24, 0x1b1, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x7, 0x25, 0x1b6, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x1b9, 0xb, 0x25, 
       0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x1be, 0xa, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x1c3, 0xa, 0x26, 0x3, 0x26, 
       0x3, 0x26, 0x5, 0x26, 0x1c7, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 
       0x27, 0x7, 0x27, 0x1cc, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x1cf, 0xb, 
       0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x1d4, 0xa, 0x28, 
       0xc, 0x28, 0xe, 0x28, 0x1d7, 0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x1e0, 
       0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1e4, 0xa, 0x2a, 0x3, 
       0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
       0x2a, 0x5, 0x2a, 0x1ed, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
       0x3, 0x2b, 0x5, 0x2b, 0x1f3, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
       0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x2, 0x2, 0x2e, 0x2, 0x4, 0x6, 0x8, 0xa, 
       0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
       0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
       0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
       0x50, 0x52, 0x54, 0x56, 0x58, 0x2, 0xe, 0x6, 0x2, 0x5, 0x5, 0x14, 
       0x14, 0x16, 0x16, 0x1c, 0x1c, 0x4, 0x2, 0x7, 0x7, 0xc, 0xc, 0x4, 
       0x2, 0x3, 0x3, 0x6, 0x6, 0x4, 0x2, 0x27, 0x27, 0x2b, 0x2b, 0x3, 0x2, 
       0x29, 0x2a, 0x4, 0x2, 0x10, 0x10, 0x1f, 0x1f, 0x3, 0x2, 0x3d, 0x3e, 
       0x3, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x30, 0x35, 0x4, 0x2, 0x37, 0x37, 
       0x3a, 0x3b, 0x7, 0x2, 0x9, 0x9, 0xf, 0xf, 0x11, 0x11, 0x1b, 0x1b, 
       0x1d, 0x1d, 0x5, 0x2, 0x4, 0xf, 0x11, 0x1e, 0x20, 0x20, 0x2, 0x222, 
       0x2, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x4, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6, 
       0x6f, 0x3, 0x2, 0x2, 0x2, 0x8, 0x72, 0x3, 0x2, 0x2, 0x2, 0xa, 0x75, 
       0x3, 0x2, 0x2, 0x2, 0xc, 0x7f, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa2, 0x3, 
       0x2, 0x2, 0x2, 0x10, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x12, 0xbf, 0x3, 0x2, 
       0x2, 0x2, 0x14, 0xdf, 0x3, 0x2, 0x2, 0x2, 0x16, 0xe1, 0x3, 0x2, 0x2, 
       0x2, 0x18, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xec, 0x3, 0x2, 0x2, 0x2, 
       0x1c, 0xf1, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x20, 
       0x11e, 0x3, 0x2, 0x2, 0x2, 0x22, 0x120, 0x3, 0x2, 0x2, 0x2, 0x24, 
       0x128, 0x3, 0x2, 0x2, 0x2, 0x26, 0x140, 0x3, 0x2, 0x2, 0x2, 0x28, 
       0x14a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x2c, 
       0x150, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x156, 0x3, 0x2, 0x2, 0x2, 0x30, 
       0x165, 0x3, 0x2, 0x2, 0x2, 0x32, 0x167, 0x3, 0x2, 0x2, 0x2, 0x34, 
       0x173, 0x3, 0x2, 0x2, 0x2, 0x36, 0x182, 0x3, 0x2, 0x2, 0x2, 0x38, 
       0x18d, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x194, 0x3, 0x2, 0x2, 0x2, 0x3c, 
       0x19a, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x40, 
       0x19f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x44, 
       0x1a8, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x48, 
       0x1b2, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x4c, 
       0x1c8, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x50, 
       0x1df, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x54, 
       0x1f2, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x58, 
       0x1f6, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5c, 0x5, 0x6, 0x4, 0x2, 0x5b, 
       0x5d, 0x5, 0x8, 0x5, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 
       0x3, 0x2, 0x2, 0x2, 0x5d, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x60, 0x5, 
       0xa, 0x6, 0x2, 0x5f, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 
       0x2, 0x2, 0x60, 0x62, 0x3, 0x2, 0x2, 0x2, 0x61, 0x63, 0x5, 0xc, 0x7, 
       0x2, 0x62, 0x61, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 
       0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x5, 0xe, 0x8, 0x2, 0x65, 
       0x66, 0x7, 0x2, 0x2, 0x3, 0x66, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 
       0x5, 0x4, 0x3, 0x2, 0x68, 0x69, 0x7, 0x2, 0x2, 0x3, 0x69, 0x6b, 0x3, 
       0x2, 0x2, 0x2, 0x6a, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x67, 0x3, 0x2, 
       0x2, 0x2, 0x6b, 0x3, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0xb, 0x2, 
       0x2, 0x6d, 0x6e, 0x5, 0x2e, 0x18, 0x2, 0x6e, 0x5, 0x3, 0x2, 0x2, 
       0x2, 0x6f, 0x70, 0x7, 0x15, 0x2, 0x2, 0x70, 0x71, 0x5, 0x18, 0xd, 
       0x2, 0x71, 0x7, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x7, 0x20, 0x2, 0x2, 
       0x73, 0x74, 0x5, 0x44, 0x23, 0x2, 0x74, 0x9, 0x3, 0x2, 0x2, 0x2, 
       0x75, 0x76, 0x7, 0x12, 0x2, 0x2, 0x76, 0x77, 0x7, 0x8, 0x2, 0x2, 
       0x77, 0x7c, 0x5, 0x16, 0xc, 0x2, 0x78, 0x79, 0x7, 0x45, 0x2, 0x2, 
       0x79, 0x7b, 0x5, 0x16, 0xc, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 
       0x7b, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7c, 
       0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7c, 
       0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x18, 0x2, 0x2, 0x80, 0x81, 
       0x7, 0x8, 0x2, 0x2, 0x81, 0x86, 0x5, 0x14, 0xb, 0x2, 0x82, 0x83, 
       0x7, 0x45, 0x2, 0x2, 0x83, 0x85, 0x5, 0x14, 0xb, 0x2, 0x84, 0x82, 
       0x3, 0x2, 0x2, 0x2, 0x85, 0x88, 0x3, 0x2, 0x2, 0x2, 0x86, 0x84, 0x3, 
       0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 0xd, 0x3, 0x2, 
       0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8b, 0x7, 0x1e, 
       0x2, 0x2, 0x8a, 0x8c, 0x7, 0xd, 0x2, 0x2, 0x8b, 0x8a, 0x3, 0x2, 0x2, 
       0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 
       0x8d, 0x92, 0x5, 0x10, 0x9, 0x2, 0x8e, 0x8f, 0x7, 0x45, 0x2, 0x2, 
       0x8f, 0x91, 0x5, 0x10, 0x9, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 
       0x91, 0x94, 0x3, 0x2, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 
       0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x97, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 
       0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x7, 0x13, 0x2, 0x2, 0x96, 0x98, 
       0x7, 0x2d, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 
       0x3, 0x2, 0x2, 0x2, 0x98, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9b, 0x7, 
       0x1e, 0x2, 0x2, 0x9a, 0x9c, 0x7, 0xd, 0x2, 0x2, 0x9b, 0x9a, 0x3, 
       0x2, 0x2, 0x2, 0x9b, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x3, 0x2, 
       0x2, 0x2, 0x9d, 0xa0, 0x7, 0x3a, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x13, 
       0x2, 0x2, 0x9f, 0xa1, 0x7, 0x2d, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 
       0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa3, 0x3, 0x2, 0x2, 
       0x2, 0xa2, 0x89, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x99, 0x3, 0x2, 0x2, 0x2, 
       0xa3, 0xf, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa6, 0x7, 0x2b, 0x2, 0x2, 0xa5, 
       0xa7, 0x7, 0x28, 0x2, 0x2, 0xa6, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa6, 
       0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 
       0x5, 0x12, 0xa, 0x2, 0xa9, 0xaa, 0x7, 0x3f, 0x2, 0x2, 0xaa, 0xac, 
       0x7, 0x2b, 0x2, 0x2, 0xab, 0xad, 0x7, 0x28, 0x2, 0x2, 0xac, 0xab, 
       0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 
       0x2, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x40, 0x2, 0x2, 0xaf, 0xbe, 0x3, 
       0x2, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0xa, 0x2, 0x2, 0xb1, 0xb3, 0x7, 0x3f, 
       0x2, 0x2, 0xb2, 0xb4, 0x7, 0xd, 0x2, 0x2, 0xb3, 0xb2, 0x3, 0x2, 0x2, 
       0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xba, 0x3, 0x2, 0x2, 0x2, 
       0xb5, 0xb7, 0x7, 0x2b, 0x2, 0x2, 0xb6, 0xb8, 0x7, 0x28, 0x2, 0x2, 
       0xb7, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 
       0xbb, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbb, 0x7, 0x3a, 0x2, 0x2, 0xba, 
       0xb5, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 
       0x3, 0x2, 0x2, 0x2, 0xbc, 0xbe, 0x7, 0x40, 0x2, 0x2, 0xbd, 0xa4, 
       0x3, 0x2, 0x2, 0x2, 0xbd, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xb0, 0x3, 
       0x2, 0x2, 0x2, 0xbe, 0x11, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x9, 0x2, 
       0x2, 0x2, 0xc0, 0x13, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc3, 0x7, 0x2b, 
       0x2, 0x2, 0xc2, 0xc4, 0x7, 0x28, 0x2, 0x2, 0xc3, 0xc2, 0x3, 0x2, 
       0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc6, 0x3, 0x2, 0x2, 
       0x2, 0xc5, 0xc7, 0x9, 0x3, 0x2, 0x2, 0xc6, 0xc5, 0x3, 0x2, 0x2, 0x2, 
       0xc6, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xc8, 
       0xc9, 0x5, 0x12, 0xa, 0x2, 0xc9, 0xca, 0x7, 0x3f, 0x2, 0x2, 0xca, 
       0xcc, 0x7, 0x2b, 0x2, 0x2, 0xcb, 0xcd, 0x7, 0x28, 0x2, 0x2, 0xcc, 
       0xcb, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 
       0x3, 0x2, 0x2, 0x2, 0xce, 0xd0, 0x7, 0x40, 0x2, 0x2, 0xcf, 0xd1, 
       0x9, 0x3, 0x2, 0x2, 0xd0, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 
       0x2, 0x2, 0x2, 0xd1, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0xa, 
       0x2, 0x2, 0xd3, 0xd5, 0x7, 0x3f, 0x2, 0x2, 0xd4, 0xd6, 0x7, 0xd, 
       0x2, 0x2, 0xd5, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x3, 0x2, 0x2, 
       0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd9, 0x7, 0x2b, 0x2, 
       0x2, 0xd8, 0xda, 0x7, 0x28, 0x2, 0x2, 0xd9, 0xd8, 0x3, 0x2, 0x2, 
       0x2, 0xd9, 0xda, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x3, 0x2, 0x2, 0x2, 
       0xdb, 0xdd, 0x7, 0x40, 0x2, 0x2, 0xdc, 0xde, 0x9, 0x3, 0x2, 0x2, 
       0xdd, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 
       0xe0, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xc8, 
       0x3, 0x2, 0x2, 0x2, 0xdf, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x15, 0x3, 
       0x2, 0x2, 0x2, 0xe1, 0xe3, 0x7, 0x2b, 0x2, 0x2, 0xe2, 0xe4, 0x7, 
       0x28, 0x2, 0x2, 0xe3, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3, 
       0x2, 0x2, 0x2, 0xe4, 0x17, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe9, 0x5, 0x1c, 
       0xf, 0x2, 0xe6, 0xe8, 0x5, 0x1a, 0xe, 0x2, 0xe7, 0xe6, 0x3, 0x2, 
       0x2, 0x2, 0xe8, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 
       0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 0x2, 0xea, 0x19, 0x3, 0x2, 0x2, 0x2, 
       0xeb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 0x17, 0x2, 0x2, 
       0xed, 0xee, 0x7, 0x41, 0x2, 0x2, 0xee, 0xef, 0x5, 0x18, 0xd, 0x2, 
       0xef, 0xf0, 0x7, 0x42, 0x2, 0x2, 0xf0, 0x1b, 0x3, 0x2, 0x2, 0x2, 
       0xf1, 0xf6, 0x5, 0x1e, 0x10, 0x2, 0xf2, 0xf3, 0x7, 0x45, 0x2, 0x2, 
       0xf3, 0xf5, 0x5, 0x1e, 0x10, 0x2, 0xf4, 0xf2, 0x3, 0x2, 0x2, 0x2, 
       0xf5, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6, 
       0xf7, 0x3, 0x2, 0x2, 0x2, 0xf7, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf6, 
       0x3, 0x2, 0x2, 0x2, 0xf9, 0x102, 0x5, 0x2c, 0x17, 0x2, 0xfa, 0xfd, 
       0x5, 0x30, 0x19, 0x2, 0xfb, 0xfd, 0x5, 0x20, 0x11, 0x2, 0xfc, 0xfa, 
       0x3, 0x2, 0x2, 0x2, 0xfc, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x3, 
       0x2, 0x2, 0x2, 0xfe, 0xff, 0x5, 0x2c, 0x17, 0x2, 0xff, 0x101, 0x3, 
       0x2, 0x2, 0x2, 0x100, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x101, 0x104, 0x3, 
       0x2, 0x2, 0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x3, 
       0x2, 0x2, 0x2, 0x103, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x104, 0x102, 0x3, 
       0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0x30, 0x2, 0x2, 0x106, 0x108, 0x7, 
       0x43, 0x2, 0x2, 0x107, 0x109, 0x5, 0x2a, 0x16, 0x2, 0x108, 0x107, 
       0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10b, 
       0x3, 0x2, 0x2, 0x2, 0x10a, 0x10c, 0x7, 0x2b, 0x2, 0x2, 0x10b, 0x10a, 
       0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 
       0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x5, 0x22, 0x12, 0x2, 0x10e, 0x10f, 
       0x7, 0x44, 0x2, 0x2, 0x10f, 0x110, 0x7, 0x36, 0x2, 0x2, 0x110, 0x11f, 
       0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x7, 0x36, 0x2, 0x2, 0x112, 0x114, 
       0x7, 0x43, 0x2, 0x2, 0x113, 0x115, 0x5, 0x2a, 0x16, 0x2, 0x114, 0x113, 
       0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x3, 0x2, 0x2, 0x2, 0x115, 0x117, 
       0x3, 0x2, 0x2, 0x2, 0x116, 0x118, 0x7, 0x2b, 0x2, 0x2, 0x117, 0x116, 
       0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 
       0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x5, 0x22, 0x12, 0x2, 0x11a, 0x11b, 
       0x7, 0x44, 0x2, 0x2, 0x11b, 0x11c, 0x7, 0x36, 0x2, 0x2, 0x11c, 0x11d, 
       0x7, 0x35, 0x2, 0x2, 0x11d, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x105, 
       0x3, 0x2, 0x2, 0x2, 0x11e, 0x111, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x21, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x125, 0x5, 0x24, 0x13, 0x2, 0x121, 0x122, 
       0x7, 0x38, 0x2, 0x2, 0x122, 0x124, 0x5, 0x24, 0x13, 0x2, 0x123, 0x121, 
       0x3, 0x2, 0x2, 0x2, 0x124, 0x127, 0x3, 0x2, 0x2, 0x2, 0x125, 0x123, 
       0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 0x2, 0x2, 0x2, 0x126, 0x23, 
       0x3, 0x2, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 0x128, 0x12d, 
       0x5, 0x26, 0x14, 0x2, 0x129, 0x12a, 0x7, 0x37, 0x2, 0x2, 0x12a, 0x12c, 
       0x5, 0x26, 0x14, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12f, 
       0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 
       0x3, 0x2, 0x2, 0x2, 0x12e, 0x25, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12d, 
       0x3, 0x2, 0x2, 0x2, 0x130, 0x132, 0x7, 0x39, 0x2, 0x2, 0x131, 0x130, 
       0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 
       0x3, 0x2, 0x2, 0x2, 0x133, 0x135, 0x7, 0x29, 0x2, 0x2, 0x134, 0x136, 
       0x5, 0x28, 0x15, 0x2, 0x135, 0x134, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 
       0x3, 0x2, 0x2, 0x2, 0x136, 0x141, 0x3, 0x2, 0x2, 0x2, 0x137, 0x139, 
       0x7, 0x39, 0x2, 0x2, 0x138, 0x137, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 
       0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 
       0x7, 0x3f, 0x2, 0x2, 0x13b, 0x13c, 0x5, 0x22, 0x12, 0x2, 0x13c, 0x13e, 
       0x7, 0x40, 0x2, 0x2, 0x13d, 0x13f, 0x5, 0x28, 0x15, 0x2, 0x13e, 0x13d, 
       0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x141, 
       0x3, 0x2, 0x2, 0x2, 0x140, 0x131, 0x3, 0x2, 0x2, 0x2, 0x140, 0x138, 
       0x3, 0x2, 0x2, 0x2, 0x141, 0x27, 0x3, 0x2, 0x2, 0x2, 0x142, 0x14b, 
       0x7, 0x3a, 0x2, 0x2, 0x143, 0x14b, 0x7, 0x3d, 0x2, 0x2, 0x144, 0x14b, 
       0x7, 0x3c, 0x2, 0x2, 0x145, 0x146, 0x7, 0x41, 0x2, 0x2, 0x146, 0x147, 
       0x7, 0x2d, 0x2, 0x2, 0x147, 0x148, 0x7, 0x45, 0x2, 0x2, 0x148, 0x149, 
       0x7, 0x2d, 0x2, 0x2, 0x149, 0x14b, 0x7, 0x42, 0x2, 0x2, 0x14a, 0x142, 
       0x3, 0x2, 0x2, 0x2, 0x14a, 0x143, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x144, 
       0x3, 0x2, 0x2, 0x2, 0x14a, 0x145, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x29, 
       0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x9, 0x4, 0x2, 0x2, 0x14d, 0x2b, 
       0x3, 0x2, 0x2, 0x2, 0x14e, 0x151, 0x5, 0x2e, 0x18, 0x2, 0x14f, 0x151, 
       0x5, 0x34, 0x1b, 0x2, 0x150, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x150, 0x14f, 
       0x3, 0x2, 0x2, 0x2, 0x151, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x152, 0x157, 
       0x5, 0x3a, 0x1e, 0x2, 0x153, 0x157, 0x7, 0x25, 0x2, 0x2, 0x154, 0x157, 
       0x7, 0x26, 0x2, 0x2, 0x155, 0x157, 0x5, 0x42, 0x22, 0x2, 0x156, 0x152, 
       0x3, 0x2, 0x2, 0x2, 0x156, 0x153, 0x3, 0x2, 0x2, 0x2, 0x156, 0x154, 
       0x3, 0x2, 0x2, 0x2, 0x156, 0x155, 0x3, 0x2, 0x2, 0x2, 0x157, 0x2f, 
       0x3, 0x2, 0x2, 0x2, 0x158, 0x15b, 0x7, 0x34, 0x2, 0x2, 0x159, 0x15a, 
       0x7, 0x3e, 0x2, 0x2, 0x15a, 0x15c, 0x5, 0x32, 0x1a, 0x2, 0x15b, 0x159, 
       0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 
       0x3, 0x2, 0x2, 0x2, 0x15d, 0x166, 0x7, 0x3e, 0x2, 0x2, 0x15e, 0x162, 
       0x7, 0x3e, 0x2, 0x2, 0x15f, 0x160, 0x5, 0x32, 0x1a, 0x2, 0x160, 0x161, 
       0x7, 0x3e, 0x2, 0x2, 0x161, 0x163, 0x3, 0x2, 0x2, 0x2, 0x162, 0x15f, 
       0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 
       0x3, 0x2, 0x2, 0x2, 0x164, 0x166, 0x7, 0x35, 0x2, 0x2, 0x165, 0x158, 
       0x3, 0x2, 0x2, 0x2, 0x165, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x166, 0x31, 
       0x3, 0x2, 0x2, 0x2, 0x167, 0x169, 0x7, 0x43, 0x2, 0x2, 0x168, 0x16a, 
       0x9, 0x5, 0x2, 0x2, 0x169, 0x168, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 
       0x3, 0x2, 0x2, 0x2, 0x16a, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16d, 
       0x9, 0x6, 0x2, 0x2, 0x16c, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16d, 
       0x3, 0x2, 0x2, 0x2, 0x16d, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x170, 
       0x5, 0x36, 0x1c, 0x2, 0x16f, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 
       0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 
       0x7, 0x44, 0x2, 0x2, 0x172, 0x33, 0x3, 0x2, 0x2, 0x2, 0x173, 0x175, 
       0x7, 0x3f, 0x2, 0x2, 0x174, 0x176, 0x7, 0x2b, 0x2, 0x2, 0x175, 0x174, 
       0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x3, 0x2, 0x2, 0x2, 0x176, 0x17a, 
       0x3, 0x2, 0x2, 0x2, 0x177, 0x179, 0x7, 0x29, 0x2, 0x2, 0x178, 0x177, 
       0x3, 0x2, 0x2, 0x2, 0x179, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x178, 
       0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17e, 
       0x3, 0x2, 0x2, 0x2, 0x17c, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17f, 
       0x5, 0x36, 0x1c, 0x2, 0x17e, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 
       0x3, 0x2, 0x2, 0x2, 0x17f, 0x180, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 
       0x7, 0x40, 0x2, 0x2, 0x181, 0x35, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 
       0x7, 0x41, 0x2, 0x2, 0x183, 0x188, 0x5, 0x38, 0x1d, 0x2, 0x184, 0x185, 
       0x7, 0x45, 0x2, 0x2, 0x185, 0x187, 0x5, 0x38, 0x1d, 0x2, 0x186, 0x184, 
       0x3, 0x2, 0x2, 0x2, 0x187, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x188, 0x186, 
       0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18b, 
       0x3, 0x2, 0x2, 0x2, 0x18a, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18c, 
       0x7, 0x42, 0x2, 0x2, 0x18c, 0x37, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x192, 
       0x5, 0x3c, 0x1f, 0x2, 0x18e, 0x18f, 0x7, 0x46, 0x2, 0x2, 0x18f, 0x193, 
       0x5, 0x42, 0x22, 0x2, 0x190, 0x193, 0x7, 0x21, 0x2, 0x2, 0x191, 0x193, 
       0x7, 0x22, 0x2, 0x2, 0x192, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x192, 0x190, 
       0x3, 0x2, 0x2, 0x2, 0x192, 0x191, 0x3, 0x2, 0x2, 0x2, 0x193, 0x39, 
       0x3, 0x2, 0x2, 0x2, 0x194, 0x195, 0x7, 0x3f, 0x2, 0x2, 0x195, 0x196, 
       0x5, 0x3c, 0x1f, 0x2, 0x196, 0x197, 0x7, 0x40, 0x2, 0x2, 0x197, 0x3b, 
       0x3, 0x2, 0x2, 0x2, 0x198, 0x19b, 0x7, 0x2f, 0x2, 0x2, 0x199, 0x19b, 
       0x5, 0x58, 0x2d, 0x2, 0x19a, 0x198, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x199, 
       0x3, 0x2, 0x2, 0x2, 0x19b, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19d, 
       0x9, 0x7, 0x2, 0x2, 0x19d, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a0, 
       0x9, 0x8, 0x2, 0x2, 0x19f, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 
       0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 
       0x9, 0x9, 0x2, 0x2, 0x1a2, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a7, 
       0x5, 0x40, 0x21, 0x2, 0x1a4, 0x1a7, 0x7, 0x2c, 0x2, 0x2, 0x1a5, 0x1a7, 
       0x5, 0x3e, 0x20, 0x2, 0x1a6, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a4, 
       0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x43, 
       0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x5, 0x46, 0x24, 0x2, 0x1a9, 0x45, 
       0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1af, 0x5, 0x48, 0x25, 0x2, 0x1ab, 0x1ac, 
       0x7, 0x19, 0x2, 0x2, 0x1ac, 0x1ae, 0x5, 0x48, 0x25, 0x2, 0x1ad, 0x1ab, 
       0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1ad, 
       0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x47, 
       0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b7, 
       0x5, 0x4a, 0x26, 0x2, 0x1b3, 0x1b4, 0x7, 0x4, 0x2, 0x2, 0x1b4, 0x1b6, 
       0x5, 0x4a, 0x26, 0x2, 0x1b5, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b9, 
       0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 
       0x3, 0x2, 0x2, 0x2, 0x1b8, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1b7, 
       0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bd, 0x5, 0x4c, 0x27, 0x2, 0x1bb, 0x1bc, 
       0x9, 0xa, 0x2, 0x2, 0x1bc, 0x1be, 0x5, 0x4c, 0x27, 0x2, 0x1bd, 0x1bb, 
       0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1c7, 
       0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 0x5, 0x4c, 0x27, 0x2, 0x1c0, 0x1c2, 
       0x7, 0xe, 0x2, 0x2, 0x1c1, 0x1c3, 0x7, 0x1a, 0x2, 0x2, 0x1c2, 0x1c1, 
       0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c4, 
       0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x5, 0x56, 0x2c, 0x2, 0x1c5, 0x1c7, 
       0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1bf, 
       0x3, 0x2, 0x2, 0x2, 0x1c7, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1cd, 
       0x5, 0x4e, 0x28, 0x2, 0x1c9, 0x1ca, 0x9, 0x8, 0x2, 0x2, 0x1ca, 0x1cc, 
       0x5, 0x4e, 0x28, 0x2, 0x1cb, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cf, 
       0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1ce, 
       0x3, 0x2, 0x2, 0x2, 0x1ce, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1cd, 
       0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d5, 0x5, 0x50, 0x29, 0x2, 0x1d1, 0x1d2, 
       0x9, 0xb, 0x2, 0x2, 0x1d2, 0x1d4, 0x5, 0x50, 0x29, 0x2, 0x1d3, 0x1d1, 
       0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d3, 
       0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x4f, 
       0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 
       0x7, 0x1a, 0x2, 0x2, 0x1d9, 0x1e0, 0x5, 0x50, 0x29, 0x2, 0x1da, 0x1db, 
       0x7, 0x3d, 0x2, 0x2, 0x1db, 0x1e0, 0x5, 0x50, 0x29, 0x2, 0x1dc, 0x1dd, 
       0x7, 0x3e, 0x2, 0x2, 0x1dd, 0x1e0, 0x5, 0x50, 0x29, 0x2, 0x1de, 0x1e0, 
       0x5, 0x52, 0x2a, 0x2, 0x1df, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1da, 
       0x3, 0x2, 0x2, 0x2, 0x1df, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1de, 
       0x3, 0x2, 0x2, 0x2, 0x1e0, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e3, 
       0x7, 0x2b, 0x2, 0x2, 0x1e2, 0x1e4, 0x7, 0x28, 0x2, 0x2, 0x1e3, 0x1e2, 
       0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1ed, 
       0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1ed, 0x5, 0x54, 0x2b, 0x2, 0x1e6, 0x1e7, 
       0x7, 0x3f, 0x2, 0x2, 0x1e7, 0x1e8, 0x5, 0x44, 0x23, 0x2, 0x1e8, 0x1e9, 
       0x7, 0x40, 0x2, 0x2, 0x1e9, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1ed, 
       0x7, 0x23, 0x2, 0x2, 0x1eb, 0x1ed, 0x7, 0x24, 0x2, 0x2, 0x1ec, 0x1e1, 
       0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1e6, 
       0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1eb, 
       0x3, 0x2, 0x2, 0x2, 0x1ed, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1f3, 
       0x7, 0x2d, 0x2, 0x2, 0x1ef, 0x1f3, 0x7, 0x2e, 0x2, 0x2, 0x1f0, 0x1f3, 
       0x7, 0x2c, 0x2, 0x2, 0x1f1, 0x1f3, 0x5, 0x3e, 0x20, 0x2, 0x1f2, 0x1ee, 
       0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f0, 
       0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x55, 
       0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f5, 0x9, 0xc, 0x2, 0x2, 0x1f5, 0x57, 
       0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x9, 0xd, 0x2, 0x2, 0x1f7, 0x59, 
       0x3, 0x2, 0x2, 0x2, 0x49, 0x5c, 0x5f, 0x62, 0x6a, 0x7c, 0x86, 0x8b, 
       0x92, 0x97, 0x9b, 0xa0, 0xa2, 0xa6, 0xac, 0xb3, 0xb7, 0xba, 0xbd, 
       0xc3, 0xc6, 0xcc, 0xd0, 0xd5, 0xd9, 0xdd, 0xdf, 0xe3, 0xe9, 0xf6, 
       0xfc, 0x102, 0x108, 0x10b, 0x114, 0x117, 0x11e, 0x125, 0x12d, 0x131, 
       0x135, 0x138, 0x13e, 0x140, 0x14a, 0x150, 0x156, 0x15b, 0x162, 0x165, 
       0x169, 0x16c, 0x16f, 0x175, 0x17a, 0x17e, 0x188, 0x192, 0x19a, 0x19f, 
       0x1a6, 0x1af, 0x1b7, 0x1bd, 0x1c2, 0x1c6, 0x1cd, 0x1d5, 0x1df, 0x1e3, 
       0x1ec, 0x1f2, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MDBParser::Initializer MDBParser::_init;
