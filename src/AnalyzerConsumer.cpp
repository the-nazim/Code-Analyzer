#include "../include/AnalyzerConsumer.h"

void AnalyzerConsumer::HandleTranslationUnit(clang::ASTContext &context) {
    visitor.TraverseDecl(context.getTranslationUnitDecl());
}