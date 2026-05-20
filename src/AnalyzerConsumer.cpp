#include <iostream>
#include "../include/AnalyzerConsumer.h"

void AnalyzerConsumer::HandleTranslationUnit(clang::ASTContext &context) {
    std::cout << "AST Traversal Started" << std::endl;
    visitor.TraverseDecl(context.getTranslationUnitDecl());
    visitor.ReportUnusedVariables();
}