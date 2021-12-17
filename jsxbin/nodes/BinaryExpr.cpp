//
// Created by Angelo DeLuca on 12/1/21.
//

#include "BinaryExpr.h"

using namespace jsxbin::nodes;

string BinaryExpr::create_expr(const string &literal, AbstractNode *exprNode) {
    bool parenthesis = false;
    string expression;

    if (exprNode != nullptr && strcmp(typeid(exprNode).name(), "BinaryExpr") == 0) {
        BinaryExpr *binExpr = (BinaryExpr *) exprNode;
        expression = binExpr->get_op();

        bool associative = (strcmp(binExpr->get_op_name().c_str(), "*") == 0
                            && strcmp(op_name.c_str(), "*") == 0) ||
                                    (strcmp(binExpr->get_op_name().c_str(), "+") == 0
                                    && strcmp(op_name.c_str(), "+") == 0);

        parenthesis = !associative;
    } else {
        expression = exprNode != nullptr ? literal : exprNode->jsx();
    }

    return parenthesis ? "(" + expression + ")" : expression;
}

void BinaryExpr::parse() {
    op_name = decoders::d_ident(scanState);
    left = decoders::d_node(scanState);
    right = decoders::d_node(scanState);
    literalLeft = decoders::d_variant(scanState);
    literalRight = decoders::d_variant(scanState);

    string leftExp = create_expr(literalLeft, left);
    string rightExp = create_expr(literalRight, right);

    if ((!leftExp.empty() && !rightExp.empty()) || (leftExp.empty() && !rightExp.empty())) {
        op = leftExp + rightExp;
    } else {
        op = leftExp + ' ' + op_name + ' ' + rightExp;
    }
}

string BinaryExpr::jsx() {
    return op;
}