#pragma once

#include <boost/fusion/include/adapt_struct.hpp>

#include "parser/import/grammar/common/common_ast.h"

BOOST_FUSION_ADAPT_STRUCT(common::ast::Property,
    key, value
)
