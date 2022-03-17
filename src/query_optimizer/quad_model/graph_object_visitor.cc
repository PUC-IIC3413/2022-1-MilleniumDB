#include "graph_object_visitor.h"

#include "base/exceptions.h"
#include "query_optimizer/quad_model/quad_model.h"

GraphObjectVisitor::GraphObjectVisitor(bool create_if_not_exists) :
    create_if_not_exists (create_if_not_exists) { }


ObjectId GraphObjectVisitor::operator()(const NamedNodeInlined& named_node_inlined) const {
    std::string str(named_node_inlined.id);
    uint64_t res = 0;
    int shift_size = 8*6;
    // MUST convert to uint8_t and then to uint64_t.
    // Shift with shift_size >=32 is undefined behaviour.
    for (uint8_t byte : str) {
        uint64_t byte64 = static_cast<uint64_t>(byte);
        res |= byte64 << shift_size;
        shift_size -= 8;
    }
    return ObjectId(res | ObjectId::IDENTIFIABLE_INLINED_MASK);
}


ObjectId GraphObjectVisitor::operator()(const NamedNodeExternal& named_node_external) const {
    return ObjectId(named_node_external.external_id | ObjectId::IDENTIFIABLE_EXTERNAL_MASK);
}


ObjectId GraphObjectVisitor::operator()(const NamedNodeTmp& named_node_tmp) const {
    if (create_if_not_exists) {
        bool created;
        auto external_id = quad_model.strings_hash().get_or_create_id(*named_node_tmp.name, &created);
        return ObjectId(external_id | ObjectId::IDENTIFIABLE_EXTERNAL_MASK);
    } else {
        auto external_id = quad_model.strings_hash().get_id(*named_node_tmp.name);
        if (external_id == ObjectId::OBJECT_ID_NOT_FOUND) {
            return ObjectId::get_not_found();
        } else {
            return ObjectId(external_id | ObjectId::IDENTIFIABLE_EXTERNAL_MASK);
        }
    }
}


ObjectId GraphObjectVisitor::operator()(const Edge& edge) const {
    return ObjectId(ObjectId::CONNECTION_MASK | edge.id);
}


ObjectId GraphObjectVisitor::operator()(const AnonymousNode& anonymous_node) const {
    return ObjectId(ObjectId::ANONYMOUS_NODE_MASK | anonymous_node.id);
}


ObjectId GraphObjectVisitor::operator()(const StringInlined& string_inlined) const {
    std::string str(string_inlined.id);

    uint64_t res = 0;
    int shift_size = 8*6;
    // MUST convert to uint8_t and then to uint64_t.
    // Shift with shift_size >=32 is undefined behaviour.
    for (uint8_t byte : str) {
        uint64_t byte64 = static_cast<uint64_t>(byte);
        res |= byte64 << shift_size;
        shift_size -= 8;
    }
    return ObjectId(res | ObjectId::VALUE_INLINE_STR_MASK);
}


ObjectId GraphObjectVisitor::operator()(const StringExternal& string_external) const {
    return ObjectId(string_external.external_id | ObjectId::VALUE_EXTERNAL_STR_MASK);
}


ObjectId GraphObjectVisitor::operator()(const StringTmp& tmp) const {
    if (create_if_not_exists) {
        bool created;
        auto external_id = quad_model.strings_hash().get_or_create_id(*tmp.str, &created);
        return ObjectId(external_id | ObjectId::VALUE_EXTERNAL_STR_MASK);
    } else {
        auto external_id = quad_model.strings_hash().get_id(*tmp.str);
        if (external_id == ObjectId::OBJECT_ID_NOT_FOUND) {
            return ObjectId::get_not_found();
        } else {
            return ObjectId(external_id | ObjectId::VALUE_EXTERNAL_STR_MASK);
        }
    }
}


ObjectId GraphObjectVisitor::operator()(const NullGraphObject&) const {
    return ObjectId::get_null();
}


ObjectId GraphObjectVisitor::operator()(const NotFoundObject&) const {
    return ObjectId::get_not_found();
}


ObjectId GraphObjectVisitor::operator()(const int64_t n) const {
    int64_t int_value = n;

    if (int_value < 0) {
        int_value *= -1;

        // check if it needs more than 7 bytes
        if ( (int_value & 0xFF00'0000'0000'0000UL) == 0) {
            int_value = (~int_value) & 0x00FF'FFFF'FFFF'FFFFUL;
            return ObjectId(ObjectId::VALUE_NEGATIVE_INT_MASK | int_value);
        } else {
            // VALUE_EXTERNAL_INT_MASK
            throw NotSupportedException("BIG INTEGERS NOT SUPPORTED YET");
        }
    }
    else {
        // check if it needs more than 7 bytes
        if ( (int_value & 0xFF00'0000'0000'0000UL) == 0) {
            return ObjectId(ObjectId::VALUE_POSITIVE_INT_MASK | int_value);
        } else {
            // VALUE_EXTERNAL_INT_MASK
            throw NotSupportedException("BIG INTEGERS NOT SUPPORTED YET");
        }
    }
}


ObjectId GraphObjectVisitor::operator()(const bool value_bool) const {
    if (value_bool) {
        return ObjectId(ObjectId::VALUE_BOOL_MASK | 0x01);
    } else {
        return ObjectId(ObjectId::VALUE_BOOL_MASK | 0x00);
    }
}


ObjectId GraphObjectVisitor::operator()(const float value_float) const {
    static_assert(sizeof(value_float) == 4);
    unsigned char bytes[sizeof(value_float)];
    memcpy(bytes, &value_float, sizeof(value_float));

    uint64_t res = 0;
    int shift_size = 0;
    for (std::size_t i = 0; i < sizeof(bytes); ++i) {
        uint64_t byte = bytes[i];
        res |= byte << shift_size;
        shift_size += 8;
    }
    return ObjectId(ObjectId::VALUE_FLOAT_MASK | res);
}


ObjectId GraphObjectVisitor::operator()(const Path& path) const {
    return ObjectId(ObjectId::VALUE_PATH_MASK | path.path_id);
}
