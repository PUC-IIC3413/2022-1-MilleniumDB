#pragma once

#include "base/graph_object/graph_object.h"
#include "base/ids/object_id.h"

struct GraphObjectVisitor {
    const bool create_if_not_exists;

    GraphObjectVisitor(bool create_if_not_exists);

    ObjectId operator()(const NamedNodeInlined&)  const;
    ObjectId operator()(const NamedNodeExternal&) const;
    ObjectId operator()(const NamedNodeTmp&)      const;
    ObjectId operator()(const Edge&)              const;
    ObjectId operator()(const AnonymousNode&)     const;
    ObjectId operator()(const StringInlined&)     const;
    ObjectId operator()(const StringExternal&)    const;
    ObjectId operator()(const StringTmp&)         const;
    ObjectId operator()(const NullGraphObject&)   const;
    ObjectId operator()(const NotFoundObject&)    const;
    ObjectId operator()(const Path&)              const;
    ObjectId operator()(const int64_t)            const;
    ObjectId operator()(const bool)               const;
    ObjectId operator()(const float)              const;
};
