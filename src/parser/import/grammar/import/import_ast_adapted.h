#pragma once

#include "import_ast.h"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(import::ast::Node,
    name, labels, properties
)

BOOST_FUSION_ADAPT_STRUCT(import::ast::Edge,
    lhs_id, direction, rhs_id, labels, properties
)

BOOST_FUSION_ADAPT_STRUCT(import::ast::ImplicitEdge,
    nesting, direction, rhs_id, labels, properties
)
