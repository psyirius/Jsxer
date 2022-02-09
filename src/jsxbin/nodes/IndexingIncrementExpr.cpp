#include "IndexingIncrementExpr.h"

void IndexingIncrementExpr::parse() {
    variable = decoders::d_node(reader);
    operation = decoders::d_literal_num(reader);
    postfix = decoders::d_bool(reader);
}

string IndexingIncrementExpr::to_string() {
    string op = operation == 1 ? "++" : "--";
    return postfix ? variable->to_string() + op : op + variable->to_string() ;
}