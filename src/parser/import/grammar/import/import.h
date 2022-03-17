#pragma once

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/home/x3.hpp>

#include "import_ast.h"

namespace import {

    namespace parser {
        namespace x3 = boost::spirit::x3;
        using import_type = x3::rule<class import_line, ast::ImportLine>;
        BOOST_SPIRIT_DECLARE(import_type)
    }

    parser::import_type import();
}
