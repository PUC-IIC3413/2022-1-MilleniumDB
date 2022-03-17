#pragma once

#include <memory>
#include <ostream>
#include <type_traits>
#include <variant>

#include "base/graph_object/anonymous_node.h"
#include "base/graph_object/edge.h"
#include "base/graph_object/named_node_external.h"
#include "base/graph_object/named_node_inlined.h"
#include "base/graph_object/named_node_tmp.h"
#include "base/graph_object/not_found_object.h"
#include "base/graph_object/null_graph_object.h"
#include "base/graph_object/path.h"
#include "base/graph_object/string_external.h"
#include "base/graph_object/string_inlined.h"
#include "base/graph_object/string_tmp.h"

// int64_t and float needs to be contigous
// StringInlined and StringExternal needs to be contigous
// NamedNodeInlined and NamedNodeExternal needs to be contigous
using GraphObjectVariant = std::variant<NullGraphObject, NotFoundObject,
                                        NamedNodeInlined, NamedNodeExternal, NamedNodeTmp,
                                        Edge, AnonymousNode, Path,
                                        StringInlined, StringExternal, StringTmp,
                                        bool, int64_t, float>;

struct GraphObjectOstreamVisitor {
    std::ostream& os;

    GraphObjectOstreamVisitor(std::ostream& os) : os(os) { }

    void operator()(const NamedNodeInlined& n) const {
        os << n.id;
    }

    void operator()(const NamedNodeExternal& n) const {
        os << n.to_string();
    }

    void operator()(const NamedNodeTmp& n) const {
        os << *n.name;
    }

    void operator()(const StringInlined& s) const {
        os << '"' << s.id << '"';
    }

    void operator()(const StringExternal& s) const {
        os << '"' << s.to_string() << '"';
    }

    void operator()(const StringTmp& s) const {
        os << '"' << *s.str << '"';
    }

    void operator()(const Edge& e) const {
        os << "_e" << e.id;
    }

    void operator()(const AnonymousNode& a) const {
        os << "_a" << a.id;
    }

    void operator()(const NullGraphObject&) const {
        os << "null";
    }

    void operator()(const NotFoundObject&) const {
        os << "NotFoundObj";
    }

    void operator()(const int64_t n) const {
        os << n;
    }

    void operator()(const float f) const {
        os << f;
    }

    void operator()(const bool b) const {
        os << (b ? "true" : "false");
    }

    void operator()(const Path& p) const {
        p.path_printer->print(os, p.path_id);
    }
};

class GraphObject {
public:
    GraphObjectVariant value;

    GraphObject() : value(NullGraphObject()) { }

    static GraphObject make_named_node_external(uint64_t external_id) {
        NamedNodeExternal named_node_external(external_id);
        return GraphObject(named_node_external);
    }

    static GraphObject make_named_node_inlined(const char c[8]) {
        NamedNodeInlined named_node_inlined { c };
        return GraphObject(named_node_inlined);
    }

    static GraphObject make_named_node_tmp(const std::string& tmp) {
        GraphObjectVariant named_node_tmp = NamedNodeTmp(tmp);
        return GraphObject(std::move(named_node_tmp));
    }

    static GraphObject make_anonymous(uint64_t id) {
        return GraphObject(AnonymousNode(id));
    }

    static GraphObject make_edge(uint64_t id) {
        return GraphObject(Edge(id));
    }

    static GraphObject make_int(int64_t i) {
        return GraphObject(i);
    }

    static GraphObject make_float(float f) {
        return GraphObject(f);
    }

    static GraphObject make_bool(bool b) {
        return GraphObject(b);
    }

    static GraphObject make_null() {
        return GraphObject(NullGraphObject());
    }

    static GraphObject make_not_found() {
        return GraphObject(NotFoundObject());
    }

    static GraphObject make_string(const std::string& str) {
        if (str.size() < 8) {
            char c[8];
            std::size_t i = 0;
            for (; i < str.size(); ++i) {
                c[i] = str[i];
            }
            for (; i < 8; ++i) {
                c[i] = '\0';
            }
            return GraphObject::make_string_inlined(c);
        } else {
            return GraphObject::make_string_tmp(str);
        }
    }

    static GraphObject make_named_node(const std::string& str) {
        if (str.size() < 8) {
            char c[8];
            std::size_t i = 0;
            for (; i < str.size(); ++i) {
                c[i] = str[i];
            }
            for (; i < 8; ++i) {
                c[i] = '\0';
            }
            return GraphObject::make_named_node_inlined(c);
        } else {
            return GraphObject::make_named_node_tmp(str);
        }
    }

    static GraphObject make_string_external(uint64_t external_id) {
        StringExternal string_external { external_id };
        return GraphObject(string_external);
    }

    // must receive an array of size 8, terminating in '\0'
    static GraphObject make_string_inlined(const char* str) {
        StringInlined string_inlined { str };
        return GraphObject(string_inlined);
    }

    static GraphObject make_string_tmp(const std::string& str) {
        StringTmp string_tmp { str };
        return GraphObject(string_tmp);
    }

    static GraphObject make_path(uint64_t path_id) {
        Path p { path_id };
        return GraphObject(p);
    }

    friend std::ostream& operator<<(std::ostream& os, const GraphObject& graph_obj) {
        std::visit(GraphObjectOstreamVisitor { os }, graph_obj.value);
        return os;
    }

    inline bool operator==(const GraphObject& rhs) const noexcept {
        return this->value == rhs.value;
    }

    inline bool operator!=(const GraphObject& rhs) const noexcept {
        return this->value != rhs.value;
    }

    inline bool operator<=(const GraphObject& rhs) const noexcept {
        if (std::holds_alternative<NamedNodeExternal>(this->value)) {
            if (std::holds_alternative<NamedNodeInlined>(rhs.value)) {
                return strcmp(std::get<NamedNodeExternal>(this->value).to_string().c_str(),
                              std::get<NamedNodeInlined>(rhs.value).id)
                    <= 0;
            }
        }

        else if (std::holds_alternative<NamedNodeInlined>(this->value)) {
            if (std::holds_alternative<NamedNodeExternal>(rhs.value)) {
                return strcmp(std::get<NamedNodeInlined>(this->value).id,
                              std::get<NamedNodeExternal>(rhs.value).to_string().c_str())
                    <= 0;
            }
        }

        else if (std::holds_alternative<StringExternal>(this->value)) {
            if (std::holds_alternative<StringInlined>(rhs.value)) {
                return strcmp(std::get<StringExternal>(this->value).to_string().c_str(),
                              std::get<StringInlined>(rhs.value).id) <= 0;
            }
        }

        else if (std::holds_alternative<StringInlined>(this->value)) {
            if (std::holds_alternative<StringExternal>(rhs.value)) {
                return strcmp(std::get<StringInlined>(this->value).id,
                                                      std::get<StringExternal>(rhs.value).to_string().c_str()) <= 0;
            }
        }

        else if (std::holds_alternative<int64_t>(this->value)) {
            if (std::holds_alternative<float>(rhs.value)) {
                return std::get<int64_t>(this->value) <= std::get<float>(rhs.value);
            }
        }

        else if (std::holds_alternative<float>(this->value)) {
            if (std::holds_alternative<int64_t>(rhs.value)) {
                return std::get<float>(this->value) <= std::get<int64_t>(rhs.value);
            }
        }
        return this->value <= rhs.value;
    }

    inline bool operator>=(const GraphObject& rhs) const noexcept {
        if (std::holds_alternative<NamedNodeExternal>(this->value)) {
            if (std::holds_alternative<NamedNodeInlined>(rhs.value)) {
                return strcmp(std::get<NamedNodeExternal>(this->value).to_string().c_str(),
                              std::get<NamedNodeInlined>(rhs.value).id)
                    >= 0;
            }
        }

        else if (std::holds_alternative<NamedNodeInlined>(this->value)) {
            if (std::holds_alternative<NamedNodeExternal>(rhs.value)) {
                return strcmp(std::get<NamedNodeInlined>(this->value).id,
                              std::get<NamedNodeExternal>(rhs.value).to_string().c_str())
                    >= 0;
            }
        }

        else if (std::holds_alternative<StringExternal>(this->value)) {
            if (std::holds_alternative<StringInlined>(rhs.value)) {
                return strcmp(std::get<StringExternal>(this->value).to_string().c_str(),
                              std::get<StringInlined>(rhs.value).id)
                    >= 0;
            }
        }

        else if (std::holds_alternative<StringInlined>(this->value)) {
            if (std::holds_alternative<StringExternal>(rhs.value)) {
                return strcmp(std::get<StringInlined>(this->value).id,
                              std::get<StringExternal>(rhs.value).to_string().c_str())
                    >= 0;
            }
        }

        else if (std::holds_alternative<int64_t>(this->value)) {
            if (std::holds_alternative<float>(rhs.value)) {
                return std::get<int64_t>(this->value) >= std::get<float>(rhs.value);
            }
        }

        else if (std::holds_alternative<float>(this->value)) {
            if (std::holds_alternative<int64_t>(rhs.value)) {
                return std::get<float>(this->value) >= std::get<int64_t>(rhs.value);
            }
        }
        return this->value >= rhs.value;
    }

    inline bool operator<(const GraphObject& rhs) const noexcept {
        if (std::holds_alternative<NamedNodeExternal>(this->value)) {
            if (std::holds_alternative<NamedNodeInlined>(rhs.value)) {
                return strcmp(std::get<NamedNodeExternal>(this->value).to_string().c_str(),
                              std::get<NamedNodeInlined>(rhs.value).id)
                    < 0;
            }
        }

        else if (std::holds_alternative<NamedNodeInlined>(this->value)) {
            if (std::holds_alternative<NamedNodeExternal>(rhs.value)) {
                return strcmp(std::get<NamedNodeInlined>(this->value).id,
                              std::get<NamedNodeExternal>(rhs.value).to_string().c_str())
                    < 0;
            }
        }

        else if (std::holds_alternative<StringExternal>(this->value)) {
            if (std::holds_alternative<StringInlined>(rhs.value)) {
                return strcmp(std::get<StringExternal>(this->value).to_string().c_str(),
                              std::get<StringInlined>(rhs.value).id)
                    < 0;
            }
        }

        else if (std::holds_alternative<StringInlined>(this->value)) {
            if (std::holds_alternative<StringExternal>(rhs.value)) {
                return strcmp(std::get<StringInlined>(this->value).id,
                              std::get<StringExternal>(rhs.value).to_string().c_str())
                    < 0;
            }
        }

        else if (std::holds_alternative<int64_t>(this->value)) {
            if (std::holds_alternative<float>(rhs.value)) {
                return std::get<int64_t>(this->value) < std::get<float>(rhs.value);
            }
        }

        else if (std::holds_alternative<float>(this->value)) {
            if (std::holds_alternative<int64_t>(rhs.value)) {
                return std::get<float>(this->value) < std::get<int64_t>(rhs.value);
            }
        }
        return this->value < rhs.value;
    }

    inline bool operator>(const GraphObject& rhs) const noexcept {
        if (std::holds_alternative<NamedNodeExternal>(this->value)) {
            if (std::holds_alternative<NamedNodeInlined>(rhs.value)) {
                return strcmp(std::get<NamedNodeExternal>(this->value).to_string().c_str(),
                              std::get<NamedNodeInlined>(rhs.value).id)
                    > 0;
            }
        }

        else if (std::holds_alternative<NamedNodeInlined>(this->value)) {
            if (std::holds_alternative<NamedNodeExternal>(rhs.value)) {
                return strcmp(std::get<NamedNodeInlined>(this->value).id,
                              std::get<NamedNodeExternal>(rhs.value).to_string().c_str())
                    > 0;
            }
        }

        else if (std::holds_alternative<StringExternal>(this->value)) {
            if (std::holds_alternative<StringInlined>(rhs.value)) {
                return strcmp(std::get<StringExternal>(this->value).to_string().c_str(),
                              std::get<StringInlined>(rhs.value).id)
                    > 0;
            }
        }

        else if (std::holds_alternative<StringInlined>(this->value)) {
            if (std::holds_alternative<StringExternal>(rhs.value)) {
                return strcmp(std::get<StringInlined>(this->value).id,
                              std::get<StringExternal>(rhs.value).to_string().c_str())
                    > 0;
            }
        }

        else if (std::holds_alternative<int64_t>(this->value)) {
            if (std::holds_alternative<float>(rhs.value)) {
                return std::get<int64_t>(this->value) > std::get<float>(rhs.value);
            }
        }

        else if (std::holds_alternative<float>(this->value)) {
            if (std::holds_alternative<int64_t>(rhs.value)) {
                return std::get<float>(this->value) > std::get<int64_t>(rhs.value);
            }
        }
        return this->value > rhs.value;
    }

    inline GraphObject operator+(const GraphObject& rhs) const noexcept {
        if (std::holds_alternative<int64_t>(this->value)) {
            if (std::holds_alternative<int64_t>(rhs.value)) {
                // int + int = int
                return GraphObject::make_int(std::get<int64_t>(this->value) + std::get<int64_t>(rhs.value));
            } else if (std::holds_alternative<float>(rhs.value)) {
                // int + float = float
                return GraphObject::make_float(std::get<int64_t>(this->value) + std::get<float>(rhs.value));
            }
        } else if (std::holds_alternative<float>(this->value)) {
            if (std::holds_alternative<float>(rhs.value)) {
                // float + float = float
                return GraphObject::make_float(std::get<float>(this->value) + std::get<float>(rhs.value));
            } else if (std::holds_alternative<int64_t>(rhs.value)) {
                // float + int = float
                return GraphObject::make_float(std::get<float>(this->value) + std::get<int64_t>(rhs.value));
            }
        }
        return GraphObject::make_null();
    }

    inline GraphObject operator-(const GraphObject& rhs) const noexcept {
        if (std::holds_alternative<int64_t>(this->value)) {
            if (std::holds_alternative<int64_t>(rhs.value)) {
                // int - int = int
                return GraphObject::make_int(std::get<int64_t>(this->value) - std::get<int64_t>(rhs.value));
            } else if (std::holds_alternative<float>(rhs.value)) {
                // int - float = float
                return GraphObject::make_float(std::get<int64_t>(this->value) - std::get<float>(rhs.value));
            }
        } else if (std::holds_alternative<float>(this->value)) {
            if (std::holds_alternative<float>(rhs.value)) {
                // float - float = float
                return GraphObject::make_float(std::get<float>(this->value) - std::get<float>(rhs.value));
            } else if (std::holds_alternative<int64_t>(rhs.value)) {
                // float - int = float
                return GraphObject::make_float(std::get<float>(this->value) - std::get<int64_t>(rhs.value));
            }
        }
        return GraphObject::make_null();
    }

    inline GraphObject operator*(const GraphObject& rhs) const noexcept {
        if (std::holds_alternative<int64_t>(this->value)) {
            if (std::holds_alternative<int64_t>(rhs.value)) {
                // int * int = int
                return GraphObject::make_int(std::get<int64_t>(this->value) * std::get<int64_t>(rhs.value));
            } else if (std::holds_alternative<float>(rhs.value)) {
                // int * float = float
                return GraphObject::make_float(std::get<int64_t>(this->value) * std::get<float>(rhs.value));
            }
        } else if (std::holds_alternative<float>(this->value)) {
            if (std::holds_alternative<float>(rhs.value)) {
                // float * float = float
                return GraphObject::make_float(std::get<float>(this->value) * std::get<float>(rhs.value));
            } else if (std::holds_alternative<int64_t>(rhs.value)) {
                // float * int = float
                return GraphObject::make_float(std::get<float>(this->value) * std::get<int64_t>(rhs.value));
            }
        }
        return GraphObject::make_null();
    }

    inline GraphObject operator/(const GraphObject& rhs) const noexcept {
        if (std::holds_alternative<int64_t>(this->value)) {
            if (std::holds_alternative<int64_t>(rhs.value)) {
                // int / int = int
                if (std::get<int64_t>(rhs.value) == 0) {
                    // avoid division by 0
                    return GraphObject::make_null();
                }
                return GraphObject::make_int(std::get<int64_t>(this->value) / std::get<int64_t>(rhs.value));
            } else if (std::holds_alternative<float>(rhs.value)) {
                // int / float = float
                if (std::get<float>(rhs.value) == 0) {
                    // avoid division by 0
                    return GraphObject::make_null();
                }
                return GraphObject::make_float(std::get<int64_t>(this->value) / std::get<float>(rhs.value));
            }
        } else if (std::holds_alternative<float>(this->value)) {
            if (std::holds_alternative<float>(rhs.value)) {
                // float / float = float
                if (std::get<float>(rhs.value) == 0) {
                    // avoid division by 0
                    return GraphObject::make_null();
                }
                return GraphObject::make_float(std::get<float>(this->value) / std::get<float>(rhs.value));
            } else if (std::holds_alternative<int64_t>(rhs.value)) {
                // float / int = float
                if (std::get<int64_t>(rhs.value) == 0) {
                    // avoid division by 0
                    return GraphObject::make_null();
                }
                return GraphObject::make_float(std::get<float>(this->value) / std::get<int64_t>(rhs.value));
            }
        }
        return GraphObject::make_null();
    }

    inline GraphObject operator%(const GraphObject& rhs) const noexcept {
        if (std::holds_alternative<int64_t>(this->value)) {
            if (std::holds_alternative<int64_t>(rhs.value)) {
                // int % int = int
                if (std::get<int64_t>(rhs.value) == 0) {
                    // avoid division by 0
                    return GraphObject::make_null();
                }
                return GraphObject::make_int(std::get<int64_t>(this->value) % std::get<int64_t>(rhs.value));
            }
        }
        return GraphObject::make_null();
    }

private:
    GraphObject(GraphObjectVariant value) : value(value) { }
};

static_assert(std::is_trivially_copyable<GraphObject>::value);

static_assert(sizeof(GraphObject) <= 16,
              "GraphObject size should be small, if it needs to increase the size avoid copies");
