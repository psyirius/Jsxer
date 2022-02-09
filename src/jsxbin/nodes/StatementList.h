#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include <algorithm>

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class StatementList : public AstNode {
    public:
        explicit StatementList(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        size_t length;
        decoders::LineInfo body;
        vector<AstNode*> statements;
    };
} }