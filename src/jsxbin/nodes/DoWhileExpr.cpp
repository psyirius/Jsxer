#include "DoWhileExpr.h"

void DoWhileExpr::parse() {
    body = decoders::d_line_info(reader);
    condition = decoders::d_node(reader);
}

string DoWhileExpr::to_string() {
    string label = body.lbl_statement();
    string inner = body.create_body();
    string result;

    result += label + "do {\n";
    result += "  " + inner + '\n';
    result += "} while (" + condition->to_string() + ')';

    return result;
}