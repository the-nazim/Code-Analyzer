#include <iostream>
#include "../include/AnalyzerConsumer.h"

void AnalyzerConsumer::HandleTranslationUnit(clang::ASTContext &context) {
    std::cout << "AST Traversal Started" << std::endl;
    ASTVisitor visitor(&context);
    visitor.TraverseDecl(context.getTranslationUnitDecl());
    visitor.ReportUnusedVariables();
}